#include <stdio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <pthread.h> 
#include <signal.h> 
#define MAX_LEN 1024 int sockfd;
struct sockaddr_in server_addr; socklen_t addr_len;
char name[32];
volatile sig_atomic_t flag=0;
void str_trim_lf(char* arr,int length) { for (int i=0;i<length;i++) {
if (arr[i]=='\n') {
arr[i]='\0'; break;}}}
void exit_client() {
char exit_msg[]="  exit  ";
sendto(sockfd,exit_msg,strlen(exit_msg),0,(struct sockaddr *)&server_addr,addr_len); flag=1;
close(sockfd);
printf("\nDisconnected from server.\n"); exit(EXIT_SUCCESS);}
void catch_ctrl_c_and_exit(int sig) {exit_client();} void* send_msg_handler(void* arg) {
char buffer[MAX_LEN]; while (1) {
fgets(buffer,MAX_LEN,stdin); str_trim_lf(buffer,MAX_LEN);
if (strcmp(buffer,"exit")==0) { exit_client();
} else {
sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr
*)&server_addr,addr_len);}}
return NULL;}
void* recv_msg_handler(void* arg) { char message[MAX_LEN];
while (1) {
if (flag) break;
int receive=recvfrom(sockfd,message,MAX_LEN,0,NULL,NULL); if (receive>0) {
message[receive]='\0'; printf("%s\n",message);}}
return NULL;}
int main(int argc,char* argv[]) { if (argc!=3) {
printf("Usage: %s <ip> <port>\n",argv[0]); return EXIT_FAILURE;}
const char* ip=argv[1]; int port=atoi(argv[2]);
signal(SIGINT,catch_ctrl_c_and_exit); sockfd=socket(AF_INET,SOCK_DGRAM,0); server_addr.sin_family=AF_INET; server_addr.sin_addr.s_addr=inet_addr(ip); server_addr.sin_port=htons(port); addr_len=sizeof(server_addr); printf("Enter your name: "); fgets(name,32,stdin); str_trim_lf(name,32);
sendto(sockfd,name,strlen(name),0,(struct sockaddr *)&server_addr,addr_len); printf("\n--- Welcome to the chat ---\n");
printf("Type /list to see active users\n");
printf("Type /msg <user> <message> to send a private message\n"); printf("Type 'exit' to quit\n\n");
pthread_t send_msg_thread,recv_msg_thread; pthread_create(&send_msg_thread,NULL,send_msg_handler,NULL); pthread_create(&recv_msg_thread,NULL,recv_msg_handler,NULL); pthread_join(send_msg_thread,NULL); pthread_join(recv_msg_thread,NULL);
close(sockfd); return EXIT_SUCCESS;
}
