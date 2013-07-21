/*
 * apue.h
 *
 *  Created on: 2013年7月7日
 *      Author: root
 */

#ifndef APUE_H_
#define APUE_H_
#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>
#ifndef TIOCGWINS2
#include <sys/ioctl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#define MAXLINE 4096

/*定义新文件的默认权限*/
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
/*定义新文件夹的默认权限*/
#define DIR_MODE (FILE_MODE|S_IXURS|S_IXGRP|S_IXOTH)
/*定义信号处理函数*/
typedef void Sigfunc(int);

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((Sigfunc *)-1)
#endif

#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))


void err_dump(const char *,...);
void err_msg(const char *,...);
void err_quit(const char *,...);
void err_exit(int,const char *,...);
void err_ret(const char *,...);
void err_sys(const char *,...);



#endif /* APUE_H_ */
