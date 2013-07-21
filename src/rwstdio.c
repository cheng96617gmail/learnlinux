/*
 * rwstdio.c
 *
 *  Created on: 2013年7月9日
 *      Author: root
 *      Content:读写有缓存的标准输入输出
 */

#include "apue.h"

int main(void){
	int c;
	while((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");

	exit(0);
}

