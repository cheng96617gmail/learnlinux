#include "apue.h"
#include <fcntl.h>

char *buf1 = "1234567890";
char *buf2 = "ABCDEFGHIJ";

int main(void) {
	int fd;
	if ((fd = open("a.hole", O_WRONLY | O_CREAT | O_TRUNC)) < 0)
		err_sys("create error");
	if (write(fd, buf1, 10) != 10)
		err_sys("write buf1 error");
	if(lseek(fd,16384,SEEK_SET)==-1)
		err_sys("seek error");
	if(write(fd,buf2,10)!=10)
		err_sys("write buf2 error");
	exit(0);
}
