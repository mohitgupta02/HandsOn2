/*
MT2024049
Mohit Gupta
Write a program to send and receive data from parent to child vice versa.Use two way communication.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2], a[2], l;
    pid_t cpid;
    char buf;
    char *s;
    long int size = 50;
    s = (char *)malloc(size);
    if (pipe(pipefd) == -1)
    {
        perror("pipe pipefd");
        exit(EXIT_FAILURE);
    }

    if (pipe(a) == -1)
    {
        perror("pipe a");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0)
    {
        sleep(5);
        printf("writing in pipe from child process\n");
        l = getline(&s, &size, stdin);
        close(a[0]);
        write(a[1], s, l);
        close(a[1]);

        sleep(5);
        close(pipefd[1]);
        printf("display in child \n");
        while (read(pipefd[0], &buf, 1) > 0)
            write(1, &buf, 1);

        write(1, "\n", 1);
        close(pipefd[0]);
    }
    else
    {
        printf("writing in pipe from parent process\n");
        l = getline(&s, &size, stdin);
        close(pipefd[0]);
        write(pipefd[1], s, l);
        close(pipefd[1]);

        sleep(5);
        close(a[1]);
        printf("display in parent \n");
        while (read(a[0], &buf, 1) > 0)
            write(1, &buf, 1);
        write(1, "\n", 1);
        close(a[0]);

        wait(0);
    }
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 16.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
writing in pipe from parent process
hjkl
writing in pipe from child process
sdfg'
display in parent 
sdfg'

display in child 
hjkl

*/
