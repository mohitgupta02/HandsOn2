/*
MT2024049
Mohit Gupta
Write a simple program to print the created thread ids.

*/


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
}

void main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 7.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Printing from thread :132019531024064
Printing from thread :132019520538304
Printing from thread :132019510052544

*/
