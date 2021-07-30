#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void * mythread(void* arg){
    while(1)
    {
        printf("mythread PID: %d\n", (int)getpid());
        printf("mythread TID: %d\n", (int)syscall(SYS_gettid));
        sleep(5);
    }
}

int main(){
    pthread_t thread;

    pthread_create(&thread, NULL, &mythread, NULL);

    while (1)
    {
        printf("main PID: %d\n", (int)getpid());
        printf("main TID: %d\n", (int)syscall(SYS_gettid));
        sleep(10);
    }
    
    return 0;
}