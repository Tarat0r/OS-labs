#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inc.h"

int pivo(const Request* req, Response* res) {
  printf("Весь = %f / Кол-во = %f\n", req->params[0], req->params[1]);
  float kg = req->params[0];
  float pivo = req->params[1];
  kg = kg * 0.7;
  pivo = pivo * 0.045 * 0.79 * 1000;
  pivo = pivo - pivo * 0.1;
  res->data = pivo/kg;
  printf("PIVO = %f промила\n", res->data );
  return true;
}
int vino(const Request* req, Response* res) {
  printf("Весь = %f / Кол-во = %f\n", req->params[0], req->params[1]);
  float kg = req->params[0];
  float vino = req->params[1];
  kg = kg * 0.7;
  vino = vino * 0.11 * 0.79 * 1000;
  vino = vino - vino * 0.1;
  res->data = vino/kg;
  printf("VINO = %f промила\n", res->data );
  return true;
}

int vodka(const Request* req, Response* res) {
  printf("Весь = %f / Кол-во = %f\n", req->params[0], req->params[1]);
  float kg = req->params[0];
  float vodka = req->params[1];
  kg = kg * 0.7;
  vodka = vodka * 0.4 * 0.79 *1000;
  vodka = vodka - vodka * 0.1;
  res->data = vodka/kg;
  printf("VODKA = %f промила\n", res->data );
  return true;
}

int handleRequest(const Request* req, Response* res) {
  switch (req->op) {
	case PIVO:
  	return pivo(req, res);
	case VINO:
  	return vino(req, res);
	case VODKA:
  	return vodka(req, res);
	default:
  	return false;
  }
}


int main() {
  struct sockaddr_in servaddr;
  int listen_fd = socket(AF_INET, SOCK_STREAM, 0); 

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family  	= AF_INET;

  servaddr.sin_addr.s_addr = htons(INADDR_ANY);

  servaddr.sin_port    	= htons(22000);

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));7
  listen(listen_fd, 1);

  int comm_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL); 

  Request req  = {0};
  Response res = {0};

  if (read(comm_fd, (byte*)&req, sizeof(Request)));

  if (req.ack == ACK) {

	printRequest(req);

	res.ack = req.ack;
	res.id = req.id;

	if (handleRequest(&req, &res)) {
  	res.status = true;
	}
	else {
  	res.status = false;
	}

	printResponse(res);

	if (write(comm_fd, (byte*)&res, sizeof(Response)));
  }
  else {
	printf("Unrecognized ACK (%d). Failing here\n", req.ack);
  }

  close(comm_fd);

  return 0;
}