#include <windows.h>
#include <wincrypt.h>
#include <assert.h>
class WinRandom
{
    HCRYPTPROV handle;

public:
    WinRandom()
    {
        handle = NULL;
        CryptAcquireContext(
            (HCRYPTPROV *)&handle, NULL, NULL,
            PROV_RSA_FULL, 0);
    }
    ~WinRandom()
    {
        if (handle != NULL)
            CryptReleaseContext(handle, 0);
    }
    bool randBuf(void *dest, int len)
    {
        if (handle == NULL)
            return false;
        return CryptGenRandom(handle, len, (BYTE *)dest);
    }
#define _(func, typ)                                \
    typ func()                                      \
    {                                               \
        typ ret = 0;                                \
        assert(randBuf((void *)&ret, sizeof(ret))); \
        return ret;                                 \
    }
    _(randInt, int)
    _(randLong, long long)
    _(randUnsigned, unsigned)
    _(randUnsignedLong, unsigned long long)
    _(randShort, short)
    _(randUnsignedShort, unsigned short)
    _(randChar, char)
    _(randUnsignedChar, unsigned char)
    _(randSignedChar, signed char)
};