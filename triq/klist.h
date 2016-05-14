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
#ifndef _KLIST_H_
#define _KLIST_H_

#include <algorithm>
#include <deque>

class QDataStream;


template <class T> class KList {
public:
    typedef typename std::deque<T>::size_type size_type;
    typedef typename std::deque<T>::const_reference const_reference;
    typedef typename std::deque<T>::reference reference;
    typedef typename std::deque<T>::const_iterator ConstIterator;
    typedef typename std::deque<T>::iterator Iterator;

public:
    KList();
    KList(const KList &other);

    size_type count() const;
    bool isEmpty() const;

    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;

    const T &first() const;
    const T &last() const;

    reference operator[] (size_type n);
    const_reference operator[] (size_type n) const;

    ConstIterator find(const T &val);

    Iterator insert(Iterator it, const T &val);
    void prepend(const T &val);
    void append(const T &val);
    KList<T> &operator<<(const T &val);
    KList<T> &operator+=(const T &val);
    KList<T> &operator+=(const KList<T> &other);

    void clear();
    Iterator remove(ConstIterator position);

private:
    std::deque<T> list;
};


template <class T>
KList<T>::KList()
{
}


template <class T>
KList<T>::KList(const KList &other)
{
    list = other.list;
}


template <class T>
typename std::deque<T>::size_type KList<T>::count() const
{
    return list.size();
}


template <class T>
bool KList<T>::isEmpty() const
{
    return list.empty();
}


template <class T>
typename KList<T>::Iterator KList<T>::begin()
{
    return list.begin();
}


template <class T>
typename KList<T>::ConstIterator KList<T>::begin() const
{
    return list.begin();
}


template <class T>
typename KList<T>::Iterator KList<T>::end()
{
    return list.end();
}


template <class T>
typename KList<T>::ConstIterator KList<T>::end() const
{
    return list.end();
}


template <class T>
const T &KList<T>::first() const
{
    return list.front();
}


template <class T>
const T &KList<T>::last() const
{
    return list.back();
}


template <class T>
typename KList<T>::reference KList<T>::operator[](KList::size_type n)
{
    return list.at(n);
}


template <class T>
typename KList<T>::const_reference KList<T>::operator[](KList::size_type n) const
{
    return list.at(n);
}


template <class T>
typename KList<T>::ConstIterator KList<T>::find(const T &val)
{
    return std::find(list.begin(), list.end(), val);
}


template <class T>
typename KList<T>::Iterator KList<T>::insert(KList::Iterator it, const T &val)
{
    return list.insert(it, val);
}


template <class T>
void KList<T>::prepend(const T &val)
{
    list.push_front(val);
}


template <class T>
void KList<T>::append(const T &val)
{
    list.push_back(val);
}


template <class T>
KList<T> &KList<T>::operator<<(const T &val)
{
    append(val);
    return *this;
}


template <class T>
KList<T> &KList<T>::operator+=(const T &val)
{
    append(val);
    return *this;
}


template <class T>
KList<T> &KList<T>::operator+=(const KList<T> &other)
{
    list.insert(list.end(), other.list.begin(), other.list.end());
    return *this;
}


template <class T>
void KList<T>::clear()
{
    list.clear();
}


template <class T>
typename KList<T>::Iterator KList<T>::remove(KList<T>::ConstIterator position)
{
    return list.erase(position);
}


template <class T>
inline KList<T> operator+(const KList<T> &list1, const KList<T> &list2)
{
    KList<T> result;

    result += list1;
    result += list2;

    return result;
}


template <class T>
inline QDataStream & operator>>(QDataStream &stream, KList<T> &list)
{
    list.clear();

    Q_UINT32 c;
    stream >> c;

    for(Q_UINT32 i = 0; i < c; i++)
    {
        T t;
        stream >> t;
        list.append(t);

        if(stream.atEnd())
            break;
    }

    return stream;
}


template <class T>
inline QDataStream & operator<<(QDataStream &stream, const KList<T> &list)
{
    stream << static_cast<Q_UINT32>(list.count());

    for(const auto &it : list)
        stream << it;

    return stream;
}


#endif
