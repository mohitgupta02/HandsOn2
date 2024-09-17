/*
============================================================================
	Gupta Mohit
	MT2024049
	6. Write a simple program to create three threads.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function1();
void *thread_function2();
void *thread_function3();

int i,j,m,n;
int main(){
pthread_t a_thread;
pthread_t b_thread;
pthread_t c_thread;
pthread_create(&a_thread,NULL,thread_function1,NULL);
pthread_join(a_thread,NULL);
pthread_create(&b_thread,NULL,thread_function2,NULL);
pthread_join(b_thread,NULL);
pthread_create(&c_thread,NULL,thread_function3,NULL);
pthread_join(c_thread,NULL);
printf("After Thread");
sleep(1);
for(j=11;j<16;j++){
printf("%d\n",j);
}
}

void *thread_function1(){
printf("Inside the thread 1  ");
for(i=0;i<5;i++){
printf("%d\n",i);
}
}

void *thread_function2(){
// wait(2);
printf("Inside the thread 2  ");
for(m=0;m<5;m++){
printf("%d\n",m);
}
}

void *thread_function3(){
// wait(5);
printf("Inside the thread 3  ");
for(n=0;n<5;n++){
printf("%d\n",n);
}
}

/*
============================================================================
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 6.c -lpthread
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
Inside the thread 1  0
1
2
3
4
Inside the thread 2  0
1
2
3
4
Inside the thread 3  0
1
2
3
4
After Thread11
12
13
14
15

============================================================================
*/
