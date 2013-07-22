#include "apue.h"

int main(void) {
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("seek error");
	else
		printf("seek ok");
	exit(0);
}
