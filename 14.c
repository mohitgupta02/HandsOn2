/*
    MT2024049
    Mohit Gupta
    Write a simple program to create a pipe, write to the pipe, read from pipe and display on
    the monitor.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int pipefd[2];
    char *buff;
    char buf[10];

    if (pipe(pipefd) == -1)
    {
        printf("pipe error");
        exit(1);
    }
    printf("enter string of size 10 character\n");
    scanf("%s", buf);
    write(pipefd[1], buf, 10);
    write(pipefd[1], "\n", 1);
    close(pipefd[1]);

    printf("Display on Monitor\n");
    while (read(pipefd[0], &buff, 1))
    {
        write(1, &buff, 1);
    }
    return 0;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 14.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
enter string of size 10 character
mohitgupta
Display on Monitor
mohitgupta

*/
