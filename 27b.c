/*
MT2024049
Mohit Gupta
Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    key_t queueKey;
    int queueIdentifier;
    int messageSize;

    struct msgbuf
    {
        long mtype;
        int someNumber;
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!\n");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!\n");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    data.mtype = 1;

    messageSize = msgrcv(queueIdentifier, &data, sizeof(data), data.mtype, IPC_NOWAIT);

    if (messageSize == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Received number: %d\n", data.someNumber);

    return 0;
}

/*
//while message in the queue
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 27b.c -o 27b
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./27b
Key: 16918610
Message Queue Identifier: 0
Received number: 100
// while message not in queue
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./27b
Key: 16918610
Message Queue Identifier: 0

Error while sending message via Message Queue!
: No message of desired type

*/