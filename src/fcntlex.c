#include <fcntl.h>
#include "apue.h"

int main(int argc, char *argv[]) {
	int val;
	if (argc != 2) {
		err_sys("fcntl usarge:<descripter>\n");
	}
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for fd %d\n", atoi(argv[1]));
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
	exit(0);
}
