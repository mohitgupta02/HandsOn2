/*
MT2024049
Mohit Gupta
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
void main()
{
    pid_t pid;
    printf("Enter process id\n");
    scanf("%d",&pid);
    int status = kill(pid, SIGSTOP);
    if (status == -1)
    {
        perror("Error while sending kill signal!");
    }
}
/*

mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 13a.c -o 13a
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 13b.c -o 13b
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./13a &
[1] 3963
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ 
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./13b
Enter process id
3963

[1]+  Stopped                 ./13a
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ cat /proc/3963/status
Name:	13a
Umask:	0002
State:	T (stopped)
Tgid:	3963
Ngid:	0
Pid:	3963
PPid:	3259
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256

*/
