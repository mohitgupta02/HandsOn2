/*
MT2024049
Mohit Gupta
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
void main()
{
	printf("Process ID: %d", getpid());
	for(;;);
}

/* 

*/
