/*
    MT2024049
    Mohit Gupta
    Create a FIFO file by
    a.mknod command
    b.mkfifo command
    c.use strace command to find out,which command(mknod or mkfifo) is better.
    c.mknod system call
    d.mkfifo library function
*/

#include <stdio.h>
#include <sys/stat.h>
int main()
{
    int o = mkfifo("./mkfifo_syscall", S_IRWXU);
    if (o == 0)
    {
        printf("fifo special file is created\n");
    }

    int f = mknod("./fifo_using_mknode_sys_call", S_IRWXU | S_IFIFO, 0);
    if (f == 0)
    {
        printf("fifo special file is created\n");
    }
}
/*
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ gcc 19.c
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ./a.out 
fifo special file is created
fifo special file is created

mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ mknod 19mknod p
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ls -l 19mknod
prw-rw-r-- 1 mohit mohit 0 Sep 20 17:49 19mknod

mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ mkfifo 19mkfifo
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ ls -l 19mkfifo
prw-rw-r-- 1 mohit mohit 0 Sep 20 17:49 19mkfifo



mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ strace -c mknod 
mknod: missing operand
Try 'mknod --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 54.24    0.000787         787         1           execve
 19.09    0.000277          14        19           mmap
  7.17    0.000104           5        19        11 openat
  4.76    0.000069           9         7           read
  3.24    0.000047           4        10           close
  3.24    0.000047          23         2         2 statfs
  2.34    0.000034           4         8           fstat
  2.14    0.000031          10         3           brk
  1.10    0.000016           8         2           pread64
  0.76    0.000011           5         2         2 access
  0.48    0.000007           7         1           arch_prctl
  0.41    0.000006           6         1           getrandom
  0.41    0.000006           6         1           rseq
  0.34    0.000005           5         1           set_tid_address
  0.28    0.000004           4         1           set_robust_list
  0.00    0.000000           0         4           write
  0.00    0.000000           0         5           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         1           prlimit64
------ ----------- ----------- --------- --------- ----------------
100.00    0.001451          16        89        15 total
mohit@mohit-VMware-Virtual-Platform:~/Desktop/HandsOn2$ strace -c mkfifo
mkfifo: missing operand
Try 'mkfifo --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 44.80    0.003038        3038         1           execve
 24.76    0.001679          88        19           mmap
  9.70    0.000658          34        19        11 openat
  6.21    0.000421          52         8           fstat
  3.57    0.000242          24        10           close
  3.05    0.000207          29         7           read
  2.24    0.000152          38         4           write
  1.40    0.000095          31         3           brk
  1.00    0.000068          68         1           munmap
  0.81    0.000055          27         2         2 access
  0.80    0.000054          27         2         2 statfs
  0.74    0.000050          25         2           pread64
  0.19    0.000013          13         1           getrandom
  0.16    0.000011          11         1           arch_prctl
  0.16    0.000011          11         1           prlimit64
  0.15    0.000010          10         1           set_robust_list
  0.13    0.000009           9         1           set_tid_address
  0.13    0.000009           9         1           rseq
  0.00    0.000000           0         5           mprotect
------ ----------- ----------- --------- --------- ----------------
100.00    0.006782          76        89        15 total

*/
