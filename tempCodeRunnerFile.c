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
    key_t key = ftok(".", 1); // projext path is current directory and project id=1
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("enter msgtype:\n");
    scanf("%ld", &message.mesg_type);
    int size_s = msgrcv(msgid, &message, sizeof(message), message.mesg_type, IPC_NOWAIT); 
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