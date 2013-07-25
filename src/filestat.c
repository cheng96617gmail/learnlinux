#include "apue.h"
#include <time.h>

int main(int argc, char *argv[]) {
	int i;
	struct stat buf;
	char *ptr;
	if (argc < 2) {
		err_sys("filestat usargv:<filename>");
	}
	for (i = 1; i < argc; i++) {
		printf("%s:",argv[i]);
		if(lstat(argv[i],&buf)<0){
			err_ret("%s is not filename",argv[1]);
			continue;
		}
		if(S_ISREG(buf.st_mode))
			ptr="regular";
		else if(S_ISDIR(buf.st_mode))
			ptr="dir";
		else if(S_ISCHR(buf.st_mode))
			ptr="character special";
		else if(S_ISBLK(buf.st_mode))
			ptr="block special";
		else if(S_ISFIFO(buf.st_mode))
			ptr="fifo special";
		else if(S_ISLNK(buf.st_mode))
			ptr="link special";
		else if(S_ISSOCK(buf.st_mode))
			ptr="sock special";
		printf("is %s\n",ptr);
		printf("st_ino:%d, ",(int)buf.st_ino);
		printf("st_dev:%d, ",(int)buf.st_dev);
		printf("st_rdev:%d, ",(int)buf.st_rdev);
		printf("st_nlink:%d, ",(int)buf.st_nlink);
		printf("st_uid:%d, ",(int)buf.st_uid);
		printf("st_gid:%d, ",(int)buf.st_gid);
		printf("st_size:%d, ",(int)buf.st_size);
		printf("st_atime:%s, ",ctime(&buf.st_atime));

		//printf("st_atime:"+buf.st_atime);
		//printf("st_ctime:"+buf.st_ctime);
		//printf("st_mtime:"+buf.st_mtime);
		printf("st_blksize:%d, ",(int)buf.st_blksize);
		printf("st_blocks:%d, ",(int)buf.st_blocks);
	}
	exit(0);
}
