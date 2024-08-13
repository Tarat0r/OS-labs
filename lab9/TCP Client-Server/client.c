#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

unsigned long long rdtsc(void) {
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ((unsigned long long)lo) | ( ( (unsigned long long) hi) << 32);
}

void func(int sockfd)
{
	char buff[MAX];

    	bzero(buff, sizeof(buff));
    	//printf("Enter the string : ");



    	write(sockfd, "ZDR2\n", 5);
    	bzero(buff, sizeof(buff));
    	read(sockfd, buff, sizeof(buff));
  	 
    	if ((strncmp(buff, "exit", 4)) == 0) {
        	printf("Client Exit...\n");
        	return 0;
    	}
}
   
int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;
   
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
    	printf("socket creation failed...\n");
    	exit(0);
	}
	else
    	printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));
   
	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);
   
	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
    	printf("connection with the server failed...\n");
    	exit(0);
	}
	else
    	printf("connected to the server..\n");
 	 
	unsigned long long res;
	unsigned long long mid;
	unsigned long long int t1, t2;
   
  	   mid=0;
    for (size_t i = 0; i < 1000000; i++) {
      t1=rdtsc();
      t2=rdtsc();
      mid += t2-t1;
    }
    mid /= 1000000;
	// function for chat
  for (size_t i = 0; i < 1000000; i++) {
	t1=rdtsc();
	func(sockfd);
	t2=rdtsc();;
	//printf("%ld,%llu\n",i,t2-t1-mid);
	res = res + t2-t1-mid;
    }
   	printf("time = %llu\n",res/1000000);
	// close the socket
	close(sockfd);
}