/*
 * mychmod.c
 *
 *  Created on: 2013年7月24日
 *      Author: root
 */

#include "apue.h"
#include <fcntl.h>

int RWRWRW=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
static void umaskcreat(void);
static void chmodfile(void);
int main(int argc,char *argv[])
{
	printf("usage: mychmod [-c chmod]\n");
	if(argc<2){
		umaskcreat();
		exit(0);
	}
	if(strcmp(argv[1],"-c")==0){
		chmodfile();
	}
	exit(0);
}
static void umaskcreat(void){
	umask(0);
	if(creat("foo",RWRWRW)<0){
		err_sys("create foo fail");
	}
	umask(S_IWGRP|S_IWOTH);
	if(creat("bar",RWRWRW)<0){
		err_sys("create bar fail");
	}
}
static void chmodfile(void){
	struct stat buf;
	if(lstat("foo",&buf)<0){
		err_ret("foo get stat fail");
	}

	if(chmod("foo",(buf.st_mode & ~S_IWGRP) | S_ISGID)<0){
		err_sys("chmod foo fail");
	}
	if(chmod("bar",S_IWGRP|S_IWOTH)){
		err_sys("chmod error for bar");
	}
}
