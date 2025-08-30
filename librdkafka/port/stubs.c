#include <sys/unistd.h>
#include <sys/errno.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "pthread.h"
// No-op on ESP-IDF, as signals are note supported
int sigaction (int, const struct sigaction *, struct sigaction *)
{
    return 0;
}

int nanosleep (const struct timespec  *rqtp, struct timespec *rmtp)
{
    usleep(rqtp->tv_sec * 1000000 + rqtp->tv_nsec/1000);
    return 0;
}

///
int pthread_kill(pthread_t thread, int sig)
{
    if (sig <= 0 || sig >= NSIG) {   // NSIG is usually 32 or 64 depending on libc
        return EINVAL;
    }

    if ((void*)thread == NULL) {
        return ESRCH;
    }

    // In ESP-IDF pthread shim, pthread_t is just a TaskHandle_t
    TaskHandle_t handle = (TaskHandle_t)thread;

    // Deliver signal to the target task (very simplified):
    // Use FreeRTOS notifications as "signals"
    if (xTaskNotify(handle, (1U << sig), eSetBits) == pdPASS) {
        return 0;
    }

    return ESRCH;
}
