#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int c;
	for (c=0;c<5;c++)
	{	pid_t p=fork();
		if (p==0)
			printf("child (pid=%u)\n",getpid());
		else
			printf("parent (pid=%u) created child (pid=%u)\n",getpid(),p);
		
		
	}
	return 0;
}
