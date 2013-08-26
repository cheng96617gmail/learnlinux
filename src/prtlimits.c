/*
 * prtlimits.c
 *
 *  Created on: 2013年8月26日
 *      Author: root
 */

#include "apue.h"
#if defined(BSD) || defined(MACOS)
#include <sys/time.h>
#define FMT "%10lld"
#else
#define FMT "%10ld"
#endif
#include <sys/resource.h>

#define doit(name) myfunc(#name,name)

void myfunc(char *,int);

int main(int argc,char *argv[]){
#ifdef RLIMIT_AS
	doit(RLIMIT_AS);
#endif
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);
#ifdef RLIMIT_LOCKS
	doit(RLIMIT_LOCKS);
#endif
#ifdef RLIMIT_MEMLOCKS
	doit(RLIMIT_MEMLOCKS);
#endif
	doit(RLIMIT_NOFILE);
	doit(RLIMIT_NPROC);
	doit(RLIMIT_RSS);
	doit(RLIMIT_STACK);
	exit(0);
}
void myfunc(char *name,int resource){
	struct rlimit limit;
	if(getrlimit(resource,&limit)<0){
		err_sys("getrlimit error for %s",name);
	}
	printf("%-14s ",name);
	if(limit.rlim_cur==RLIM_INFINITY){
		printf("(infinite) ");
	}else
		printf(FMT,limit.rlim_cur);

	if(limit.rlim_max==RLIM_INFINITY){
		printf("(infinite) ");
	}else
		printf(FMT,limit.rlim_max);
	putchar('\n');
}

