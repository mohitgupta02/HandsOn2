/*
Name: Mohit Gupta
Roll No.: MT2024049
Program Description: Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
                            c. ITIMER_PROF

*/

#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int timerStatus;

    struct itimerval timer;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        printf("Error while setting an interval timer!\n");
    
    int count = 1;
    while(1)
    {
        printf("%d\n", count++);
        sleep(1);
    }
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 1c.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 1
1
2
3
4
5
6
7
8
9
10
Alarm clock
*/