/*
MT2024049
Mohit Gupta    
Write a program to create a shared memory.
a.write some data to the shared memory
b.attach with O_RDONLY and check whether you are able to overwrite.
c.detach the shared memory
d.remove the shared memory
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main()
{
    key_t key = ftok(".", 2);
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    char *data;
    data = shmat(shmid, (void *)0, SHM_RDONLY);
    if (data == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }

    printf("write in shared memory\n");
    scanf("%[^\n]", data);
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 30b.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
write in shared memory
new data in shared
Segmentation fault (core dumped)

*/
