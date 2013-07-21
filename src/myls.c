#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]) {
	DIR *dir;
	struct dirent *ent;
	if (argc != 2) {
		err_quit("usage: ls diretory name");
	}

	if ((dir = opendir(argv[1])) == NULL) {
		err_sys("cann't open dir:%s", argv[1]);
	}
	while ((ent = readdir(dir)) != NULL ) {
		printf("%s\n",ent->d_name);
	}
	closedir(dir);
	exit(0);
}
