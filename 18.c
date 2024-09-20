
/*
    MT2024049
    Mohit Gupta
    Write a program to find out total number of directories on the pwd.
    execute ls -l | grep ^d | wc ? Use only dup2.
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2];
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);

    if (pipeOneStatus == -1 || pipeTwoStatus)
        perror("Error while creating the pipe!\n");
    else
    {
        childOne = fork();

        if (childOne == -1)
            perror("Error while creating first child!\n");
        else if (childOne == 0)
        {
            close(pipeCmdTwoToThree[1]);
            close(pipeCmdOneToTwo[0]);
            close(pipeCmdOneToTwo[1]);

            close(STDIN_FILENO);
            dup2(pipeCmdTwoToThree[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            childTwo = fork();

            if (childTwo == -1)
                perror("Error while creating second child!\n");
            else if (childTwo == 0)
            {
                close(pipeCmdOneToTwo[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDIN_FILENO);
                dup2(pipeCmdOneToTwo[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else
            {
                close(pipeCmdOneToTwo[0]);
                close(pipeCmdTwoToThree[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDOUT_FILENO);
                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO);

                execl("/usr/bin/ls", "ls -l", "-l", NULL);
            }
        }
    }
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 18.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
      0       0       0
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ls -l
total 324
-rw-rw-r-- 1 mohit mohit  1931 Sep 20 17:31 18.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ mkdir temp
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
      1       9      49
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ls -l
total 328
-rw-rw-r-- 1 mohit mohit  1931 Sep 20 17:31 18.c

mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ls -l | grep ^d | wc
      1       9      49

*/
