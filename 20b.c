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
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); 

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
    }
}
/*
ohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ nano 20b.c
mohit
hello
*/
