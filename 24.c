/*
MT2024049
Mohit Gupta
Write a program to create a message queue and print the key and message queue id.
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
    printf("Key for given path and project id is :%d \n", key);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Message queue id : %d\n", msgid);
    return 0;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 24.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Key for given path and project id is :16918610 
Message queue id : 0

*/
