/*
 * 我的自己的proc
 */

#include "apue.h"
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	char buf[MAXLINE];
	int status;

	while (fgets(buf, MAXLINE, stdin) != NULL ) {
		printf("%% ");
		if (buf[strlen(buf) - 1] == '\n') {
			buf[strlen(buf) - 1] = 0;
		}

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		}
		if (pid == 0) {
			execlp(buf, buf, (char *) 0);
			err_ret("can't execute command: ", buf);
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("wait error");
		}
	}
	exit(0);
}
