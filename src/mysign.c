//添加信号处理的进程处理程序

#include "apue.h"
#include <sys/wait.h>

static void sig_init(int);
int main(void) {
	char buf[MAXLINE];
	int status;
	pid_t pid;

	if (signal(SIGINT, sig_init) == SIG_ERR) {
		err_sys("signal error");
	}

	printf("%%");
	while (fgets(buf, MAXLINE, stdin) != NULL ) {
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		}
		if (pid == 0) {
			execlp(buf, buf, (char *) 0);
			err_ret("command cann't execute:  ", buf);
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("waitpid error");
		}
		printf("%%");

	}
	exit(0);
}

static void sig_init(int sig) {
	printf("interrupt\n %% %d\n", sig);
}
