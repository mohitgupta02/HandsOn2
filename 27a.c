/*
MT2024049
Mohit Gupta
Write a program to receive messages from the message queue.
a. with 0 as a flag
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main()
{
    mesg_buffer message;
    key_t key = ftok(".", 1);
    int msgid = msgget(key, 0666 | IPC_CREAT);
//    printf("enter msgtype:\n");
//    scanf("%ld", &message.mesg_type);
    int size_s = msgrcv(msgid, &message, sizeof(message), message.mesg_type, 0); 
    if (size_s <= 0)
    {
        perror("No message in queue\n");
    }
    else
    {
        printf("Message: %s\n", message.mesg_text);
    }
    return 0;
}
/*

*/
