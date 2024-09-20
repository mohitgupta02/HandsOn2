/*
MT2024049
Mohit Gupta
Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
void main()
{
    key_t shaKey = ftok(".", 666);
    int shmid = shmget(shaKey, 1024, IPC_CREAT | 0744);
    char *shmPointer;
    shmPointer = shmat(shmid, (void *)0, 0);
    key_t semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } semSet;

    semKey = ftok(".", 333);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, 0);
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 2;
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("entering to obtain lock on the critical section\n");

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Obtained lock on critical section!\n");
    //  Start of Critical Section 

    printf("inside Critical section");
    getchar();
    int data;
    int fd = open("./32c_ticket.txt", O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file!");
    }

    int n = read(fd, &data, sizeof(data));
    if (n == 0)
    {
        data = 1;
    }
    else
    {
        data += 1;
        lseek(fd, 0, SEEK_SET); // reset seek
    }
    write(fd, &data, sizeof(data));
    printf("ticket number is : %d\t \n", data);
    printf("ticket number is stored in file\n");

    //  End of Critical Section 

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 32c.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
entering to obtain lock on the critical section
Obtained lock on critical section!
inside Critical sectionthis is critical secc
ticket number is : 1	 
ticket number is stored in file

*/
