#include "sys/socket.h"
#include <unistd.h>
// #include <sys/time.h>
// #include <inttypes.h>
// #include "rdkafka_int.h"
// #include "rdatomic.h"

// extern int __real_mbedtls_ssl_handshake_step(mbedtls_ssl_context *ssl);

extern int __real_lwip_getsockopt(int s,int level,int optname,void *opval,socklen_t *optlen);

int __wrap_lwip_getsockopt(int s,int level,int optname,void *opval,socklen_t *optlen)
{
    if ((level == SOL_SOCKET && optname == SO_RCVBUF) ||
        (level == SOL_SOCKET && optname == SO_SNDBUF)) {
        *(size_t *)opval = 64*1024;
        return 0;
    }
    return __real_lwip_getsockopt(s, level, optname, opval, optlen);
}

extern ssize_t __real_lwip_sendmsg(int s,const struct msghdr *message,int flags);

ssize_t __wrap_lwip_sendmsg(int s,const struct msghdr *message,int flags)
{
    return __real_lwip_sendmsg(s, message, flags & (~MSG_NOSIGNAL));
}

// void __wrap_rd_usleep(int usec, rd_atomic32_t *terminate)
// {
//     usleep(usec);
// }

// __wrap_mbedtls_ssl_handshake_step
