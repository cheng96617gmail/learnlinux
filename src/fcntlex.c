#include <fcntl.h>
#include "apue.h"
static void getfl(int fd);
static void setfl(int fd, int flags);
int main(int argc, char *argv[]) {

	if (argc != 2) {
		err_sys("fcntl usarge:<descripter>\n");
	}
	int fd=atoi(argv[1]);
	getfl(fd);
	setfl(fd,O_NONBLOCK);
	getfl(fd);
	exit(0);
}
static void getfl(int fd){
	int val;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
			err_sys("fcntl error for fd %d\n", fd);
		switch (val & O_ACCMODE) {
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDONLY:
			printf("read only");
			break;
		case O_RDWR:
			printf("write read");
			break;
		default:
			err_dump("unknown access mode");
		}
		if (val & O_APPEND) {
			printf(",append");
		}
		if (val & O_NONBLOCK)
			printf(",noblock");

	#ifdef O_SYNC
		if (val & O_SYNC)
			printf(",sync");
	#endif
	#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
		printf(",fsync");
	#endif
		putchar('\n');
}
static void setfl(int fd, int flags) {
	int val;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
		err_sys("fcntl error fd %d", fd);
	}
	val |= flags;
	if (fcntl(fd, F_SETFL, val) == -1) {
		err_sys("setfl error\n");
	}
}
