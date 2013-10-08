/*
 * apue.c
 *
 *  Created on: 2013年7月8日
 *      Author: root
 */

#include "apue.h" 
#include <stdarg.h>
#include <errno.h>
#include <limits.h>

static void err_doit(int, int, const char *, va_list);

void err_dump(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

void err_ret(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

void err_sys(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_exit(int error, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_msg(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);

}

void err_quit(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

static void err_doit(int errflags, int error, const char *fmt, va_list ap) {
	char buf[MAXLINE];

	vsnprintf(buf, MAXLINE, fmt, ap);

	if (errflags)
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
				strerror(error));

	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
}

char* path_alloc(int *len){
	char *rs;
	*len=PATH_MAX+1;
	rs=(char *)calloc(*len,sizeof(char));
	if(rs==0){
		err_sys("virtual memory exhausted");
	}
	return rs;
}

int Socket(int namespace,int style,int protocol){
	int n;
	if((n=socket(namespace,style,protocol))<0)
		err_sys("socket error");
	return n;
}

int Bind(int socket,SA *addr,socklen_t len){
	int n;
	if((n=bind(socket,addr,len))<0)
		err_sys("bind error");
	return n;
}

int Listen(int socket,int n){
	int r;
	if((r=listen(socket,n))<0)
		err_sys(" error");
	return r;
}

int Accept(int socket,SA *addr,socklen_t *len){
	int n;
	if((n=accept(socket,addr,len))<0)
		err_sys("accept error");
	return n;
}

size_t Write(int filedes,const char *buffer,size_t size){
	size_t n;
	if((n=write(filedes,buffer,size))<0)
		err_sys("write error");
	return n;
}
int Close(int filedes){
	int n;
	if((n=close(filedes))<0)
		err_sys("close error");
	return n;
}
