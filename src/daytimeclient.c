/*
 * daytimeclient.c
 *
 *  Created on: 2013年8月30日
 *      Author: root
 */

#include "apue.h"

int main(int argc, char *argv[]) {
	int sockfd, n;
	char revline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	if (argc < 2) {
		err_quit("usage: daytimeclient <IP address>");
	}
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		err_sys("socket error");
	}
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(13);
	if(inet_pton(AF_INET,argv[1],&(servaddr.sin_addr))<=0)
		err_quit("inet_pton error for %s",argv[1]);
	if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))<0)
		err_sys("connect error");
	while((n=read(sockfd,revline,MAXLINE))>0){
		revline[n]=0;
		if(fputs(revline,stdout)<0){
			err_sys("fputs error");
		}

	}
	if(n<0)
		err_sys("read error");
	exit(0);
}
