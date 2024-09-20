/*
MT2024049
Mohit Gupta
Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid());
        int status=kill(getppid(),SIGKILL);
        if(status==0){
            printf("Parent is killed Chiled is now orphan\n");
            sleep(10);
        }else{
            perror("Error while killing parent process!");
        }
    }
    else
    {
        while(1);
    }
    return 0;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 12.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
inside child pid= 3826
parent id= 3825
Parent is killed Chiled is now orphan
Killed

*/
