/*
MT2024049
Mohit Gupta
Write a program to create a message queue and print the key and message queue id.
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
    int messageSendStatus;

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
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Message sent!\n");

    return 0;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 26.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Key: 16918610
Message Queue Identifier: 0

Message sent!

*/
