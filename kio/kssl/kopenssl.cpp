/* This file is part of the KDE libraries
   Copyright (C) 2001-2003 George Staikos <staikos@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef KSSL_HAVE_SSL
#include <openssl/opensslv.h>
#endif

#include <kdebug.h>
#include <kconfig.h>
#include <kstaticdeleter.h>
#include <qregexp.h>
#include <qdir.h>

#include <stdio.h>
#include <unistd.h>
#include "kopenssl.h"

#define GET_CRYPTOLIB_SYMBOL(a) ((_cryptoLib->hasSymbol(a)) ? _cryptoLib->symbol(a) : NULL)
#define GET_SSLLIB_SYMBOL(a) ((_sslLib->hasSymbol(a)) ? _sslLib->symbol(a) : NULL)

extern "C" {
#ifdef KSSL_HAVE_SSL
static int (*K_SSL_connect)(SSL *) = 0L;
static int (*K_SSL_accept)(SSL *) = 0L;
static int (*K_SSL_read)(SSL *, void *, int) = 0L;
static int (*K_SSL_write)(SSL *, const void *, int) = 0L;
static SSL *(*K_SSL_new)(SSL_CTX *) = 0L;
static void (*K_SSL_free)(SSL *) = 0L;
static int (*K_SSL_shutdown)(SSL *) = 0L;
static SSL_CTX *(*K_SSL_CTX_new)(SSL_METHOD *) = 0L;
static void (*K_SSL_CTX_free)(SSL_CTX *) = 0L;
static int (*K_SSL_set_fd)(SSL *, int) = 0L;
static int (*K_SSL_pending)(SSL *) = 0L;
static int (*K_SSL_peek)(SSL *, void *, int) = 0L;
static int (*K_SSL_CTX_set_cipher_list)(SSL_CTX *, const char *) = 0L;
static void (*K_SSL_CTX_set_verify)(SSL_CTX *, int, int (*)(int, X509_STORE_CTX *)) = 0L;
static int (*K_SSL_use_certificate)(SSL *, X509 *) = 0L;
static SSL_CIPHER *(*K_SSL_get_current_cipher)(SSL *) = 0L;
static long (*K_SSL_set_options)(SSL *ssl, long options) = 0L;
static int (*K_SSL_session_reused)(SSL *ssl) = 0L;
static long (*K_SSL_ctrl)(SSL *, int, long, void *) = 0L;
static int (*K_RAND_egd)(const char *) = 0L;
static const char *(*K_RAND_file_name)(char *, size_t) = 0L;
static int (*K_RAND_load_file)(const char *, long) = 0L;
static int (*K_RAND_write_file)(const char *) = 0L;
static SSL_METHOD *(*K_TLSv1_client_method)() = 0L;
static SSL_METHOD *(*K_SSLv2_client_method)() = 0L;
static SSL_METHOD *(*K_SSLv3_client_method)() = 0L;
static SSL_METHOD *(*K_TLS_client_method)() = 0L;
static X509 *(*K_SSL_get_peer_certificate)(SSL *) = 0L;
static int (*K_SSL_CIPHER_get_bits)(SSL_CIPHER *, int *) = 0L;
static char *(*K_SSL_CIPHER_get_version)(SSL_CIPHER *) = 0L;
static const char *(*K_SSL_CIPHER_get_name)(SSL_CIPHER *) = 0L;
static char *(*K_SSL_CIPHER_description)(SSL_CIPHER *, char *, int) = 0L;
static X509 *(*K_d2i_X509)(X509 **, unsigned char **, long) = 0L;
static X509_CRL *(*K_d2i_X509_CRL)(X509_CRL **, unsigned char **, long) = 0L;
static int (*K_i2d_X509)(X509 *, unsigned char **) = 0L;
static int (*K_X509_cmp)(X509 *, X509 *) = 0L;
static int (*K_X509_subject_name_cmp)(const X509 *, const X509 *) = 0L;
static void (*K_X509_STORE_CTX_free)(X509_STORE_CTX *) = 0L;
static int (*K_X509_verify_cert)(X509_STORE_CTX *) = 0L;
static X509_STORE_CTX *(*K_X509_STORE_CTX_new)(void) = 0L;
static void (*K_X509_STORE_free)(X509_STORE *) = 0L;
static X509_STORE *(*K_X509_STORE_new)(void) = 0L;
static void (*K_X509_free)(X509 *) = 0L;
static void (*K_X509_CRL_free)(X509_CRL *) = 0L;
static char *(*K_X509_NAME_oneline)(X509_NAME *, char *, int) = 0L;
static X509_NAME *(*K_X509_get_subject_name)(X509 *) = 0L;
static X509_NAME *(*K_X509_get_issuer_name)(X509 *) = 0L;
static X509_LOOKUP *(*K_X509_STORE_add_lookup)(X509_STORE *, X509_LOOKUP_METHOD *) = 0L;
static X509_LOOKUP_METHOD *(*K_X509_LOOKUP_file)(void) = 0L;
static void (*K_X509_LOOKUP_free)(X509_LOOKUP *) = 0L;
static int (*K_X509_LOOKUP_ctrl)(X509_LOOKUP *, int, const char *, long, char **) = 0L;
static void (*K_X509_STORE_CTX_init)(X509_STORE_CTX *, X509_STORE *, X509 *, STACK_OF(X509) *) = 0L;
static void (*K_CRYPTO_free)(void *) = 0L;
static X509 *(*K_X509_dup)(X509 *) = 0L;
static void (*K_X509_get0_signature)(const ASN1_BIT_STRING **psig, const X509_ALGOR **palg, const X509 *x) = 0L;
static BIO_METHOD *(*K_BIO_s_mem)(void) = 0L;
static BIO *(*K_BIO_new)(BIO_METHOD *) = 0L;
static BIO *(*K_BIO_new_fp)(FILE *, int) = 0L;
static BIO *(*K_BIO_new_mem_buf)(void *, int) = 0L;
static int (*K_BIO_free)(BIO *) = 0L;
static long (*K_BIO_ctrl)(BIO *, int, long, void *) = 0L;
static int (*K_BIO_write)(BIO *b, const void *data, int len) = 0L;
static void *(*K_BIO_get_data)(BIO *a) = 0L;
static int (*K_PEM_ASN1_write_bio)(int (*)(), const char *, BIO *, char *, const EVP_CIPHER *, unsigned char *, int, pem_password_cb *, void *) = 0L;
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
static int (*K_ASN1_item_i2d_fp)(ASN1_ITEM *, FILE *, unsigned char *) = 0L;
static ASN1_ITEM *K_NETSCAPE_X509_it = 0L;
#else
static ASN1_METHOD *(*K_X509_asn1_meth)(void) = 0L;
static int (*K_ASN1_i2d_fp)(int (*)(), FILE *, unsigned char *) = 0L;
static int (*K_i2d_ASN1_HEADER)(ASN1_HEADER *, unsigned char **) = 0L;
#endif
static int (*K_X509_print_fp)(FILE *, X509 *) = 0L;
static int (*K_i2d_PKCS12)(PKCS12 *, unsigned char **) = 0L;
static int (*K_i2d_PKCS12_fp)(FILE *, PKCS12 *) = 0L;
static int (*K_PKCS12_newpass)(PKCS12 *, char *, char *) = 0L;
static PKCS12 *(*K_d2i_PKCS12_fp)(FILE *, PKCS12 **) = 0L;
static PKCS12 *(*K_PKCS12_new)(void) = 0L;
static void (*K_PKCS12_free)(PKCS12 *) = 0L;
static int (*K_PKCS12_parse)(PKCS12 *, const char *, EVP_PKEY **, X509 **, STACK_OF(X509) **) = 0L;
static void (*K_EVP_PKEY_free)(EVP_PKEY *) = 0L;
static EVP_PKEY *(*K_EVP_PKEY_new)() = 0L;
static int (*K_EVP_PKEY_base_id)(const EVP_PKEY *pkey) = 0L;
static RSA *(*K_EVP_PKEY_get0_RSA)(EVP_PKEY *pkey) = 0L;
static DSA *(*K_EVP_PKEY_get0_DSA)(EVP_PKEY *pkey) = 0L;
static void (*K_X509_REQ_free)(X509_REQ *) = 0L;
static X509_REQ *(*K_X509_REQ_new)() = 0L;
static int (*K_SSL_CTX_use_PrivateKey)(SSL_CTX *, EVP_PKEY *) = 0L;
static int (*K_SSL_CTX_use_certificate)(SSL_CTX *, X509 *) = 0L;
static int (*K_SSL_get_error)(SSL *, int) = 0L;
static STACK_OF(X509) * (*K_SSL_get_peer_cert_chain)(SSL *) = 0L;
static void (*K_X509_STORE_CTX_set0_untrusted)(X509_STORE_CTX *, STACK_OF(X509) *) = 0L;
static void (*K_X509_STORE_CTX_set_purpose)(X509_STORE_CTX *, int) = 0L;
static void (*K_sk_free)(STACK *) = 0L;
static int (*K_sk_num)(STACK *) = 0L;
static char *(*K_sk_pop)(STACK *) = 0L;
static char *(*K_sk_value)(STACK *, int) = 0L;
static STACK *(*K_sk_new)(int (*)()) = 0L;
static int (*K_sk_push)(STACK *, char *) = 0L;
static STACK *(*K_sk_dup)(const STACK *) = 0L;
static char *(*K_i2s_ASN1_INTEGER)(X509V3_EXT_METHOD *, ASN1_INTEGER *) = 0L;
static ASN1_INTEGER *(*K_X509_get_serialNumber)(X509 *) = 0L;
static EVP_PKEY *(*K_X509_get_pubkey)(X509 *) = 0L;
static int (*K_i2d_PublicKey)(EVP_PKEY *, unsigned char **) = 0L;
static int (*K_X509_check_private_key)(X509 *, EVP_PKEY *) = 0L;
static char *(*K_BN_bn2hex)(const BIGNUM *) = 0L;
static int (*K_X509_digest)(const X509 *, const EVP_MD *, unsigned char *, unsigned int *) = 0L;
static EVP_MD *(*K_EVP_md5)() = 0L;
static void (*K_ASN1_INTEGER_free)(ASN1_INTEGER *) = 0L;
static int (*K_OBJ_obj2nid)(ASN1_OBJECT *) = 0L;
static const char *(*K_OBJ_nid2ln)(int) = 0L;
static int (*K_X509_get_ext_count)(X509 *) = 0L;
static int (*K_X509_get_ext_by_NID)(X509 *, int, int) = 0L;
static int (*K_X509_get_ext_by_OBJ)(X509 *, ASN1_OBJECT *, int) = 0L;
static X509_EXTENSION *(*K_X509_get_ext)(X509 *, int loc) = 0L;
static X509_EXTENSION *(*K_X509_delete_ext)(X509 *, int) = 0L;
static int (*K_X509_add_ext)(X509 *, X509_EXTENSION *, int) = 0L;
static void *(*K_X509_get_ext_d2i)(X509 *, int, int *, int *) = 0L;
static char *(*K_i2s_ASN1_OCTET_STRING)(X509V3_EXT_METHOD *, ASN1_OCTET_STRING *) = 0L;
static int (*K_ASN1_BIT_STRING_get_bit)(ASN1_BIT_STRING *, int) = 0L;
static PKCS7 *(*K_PKCS7_new)() = 0L;
static void (*K_PKCS7_free)(PKCS7 *) = 0L;
static void (*K_PKCS7_content_free)(PKCS7 *) = 0L;
static int (*K_i2d_PKCS7)(PKCS7 *, unsigned char **) = 0L;
static PKCS7 *(*K_d2i_PKCS7)(PKCS7 **, unsigned char **, long) = 0L;
static int (*K_i2d_PKCS7_fp)(FILE *, PKCS7 *) = 0L;
static PKCS7 *(*K_d2i_PKCS7_fp)(FILE *, PKCS7 **) = 0L;
static int (*K_i2d_PKCS7_bio)(BIO *bp, PKCS7 *p7) = 0L;
static PKCS7 *(*K_d2i_PKCS7_bio)(BIO *bp, PKCS7 **p7) = 0L;
static PKCS7 *(*K_PKCS7_dup)(PKCS7 *) = 0L;
static STACK_OF(X509_NAME) * (*K_SSL_load_client_CA_file)(const char *) = 0L;
static STACK_OF(X509_INFO) * (*K_PEM_X509_INFO_read)(FILE *, STACK_OF(X509_INFO) *, pem_password_cb *, void *) = 0L;
static char *(*K_ASN1_d2i_fp)(char *(*)(), char *(*)(), FILE *, unsigned char **) = 0L;
static X509 *(*K_X509_new)() = 0L;
static int (*K_X509_PURPOSE_get_count)() = 0L;
static int (*K_X509_PURPOSE_get_id)(X509_PURPOSE *) = 0L;
static int (*K_X509_check_purpose)(X509 *, int, int) = 0L;
static X509_PURPOSE *(*K_X509_PURPOSE_get0)(int) = 0L;
static int (*K_EVP_PKEY_assign)(EVP_PKEY *, int, char *) = 0L;
static int (*K_X509_REQ_set_pubkey)(X509_REQ *, EVP_PKEY *) = 0L;
static void (*K_RSA_get0_key)(const RSA *r, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d) = 0L;
static RSA *(*K_RSA_generate_key)(int, unsigned long, void (*)(int, int, void *), void *) = 0L;
static void (*K_DSA_get0_pqg)(const DSA *d, const BIGNUM **p, const BIGNUM **q, const BIGNUM **g) = 0L;
static void (*K_DSA_get0_key)(const DSA *d, const BIGNUM **pub_key, const BIGNUM **priv_key) = 0L;
static int (*K_i2d_X509_REQ_fp)(FILE *, X509_REQ *) = 0L;
static void (*K_ERR_clear_error)() = 0L;
static unsigned long (*K_ERR_get_error)() = 0L;
static void (*K_ERR_print_errors_fp)(FILE *) = 0L;
static PKCS7 *(*K_PKCS7_sign)(X509 *, EVP_PKEY *, STACK_OF(X509) *, BIO *, int) = 0L;
static int (*K_PKCS7_verify)(PKCS7 *, STACK_OF(X509) *, X509_STORE *, BIO *, BIO *, int) = 0L;
static STACK_OF(X509) * (*K_PKCS7_get0_signers)(PKCS7 *, STACK_OF(X509) *, int) = 0L;
static PKCS7 *(*K_PKCS7_encrypt)(STACK_OF(X509) *, BIO *, EVP_CIPHER *, int) = 0L;
static int (*K_PKCS7_decrypt)(PKCS7 *, EVP_PKEY *, X509 *, BIO *, int) = 0L;
static SSL_SESSION *(*K_SSL_get1_session)(SSL *) = 0L;
static void (*K_SSL_SESSION_free)(SSL_SESSION *) = 0L;
static int (*K_SSL_set_session)(SSL *, SSL_SESSION *) = 0L;
static SSL_SESSION *(*K_d2i_SSL_SESSION)(SSL_SESSION **, unsigned char **, long) = 0L;
static int (*K_i2d_SSL_SESSION)(SSL_SESSION *, unsigned char **) = 0L;
static STACK *(*K_X509_get1_email)(X509 *x) = 0L;
static void (*K_X509_email_free)(STACK *sk) = 0L;
static EVP_CIPHER *(*K_EVP_des_ede3_cbc)() = 0L;
static EVP_CIPHER *(*K_EVP_des_cbc)() = 0L;
static EVP_CIPHER *(*K_EVP_rc2_cbc)() = 0L;
static EVP_CIPHER *(*K_EVP_rc2_64_cbc)() = 0L;
static EVP_CIPHER *(*K_EVP_rc2_40_cbc)() = 0L;
static int (*K_i2d_PrivateKey_fp)(FILE *, EVP_PKEY *) = 0L;
static int (*K_i2d_PKCS8PrivateKey_fp)(FILE *, EVP_PKEY *, const EVP_CIPHER *, char *, int, pem_password_cb *, void *) = 0L;
static void (*K_RSA_free)(RSA *) = 0L;
static EVP_CIPHER *(*K_EVP_bf_cbc)() = 0L;
static int (*K_X509_REQ_sign)(X509_REQ *, EVP_PKEY *, const EVP_MD *) = 0L;
static int (*K_X509_NAME_add_entry_by_txt)(X509_NAME *, char *, int, unsigned char *, int, int, int) = 0L;
static X509_NAME *(*K_X509_NAME_new)() = 0L;
static int (*K_X509_REQ_set_subject_name)(X509_REQ *, X509_NAME *) = 0L;
static unsigned char *(*K_ASN1_STRING_data)(ASN1_STRING *) = 0L;
static int (*K_ASN1_STRING_length)(ASN1_STRING *) = 0L;
static STACK_OF(SSL_CIPHER) * (*K_SSL_get_ciphers)(const SSL *ssl) = 0L;
static const ASN1_TIME *(*K_X509_CRL_get0_lastUpdate)(const X509_CRL *crl) = 0L;
static const ASN1_TIME *(*K_X509_CRL_get0_nextUpdate)(const X509_CRL *crl) = 0L;
static X509 *(*K_X509_STORE_CTX_get_current_cert)(X509_STORE_CTX *ctx) = 0L;
static int (*K_X509_STORE_CTX_get_error)(X509_STORE_CTX *ctx) = 0L;
static int (*K_X509_STORE_CTX_get_error_depth)(X509_STORE_CTX *ctx) = 0L;
static void (*K_X509_STORE_CTX_set_error)(X509_STORE_CTX *ctx, int s) = 0L;
static void (*K_X509_STORE_set_verify_cb)(X509_STORE *ctx, X509_STORE_CTX_verify_cb verify_cb) = 0L;
static STACK_OF(X509_OBJECT) * (*K_X509_STORE_get0_objects)(X509_STORE *v) = 0L;
static X509_LOOKUP_TYPE (*K_X509_OBJECT_get_type)(const X509_OBJECT *a) = 0L;
static X509 *(*K_X509_OBJECT_get0_X509)(const X509_OBJECT *a) = 0L;
static ASN1_TIME *(*K_X509_getm_notAfter)(const X509 *x) = 0L;
static ASN1_TIME *(*K_X509_getm_notBefore)(const X509 *x) = 0L;
#endif
}


bool KOpenSSLProxy::hasLibSSL() const
{
    return _sslLib != 0L;
}


bool KOpenSSLProxy::hasLibCrypto() const
{
    return _cryptoLib != 0L;
}


void KOpenSSLProxy::destroy()
{
    delete this;
    _me = 0L;
}

#ifdef __OpenBSD__
#include <qdir.h>
#include <qstring.h>
#include <qstringlist.h>

static QString findMostRecentLib(QString dir, QString name)
{
    // Grab all shared libraries in the directory
    QString filter = "lib" + name + ".so.*";
    QDir d(dir, filter);
    if(!d.exists())
        return 0L;
    QStringList l = d.entryList();

    // Find the best one
    int bestmaj = -1;
    int bestmin = -1;
    QString best = 0L;
    // where do we start
    uint s = filter.length() - 1;
    for(QStringList::Iterator it = l.begin(); it != l.end(); ++it)
    {
        QString numberpart = (*it).mid(s);
        uint endmaj = numberpart.find('.');
        if(endmaj == -1)
            continue;
        bool ok;
        int maj = numberpart.left(endmaj).toInt(&ok);
        if(!ok)
            continue;
        int min = numberpart.mid(endmaj + 1).toInt(&ok);
        if(!ok)
            continue;
        if(maj > bestmaj || (maj == bestmaj && min > bestmin))
        {
            bestmaj = maj;
            bestmin = min;
            best = (*it);
        }
    }
    if(best.isNull())
        return 0L;
    else
        return dir + "/" + best;
}
#endif


KOpenSSLProxy::KOpenSSLProxy()
{
    KLibLoader *ll = KLibLoader::self();
    _ok = false;
    QStringList libpaths, libnamesc, libnamess;
    KConfig *cfg;

    _cryptoLib = 0L;
    _sslLib = 0L;

    cfg = new KConfig("cryptodefaults", false, false);
    cfg->setGroup("OpenSSL");
    QString upath = cfg->readPathEntry("Path");
    if(!upath.isEmpty())
        libpaths << upath;

    delete cfg;

#ifdef __OpenBSD__
    {
        QString libname = findMostRecentLib("/usr/lib" KDELIBSUFF, "crypto");
        if(!libname.isNull())
            _cryptoLib = ll->globalLibrary(libname.latin1());
    }
#elif defined(__CYGWIN__)
    libpaths << "/usr/bin/"
             << "/usr/local/bin"
             << "/usr/local/openssl/bin"
             << "/opt/openssl/bin"
             << "/opt/kde3/bin"
             << "";

    libnamess << "cygssl-0.9.7.dll"
              << "cygssl.dll"
              << "libssl.dll"
              << "";

    libnamesc << "cygcrypto.dll"
              << "libcrypto.dll"
              << "";
#else
    libpaths
#ifdef _AIX
        << "/opt/freeware/lib/"
#endif
        << "/usr/lib" KDELIBSUFF "/"
        << "/usr/ssl/lib" KDELIBSUFF "/"
        << "/usr/local/lib" KDELIBSUFF "/"
        << "/usr/local/openssl/lib" KDELIBSUFF "/"
        << "/usr/local/ssl/lib" KDELIBSUFF "/"
        << "/opt/openssl/lib" KDELIBSUFF "/"
        << "/lib" KDELIBSUFF "/"
        << "";

    // FIXME: #define here for the various OS types to optimize
    libnamess
#ifdef hpux
        << "libssl.sl"
#elif defined(_AIX)
        << "libssl.a(libssl.so.0)"
#elif defined(__APPLE__)
        << "libssl.dylib"
        << "libssl.0.9.dylib"
#else
#ifdef SHLIB_VERSION_NUMBER
        << "libssl.so." SHLIB_VERSION_NUMBER
#endif
        << "libssl.so"
        << "libssl.so.0"
#endif
        ;

    libnamesc
#ifdef hpux
        << "libcrypto.sl"
#elif defined(_AIX)
        << "libcrypto.a(libcrypto.so.0)"
#elif defined(__APPLE__)
        << "libcrypto.dylib"
        << "libcrypto.0.9.dylib"
#else
#ifdef SHLIB_VERSION_NUMBER
        << "libcrypto.so." SHLIB_VERSION_NUMBER
#endif
        << "libcrypto.so"
        << "libcrypto.so.0"
#endif
        ;
#endif

    for(QStringList::Iterator it = libpaths.begin(); it != libpaths.end(); ++it)
    {
        for(QStringList::Iterator shit = libnamesc.begin(); shit != libnamesc.end(); ++shit)
        {
            QString alib = *it;
            if(!alib.isEmpty() && !alib.endsWith("/"))
                alib += "/";
            alib += *shit;
            QString tmpStr(alib.latin1());
            tmpStr.replace(QRegExp("\\(.*\\)"), "");
            if(!access(tmpStr.latin1(), R_OK))
                _cryptoLib = ll->globalLibrary(alib.latin1());
            if(!_cryptoLib)
            {
                // Multiarch triplet search
                QDir madir(*it);
                QStringList multiarchdirs = madir.entryList("*-*-*", QDir::Dirs);
                for(QStringList::Iterator mait = multiarchdirs.begin(); mait != multiarchdirs.end(); ++mait)
                {
                    QString malib = *it + *mait + "/" + *shit;
                    QString tmpStr(malib.latin1());
                    tmpStr.replace(QRegExp("\\(.*\\)"), "");
                    if(!access(tmpStr.latin1(), R_OK))
                        _cryptoLib = ll->globalLibrary(malib.latin1());
                }
            }
            if(_cryptoLib)
                break;
        }
        if(_cryptoLib)
            break;
    }

    if(_cryptoLib)
    {
#ifdef KSSL_HAVE_SSL
        K_X509_free = (void (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_free");
        K_X509_CRL_free = (void (*)(X509_CRL *))GET_CRYPTOLIB_SYMBOL("X509_CRL_free");
        K_RAND_egd = (int (*)(const char *))GET_CRYPTOLIB_SYMBOL("RAND_egd");
        K_RAND_load_file = (int (*)(const char *, long))GET_CRYPTOLIB_SYMBOL("RAND_load_file");
        K_RAND_file_name = (const char *(*)(char *, size_t))GET_CRYPTOLIB_SYMBOL("RAND_file_name");
        K_RAND_write_file = (int (*)(const char *))GET_CRYPTOLIB_SYMBOL("RAND_write_file");
        K_CRYPTO_free = (void (*)(void *))GET_CRYPTOLIB_SYMBOL("CRYPTO_free");
        K_d2i_X509 = (X509 * (*)(X509 **, unsigned char **, long))GET_CRYPTOLIB_SYMBOL("d2i_X509");
        K_d2i_X509_CRL = (X509_CRL * (*)(X509_CRL **, unsigned char **, long))GET_CRYPTOLIB_SYMBOL("d2i_X509_CRL");
        K_i2d_X509 = (int (*)(X509 *, unsigned char **))GET_CRYPTOLIB_SYMBOL("i2d_X509");
        K_X509_cmp = (int (*)(X509 *, X509 *))GET_CRYPTOLIB_SYMBOL("X509_cmp");
        K_X509_subject_name_cmp = (int (*)(const X509 *, const X509 *))GET_CRYPTOLIB_SYMBOL("X509_subject_name_cmp");
        K_X509_STORE_CTX_new = (X509_STORE_CTX * (*)(void))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_new");
        K_X509_STORE_CTX_free = (void (*)(X509_STORE_CTX *))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_free");
        K_X509_verify_cert = (int (*)(X509_STORE_CTX *))GET_CRYPTOLIB_SYMBOL("X509_verify_cert");
        K_X509_STORE_new = (X509_STORE * (*)(void))GET_CRYPTOLIB_SYMBOL("X509_STORE_new");
        K_X509_STORE_free = (void (*)(X509_STORE *))GET_CRYPTOLIB_SYMBOL("X509_STORE_free");
        K_X509_NAME_oneline = (char *(*)(X509_NAME *, char *, int))GET_CRYPTOLIB_SYMBOL("X509_NAME_oneline");
        K_X509_get_subject_name = (X509_NAME * (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_get_subject_name");
        K_X509_get_issuer_name = (X509_NAME * (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_get_issuer_name");
        K_X509_STORE_add_lookup = (X509_LOOKUP * (*)(X509_STORE *, X509_LOOKUP_METHOD *))GET_CRYPTOLIB_SYMBOL("X509_STORE_add_lookup");
        K_X509_LOOKUP_file = (X509_LOOKUP_METHOD * (*)(void))GET_CRYPTOLIB_SYMBOL("X509_LOOKUP_file");
        K_X509_LOOKUP_free = (void (*)(X509_LOOKUP *))GET_CRYPTOLIB_SYMBOL("X509_LOOKUP_free");
        K_X509_LOOKUP_ctrl = (int (*)(X509_LOOKUP *, int, const char *, long, char **))GET_CRYPTOLIB_SYMBOL("X509_LOOKUP_ctrl");
        K_X509_STORE_CTX_init = (void (*)(X509_STORE_CTX *, X509_STORE *, X509 *, STACK_OF(X509) *))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_init");
        K_X509_dup = (X509 * (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_dup");
        K_X509_get0_signature =
            (void (*)(const ASN1_BIT_STRING **psig, const X509_ALGOR **palg, const X509 *x))GET_CRYPTOLIB_SYMBOL("X509_get0_signature");
        K_BIO_s_mem = (BIO_METHOD * (*)(void))GET_CRYPTOLIB_SYMBOL("BIO_s_mem");
        K_BIO_new = (BIO * (*)(BIO_METHOD *))GET_CRYPTOLIB_SYMBOL("BIO_new");
        K_BIO_new_fp = (BIO * (*)(FILE *, int))GET_CRYPTOLIB_SYMBOL("BIO_new_fp");
        K_BIO_new_mem_buf = (BIO * (*)(void *, int))GET_CRYPTOLIB_SYMBOL("BIO_new_mem_buf");
        K_BIO_free = (int (*)(BIO *))GET_CRYPTOLIB_SYMBOL("BIO_free");
        K_BIO_ctrl = (long (*)(BIO *, int, long, void *))GET_CRYPTOLIB_SYMBOL("BIO_ctrl");
        K_BIO_write = (int (*)(BIO * b, const void *data, int len))GET_CRYPTOLIB_SYMBOL("BIO_write");
        K_BIO_get_data = (void *(*)(BIO * a))GET_CRYPTOLIB_SYMBOL("BIO_get_data");
        K_PEM_ASN1_write_bio = (int (*)(int (*)(), const char *, BIO *, char *, const EVP_CIPHER *, unsigned char *, int, pem_password_cb *,
                                        void *))GET_CRYPTOLIB_SYMBOL("PEM_ASN1_write_bio");
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
        K_ASN1_item_i2d_fp = (int (*)(ASN1_ITEM *, FILE *, unsigned char *))GET_CRYPTOLIB_SYMBOL("ASN1_item_i2d_fp");
        K_NETSCAPE_X509_it = (ASN1_ITEM *)GET_CRYPTOLIB_SYMBOL("NETSCAPE_X509_it");
#else
        K_X509_asn1_meth = (ASN1_METHOD * (*)(void))GET_CRYPTOLIB_SYMBOL("X509_asn1_meth");
        K_ASN1_i2d_fp = (int (*)(int (*)(), FILE *, unsigned char *))GET_CRYPTOLIB_SYMBOL("ASN1_i2d_fp");
        K_i2d_ASN1_HEADER = (int (*)(ASN1_HEADER *, unsigned char **))GET_CRYPTOLIB_SYMBOL("i2d_ASN1_HEADER");
#endif
        K_X509_print_fp = (int (*)(FILE *, X509 *))GET_CRYPTOLIB_SYMBOL("X509_print_fp");
        K_i2d_PKCS12 = (int (*)(PKCS12 *, unsigned char **))GET_CRYPTOLIB_SYMBOL("i2d_PKCS12");
        K_i2d_PKCS12_fp = (int (*)(FILE *, PKCS12 *))GET_CRYPTOLIB_SYMBOL("i2d_PKCS12_fp");
        K_PKCS12_newpass = (int (*)(PKCS12 *, char *, char *))GET_CRYPTOLIB_SYMBOL("PKCS12_newpass");
        K_d2i_PKCS12_fp = (PKCS12 * (*)(FILE *, PKCS12 **))GET_CRYPTOLIB_SYMBOL("d2i_PKCS12_fp");
        K_PKCS12_new = (PKCS12 * (*)())GET_CRYPTOLIB_SYMBOL("PKCS12_new");
        K_PKCS12_free = (void (*)(PKCS12 *))GET_CRYPTOLIB_SYMBOL("PKCS12_free");
        K_PKCS12_parse = (int (*)(PKCS12 *, const char *, EVP_PKEY **, X509 **, STACK_OF(X509) **))GET_CRYPTOLIB_SYMBOL("PKCS12_parse");
        K_EVP_PKEY_free = (void (*)(EVP_PKEY *))GET_CRYPTOLIB_SYMBOL("EVP_PKEY_free");
        K_EVP_PKEY_new = (EVP_PKEY * (*)())GET_CRYPTOLIB_SYMBOL("EVP_PKEY_new");
        K_EVP_PKEY_base_id = (int (*)(const EVP_PKEY *pkey))GET_CRYPTOLIB_SYMBOL("EVP_PKEY_base_id");
        K_EVP_PKEY_get0_RSA = (RSA * (*)(EVP_PKEY * pkey))GET_CRYPTOLIB_SYMBOL("EVP_PKEY_get0_RSA");
        K_EVP_PKEY_get0_DSA = (DSA * (*)(EVP_PKEY * pkey))GET_CRYPTOLIB_SYMBOL("EVP_PKEY_get0_DSA");
        K_X509_REQ_free = (void (*)(X509_REQ *))GET_CRYPTOLIB_SYMBOL("X509_REQ_free");
        K_X509_REQ_new = (X509_REQ * (*)())GET_CRYPTOLIB_SYMBOL("X509_REQ_new");
        K_X509_STORE_CTX_set0_untrusted = (void (*)(X509_STORE_CTX *, STACK_OF(X509) *))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_set0_untrusted");
        if(!K_X509_STORE_CTX_set0_untrusted)
            K_X509_STORE_CTX_set0_untrusted = (void (*)(X509_STORE_CTX *, STACK_OF(X509) *))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_set_chain");
        K_X509_STORE_CTX_set_purpose = (void (*)(X509_STORE_CTX *, int))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_set_purpose");
        K_sk_free = (void (*)(STACK *))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_free");
        if(!K_sk_free)
            K_sk_free = (void (*)(STACK *))GET_CRYPTOLIB_SYMBOL("sk_free");
        K_sk_num = (int (*)(STACK *))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_num");
        if(!K_sk_num)
            K_sk_num = (int (*)(STACK *))GET_CRYPTOLIB_SYMBOL("sk_num");
        K_sk_pop = (char *(*)(STACK *))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_pop");
        if(!K_sk_pop)
            K_sk_pop = (char *(*)(STACK *))GET_CRYPTOLIB_SYMBOL("sk_pop");
        K_sk_value = (char *(*)(STACK *, int))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_value");
        if(!K_sk_value)
            K_sk_value = (char *(*)(STACK *, int))GET_CRYPTOLIB_SYMBOL("sk_value");
        K_sk_new = (STACK * (*)(int (*)()))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_new");
        if(!K_sk_new)
            K_sk_new = (STACK * (*)(int (*)()))GET_CRYPTOLIB_SYMBOL("sk_new");
        K_sk_push = (int (*)(STACK *, char *))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_push");
        if(!K_sk_push)
            K_sk_push = (int (*)(STACK *, char *))GET_CRYPTOLIB_SYMBOL("sk_push");
        K_sk_dup = (STACK * (*)(const STACK *))GET_CRYPTOLIB_SYMBOL("OPENSSL_sk_dup");
        if(!K_sk_dup)
            K_sk_dup = (STACK * (*)(const STACK *))GET_CRYPTOLIB_SYMBOL("sk_dup");
        K_i2s_ASN1_INTEGER = (char *(*)(X509V3_EXT_METHOD *, ASN1_INTEGER *))GET_CRYPTOLIB_SYMBOL("i2s_ASN1_INTEGER");
        K_X509_get_serialNumber = (ASN1_INTEGER * (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_get_serialNumber");
        K_X509_get_pubkey = (EVP_PKEY * (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_get_pubkey");
        K_i2d_PublicKey = (int (*)(EVP_PKEY *, unsigned char **))GET_CRYPTOLIB_SYMBOL("i2d_PublicKey");
        K_X509_check_private_key = (int (*)(X509 *, EVP_PKEY *))GET_CRYPTOLIB_SYMBOL("X509_check_private_key");
        K_BN_bn2hex = (char *(*)(const BIGNUM *))GET_CRYPTOLIB_SYMBOL("BN_bn2hex");
        K_X509_digest = (int (*)(const X509 *, const EVP_MD *, unsigned char *, unsigned int *))GET_CRYPTOLIB_SYMBOL("X509_digest");
        K_EVP_md5 = (EVP_MD * (*)())GET_CRYPTOLIB_SYMBOL("EVP_md5");
        K_ASN1_INTEGER_free = (void (*)(ASN1_INTEGER *))GET_CRYPTOLIB_SYMBOL("ASN1_INTEGER_free");
        K_OBJ_obj2nid = (int (*)(ASN1_OBJECT *))GET_CRYPTOLIB_SYMBOL("OBJ_obj2nid");
        K_OBJ_nid2ln = (const char *(*)(int))GET_CRYPTOLIB_SYMBOL("OBJ_nid2ln");
        K_X509_get_ext_count = (int (*)(X509 *))GET_CRYPTOLIB_SYMBOL("X509_get_ext_count");
        K_X509_get_ext_by_NID = (int (*)(X509 *, int, int))GET_CRYPTOLIB_SYMBOL("X509_get_ext_by_NID");
        K_X509_get_ext_by_OBJ = (int (*)(X509 *, ASN1_OBJECT *, int))GET_CRYPTOLIB_SYMBOL("X509_get_ext_by_OBJ");
        K_X509_get_ext = (X509_EXTENSION * (*)(X509 *, int))GET_CRYPTOLIB_SYMBOL("X509_get_ext");
        K_X509_delete_ext = (X509_EXTENSION * (*)(X509 *, int))GET_CRYPTOLIB_SYMBOL("X509_delete_ext");
        K_X509_add_ext = (int (*)(X509 *, X509_EXTENSION *, int))GET_CRYPTOLIB_SYMBOL("X509_add_ext");
        K_X509_get_ext_d2i = (void *(*)(X509 *, int, int *, int *))GET_CRYPTOLIB_SYMBOL("X509_get_ext_d2i");
        K_i2s_ASN1_OCTET_STRING = (char *(*)(X509V3_EXT_METHOD *, ASN1_OCTET_STRING *))GET_CRYPTOLIB_SYMBOL("i2s_ASN1_OCTET_STRING");
        K_ASN1_BIT_STRING_get_bit = (int (*)(ASN1_BIT_STRING *, int))GET_CRYPTOLIB_SYMBOL("ASN1_BIT_STRING_get_bit");
        K_PKCS7_new = (PKCS7 * (*)())GET_CRYPTOLIB_SYMBOL("PKCS7_new");
        K_PKCS7_free = (void (*)(PKCS7 *))GET_CRYPTOLIB_SYMBOL("PKCS7_free");
        K_PKCS7_content_free = (void (*)(PKCS7 *))GET_CRYPTOLIB_SYMBOL("PKCS7_content_free");
        K_i2d_PKCS7 = (int (*)(PKCS7 *, unsigned char **))GET_CRYPTOLIB_SYMBOL("i2d_PKCS7");
        K_i2d_PKCS7_fp = (int (*)(FILE *, PKCS7 *))GET_CRYPTOLIB_SYMBOL("i2d_PKCS7_fp");
        K_i2d_PKCS7_bio = (int (*)(BIO * bp, PKCS7 * p7))GET_CRYPTOLIB_SYMBOL("i2d_PKCS7_bio");
        K_d2i_PKCS7 = (PKCS7 * (*)(PKCS7 **, unsigned char **, long))GET_CRYPTOLIB_SYMBOL("d2i_PKCS7");
        K_d2i_PKCS7_fp = (PKCS7 * (*)(FILE *, PKCS7 **))GET_CRYPTOLIB_SYMBOL("d2i_PKCS7_fp");
        K_d2i_PKCS7_bio = (PKCS7 * (*)(BIO * bp, PKCS7 * *p7))GET_CRYPTOLIB_SYMBOL("d2i_PKCS7_bio");
        K_PKCS7_dup = (PKCS7 * (*)(PKCS7 *))GET_CRYPTOLIB_SYMBOL("PKCS7_dup");
        K_PKCS7_sign = (PKCS7 * (*)(X509 *, EVP_PKEY *, STACK_OF(X509) *, BIO *, int))GET_CRYPTOLIB_SYMBOL("PKCS7_sign");
        K_PKCS7_verify = (int (*)(PKCS7 *, STACK_OF(X509) *, X509_STORE *, BIO *, BIO *, int))GET_CRYPTOLIB_SYMBOL("PKCS7_verify");
        K_PKCS7_get0_signers = (STACK_OF(X509) * (*)(PKCS7 *, STACK_OF(X509) *, int))GET_CRYPTOLIB_SYMBOL("PKCS7_get0_signers");
        K_PKCS7_encrypt = (PKCS7 * (*)(STACK_OF(X509) *, BIO *, EVP_CIPHER *, int))GET_CRYPTOLIB_SYMBOL("PKCS7_encrypt");
        K_PKCS7_decrypt = (int (*)(PKCS7 *, EVP_PKEY *, X509 *, BIO *, int))GET_CRYPTOLIB_SYMBOL("PKCS7_decrypt");
        K_PEM_X509_INFO_read =
            (STACK_OF(X509_INFO) * (*)(FILE *, STACK_OF(X509_INFO) *, pem_password_cb *, void *))GET_CRYPTOLIB_SYMBOL("PEM_X509_INFO_read");
        K_ASN1_d2i_fp = (char *(*)(char *(*)(), char *(*)(), FILE *, unsigned char **))GET_CRYPTOLIB_SYMBOL("ASN1_d2i_fp");
        K_X509_new = (X509 * (*)())GET_CRYPTOLIB_SYMBOL("X509_new");
        K_X509_PURPOSE_get_count = (int (*)())GET_CRYPTOLIB_SYMBOL("X509_PURPOSE_get_count");
        K_X509_PURPOSE_get_id = (int (*)(X509_PURPOSE *))GET_CRYPTOLIB_SYMBOL("X509_PURPOSE_get_id");
        K_X509_check_purpose = (int (*)(X509 *, int, int))GET_CRYPTOLIB_SYMBOL("X509_check_purpose");
        K_X509_PURPOSE_get0 = (X509_PURPOSE * (*)(int))GET_CRYPTOLIB_SYMBOL("X509_PURPOSE_get0");
        K_EVP_PKEY_assign = (int (*)(EVP_PKEY *, int, char *))GET_CRYPTOLIB_SYMBOL("EVP_PKEY_assign");
        K_X509_REQ_set_pubkey = (int (*)(X509_REQ *, EVP_PKEY *))GET_CRYPTOLIB_SYMBOL("X509_REQ_set_pubkey");
        K_RSA_get0_key = (void (*)(const RSA *r, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d))GET_CRYPTOLIB_SYMBOL("RSA_get0_key");
        K_RSA_generate_key = (RSA * (*)(int, unsigned long, void (*)(int, int, void *), void *))GET_CRYPTOLIB_SYMBOL("RSA_generate_key");
        K_DSA_get0_pqg = (void (*)(const DSA *d, const BIGNUM **p, const BIGNUM **q, const BIGNUM **g))GET_CRYPTOLIB_SYMBOL("DSA_get0_pqg");
        K_DSA_get0_key = (void (*)(const DSA *d, const BIGNUM **pub_key, const BIGNUM **priv_key))GET_CRYPTOLIB_SYMBOL("DSA_get0_key");
        K_i2d_X509_REQ_fp = (int (*)(FILE *, X509_REQ *))GET_CRYPTOLIB_SYMBOL("i2d_X509_REQ_fp");
        K_ERR_clear_error = (void (*)())GET_CRYPTOLIB_SYMBOL("ERR_clear_error");
        K_ERR_get_error = (unsigned long (*)())GET_CRYPTOLIB_SYMBOL("ERR_get_error");
        K_ERR_print_errors_fp = (void (*)(FILE *))GET_CRYPTOLIB_SYMBOL("ERR_print_errors_fp");
        K_X509_get1_email = (STACK * (*)(X509 * x))GET_CRYPTOLIB_SYMBOL("X509_get1_email");
        K_X509_email_free = (void (*)(STACK * sk))GET_CRYPTOLIB_SYMBOL("X509_email_free");
        K_EVP_des_ede3_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_des_ede3_cbc");
        K_EVP_des_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_des_cbc");
        K_EVP_rc2_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_rc2_cbc");
        K_EVP_rc2_64_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_rc2_64_cbc");
        K_EVP_rc2_40_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_rc2_40_cbc");
        K_i2d_PrivateKey_fp = (int (*)(FILE *, EVP_PKEY *))GET_CRYPTOLIB_SYMBOL("i2d_PrivateKey_fp");
        K_i2d_PKCS8PrivateKey_fp =
            (int (*)(FILE *, EVP_PKEY *, const EVP_CIPHER *, char *, int, pem_password_cb *, void *))GET_CRYPTOLIB_SYMBOL("i2d_PKCS8PrivateKey_fp");
        K_RSA_free = (void (*)(RSA *))GET_CRYPTOLIB_SYMBOL("RSA_free");
        K_EVP_bf_cbc = (EVP_CIPHER * (*)())GET_CRYPTOLIB_SYMBOL("EVP_bf_cbc");
        K_X509_REQ_sign = (int (*)(X509_REQ *, EVP_PKEY *, const EVP_MD *))GET_CRYPTOLIB_SYMBOL("X509_REQ_sign");
        K_X509_NAME_add_entry_by_txt =
            (int (*)(X509_NAME *, char *, int, unsigned char *, int, int, int))GET_CRYPTOLIB_SYMBOL("X509_NAME_add_entry_by_txt");
        K_X509_NAME_new = (X509_NAME * (*)())GET_CRYPTOLIB_SYMBOL("X509_NAME_new");
        K_X509_REQ_set_subject_name = (int (*)(X509_REQ *, X509_NAME *))GET_CRYPTOLIB_SYMBOL("X509_REQ_set_subject_name");
        K_ASN1_STRING_data = (unsigned char *(*)(ASN1_STRING *))GET_CRYPTOLIB_SYMBOL("ASN1_STRING_data");
        K_ASN1_STRING_length = (int (*)(ASN1_STRING *))GET_CRYPTOLIB_SYMBOL("ASN1_STRING_length");
        K_X509_CRL_get0_lastUpdate = (const ASN1_TIME *(*)(const X509_CRL *crl))GET_CRYPTOLIB_SYMBOL("X509_CRL_get0_lastUpdate");
        K_X509_CRL_get0_nextUpdate = (const ASN1_TIME *(*)(const X509_CRL *crl))GET_CRYPTOLIB_SYMBOL("X509_CRL_get0_nextUpdate");
        K_X509_STORE_CTX_get_current_cert = (X509 * (*)(X509_STORE_CTX * ctx))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_get_current_cert");
        K_X509_STORE_CTX_get_error = (int (*)(X509_STORE_CTX * ctx))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_get_error");
        K_X509_STORE_CTX_get_error_depth = (int (*)(X509_STORE_CTX * ctx))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_get_error_depth");
        K_X509_STORE_CTX_set_error = (void (*)(X509_STORE_CTX * ctx, int s))GET_CRYPTOLIB_SYMBOL("X509_STORE_CTX_set_error");
        K_X509_STORE_set_verify_cb = (void (*)(X509_STORE * ctx, X509_STORE_CTX_verify_cb verify_cb))GET_CRYPTOLIB_SYMBOL("X509_STORE_set_verify_cb");
        K_X509_STORE_get0_objects = (STACK_OF(X509_OBJECT) * (*)(X509_STORE * v))GET_CRYPTOLIB_SYMBOL("X509_STORE_get0_objects");
        K_X509_OBJECT_get_type = (X509_LOOKUP_TYPE(*)(const X509_OBJECT *a))GET_CRYPTOLIB_SYMBOL("X509_OBJECT_get_type");
        K_X509_OBJECT_get0_X509 = (X509 * (*)(const X509_OBJECT *a))GET_CRYPTOLIB_SYMBOL("X509_OBJECT_get0_X509");
        K_X509_getm_notAfter = (ASN1_TIME * (*)(const X509 *x))GET_CRYPTOLIB_SYMBOL("X509_getm_notAfter");
        K_X509_getm_notBefore = (ASN1_TIME * (*)(const X509 *x))GET_CRYPTOLIB_SYMBOL("X509_getm_notBefore");
#endif
    }

#ifdef __OpenBSD__
    {
        QString libname = findMostRecentLib("/usr/lib", "ssl");
        if(!libname.isNull())
            _sslLib = ll->globalLibrary(libname.latin1());
    }
#else
    for(QStringList::Iterator it = libpaths.begin(); it != libpaths.end(); ++it)
    {
        for(QStringList::Iterator shit = libnamess.begin(); shit != libnamess.end(); ++shit)
        {
            QString alib = *it;
            if(!alib.isEmpty() && !alib.endsWith("/"))
                alib += "/";
            alib += *shit;
            QString tmpStr(alib.latin1());
            tmpStr.replace(QRegExp("\\(.*\\)"), "");
            if(!access(tmpStr.latin1(), R_OK))
                _sslLib = ll->globalLibrary(alib.latin1());
            if(!_sslLib)
            {
                // Multiarch triplet search
                QDir madir(*it);
                QStringList multiarchdirs = madir.entryList("*-*-*", QDir::Dirs);
                for(QStringList::Iterator mait = multiarchdirs.begin(); mait != multiarchdirs.end(); ++mait)
                {
                    QString malib = *it + *mait + "/" + *shit;
                    QString tmpStr(malib.latin1());
                    tmpStr.replace(QRegExp("\\(.*\\)"), "");
                    if(!access(tmpStr.latin1(), R_OK))
                        _sslLib = ll->globalLibrary(malib.latin1());
                }
            }
            if(_sslLib)
                break;
        }
        if(_sslLib)
            break;
    }
#endif

    if(_sslLib)
    {
#ifdef KSSL_HAVE_SSL
        // stand back from your monitor and look at this.  it's fun! :)
        K_SSL_connect = (int (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_connect");
        K_SSL_accept = (int (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_accept");
        K_SSL_read = (int (*)(SSL *, void *, int))GET_SSLLIB_SYMBOL("SSL_read");
        K_SSL_write = (int (*)(SSL *, const void *, int))GET_SSLLIB_SYMBOL("SSL_write");
        K_SSL_new = (SSL * (*)(SSL_CTX *))GET_SSLLIB_SYMBOL("SSL_new");
        K_SSL_free = (void (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_free");
        K_SSL_shutdown = (int (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_shutdown");
        K_SSL_CTX_new = (SSL_CTX * (*)(SSL_METHOD *))GET_SSLLIB_SYMBOL("SSL_CTX_new");
        K_SSL_CTX_free = (void (*)(SSL_CTX *))GET_SSLLIB_SYMBOL("SSL_CTX_free");
        K_SSL_set_fd = (int (*)(SSL *, int))GET_SSLLIB_SYMBOL("SSL_set_fd");
        K_SSL_pending = (int (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_pending");
        K_SSL_CTX_set_cipher_list = (int (*)(SSL_CTX *, const char *))GET_SSLLIB_SYMBOL("SSL_CTX_set_cipher_list");
        K_SSL_CTX_set_verify = (void (*)(SSL_CTX *, int, int (*)(int, X509_STORE_CTX *)))GET_SSLLIB_SYMBOL("SSL_CTX_set_verify");
        K_SSL_use_certificate = (int (*)(SSL *, X509 *))GET_SSLLIB_SYMBOL("SSL_CTX_use_certificate");
        K_SSL_get_current_cipher = (SSL_CIPHER * (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_get_current_cipher");
        K_SSL_set_options = (long (*)(SSL * ssl, long options))GET_SSLLIB_SYMBOL("SSL_set_options");
        K_SSL_session_reused = (int (*)(SSL * ssl))GET_SSLLIB_SYMBOL("SSL_session_reused");
        K_SSL_ctrl = (long (*)(SSL *, int, long, void *))GET_SSLLIB_SYMBOL("SSL_ctrl");
        K_TLSv1_client_method = (SSL_METHOD * (*)())GET_SSLLIB_SYMBOL("TLSv1_client_method");
        K_SSLv2_client_method = (SSL_METHOD * (*)())GET_SSLLIB_SYMBOL("SSLv2_client_method");
        K_SSLv3_client_method = (SSL_METHOD * (*)())GET_SSLLIB_SYMBOL("SSLv3_client_method");
        K_TLS_client_method = (SSL_METHOD * (*)())GET_SSLLIB_SYMBOL("TLS_client_method");
        if(!K_TLS_client_method)
            K_TLS_client_method = (SSL_METHOD * (*)())GET_SSLLIB_SYMBOL("SSLv23_client_method");
        K_SSL_get_peer_certificate = (X509 * (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_get_peer_certificate");
        K_SSL_CIPHER_get_bits = (int (*)(SSL_CIPHER *, int *))GET_SSLLIB_SYMBOL("SSL_CIPHER_get_bits");
        K_SSL_CIPHER_get_version = (char *(*)(SSL_CIPHER *))GET_SSLLIB_SYMBOL("SSL_CIPHER_get_version");
        K_SSL_CIPHER_get_name = (const char *(*)(SSL_CIPHER *))GET_SSLLIB_SYMBOL("SSL_CIPHER_get_name");
        K_SSL_CIPHER_description = (char *(*)(SSL_CIPHER *, char *, int))GET_SSLLIB_SYMBOL("SSL_CIPHER_description");
        K_SSL_CTX_use_PrivateKey = (int (*)(SSL_CTX *, EVP_PKEY *))GET_SSLLIB_SYMBOL("SSL_CTX_use_PrivateKey");
        K_SSL_CTX_use_certificate = (int (*)(SSL_CTX *, X509 *))GET_SSLLIB_SYMBOL("SSL_CTX_use_certificate");
        K_SSL_get_error = (int (*)(SSL *, int))GET_SSLLIB_SYMBOL("SSL_get_error");
        K_SSL_get_peer_cert_chain = (STACK_OF(X509) * (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_get_peer_cert_chain");
        K_SSL_load_client_CA_file = (STACK_OF(X509_NAME) * (*)(const char *))GET_SSLLIB_SYMBOL("SSL_load_client_CA_file");
        K_SSL_peek = (int (*)(SSL *, void *, int))GET_SSLLIB_SYMBOL("SSL_peek");
        K_SSL_get1_session = (SSL_SESSION * (*)(SSL *))GET_SSLLIB_SYMBOL("SSL_get1_session");
        K_SSL_SESSION_free = (void (*)(SSL_SESSION *))GET_SSLLIB_SYMBOL("SSL_SESSION_free");
        K_SSL_set_session = (int (*)(SSL *, SSL_SESSION *))GET_SSLLIB_SYMBOL("SSL_set_session");
        K_d2i_SSL_SESSION = (SSL_SESSION * (*)(SSL_SESSION **, unsigned char **, long))GET_SSLLIB_SYMBOL("d2i_SSL_SESSION");
        K_i2d_SSL_SESSION = (int (*)(SSL_SESSION *, unsigned char **))GET_SSLLIB_SYMBOL("i2d_SSL_SESSION");
        K_SSL_get_ciphers = (STACK_OF(SSL_CIPHER) * (*)(const SSL *))GET_SSLLIB_SYMBOL("SSL_get_ciphers");
#endif


        // Initialize the library (once only!)
        void *x;
        x = GET_SSLLIB_SYMBOL("SSL_library_init");
        if(_cryptoLib)
        {
            if(x)
                ((int (*)())x)();
            x = GET_CRYPTOLIB_SYMBOL("OpenSSL_add_all_algorithms");
            if(!x)
                x = GET_CRYPTOLIB_SYMBOL("OPENSSL_add_all_algorithms");
            if(x)
            {
                ((void (*)())x)();
            }
            else
            {
                x = GET_CRYPTOLIB_SYMBOL("OpenSSL_add_all_algorithms_conf");
                if(!x)
                    x = GET_CRYPTOLIB_SYMBOL("OPENSSL_add_all_algorithms_conf");
                if(x)
                {
                    ((void (*)())x)();
                }
                else
                {
                    x = GET_CRYPTOLIB_SYMBOL("OpenSSL_add_all_algorithms_noconf");
                    if(!x)
                        x = GET_CRYPTOLIB_SYMBOL("OPENSSL_add_all_algorithms_noconf");
                    if(x)
                        ((void (*)())x)();
                }
            }
            x = GET_CRYPTOLIB_SYMBOL("OpenSSL_add_all_ciphers");
            if(!x)
                x = GET_CRYPTOLIB_SYMBOL("OPENSSL_add_all_ciphers");
            if(x)
                ((void (*)())x)();
            x = GET_CRYPTOLIB_SYMBOL("OpenSSL_add_all_digests");
            if(!x)
                x = GET_CRYPTOLIB_SYMBOL("OPENSSL_add_all_digests");
            if(x)
                ((void (*)())x)();
        }
    }
}


KOpenSSLProxy *KOpenSSLProxy::_me = 0L;
static KStaticDeleter< KOpenSSLProxy > medProxy;


KOpenSSLProxy::~KOpenSSLProxy()
{
    if(_sslLib)
    {
        _sslLib->unload();
    }
    if(_cryptoLib)
    {
        _cryptoLib->unload();
    }
    medProxy.setObject(0);
}


// FIXME: we should check "ok" and allow this to init the lib if !ok.

KOpenSSLProxy *KOpenSSLProxy::self()
{
#ifdef KSSL_HAVE_SSL
    if(!_me)
    {
        _me = medProxy.setObject(_me, new KOpenSSLProxy);
    }
#endif
    return _me;
}


#ifdef KSSL_HAVE_SSL


int KOpenSSLProxy::SSL_connect(SSL *ssl)
{
    if(K_SSL_connect)
        return (K_SSL_connect)(ssl);
    kdWarning() << "SSL_connect not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_accept(SSL *ssl)
{
    if(K_SSL_accept)
        return (K_SSL_accept)(ssl);
    kdWarning() << "SSL_accept not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_read(SSL *ssl, void *buf, int num)
{
    if(K_SSL_read)
        return (K_SSL_read)(ssl, buf, num);
    kdWarning() << "SSL_read not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_write(SSL *ssl, const void *buf, int num)
{
    if(K_SSL_write)
        return (K_SSL_write)(ssl, buf, num);
    kdWarning() << "SSL_write not defined!" << endl;
    return -1;
}


SSL *KOpenSSLProxy::SSL_new(SSL_CTX *ctx)
{
    if(K_SSL_new)
        return (K_SSL_new)(ctx);
    kdWarning() << "SSL_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::SSL_free(SSL *ssl)
{
    if(K_SSL_free)
        (K_SSL_free)(ssl);
    else
        kdWarning() << "SSL_free not defined!" << endl;
}


int KOpenSSLProxy::SSL_shutdown(SSL *ssl)
{
    if(K_SSL_shutdown)
        return (K_SSL_shutdown)(ssl);
    kdWarning() << "SSL_shutdown not defined!" << endl;
    return -1;
}


SSL_CTX *KOpenSSLProxy::SSL_CTX_new(SSL_METHOD *method)
{
    if(K_SSL_CTX_new)
        return (K_SSL_CTX_new)(method);
    kdWarning() << "SSL_CTX_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::SSL_CTX_free(SSL_CTX *ctx)
{
    if(K_SSL_CTX_free)
        (K_SSL_CTX_free)(ctx);
    else
        kdWarning() << "SSL_CTX_free not defined!" << endl;
}


int KOpenSSLProxy::SSL_set_fd(SSL *ssl, int fd)
{
    if(K_SSL_set_fd)
        return (K_SSL_set_fd)(ssl, fd);
    kdWarning() << "SSL_sed_fd not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_pending(SSL *ssl)
{
    if(K_SSL_pending)
        return (K_SSL_pending)(ssl);
    kdWarning() << "SSL_pending not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_CTX_set_cipher_list(SSL_CTX *ctx, const char *str)
{
    if(K_SSL_CTX_set_cipher_list)
        return (K_SSL_CTX_set_cipher_list)(ctx, str);
    kdWarning() << "SSL_CTX_set_cipher_list not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::SSL_CTX_set_verify(SSL_CTX *ctx, int mode, int (*verify_callback)(int, X509_STORE_CTX *))
{
    if(K_SSL_CTX_set_verify)
        (K_SSL_CTX_set_verify)(ctx, mode, verify_callback);
    else
        kdWarning() << "SSL_CTX_set_verify not defined!" << endl;
}


int KOpenSSLProxy::SSL_use_certificate(SSL *ssl, X509 *x)
{
    if(K_SSL_use_certificate)
        return (K_SSL_use_certificate)(ssl, x);
    kdWarning() << "SSL_use_certificate not defined!" << endl;
    return -1;
}


SSL_CIPHER *KOpenSSLProxy::SSL_get_current_cipher(SSL *ssl)
{
    if(K_SSL_get_current_cipher)
        return (K_SSL_get_current_cipher)(ssl);
    kdWarning() << "SSL_get_current_cipher not defined!" << endl;
    return 0L;
}


long KOpenSSLProxy::_SSL_set_options(SSL *ssl, long options)
{
    if(K_SSL_set_options)
        return (K_SSL_set_options)(ssl, options);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return this->SSL_set_options(ssl, options);
#endif
    kdWarning() << "SSL_set_options not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::_SSL_session_reused(SSL *ssl)
{
    if(K_SSL_session_reused)
        return (K_SSL_session_reused)(ssl);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return this->SSL_session_reused(ssl);
#endif
    kdWarning() << "SSL_session_reused not defined!" << endl;
    return -1;
}


long KOpenSSLProxy::SSL_ctrl(SSL *ssl, int cmd, long larg, void *parg)
{
    if(K_SSL_ctrl)
        return (K_SSL_ctrl)(ssl, cmd, larg, parg);
    kdWarning() << "SSL_ctrl not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::RAND_egd(const char *path)
{
    if(K_RAND_egd)
        return (K_RAND_egd)(path);
    kdWarning() << "RAND_egd not defined!" << endl;
    return -1;
}


SSL_METHOD *KOpenSSLProxy::TLSv1_client_method()
{
    if(K_TLSv1_client_method)
        return (K_TLSv1_client_method)();
    kdWarning() << "TLSv1_client_method not defined!" << endl;
    return 0L;
}


SSL_METHOD *KOpenSSLProxy::SSLv2_client_method()
{
    if(K_SSLv2_client_method)
        return (K_SSLv2_client_method)();
    kdWarning() << "SSLv2_client_method not defined!" << endl;
    return 0L;
}


SSL_METHOD *KOpenSSLProxy::SSLv3_client_method()
{
    if(K_SSLv3_client_method)
        return (K_SSLv3_client_method)();
    kdWarning() << "SSLv3_client_method not defined!" << endl;
    return 0L;
}


SSL_METHOD *KOpenSSLProxy::TLS_client_method()
{
    if(K_TLS_client_method)
        return (K_TLS_client_method)();
    kdWarning() << "TLS_client_method not defined!" << endl;
    return 0L;
}


X509 *KOpenSSLProxy::SSL_get_peer_certificate(SSL *s)
{
    if(K_SSL_get_peer_certificate)
        return (K_SSL_get_peer_certificate)(s);
    kdWarning() << "SSL_get_peer_certificate not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::SSL_CIPHER_get_bits(SSL_CIPHER *c, int *alg_bits)
{
    if(K_SSL_CIPHER_get_bits)
        return (K_SSL_CIPHER_get_bits)(c, alg_bits);
    kdWarning() << "SSL_CIPHER_get_bits not defined!" << endl;
    return -1;
}


char *KOpenSSLProxy::SSL_CIPHER_get_version(SSL_CIPHER *c)
{
    if(K_SSL_CIPHER_get_version)
        return (K_SSL_CIPHER_get_version)(c);
    kdWarning() << "SSL_CIPHER_get_version not defined!" << endl;
    return 0L;
}


const char *KOpenSSLProxy::SSL_CIPHER_get_name(SSL_CIPHER *c)
{
    if(K_SSL_CIPHER_get_name)
        return (K_SSL_CIPHER_get_name)(c);
    kdWarning() << "SSL_CIPHER_get_name not defined!" << endl;
    return 0L;
}


char *KOpenSSLProxy::SSL_CIPHER_description(SSL_CIPHER *c, char *buf, int size)
{
    if(K_SSL_CIPHER_description)
        return (K_SSL_CIPHER_description)(c, buf, size);
    kdWarning() << "SSL_CIPHER_description not defined!" << endl;
    return 0L;
}


X509 *KOpenSSLProxy::d2i_X509(X509 **a, unsigned char **pp, long length)
{
    if(K_d2i_X509)
        return (K_d2i_X509)(a, pp, length);
    kdWarning() << "d2i_X509 not defined!" << endl;
    return 0L;
}


X509_CRL *KOpenSSLProxy::d2i_X509_CRL(X509_CRL **a, unsigned char **pp, long length)
{
    if(K_d2i_X509_CRL)
        return (K_d2i_X509_CRL)(a, pp, length);
    kdWarning() << "d2i_X509_CRL not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::i2d_X509(X509 *a, unsigned char **pp)
{
    if(K_i2d_X509)
        return (K_i2d_X509)(a, pp);
    kdWarning() << "i2d_X509 not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_cmp(X509 *a, X509 *b)
{
    if(K_X509_cmp)
        return (K_X509_cmp)(a, b);
    kdWarning() << "X509_cmp not defined!" << endl;
    return 0;
}


int KOpenSSLProxy::X509_subject_name_cmp(const X509 *a, const X509 *b)
{
    if(K_X509_subject_name_cmp)
        return (K_X509_subject_name_cmp)(a, b);
    kdWarning() << "X509_subject_name_cmp not defined!" << endl;
    return 0;
}


X509_STORE *KOpenSSLProxy::X509_STORE_new(void)
{
    if(K_X509_STORE_new)
        return (K_X509_STORE_new)();
    kdWarning() << "X509_STORE_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_STORE_free(X509_STORE *v)
{
    if(K_X509_STORE_free)
        (K_X509_STORE_free)(v);
    else
        kdWarning() << "X509_STORE_free not defined!" << endl;
}


X509_STORE_CTX *KOpenSSLProxy::X509_STORE_CTX_new(void)
{
    if(K_X509_STORE_CTX_new)
        return (K_X509_STORE_CTX_new)();
    kdWarning() << "X509_STORE_CTX_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_STORE_CTX_free(X509_STORE_CTX *ctx)
{
    if(K_X509_STORE_CTX_free)
        (K_X509_STORE_CTX_free)(ctx);
    else
        kdWarning() << "X509_STORE_CTX_free not defined!" << endl;
}


int KOpenSSLProxy::X509_verify_cert(X509_STORE_CTX *ctx)
{
    if(K_X509_verify_cert)
        return (K_X509_verify_cert)(ctx);
    kdWarning() << "X509_verify_cert not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::X509_free(X509 *a)
{
    if(K_X509_free)
        (K_X509_free)(a);
    else
        kdWarning() << "X509_free not defined!" << endl;
}


void KOpenSSLProxy::X509_CRL_free(X509_CRL *a)
{
    if(K_X509_CRL_free)
        (K_X509_CRL_free)(a);
    else
        kdWarning() << "X509_CRL_free not defined!" << endl;
}


char *KOpenSSLProxy::X509_NAME_oneline(X509_NAME *a, char *buf, int size)
{
    if(K_X509_NAME_oneline)
        return (K_X509_NAME_oneline)(a, buf, size);
    kdWarning() << "X509_NAME_online not defined!" << endl;
    return 0L;
}


X509_NAME *KOpenSSLProxy::X509_get_subject_name(X509 *a)
{
    if(K_X509_get_subject_name)
        return (K_X509_get_subject_name)(a);
    kdWarning() << "X509_get_subject not defined!" << endl;
    return 0L;
}


X509_NAME *KOpenSSLProxy::X509_get_issuer_name(X509 *a)
{
    if(K_X509_get_issuer_name)
        return (K_X509_get_issuer_name)(a);
    kdWarning() << "X509_get_issuer not defined!" << endl;
    return 0L;
}


X509_LOOKUP *KOpenSSLProxy::X509_STORE_add_lookup(X509_STORE *v, X509_LOOKUP_METHOD *m)
{
    if(K_X509_STORE_add_lookup)
        return (K_X509_STORE_add_lookup)(v, m);
    kdWarning() << "X509_STORE_add_lookup not defined!" << endl;
    return 0L;
}


X509_LOOKUP_METHOD *KOpenSSLProxy::X509_LOOKUP_file(void)
{
    if(K_X509_LOOKUP_file)
        return (K_X509_LOOKUP_file)();
    kdWarning() << "X509_LOOKUP_file not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_LOOKUP_free(X509_LOOKUP *x)
{
    if(K_X509_LOOKUP_free)
        (K_X509_LOOKUP_free)(x);
    else
        kdWarning() << "X509_LOOKUP_free not defined!" << endl;
}


int KOpenSSLProxy::X509_LOOKUP_ctrl(X509_LOOKUP *ctx, int cmd, const char *argc, long argl, char **ret)
{
    if(K_X509_LOOKUP_ctrl)
        return (K_X509_LOOKUP_ctrl)(ctx, cmd, argc, argl, ret);
    kdWarning() << "X509_LOOKUP_ctrl not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::X509_STORE_CTX_init(X509_STORE_CTX *ctx, X509_STORE *store, X509 *x509, STACK_OF(X509) * chain)
{
    if(K_X509_STORE_CTX_init)
        (K_X509_STORE_CTX_init)(ctx, store, x509, chain);
    else
        kdWarning() << "X509_STORE_CTX_init not defined!" << endl;
}


void KOpenSSLProxy::CRYPTO_free(void *x)
{
    if(K_CRYPTO_free)
        (K_CRYPTO_free)(x);
    else
        kdWarning() << "CRYPTO_free not defined!" << endl;
}


X509 *KOpenSSLProxy::X509_dup(X509 *x509)
{
    if(K_X509_dup)
        return (K_X509_dup)(x509);
    kdWarning() << "X509_dup not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_get0_signature(const ASN1_BIT_STRING **psig, const X509_ALGOR **palg, const X509 *x)
{
    if(K_X509_get0_signature)
    {
        (X509_get0_signature)(psig, palg, x);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    if(!x)
        return;
    if(psig)
        *psig = x->signature;
    if(palg)
        *palg = x->sig_alg;
    return;
#endif
    kdWarning() << "X509_get0_signature not defined!" << endl;
}


BIO *KOpenSSLProxy::BIO_new(BIO_METHOD *type)
{
    if(K_BIO_new)
        return (K_BIO_new)(type);
    kdWarning() << "BIO_new not defined!" << endl;
    return 0L;
}


BIO_METHOD *KOpenSSLProxy::BIO_s_mem(void)
{
    if(K_BIO_s_mem)
        return (K_BIO_s_mem)();
    kdWarning() << "BIO_s_mem not defined!" << endl;
    return 0L;
}


BIO *KOpenSSLProxy::BIO_new_fp(FILE *stream, int close_flag)
{
    if(K_BIO_new_fp)
        return (K_BIO_new_fp)(stream, close_flag);
    kdWarning() << "BIO_new_fp not defined!" << endl;
    return 0L;
}


BIO *KOpenSSLProxy::BIO_new_mem_buf(void *buf, int len)
{
    if(K_BIO_new_mem_buf)
        return (K_BIO_new_mem_buf)(buf, len);
    kdWarning() << "BIO_new_mem_buf not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::BIO_free(BIO *a)
{
    if(K_BIO_free)
        return (K_BIO_free)(a);
    kdWarning() << "BIO_free not defined!" << endl;
    return -1;
}


long KOpenSSLProxy::BIO_ctrl(BIO *bp, int cmd, long larg, void *parg)
{
    if(K_BIO_ctrl)
        return (K_BIO_ctrl)(bp, cmd, larg, parg);
    kdWarning() << "BIO_ctrl not defined!" << endl;
    return 0; // failure return for BIO_ctrl is quite individual, maybe we should abort() instead
}


int KOpenSSLProxy::BIO_write(BIO *b, const void *data, int len)
{
    if(K_BIO_write)
        return (K_BIO_write)(b, data, len);
    kdWarning() << "BIO_write not defined!" << endl;
    return -1;
}


void *KOpenSSLProxy::BIO_get_data(BIO *a)
{
    if(K_BIO_get_data)
        return (K_BIO_get_data)(a);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return a->ptr;
#endif
    kdWarning() << "BIO_get_data not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::PEM_write_bio_X509(BIO *bp, X509 *x)
{
    if(K_PEM_ASN1_write_bio)
        return (K_PEM_ASN1_write_bio)((int (*)())K_i2d_X509, PEM_STRING_X509, bp, (char *)x, 0L, 0L, 0, 0L, 0L);
    kdWarning() << "PEM_write_bio_X509 not defined!" << endl;
    return -1;
}

#if OPENSSL_VERSION_NUMBER >= 0x10000000L
int KOpenSSLProxy::ASN1_i2d_fp(FILE *out, unsigned char *x)
{
    if(K_ASN1_item_i2d_fp && K_NETSCAPE_X509_it)
        return (K_ASN1_item_i2d_fp)(K_NETSCAPE_X509_it, out, x);
    kdWarning() << "ANS1_i2d_fp not defined!" << endl;
    return -1;
}
#else
ASN1_METHOD *KOpenSSLProxy::X509_asn1_meth(void)
{
    if(K_X509_asn1_meth)
        return (K_X509_asn1_meth)();
    kdWarning() << "X509_ans1_meth not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::ASN1_i2d_fp(FILE *out, unsigned char *x)
{
    if(K_ASN1_i2d_fp && K_i2d_ASN1_HEADER)
        return (K_ASN1_i2d_fp)((int (*)())K_i2d_ASN1_HEADER, out, x);
    kdWarning() << "ANS1_i2d_fp not defined!" << endl;
    return -1;
}
#endif

int KOpenSSLProxy::X509_print(FILE *fp, X509 *x)
{
    if(K_X509_print_fp)
        return (K_X509_print_fp)(fp, x);
    kdWarning() << "X509_print not defined!" << endl;
    return -1;
}


PKCS12 *KOpenSSLProxy::d2i_PKCS12_fp(FILE *fp, PKCS12 **p12)
{
    if(K_d2i_PKCS12_fp)
        return (K_d2i_PKCS12_fp)(fp, p12);
    kdWarning() << "d2i_PKCS12_fp not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::PKCS12_newpass(PKCS12 *p12, char *oldpass, char *newpass)
{
    if(K_PKCS12_newpass)
        return (K_PKCS12_newpass)(p12, oldpass, newpass);
    kdWarning() << "PKCS12_newpass not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::i2d_PKCS12(PKCS12 *p12, unsigned char **p)
{
    if(K_i2d_PKCS12)
        return (K_i2d_PKCS12)(p12, p);
    kdWarning() << "i2d_PKCS12 not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::i2d_PKCS12_fp(FILE *fp, PKCS12 *p12)
{
    if(K_i2d_PKCS12_fp)
        return (K_i2d_PKCS12_fp)(fp, p12);
    kdWarning() << "i2d_PKCS12_fp not defined!" << endl;
    return -1;
}


PKCS12 *KOpenSSLProxy::PKCS12_new(void)
{
    if(K_PKCS12_new)
        return (K_PKCS12_new)();
    kdWarning() << "PKCS12_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::PKCS12_free(PKCS12 *a)
{
    if(K_PKCS12_free)
        (K_PKCS12_free)(a);
    else
        kdWarning() << "PKCS12_free not defined!" << endl;
}


int KOpenSSLProxy::PKCS12_parse(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert, STACK_OF(X509) * *ca)
{
    if(K_PKCS12_parse)
        return (K_PKCS12_parse)(p12, pass, pkey, cert, ca);
    kdWarning() << "PKCS12_parse not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::EVP_PKEY_free(EVP_PKEY *x)
{
    if(K_EVP_PKEY_free)
        (K_EVP_PKEY_free)(x);
    else
        kdWarning() << "EVP_PKEY_free not defined!" << endl;
}


EVP_PKEY *KOpenSSLProxy::EVP_PKEY_new()
{
    if(K_EVP_PKEY_new)
        return (K_EVP_PKEY_new)();
    kdWarning() << "EVP_PKEY_new not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::EVP_PKEY_base_id(const EVP_PKEY *pkey)
{
    if(K_EVP_PKEY_base_id)
        return (K_EVP_PKEY_base_id)(pkey);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return pkey->type;
#endif
    kdWarning() << "EVP_PKEY_base_id not defined!" << endl;
    return -1;
}


RSA *KOpenSSLProxy::EVP_PKEY_get0_RSA(EVP_PKEY *pkey)
{
    if(K_EVP_PKEY_get0_RSA)
        return (K_EVP_PKEY_get0_RSA)(pkey);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return pkey->pkey.rsa;
#endif
    kdWarning() << "EVP_PKEY_get0_RSA not defined!" << endl;
    return 0L;
}


DSA *KOpenSSLProxy::EVP_PKEY_get0_DSA(EVP_PKEY *pkey)
{
    if(K_EVP_PKEY_get0_DSA)
        return (K_EVP_PKEY_get0_DSA)(pkey);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return pkey->pkey.dsa;
#endif
    kdWarning() << "EVP_PKEY_get0_DSA not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_REQ_free(X509_REQ *x)
{
    if(K_X509_REQ_free)
        (K_X509_REQ_free)(x);
    else
        kdWarning() << "X509_REQ_free not defined!" << endl;
}


X509_REQ *KOpenSSLProxy::X509_REQ_new()
{
    if(K_X509_REQ_new)
        return (K_X509_REQ_new)();
    kdWarning() << "X509_REQ_new not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::SSL_CTX_use_PrivateKey(SSL_CTX *ctx, EVP_PKEY *pkey)
{
    if(K_SSL_CTX_use_PrivateKey)
        return (K_SSL_CTX_use_PrivateKey)(ctx, pkey);
    kdWarning() << "SSL_CTX_use_PrivateKey not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_CTX_use_certificate(SSL_CTX *ctx, X509 *x)
{
    if(K_SSL_CTX_use_certificate)
        return (K_SSL_CTX_use_certificate)(ctx, x);
    kdWarning() << "SSL_CTX_use_certificate not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::SSL_get_error(SSL *ssl, int rc)
{
    if(K_SSL_get_error)
        return (K_SSL_get_error)(ssl, rc);
    kdWarning() << "SSL_get_error not defined!" << endl;
    return -1;
}


STACK_OF(X509) * KOpenSSLProxy::SSL_get_peer_cert_chain(SSL *s)
{
    if(K_SSL_get_peer_cert_chain)
        return (K_SSL_get_peer_cert_chain)(s);
    kdWarning() << "SSL_get_peer_cert_chain not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::OPENSSL_sk_free(STACK *s)
{
    if(K_sk_free)
        (K_sk_free)(s);
    else
        kdWarning() << "OPENSSL_sk_free not defined!" << endl;
}


int KOpenSSLProxy::OPENSSL_sk_num(STACK *s)
{
    if(K_sk_num)
        return (K_sk_num)(s);
    kdWarning() << "OPENSSL_sk_num not defined!" << endl;
    return -1;
}


char *KOpenSSLProxy::OPENSSL_sk_pop(STACK *s)
{
    if(K_sk_pop)
        return (K_sk_pop)(s);
    kdWarning() << "OPENSSL_sk_pop not defined!" << endl;
    return 0L;
}


char *KOpenSSLProxy::OPENSSL_sk_value(STACK *s, int n)
{
    if(K_sk_value)
        return (K_sk_value)(s, n);
    kdWarning() << "OPENSSL_sk_value not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::X509_STORE_CTX_set0_untrusted(X509_STORE_CTX *v, STACK_OF(X509) * x)
{
    if(K_X509_STORE_CTX_set0_untrusted)
        (K_X509_STORE_CTX_set0_untrusted)(v, x);
    else
        kdWarning() << "X509_STORE_CTX_set0_untrusted not defined!" << endl;
}

void KOpenSSLProxy::X509_STORE_CTX_set_purpose(X509_STORE_CTX *v, int purpose)
{
    if(K_X509_STORE_CTX_set_purpose)
        (K_X509_STORE_CTX_set_purpose)(v, purpose);
    else
        kdWarning() << "X509_STORE_CTX_set_purpose not defined!" << endl;
}


STACK *KOpenSSLProxy::OPENSSL_sk_dup(const STACK *s)
{
    if(K_sk_dup)
        return (K_sk_dup)(s);
    kdWarning() << "OPENSSL_sk_dup not defined!" << endl;
    return 0L;
}


STACK *KOpenSSLProxy::OPENSSL_sk_new(int (*cmp)())
{
    if(K_sk_new)
        return (K_sk_new)(cmp);
    kdWarning() << "OPENSSL_sk_new not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::OPENSSL_sk_push(STACK *s, char *d)
{
    if(K_sk_push)
        return (K_sk_push)(s, d);
    kdWarning() << "OPENSSL_sk_push not defined!" << endl;
    return -1;
}


char *KOpenSSLProxy::i2s_ASN1_INTEGER(X509V3_EXT_METHOD *meth, ASN1_INTEGER *aint)
{
    if(K_i2s_ASN1_INTEGER)
        return (K_i2s_ASN1_INTEGER)(meth, aint);
    kdWarning() << "i2s_ANS1_INTEGER not defined!" << endl;
    return 0L;
}


ASN1_INTEGER *KOpenSSLProxy::X509_get_serialNumber(X509 *x)
{
    if(K_X509_get_serialNumber)
        return (K_X509_get_serialNumber)(x);
    kdWarning() << "X509_get_serialNumber not defined!" << endl;
    return 0L;
}


EVP_PKEY *KOpenSSLProxy::X509_get_pubkey(X509 *x)
{
    if(K_X509_get_pubkey)
        return (K_X509_get_pubkey)(x);
    kdWarning() << "X59_get_pubkey not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::i2d_PublicKey(EVP_PKEY *a, unsigned char **pp)
{
    if(K_i2d_PublicKey)
        return (K_i2d_PublicKey)(a, pp);
    kdWarning() << "i2d_PublicKey not defined!" << endl;
    return 0;
}


int KOpenSSLProxy::X509_check_private_key(X509 *x, EVP_PKEY *p)
{
    if(K_X509_check_private_key)
        return (K_X509_check_private_key)(x, p);
    kdWarning() << "X509_check_private_key not defined!" << endl;
    return -1;
}


char *KOpenSSLProxy::BN_bn2hex(const BIGNUM *a)
{
    if(K_BN_bn2hex)
        return (K_BN_bn2hex)(a);
    kdWarning() << "BN_bn2hex not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::X509_digest(const X509 *x, const EVP_MD *t, unsigned char *md, unsigned int *len)
{
    if(K_X509_digest)
        return (K_X509_digest)(x, t, md, len);
    kdWarning() << "X509_digest not defined!" << endl;
    return -1;
}


EVP_MD *KOpenSSLProxy::EVP_md5()
{
    if(K_EVP_md5)
        return (K_EVP_md5)();
    kdWarning() << "EVP_md5 not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::ASN1_INTEGER_free(ASN1_INTEGER *a)
{
    if(K_ASN1_INTEGER_free)
        (K_ASN1_INTEGER_free)(a);
    else
        kdWarning() << "ANS1_INTEGER_free not defined!" << endl;
}


int KOpenSSLProxy::OBJ_obj2nid(ASN1_OBJECT *o)
{
    if(K_OBJ_obj2nid)
        return (K_OBJ_obj2nid)(o);
    kdWarning() << "OBJ_obj2nid not defined!" << endl;
    return -1;
}


const char *KOpenSSLProxy::OBJ_nid2ln(int n)
{
    if(K_OBJ_nid2ln)
        return (K_OBJ_nid2ln)(n);
    kdWarning() << "OBJ_nid2ln not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::X509_get_ext_count(X509 *x)
{
    if(K_X509_get_ext_count)
        return (K_X509_get_ext_count)(x);
    kdWarning() << "X509_get_ext_count not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_get_ext_by_NID(X509 *x, int nid, int lastpos)
{
    if(K_X509_get_ext_by_NID)
        return (K_X509_get_ext_by_NID)(x, nid, lastpos);
    kdWarning() << "X509_get_ext_by_NID not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_get_ext_by_OBJ(X509 *x, ASN1_OBJECT *obj, int lastpos)
{
    if(K_X509_get_ext_by_OBJ)
        return (K_X509_get_ext_by_OBJ)(x, obj, lastpos);
    kdWarning() << "X509_get_ext_by_OBJ not defined!" << endl;
    return -1;
}


X509_EXTENSION *KOpenSSLProxy::X509_get_ext(X509 *x, int loc)
{
    if(K_X509_get_ext)
        return (K_X509_get_ext)(x, loc);
    kdWarning() << "X509_get_ext not defined!" << endl;
    return 0L;
}


X509_EXTENSION *KOpenSSLProxy::X509_delete_ext(X509 *x, int loc)
{
    if(K_X509_delete_ext)
        return (K_X509_delete_ext)(x, loc);
    kdWarning() << "X509_delete_ext not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::X509_add_ext(X509 *x, X509_EXTENSION *ex, int loc)
{
    if(K_X509_add_ext)
        return (K_X509_add_ext)(x, ex, loc);
    kdWarning() << "X509_add_ext not defined!" << endl;
    return -1;
}


void *KOpenSSLProxy::X509_get_ext_d2i(X509 *x, int nid, int *crit, int *idx)
{
    if(K_X509_get_ext_d2i)
        return (K_X509_get_ext_d2i)(x, nid, crit, idx);
    kdWarning() << "X509_get_ext_d2i not defined!" << endl;
    return 0L;
}


char *KOpenSSLProxy::i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method, ASN1_OCTET_STRING *ia5)
{
    if(K_i2s_ASN1_OCTET_STRING)
        return (K_i2s_ASN1_OCTET_STRING)(method, ia5);
    kdWarning() << "i2s_ANS1_OCTET_STRING not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::ASN1_BIT_STRING_get_bit(ASN1_BIT_STRING *a, int n)
{
    if(K_ASN1_BIT_STRING_get_bit)
        return (K_ASN1_BIT_STRING_get_bit)(a, n);
    kdWarning() << "ANS1_BIT_STRING_get_bit not defined!" << endl;
    return -1;
}


PKCS7 *KOpenSSLProxy::PKCS7_new(void)
{
    if(K_PKCS7_new)
        return (K_PKCS7_new)();
    kdWarning() << "PKCS7_new not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::PKCS7_free(PKCS7 *a)
{
    if(K_PKCS7_free)
        (K_PKCS7_free)(a);
    else
        kdWarning() << "PKCS7_free not defined!" << endl;
}


void KOpenSSLProxy::PKCS7_content_free(PKCS7 *a)
{
    if(K_PKCS7_content_free)
        (K_PKCS7_content_free)(a);
    else
        kdWarning() << "PKCS7_content_free not defined!" << endl;
}


int KOpenSSLProxy::i2d_PKCS7(PKCS7 *a, unsigned char **pp)
{
    if(K_i2d_PKCS7)
        return (K_i2d_PKCS7)(a, pp);
    kdWarning() << "i2d_PKCS7 not defined!" << endl;
    return -1;
}


PKCS7 *KOpenSSLProxy::d2i_PKCS7(PKCS7 **a, unsigned char **pp, long length)
{
    if(K_d2i_PKCS7)
        return (K_d2i_PKCS7)(a, pp, length);
    kdWarning() << "d2i_PKCS7 not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::i2d_PKCS7_fp(FILE *fp, PKCS7 *p7)
{
    if(K_i2d_PKCS7_fp)
        return (K_i2d_PKCS7_fp)(fp, p7);
    kdWarning() << "i2d_PKCS7_fd not defined!" << endl;
    return -1;
}


PKCS7 *KOpenSSLProxy::d2i_PKCS7_fp(FILE *fp, PKCS7 **p7)
{
    if(K_d2i_PKCS7_fp)
        return (K_d2i_PKCS7_fp)(fp, p7);
    kdWarning() << "d2i_PKCS7_fp not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::i2d_PKCS7_bio(BIO *bp, PKCS7 *p7)
{
    if(K_i2d_PKCS7_bio)
        return (K_i2d_PKCS7_bio)(bp, p7);
    kdWarning() << "i2d_PKCS7_bio not defined!" << endl;
    return -1;
}


PKCS7 *KOpenSSLProxy::d2i_PKCS7_bio(BIO *bp, PKCS7 **p7)
{
    if(K_d2i_PKCS7_bio)
        return (K_d2i_PKCS7_bio)(bp, p7);
    kdWarning() << "d2i_PKCS7_bio not defined!" << endl;
    return 0L;
}


PKCS7 *KOpenSSLProxy::PKCS7_dup(PKCS7 *p7)
{
    if(K_PKCS7_dup)
        return (K_PKCS7_dup)(p7);
    kdWarning() << "PKCS7_dup not defined!" << endl;
    return 0L;
}


PKCS7 *KOpenSSLProxy::PKCS7_sign(X509 *signcert, EVP_PKEY *pkey, STACK_OF(X509) * certs, BIO *data, int flags)
{
    if(K_PKCS7_sign)
        return (K_PKCS7_sign)(signcert, pkey, certs, data, flags);
    kdWarning() << "PKCS7_sign not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::PKCS7_verify(PKCS7 *p, STACK_OF(X509) * st, X509_STORE *s, BIO *in, BIO *out, int flags)
{
    if(K_PKCS7_verify)
        return (K_PKCS7_verify)(p, st, s, in, out, flags);
    kdWarning() << "PKCS7_verify not defined!" << endl;
    return 0;
}


STACK_OF(X509) * KOpenSSLProxy::PKCS7_get0_signers(PKCS7 *p7, STACK_OF(X509) * certs, int flags)
{
    if(K_PKCS7_get0_signers)
        return (K_PKCS7_get0_signers)(p7, certs, flags);
    kdWarning() << "PKCS7_get0_signers not defined!" << endl;
    return 0L;
}


PKCS7 *KOpenSSLProxy::PKCS7_encrypt(STACK_OF(X509) * certs, BIO *in, EVP_CIPHER *cipher, int flags)
{
    if(K_PKCS7_encrypt)
        return (K_PKCS7_encrypt)(certs, in, cipher, flags);
    kdWarning() << "PKCS7_encrypt not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::PKCS7_decrypt(PKCS7 *p7, EVP_PKEY *pkey, X509 *cert, BIO *data, int flags)
{
    if(K_PKCS7_decrypt)
        return (K_PKCS7_decrypt)(p7, pkey, cert, data, flags);
    kdWarning() << "PKCS7_decrypt not defined!" << endl;
    return 0;
}


STACK_OF(X509_NAME) * KOpenSSLProxy::SSL_load_client_CA_file(const char *file)
{
    if(K_SSL_load_client_CA_file)
        return (K_SSL_load_client_CA_file)(file);
    kdWarning() << "SSL_load_client_CA_file not defined!" << endl;
    return 0L;
}


STACK_OF(X509_INFO) * KOpenSSLProxy::PEM_X509_INFO_read(FILE *fp, STACK_OF(X509_INFO) * sk, pem_password_cb *cb, void *u)
{
    if(K_PEM_X509_INFO_read)
        return (K_PEM_X509_INFO_read)(fp, sk, cb, u);
    kdWarning() << "PEM_X509_INFO_read not defined!" << endl;
    return 0L;
}


X509 *KOpenSSLProxy::X509_d2i_fp(FILE *out, X509 **buf)
{
    if(K_ASN1_d2i_fp)
        return reinterpret_cast< X509 * >((K_ASN1_d2i_fp)(reinterpret_cast< char *(*)() >(K_X509_new), reinterpret_cast< char *(*)() >(K_d2i_X509),
                                                          out, reinterpret_cast< unsigned char ** >(buf)));
    kdWarning() << "X509_d2i_fp not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::SSL_peek(SSL *ssl, void *buf, int num)
{
    if(K_SSL_peek)
        return (K_SSL_peek)(ssl, buf, num);
    kdWarning() << "SSL_peek not defined!" << endl;
    return -1;
}


const char *KOpenSSLProxy::RAND_file_name(char *buf, size_t num)
{
    if(K_RAND_file_name)
        return (K_RAND_file_name)(buf, num);
    kdWarning() << "RAND_file_name not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::RAND_load_file(const char *filename, long max_bytes)
{
    if(K_RAND_load_file)
        return (K_RAND_load_file)(filename, max_bytes);
    kdWarning() << "REND_load_file not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::RAND_write_file(const char *filename)
{
    if(K_RAND_write_file)
        return (K_RAND_write_file)(filename);
    kdWarning() << "RAND_write_file not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_PURPOSE_get_count()
{
    if(K_X509_PURPOSE_get_count)
        return (K_X509_PURPOSE_get_count)();
    kdWarning() << "X509_PURPOSE_get_count not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_PURPOSE_get_id(X509_PURPOSE *p)
{
    if(K_X509_PURPOSE_get_id)
        return (K_X509_PURPOSE_get_id)(p);
    kdWarning() << "X509_PURPOSE_get_id not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_check_purpose(X509 *x, int id, int ca)
{
    if(K_X509_check_purpose)
        return (K_X509_check_purpose)(x, id, ca);
    kdWarning() << "X509_check_purpose not defined!" << endl;
    return -1;
}


X509_PURPOSE *KOpenSSLProxy::X509_PURPOSE_get0(int idx)
{
    if(K_X509_PURPOSE_get0)
        return (K_X509_PURPOSE_get0)(idx);
    kdWarning() << "X509_PURPOSE_get0 not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::EVP_PKEY_assign(EVP_PKEY *pkey, int type, char *key)
{
    if(K_EVP_PKEY_assign)
        return (K_EVP_PKEY_assign)(pkey, type, key);
    kdWarning() << "EVP_PKEY_assign not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_REQ_set_pubkey(X509_REQ *x, EVP_PKEY *pkey)
{
    if(K_X509_REQ_set_pubkey)
        return (K_X509_REQ_set_pubkey)(x, pkey);
    kdWarning() << "X509_REQ_set_pubkey not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::RSA_get0_key(const RSA *r, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d)
{
    if(K_RSA_get0_key)
    {
        (K_RSA_get0_key)(r, n, e, d);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    if(!r)
        return;
    if(n)
        *n = r->n;
    if(e)
        *e = r->e;
    if(d)
        *d = r->d;
    return;
#endif
    kdWarning() << "REG_get0_key not defined!" << endl;
}


RSA *KOpenSSLProxy::RSA_generate_key(int bits, unsigned long e, void (*callback)(int, int, void *), void *cb_arg)
{
    if(K_RSA_generate_key)
        return (K_RSA_generate_key)(bits, e, callback, cb_arg);
    kdWarning() << "RSA_generate_key not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::DSA_get0_pqg(const DSA *d, const BIGNUM **p, const BIGNUM **q, const BIGNUM **g)
{
    if(K_DSA_get0_pqg)
    {
        (K_DSA_get0_pqg)(d, p, q, g);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    if(!d)
        return;
    if(p)
        *p = d->p;
    if(q)
        *q = d->q;
    if(g)
        *g = d->g;
    return;
#endif
    kdWarning() << "DSA_get0_pqg not defined!" << endl;
}


void KOpenSSLProxy::DSA_get0_key(const DSA *d, const BIGNUM **pub_key, const BIGNUM **priv_key)
{
    if(K_DSA_get0_key)
    {
        (K_DSA_get0_key)(d, pub_key, priv_key);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    if(!d)
        return;
    if(pub_key)
        *pub_key = d->pub_key;
    if(priv_key)
        *priv_key = d->priv_key;
    return;
#endif
    kdWarning() << "DSA_get0_key not defined!" << endl;
}


STACK *KOpenSSLProxy::X509_get1_email(X509 *x)
{
    if(K_X509_get1_email)
        return (K_X509_get1_email)(x);
    kdWarning() << "X509_get1_email not defined!" << endl;
    return 0L;
}

void KOpenSSLProxy::X509_email_free(STACK *sk)
{
    if(K_X509_email_free)
        (K_X509_email_free)(sk);
    else
        kdWarning() << "X509_email_free not defined!" << endl;
}

EVP_CIPHER *KOpenSSLProxy::EVP_des_ede3_cbc()
{
    if(K_EVP_des_ede3_cbc)
        return (K_EVP_des_ede3_cbc)();
    kdWarning() << "EVM_des_ede3_cbc not defined!" << endl;
    return 0L;
}

EVP_CIPHER *KOpenSSLProxy::EVP_des_cbc()
{
    if(K_EVP_des_cbc)
        return (K_EVP_des_cbc)();
    kdWarning() << "EVP_des_cbc not defined!" << endl;
    return 0L;
}

EVP_CIPHER *KOpenSSLProxy::EVP_rc2_cbc()
{
    if(K_EVP_rc2_cbc)
        return (K_EVP_rc2_cbc)();
    kdWarning() << "EVP_rc2_cbc not defined!" << endl;
    return 0L;
}

EVP_CIPHER *KOpenSSLProxy::EVP_rc2_64_cbc()
{
    if(K_EVP_rc2_64_cbc)
        return (K_EVP_rc2_64_cbc)();
    kdWarning() << "EVP_rc2_64_cbc not defined!" << endl;
    return 0L;
}

EVP_CIPHER *KOpenSSLProxy::EVP_rc2_40_cbc()
{
    if(K_EVP_rc2_40_cbc)
        return (K_EVP_rc2_40_cbc)();
    kdWarning() << "EVP_rc2_40_cbc not defined!" << endl;
    return 0L;
}

int KOpenSSLProxy::i2d_X509_REQ_fp(FILE *fp, X509_REQ *x)
{
    if(K_i2d_X509_REQ_fp)
        return (K_i2d_X509_REQ_fp)(fp, x);
    kdWarning() << "i2d_X509_REQ_fp not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::ERR_clear_error()
{
    if(K_ERR_clear_error)
        (K_ERR_clear_error)();
    else
        kdWarning() << "ERR_clear_error not defined!" << endl;
}


unsigned long KOpenSSLProxy::ERR_get_error()
{
    if(K_ERR_get_error)
        return (K_ERR_get_error)();
    kdWarning() << "ERR_get_error not defined!" << endl;
    return 0xffffffff;
}


void KOpenSSLProxy::ERR_print_errors_fp(FILE *fp)
{
    if(K_ERR_print_errors_fp)
        (K_ERR_print_errors_fp)(fp);
    else
        kdWarning() << "ERR_print_errors_fp not defined!" << endl;
}


SSL_SESSION *KOpenSSLProxy::SSL_get1_session(SSL *ssl)
{
    if(K_SSL_get1_session)
        return (K_SSL_get1_session)(ssl);
    kdWarning() << "SSL_get1_session not defined!" << endl;
    return 0L;
}


void KOpenSSLProxy::SSL_SESSION_free(SSL_SESSION *session)
{
    if(K_SSL_SESSION_free)
        (K_SSL_SESSION_free)(session);
    else
        kdWarning() << "SSL_SESSION_free not defined!" << endl;
}


int KOpenSSLProxy::SSL_set_session(SSL *ssl, SSL_SESSION *session)
{
    if(K_SSL_set_session)
        return (K_SSL_set_session)(ssl, session);
    kdWarning() << "SSL_set_session not defined!" << endl;
    return -1;
}


SSL_SESSION *KOpenSSLProxy::d2i_SSL_SESSION(SSL_SESSION **a, unsigned char **pp, long length)
{
    if(K_d2i_SSL_SESSION)
        return (K_d2i_SSL_SESSION)(a, pp, length);
    kdWarning() << "d2i_SSL_SESSION not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::i2d_SSL_SESSION(SSL_SESSION *in, unsigned char **pp)
{
    if(K_i2d_SSL_SESSION)
        return (K_i2d_SSL_SESSION)(in, pp);
    kdWarning() << "i2d_SSL_SESSION not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::i2d_PrivateKey_fp(FILE *fp, EVP_PKEY *p)
{
    if(K_i2d_PrivateKey_fp)
        return (K_i2d_PrivateKey_fp)(fp, p);
    kdWarning() << "i2d_PrivateKey not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::i2d_PKCS8PrivateKey_fp(FILE *fp, EVP_PKEY *p, const EVP_CIPHER *c, char *k, int klen, pem_password_cb *cb, void *u)
{
    if(K_i2d_PKCS8PrivateKey_fp)
        return (K_i2d_PKCS8PrivateKey_fp)(fp, p, c, k, klen, cb, u);
    kdWarning() << "i2d_PKCS8PrivateKey_fp not defined!" << endl;
    return -1;
}


void KOpenSSLProxy::RSA_free(RSA *rsa)
{
    if(K_RSA_free)
        (K_RSA_free)(rsa);
    else
        kdWarning() << "RSA_free not defined!" << endl;
}


EVP_CIPHER *KOpenSSLProxy::EVP_bf_cbc()
{
    if(K_EVP_bf_cbc)
        return (K_EVP_bf_cbc)();
    kdWarning() << "EVP_bf_cbc not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::X509_REQ_sign(X509_REQ *x, EVP_PKEY *pkey, const EVP_MD *md)
{
    if(K_X509_REQ_sign)
        return (K_X509_REQ_sign)(x, pkey, md);
    kdWarning() << "X509_REQ_sign not defined!" << endl;
    return -1;
}


int KOpenSSLProxy::X509_NAME_add_entry_by_txt(X509_NAME *name, char *field, int type, unsigned char *bytes, int len, int loc, int set)
{
    if(K_X509_NAME_add_entry_by_txt)
        return (K_X509_NAME_add_entry_by_txt)(name, field, type, bytes, len, loc, set);
    kdWarning() << "X509_NAME_add_entry not defined!" << endl;
    return -1;
}


X509_NAME *KOpenSSLProxy::X509_NAME_new()
{
    if(K_X509_NAME_new)
        return (K_X509_NAME_new)();
    kdWarning() << "X509_NAME_new not defined!" << endl;
    return 0L;
}


int KOpenSSLProxy::X509_REQ_set_subject_name(X509_REQ *req, X509_NAME *name)
{
    if(K_X509_REQ_set_subject_name)
        return (K_X509_REQ_set_subject_name)(req, name);
    kdWarning() << "X509_REQ_set_subject_name not defined!" << endl;
    return -1;
}


unsigned char *KOpenSSLProxy::ASN1_STRING_data(ASN1_STRING *x)
{
    if(K_ASN1_STRING_data)
        return (K_ASN1_STRING_data)(x);
    kdWarning() << "ASN1_STRING_data not defined!" << endl;
    return 0L;
}

int KOpenSSLProxy::ASN1_STRING_length(ASN1_STRING *x)
{
    if(K_ASN1_STRING_length)
        return (K_ASN1_STRING_length)(x);
    kdWarning() << "ASN1_STRING_length not defined!" << endl;
    return 0L;
}

STACK_OF(SSL_CIPHER) * KOpenSSLProxy::SSL_get_ciphers(const SSL *ssl)
{
    if(K_SSL_get_ciphers)
        return (K_SSL_get_ciphers)(ssl);
    kdWarning() << "SSL_get_ciphers not defined!" << endl;
    return 0L;
}

const ASN1_TIME *KOpenSSLProxy::X509_CRL_get0_lastUpdate(const X509_CRL *crl)
{
    if(K_X509_CRL_get0_lastUpdate)
        return (K_X509_CRL_get0_lastUpdate)(crl);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return X509_CRL_get_lastUpdate(crl);
#endif
    kdWarning() << "X509_CRL_get_lastUpdate not defined!" << endl;
    return 0L;
}

const ASN1_TIME *KOpenSSLProxy::X509_CRL_get0_nextUpdate(const X509_CRL *crl)
{
    if(K_X509_CRL_get0_nextUpdate)
        return (K_X509_CRL_get0_nextUpdate)(crl);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return X509_CRL_get_nextUpdate(crl);
#endif
    kdWarning() << "X509_CRL_get_nextUpdate not defined!" << endl;
    return 0L;
}

X509 *KOpenSSLProxy::X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx)
{
    if(K_X509_STORE_CTX_get_current_cert)
        return (K_X509_STORE_CTX_get_current_cert)(ctx);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return ctx->current_cert;
#endif
    kdWarning() << "X509_STORE_CTX_get_current_cert not defined!" << endl;
    return 0L;
}

int KOpenSSLProxy::X509_STORE_CTX_get_error(X509_STORE_CTX *ctx)
{
    if(K_X509_STORE_CTX_get_error)
        return (K_X509_STORE_CTX_get_error)(ctx);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return ctx->error;
#endif
    kdWarning() << "X509k_STORE_CTX_get_error not defined!" << endl;
    return -1;
}

int KOpenSSLProxy::X509_STORE_CTX_get_error_depth(X509_STORE_CTX *ctx)
{
    if(K_X509_STORE_CTX_get_error_depth)
        return (K_X509_STORE_CTX_get_error_depth)(ctx);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return ctx->error_depth;
#endif
    kdWarning() << "X509_STORE_CTX_get_error_depth not defined!" << endl;
    return -1;
}

void KOpenSSLProxy::X509_STORE_CTX_set_error(X509_STORE_CTX *ctx, int s)
{
    if(K_X509_STORE_CTX_set_error)
    {
        (K_X509_STORE_CTX_set_error)(ctx, s);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    ctx->error = s;
    return;
#endif
    kdWarning() << "X509_STORE_CTX_set_error not defined!" << endl;
}

void KOpenSSLProxy::X509_STORE_set_verify_cb(X509_STORE *ctx, X509_STORE_CTX_verify_cb verify_cb)
{
    if(K_X509_STORE_set_verify_cb)
    {
        (K_X509_STORE_set_verify_cb)(ctx, verify_cb);
        return;
    }
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    X509_STORE_set_verify_cb_func(ctx, verify_cb);
    return;
#endif
    kdWarning() << "X590_STORE_set_verify_cb not defined!" << endl;
}

STACK_OF(X509_OBJECT) * KOpenSSLProxy::X509_STORE_get0_objects(X509_STORE *v)
{
    if(K_X509_STORE_get0_objects)
        return (K_X509_STORE_get0_objects)(v);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return v->objs;
#endif
    kdWarning() << "X509_STORE_get0_objects not defined!" << endl;
}

X509_LOOKUP_TYPE KOpenSSLProxy::X509_OBJECT_get_type(const X509_OBJECT *a)
{
    if(K_X509_OBJECT_get_type)
        return (K_X509_OBJECT_get_type)(a);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return a->type;
#endif
    kdWarning() << "X509_OBJECT_get_type not defined!" << endl;
}

X509 *KOpenSSLProxy::X509_OBJECT_get0_X509(const X509_OBJECT *a)
{
    if(K_X509_OBJECT_get0_X509)
        return (K_X509_OBJECT_get0_X509)(a);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return a->data.x509;
#endif
    kdWarning() << "X509_OBJECT_get0_X509 not defined!" << endl;
}


ASN1_TIME *KOpenSSLProxy::X509_getm_notAfter(const X509 *x)
{
    if(K_X509_getm_notAfter)
        return (K_X509_getm_notAfter)(x);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return X509_get_notAfter(x);
#endif
    kdWarning() << "X509_get_notAfter not defined!" << endl;
    return 0L;
}

ASN1_TIME *KOpenSSLProxy::X509_getm_notBefore(const X509 *x)
{
    if(K_X509_getm_notBefore)
        return (K_X509_getm_notBefore)(x);
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    return X509_get_notBefore(x);
#endif
    kdWarning() << "X509_get_notBefore not defined!" << endl;
    return 0L;
}

/* cover KOpenSSLProxy API compatibility */
STACK *KOpenSSLProxy::sk_dup(const STACK *s)
{
    return OPENSSL_sk_dup(s);
}

void KOpenSSLProxy::sk_free(STACK *s)
{
    OPENSSL_sk_free(s);
}

STACK *KOpenSSLProxy::sk_new(int (*cmp)())
{
    return OPENSSL_sk_new(cmp);
}

int KOpenSSLProxy::sk_num(STACK *s)
{
    return OPENSSL_sk_num(s);
}

char *KOpenSSLProxy::sk_pop(STACK *s)
{
    return OPENSSL_sk_pop(s);
}

int KOpenSSLProxy::sk_push(STACK *s, char *d)
{
    return OPENSSL_sk_push(s, d);
}

char *KOpenSSLProxy::sk_value(STACK *s, int n)
{
    return OPENSSL_sk_value(s, n);
}

void KOpenSSLProxy::X509_STORE_CTX_set_chain(X509_STORE_CTX *v, STACK_OF(X509) * x)
{
    X509_STORE_CTX_set0_untrusted(v, x);
}

SSL_METHOD *KOpenSSLProxy::SSLv23_client_method()
{
    return TLS_client_method();
}

#endif
