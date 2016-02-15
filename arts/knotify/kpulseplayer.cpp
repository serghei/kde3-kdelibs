/************************************************************************\
 *
 *  (c) 2016 by Serghei Amelian <serghei.amelian@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
\************************************************************************/
//#include <atomic>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>
#include <qapplication.h>
#include <qobject.h>
#include <qthread.h>
#include <qasciidict.h>
#include <kdebug.h>

#include "kpulseplayer.h"


class KPulsePlayerWorker : public QThread {
public:
	KPulsePlayerWorker(KPulsePlayerPrivate *parent, const QCString &file);
	~KPulsePlayerWorker();

	void rewind() { do_rewind = true; }
	void cancel() { do_cancel = true; }

protected:
	void run();

private:
	void runOgg();

private:
	KPulsePlayerPrivate *parent;
	QCString file;

	//std::atomic_bool do_rewind;
	//std::atomic_bool do_cancel;
	bool do_rewind;
	bool do_cancel;
};


KPulsePlayerWorker::KPulsePlayerWorker(KPulsePlayerPrivate *parent, const QCString &file)
	: parent(parent), file(file), do_rewind(false), do_cancel(false)
{
	start();
}


KPulsePlayerWorker::~KPulsePlayerWorker()
{
	wait();
}


void KPulsePlayerWorker::run()
{
	runOgg();

	if(!do_cancel)
		QApplication::postEvent(reinterpret_cast<QObject*>(parent), new QCustomEvent(QEvent::User, file.data()));
}


void KPulsePlayerWorker::runOgg()
{
	OggVorbis_File vf;

	int rc = ov_fopen(file.data(), &vf);

	if(0 < rc)
	{
		const char *err = "Unknown error";

		switch(rc)
		{
			case OV_EREAD:
				err = "A read from media returned an error";
				break;
			case OV_ENOTVORBIS:
				err = "Bitstream does not contain any Vorbis data";
				break;
			case OV_EVERSION:
				err = "Vorbis version mismatch";
				break;
			case OV_EBADHEADER:
				err = "Invalid Vorbis bitstream header";
				break;
			case OV_EFAULT:
				err = "Internal logic fault; indicates a bug or heap/stack corruption";
				break;
		}

		kdDebug() << "KPulsePlayerWorker::runOgg() - vorbisfile: " << err << endl;
		return;
	}

	vorbis_info *vi = ov_info(&vf, -1);

	pa_sample_spec ss;
	ss.format = PA_SAMPLE_S16LE;
	ss.rate = vi->rate;
	ss.channels = vi->channels;

	int error;
	pa_simple *s = pa_simple_new(NULL, "KNotify", PA_STREAM_PLAYBACK, NULL, "Playback", &ss, NULL, NULL, &error);

	if(NULL == s)
	{
		kdDebug() << "KPulsePlayerWorker::runOgg() - pulseaudio: " << pa_strerror(error) << endl;
		goto VORBIS_CLEANUP;
	}

	for(int bitstream = 0; !do_cancel;)
	{
		if(do_rewind)
		{
			ov_raw_seek(&vf, 0);
			do_rewind = false;
		}

		char buf[4192];
		long len = ov_read(&vf, buf, sizeof(buf), 0, 2, 1, &bitstream);

		if(0 < len)
		{
			if(0 > pa_simple_write(s, buf, len, &error))
			{
				kdDebug() << "KPulsePlayerWorker::runOgg() - pulseaudio: " << pa_strerror(error) << endl;
				break;
			}
		}
		else
		{
			if(0 > len)
				kdDebug() << "KPulsePlayerWorker::runOgg() - vorbisfile: the ogg stream seems corrupted, abort playing" << endl;
			break;
		}
	}

	pa_simple_drain(s, &error);
	pa_simple_free(s);

VORBIS_CLEANUP:
	ov_clear(&vf);
}


class KPulsePlayerPrivate : public QObject {
public:
	KPulsePlayerPrivate();
	~KPulsePlayerPrivate();
	void play(const QCString &file);

protected:
	void customEvent(QCustomEvent *e);

private:
	QAsciiDict<KPulsePlayerWorker> workers;
};


KPulsePlayerPrivate::KPulsePlayerPrivate()
	: QObject(0, "KPulsePlayerPrivate")
{
	workers.setAutoDelete(true);
}


KPulsePlayerPrivate::~KPulsePlayerPrivate()
{
	QAsciiDictIterator<KPulsePlayerWorker> it(workers);

	// inform the workers to cancel their jobs
	for(; it.current(); ++it)
	{
		it.current()->cancel();
	}
}


void KPulsePlayerPrivate::customEvent(QCustomEvent *e)
{
	workers.remove(static_cast<const char*>(e->data()));
}


void KPulsePlayerPrivate::play(const QCString &file)
{
	// check if this sound is already playing
	KPulsePlayerWorker *worker = workers.find(file);

	// if yes, just rewind it
	if(worker)
	{
		worker->rewind();
	}
	// if not, start the worker for this sound
	else
	{
		worker = new KPulsePlayerWorker(this, file);
		workers.insert(file, worker);
	}
}


KPulsePlayer::KPulsePlayer()
{
	d = new KPulsePlayerPrivate;
}


KPulsePlayer::~KPulsePlayer()
{
	delete d;
}


void KPulsePlayer::play(const QCString &file)
{
	d->play(file);
}
