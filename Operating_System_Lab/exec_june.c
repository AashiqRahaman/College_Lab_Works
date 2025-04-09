
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

int main()
{
    int pipefd[2];
    pid_t pid_ls, pid_wc;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_ls = fork();
    if (pid_ls == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid_ls == 0)
    {
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execlp("ls", "ls", "-l", NULL);

        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    pid_wc = fork();
    if (pid_wc == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid_wc == 0)
    {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        execlp("wc", "wc", "-l", NULL);

        perror("execlp wc");
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid_ls, NULL, 0);
    waitpid(pid_wc, NULL, 0);

    return 0;
}
