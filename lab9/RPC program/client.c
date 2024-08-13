#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include "inc.h"

const struct pam_conv conv = {
    misc_conv,
    NULL
};

int main(int argc, char *argv[]{
   pam_handle_t* pamh = NULL;
   int retval;
   const char* user = "nobody";
    if(argc != 2) {
   	 printf("Usage: app [username]\n");
   	 exit(1);
    }
    user = argv[1];
   retval = pam_start("check_user", user, &conv, &pamh);
   if (retval == PAM_SUCCESS){
   retval = pam_authenticate(pamh, 0);
   }
   else printf("Not Authenticated\n");

	if (retval == PAM_SUCCESS){
	struct sockaddr_in servaddr;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(22000);

	inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Request req = {
  	.ack = ACK,
  	.id = 0,
  	.op = PIVO,  
  	.params = {81, 0.5}
	};
	int vid;
	printf("Программа считает сколько промилов в организме!\n");
	printf("Ваш вес(в кг): \n");
	scanf("%f", &req.params[0]);
	printf("Вид алкоголя(PIVO->1, VINO->2, VODKA->3):\n");
	scanf("%d", &vid);
	if (vid == 1) {
  	req.op = PIVO;
  	printf("PIVO\n");
	}
	else if (vid == 2) {
  	req.op = VINO;
  	printf("VINO\n");

	}
	else if (vid == 3) {
  	req.op = VODKA;
  	printf("VODKA\n");
	}
	else{
  	printf("Такого алкоголя нет в баре\n");
  	return 0;
	}

	printf("Количество алкоголя(в литрах)\n");
	scanf("%f", &req.params[1]);

	Response res = {0};

	printRequest(req);
	if (write(sockfd, (byte*)&req, sizeof(Request)));
	if (read(sockfd, (byte*)&res, sizeof(Response)));

	printResponse(res);

	close(sockfd);
	}
	else printf("Not Authenticated\n");
    
 	if (pam_end(pamh, retval) != PAM_SUCCESS) {
    pamh = NULL;
    printf("check_user: failed to release authenticator\n");
    exit(1);
    }

	return 0;
}