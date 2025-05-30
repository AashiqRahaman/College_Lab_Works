#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#define LENGTH 2048
volatile sig_atomic_t flag = 0;
int sockfd = 0;
char name[32];
void str_trim_lf(char *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == '\n')
        {
            arr[i] = '\0';
            break;
        }
    }
}
void catch_ctrl_c_and_exit(int sig) { flag = 1; }
void send_msg_handler()
{
    char buffer[LENGTH] = {};
    while (1)
    {
        fgets(buffer, LENGTH, stdin);
        str_trim_lf(buffer, LENGTH);
        if (strcmp(buffer, "exit") == 0)
            break;
        else
            send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, LENGTH);
    }
    catch_ctrl_c_and_exit(2);
}
void recv_msg_handler()
{
    char buffer[LENGTH] = {};
    while (1)
    {
        int receive = recv(sockfd, buffer, LENGTH, 0);
        if (receive > 0)
        {
            printf("%s", buffer);
            fflush(stdout);
        }
        else if (receive == 0)
        {
            break;
        }
        bzero(buffer, LENGTH);
    }
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);
    signal(SIGINT, catch_ctrl_c_and_exit);
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }
    printf("Enter your name: ");
    fgets(name, 32, stdin);
    str_trim_lf(name, strlen(name));
    send(sockfd, name, 32, 0);
    printf("\n--- Welcome to the chat ---\n");
    printf("Type /list to see active users\n");
    printf("Type /msg <username> <message> to send private message\n");
    printf("Type 'exit' to quit\n\n");
    pthread_t send_msg_thread;
    if (pthread_create(&send_msg_thread, NULL, (void *)send_msg_handler, NULL) != 0)
    {
        printf("ERROR: pthread\n");
        return EXIT_FAILURE;
        pthread_t recv_msg_thread;
        if (pthread_create(&recv_msg_thread, NULL, (void *)recv_msg_handler, NULL) != 0)
        {
            printf("ERROR: pthread\n");
            return EXIT_FAILURE;
        }
        while (1)
        {
            if (flag)
            {
                printf("\nBye\n");
                break;
            }
        }
        close(sockfd);
        return EXIT_SUCCESS;
    }}
