#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int usr_thread_mutex_create(pthread_mutex_t *mtx, int pthread_type)
{
    pthread_mutexattr_t         attr;
    int                         err;
    
    if ((err = pthread_mutexattr_init(&attr)) != 0) {
        printf("error occur in pthread_mutexattr_init[%d]: %s", errno, strerror(errno));
        return err;
    }

    if ((err = pthread_mutexattr_settype(&attr, pthread_type)) != 0) {
        printf("error occur in pthread_mutexattr_settype[%d]: %s", errno, strerror(errno));
        return err;
    }

    if ((err = pthread_mutex_init(mtx, &attr)) != 0) {
        printf("error occur in pthread_mutex_init[%d]: %s", errno, strerror(errno));
        return err;
    }

    if ((err = pthread_mutexattr_destroy(&attr)) != 0) {
        printf("error occur in pthread_mutexattr_destroy[%d]: %s", errno, strerror(errno));
        return err;
    }

    return 0;
}

int usr_thread_mutex_destroy(pthread_mutex_t *mtx)
{
    int                     err;
    if ((err = pthread_mutex_destroy(mtx)) != 0) {
        printf("error occur in pthread_mutex_destroy[%d]: %s", errno, strerror(errno));
        return err;
    }
    
    return 0;
}

int usr_thread_mutex_lock(pthread_mutex_t mtx)
{
    int                     err;
    if ((err = pthread_mutex_lock(mtx)) != 0) {
        printf("error occur in pthread_mutex_lock[%d]: %s", errno, strerror(errno));
        return err;
    }
    
    return 0;
}

int usr_thread_mutex_unlock(pthread_mutex_t mtx)
{
    int                     err;
    if ((err = pthread_mutex_unlock(mtx)) != 0) {
        printf("error occur in pthread_mutex_unlock[%d]: %s", errno, strerror(errno));
        return err;
    }
    
    return 0;

}

int main(int argc, char ** argv)
{
}

