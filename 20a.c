/*
MT2024049
Mohit Gupta
Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *s;
    int fd;
    long int size = 100;
    char *file = "./20-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }
    }
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ nano 20a.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./20a
enter message:
mohit
enter message:
hello
enter message:


*/
