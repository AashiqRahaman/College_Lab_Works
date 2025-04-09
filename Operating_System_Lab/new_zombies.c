#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int c;
    for (c = 0; c < 5; c++)
    {
        pid_t p = fork();
        if (p == 0)
            printf("child having id %d\n", getpid());

        else
        {

            printf("parent having id %d \n", getpid());
            sleep(20);
        }
    }
    return 0;
}
