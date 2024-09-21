/*
MT2024049
Mohit Gupta
Write a program to create a concurrent server.
a.use fork
b.use pthread_create
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int socktd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktd == -1)
    {
        perror("Erroe when creating socket");
        _exit(0);
    }
    printf("Socket created\n");

    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server established\n");

    char buf[100];
    read(socktd, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write massage for server: \n");
    scanf("%[^\n]", buf);

    write(socktd, buf, sizeof(buf));
    printf("Data sent to server\n");

    close(socktd);
}
/*

mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 34b_client.c -o clientb
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./clientb
Socket created
Connection with server established
Data from server: Hello from server

Write massage for server: 
new message
Data sent to server

*/
