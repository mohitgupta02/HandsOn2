/*
MT2024049
Mohit Gupta
 Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    __sighandler_t status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    status=signal(SIGINT, SIG_IGN);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }

    printf("reseting the default action of the SIGINT signal\n");
    status = signal(SIGINT, SIG_DFL);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 9.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal

*/
