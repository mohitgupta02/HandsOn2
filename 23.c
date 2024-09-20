/*
MT2024049
Mohit Gupta
Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;
    long sizeOfPipe;
    char *s = "23_fifo";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);

    printf("Maximum size of pipe: %d\n", PIPE_BUF);
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 23.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 4096

*/
