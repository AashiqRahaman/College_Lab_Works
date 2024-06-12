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
        printf("new child having p-id %d and parent p-id %d \n", getpid(),getppid());
        sleep(5);
        printf("now after sleep child having p-id %d and child parent pi-d %d\n", getpid(),getppid());
    }

    else if (p > 0)
    {
        printf("parent having id %d \n", p);
        exit(0);
    }
}
 