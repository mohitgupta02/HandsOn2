/*
MT2024049
Mohit Gupta
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;

    start = rdtsc();
    int iter = 1;
    while (iter <= 100)
    {
        getppid();
        iter += 1;
    }

    end = rdtsc();

    printf("time required : %llu\n", end - start);
}

/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 4.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
time required : 297862

*/
