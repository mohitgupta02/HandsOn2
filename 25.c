/*
MT2024049
Mohit Gupta
Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
*/

#include <sys/msg.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <time.h>
typedef struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main(int argc, char const *argv[])
{
    mesg_buffer message;
    key_t key = ftok(".", 1);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);
    struct ipc_perm msg_perm = buf.msg_perm;
    time_t msg_stime = buf.msg_stime;
    time_t msg_rtime = buf.msg_rtime;
    time_t msg_ctime = buf.msg_ctime;
    unsigned long msg_cbytes = buf.msg_cbytes;
    msgqnum_t msg_qnum = buf.msg_qnum;
    msglen_t msg_qbytes = buf.msg_qbytes;
    pid_t msg_lspid = buf.msg_lspid;
    pid_t msg_lrpid = buf.msg_lrpid;
    printf("access permission %d\n", msg_perm.mode);
    printf("uid : %d gid : %d \n", msg_perm.uid, msg_perm.gid);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of last msgsnd(2) %ld\n", msg_stime);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of creation or last modification by msgctl() %ld\n", msg_ctime);
    printf("number of bytes in queue %ld\n", msg_cbytes);
    printf("number of messages in queue %ld\n", msg_qnum);
    printf("Maximum number of bytes in queue %ld\n", msg_qbytes);
    printf("PID of last msgsnd(2) %d\n", msg_lspid);
    printf("PID of last msgrcv(2) %d\n", msg_lrpid);
    return 0;
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 25.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
access permission 438
uid : 1000 gid : 1000 
Time of last msgrcv(2) 0
Time of last msgsnd(2) 0
Time of last msgrcv(2) 0
Time of creation or last modification by msgctl() 1726836048
number of bytes in queue 0
number of messages in queue 0
Maximum number of bytes in queue 16384
PID of last msgsnd(2) 0
PID of last msgrcv(2) 0

*/
