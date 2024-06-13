#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void main()
{
    int c;

    pid_t p = fork();
    if (p == 0)
    {
        printf("child having id %d\n", getpid());
        sleep(5);
        printf("new child having parent p-id %d\n", getpid());
    }

    else if (p > 0)
    {
        printf("parent having id %d \n", getppid());
        exit(0);
    }
}
