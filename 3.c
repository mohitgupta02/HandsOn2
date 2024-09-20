/*
MT2024049
Mohit Gupta
Write a program to print the system resource limits. Use getrlimit system call.
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);
}

void main()
{
    int status;
    struct rlimit resourceLimits;
    printf("before updatimg limits");
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    printf("Choosing new resource limits\n");
    struct rlimit newresourceLimits; 
    newresourceLimits.rlim_cur=10000;
    newresourceLimits.rlim_max=20000;
    status = setrlimit(RLIMIT_SIGPENDING, &newresourceLimits);

    printf("after updatimg limits");
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 3.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
before updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 15194 bytes
	Hard Limit: 15194 bytes
Choosing new resource limits
after updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 15194 bytes
	Hard Limit: 15194 bytes

*/
