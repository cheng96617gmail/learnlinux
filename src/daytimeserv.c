/*
 * daytimeserv.c
 *
 *  Created on: 2013年8月30日
 *      Author: root
 */


#include "apue.h"
#include <sys/time.h>
int main(int argc,char *argv[]){
	int listenfd,connfd;
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	time_t ticks;

	listenfd=Socket(AF_INET,SOCK_STREAM,0);
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(13);
	Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	Listen(listenfd,LISTENQ);
	for(;;){
		connfd=Accept(listenfd,(SA *)NULL,NULL);
		ticks=time(NULL);
		snprintf(buf,MAXLINE,"%.24s\r\n",ctime(&ticks));
		Write(connfd,buf,strlen(buf));
		close(connfd);
	}
}
