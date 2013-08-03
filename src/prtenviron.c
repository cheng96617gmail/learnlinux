#include "apue.h"

int main(int agrc, char *argv[]){
	extern char **environ;
	int i;
	for(i=0;*environ!=NULL;i++){
		printf("%s\n",environ[i]);
	}
	exit(0);
}
