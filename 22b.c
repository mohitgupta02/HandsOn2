/*
MT2024049
Mohit Gupta
Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    int f;
    char *s = "./22-fifo";
    mkfifo(s, S_IRWXU);
    f = open(s, O_NONBLOCK | O_WRONLY);

    if (f == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }
    char *st;
    long int size=100;
    printf("enter message\n");
    int l=getline(&st,&size,stdin);
    write(f, st, l);
    close(f);
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc -o 22b 22b.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./22b
enter message
hello
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ 


*/
