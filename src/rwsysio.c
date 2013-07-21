//读写没有缓冲的标准io

#include "apue.h"

#define BUFSIZE 4096

int main(void) {
	int n;
	char buf[BUFSIZE];
	while((n=read(STDIN_FILENO,buf,BUFSIZE))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");

	exit(0);
}
