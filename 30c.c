/*
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
    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to detach it\n");
    getchar();
    printf("Detaching pointer to shared memory\n");
    shmdt(data_pointer);
    return 1;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 30c.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Shared memory attached press any key to detach it
t
Detaching pointer to shared memory

*/
