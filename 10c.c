/*
MT2024049
Mohit Gupta
Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("Caught SIGFPE\n");
}
void main()
{
    int status;
    struct sigaction act;

    act.sa_handler = print; 
    act.sa_flags = 0;
    status = sigaction(SIGFPE, &act, NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGFPE);
    }
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 10c.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Caught SIGFPE

*/
