/*
MT2024049
Mohit Gupta
Write a program to remove the message queue.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    key_t key = ftok(".", 1);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds buf;
    msgctl(msgid, IPC_RMID, &buf);
    return 0;
}
/*

*/
