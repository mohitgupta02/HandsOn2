/*
MT2024049
Mohit Gupta
Write two programs so that both can communicate by FIFO -Use two way communication.
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
    char *file = "./21a-fifo";
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

        fd = open(file, O_RDONLY); 

        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd);
        }
    }
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc -o 21a 21a.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc -o 21b 21b.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./21a
mohit
enter message:
gupta

enter message:

*/
