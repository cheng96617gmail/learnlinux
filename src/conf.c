#include "apue.h"
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *,int);
static void pr_pathconf(char *,char *,int);

int
main(int argc,char *argv[]){
	if(argc!=2)
		err_quit("usage:a.out <dirname>");
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n",ARG_MAX+0);
#else
	printf("no symbol for %s\n","ARG_MAX");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX=",_SC_ARG_MAX);
#else
	printf("no symbol for %s\n","_SC_ARG_MAX");
#endif
#ifdef ATEXIT_MAX
	printf("ATEXIT_MAX defined to be %d\n",ATEXIT_MAX+0);
#else
	printf("no symbol for %s\n","ATEXIT_MAX");
#endif
#ifdef _SC_ATEXIT_MAX
	pr_sysconf("ATEXIT_MAX=",_SC_ATEXIT_MAX);
#else
	printf("no symbol for %s\n","_SC_ATEXIT_MAX");
#endif
#ifdef CHILD_MAX
	printf("CHILD_MAX defined to be %d\n",CHILD_MAX+0);
#else
	printf("no symbol for %s\n","CHILD_MAX");
#endif
#ifdef _SC_CHILD_MAX
	pr_sysconf("CHILD_MAX=",_SC_CHILD_MAX);
#else
	printf("no symbol for %s\n","_SC_CHILD_MAX");
#endif
#ifdef clock ticks/second
	printf("clock ticks/second defined to be %d\n",clock ticks/second+0);
#else
	printf("no symbol for %s\n","clock ticks/second");
#endif
#ifdef _SC_CLK_TCK
	pr_sysconf("clock ticks/second=",_SC_CLK_TCK);
#else
	printf("no symbol for %s\n","_SC_CLK_TCK");
#endif
#ifdef COLL_WEIGHTS_MAX
	printf("COLL_WEIGHTS_MAX defined to be %d\n",COLL_WEIGHTS_MAX+0);
#else
	printf("no symbol for %s\n","COLL_WEIGHTS_MAX");
#endif
#ifdef _SC_COLL_WEIGHTS_MAX
	pr_sysconf("COLL_WEIGHTS_MAX=",_SC_COLL_WEIGHTS_MAX);
#else
	printf("no symbol for %s\n","_SC_COLL_WEIGHTS_MAX");
#endif
#ifdef HOST_NAME_MAX
	printf("HOST_NAME_MAX defined to be %d\n",HOST_NAME_MAX+0);
#else
	printf("no symbol for %s\n","HOST_NAME_MAX");
#endif
#ifdef _SC_HOST_NAME_MAX
	pr_sysconf("HOST_NAME_MAX=",_SC_HOST_NAME_MAX);
#else
	printf("no symbol for %s\n","_SC_HOST_NAME_MAX");
#endif
#ifdef IOV_MAX
	printf("IOV_MAX defined to be %d\n",IOV_MAX+0);
#else
	printf("no symbol for %s\n","IOV_MAX");
#endif
#ifdef _SC_IOV_MAX
	pr_sysconf("IOV_MAX=",_SC_IOV_MAX);
#else
	printf("no symbol for %s\n","_SC_IOV_MAX");
#endif
#ifdef LINE_MAX
	printf("LINE_MAX defined to be %d\n",LINE_MAX+0);
#else
	printf("no symbol for %s\n","LINE_MAX");
#endif
#ifdef _SC_LINE_MAX
	pr_sysconf("LINE_MAX=",_SC_LINE_MAX);
#else
	printf("no symbol for %s\n","_SC_LINE_MAX");
#endif
#ifdef NGROUPS_MAX
	printf("NGROUPS_MAX defined to be %d\n",NGROUPS_MAX+0);
#else
	printf("no symbol for %s\n","NGROUPS_MAX");
#endif
#ifdef _SC_NGROUPS_MAX
	pr_sysconf("NGROUPS_MAX=",_SC_NGROUPS_MAX);
#else
	printf("no symbol for %s\n","_SC_NGROUPS_MAX");
#endif
#ifdef OPEN_MAX
	printf("OPEN_MAX defined to be %d\n",OPEN_MAX+0);
#else
	printf("no symbol for %s\n","OPEN_MAX");
#endif
#ifdef _SC_OPEN_MAX
	pr_sysconf("OPEN_MAX=",_SC_OPEN_MAX);
#else
	printf("no symbol for %s\n","_SC_OPEN_MAX");
#endif
#ifdef PAGESIZE
	printf("PAGESIZE defined to be %d\n",PAGESIZE+0);
#else
	printf("no symbol for %s\n","PAGESIZE");
#endif
#ifdef _SC_PAGESIZE
	pr_sysconf("PAGESIZE=",_SC_PAGESIZE);
#else
	printf("no symbol for %s\n","_SC_PAGESIZE");
#endif
#ifdef PAGE_SIZE
	printf("PAGE_SIZE defined to be %d\n",PAGE_SIZE+0);
#else
	printf("no symbol for %s\n","PAGE_SIZE");
#endif
#ifdef _SC_PAGE_SIZE
	pr_sysconf("PAGE_SIZE=",_SC_PAGE_SIZE);
#else
	printf("no symbol for %s\n","_SC_PAGE_SIZE");
#endif
#ifdef RE_DUP_MAX
	printf("RE_DUP_MAX defined to be %d\n",RE_DUP_MAX+0);
#else
	printf("no symbol for %s\n","RE_DUP_MAX");
#endif
#ifdef _SC_RE_DUP_MAX
	pr_sysconf("RE_DUP_MAX=",_SC_RE_DUP_MAX);
#else
	printf("no symbol for %s\n","_SC_RE_DUP_MAX");
#endif
#ifdef STREAM_MAX
	printf("STREAM_MAX defined to be %d\n",STREAM_MAX+0);
#else
	printf("no symbol for %s\n","STREAM_MAX");
#endif
#ifdef _SC_STREAM_MAX
	pr_sysconf("STREAM_MAX=",_SC_STREAM_MAX);
#else
	printf("no symbol for %s\n","_SC_STREAM_MAX");
#endif
#ifdef SYMLOOP_MAX
	printf("SYMLOOP_MAX defined to be %d\n",SYMLOOP_MAX+0);
#else
	printf("no symbol for %s\n","SYMLOOP_MAX");
#endif
#ifdef _SC_SYMLOOP_MAX
	pr_sysconf("SYMLOOP_MAX=",_SC_SYMLOOP_MAX);
#else
	printf("no symbol for %s\n","_SC_SYMLOOP_MAX");
#endif
#ifdef TTY_NAME_MAX
	printf("TTY_NAME_MAX defined to be %d\n",TTY_NAME_MAX+0);
#else
	printf("no symbol for %s\n","TTY_NAME_MAX");
#endif
#ifdef _SC_TTY_NAME_MAX
	pr_sysconf("TTY_NAME_MAX=",_SC_TTY_NAME_MAX);
#else
	printf("no symbol for %s\n","_SC_TTY_NAME_MAX");
#endif
#ifdef TZNAME_MAX
	printf("TZNAME_MAX defined to be %d\n",TZNAME_MAX+0);
#else
	printf("no symbol for %s\n","TZNAME_MAX");
#endif
#ifdef _SC_TZNAME_MAX
	pr_sysconf("TZNAME_MAX=",_SC_TZNAME_MAX);
#else
	printf("no symbol for %s\n","_SC_TZNAME_MAX");
#endif
#ifdef FILESIZEBITS
	printf("FILESIZEBITS defined to be %d\n",FILESIZEBITS+0);
#else
	printf("no symbol for %s\n","FILESIZEBITS");
#endif
#ifdef _PC_FILESIZEBITS
	pr_pathconf("FILESIZEBITS=",argv[1],_PC_FILESIZEBITS);
#else
	printf("no symbol for %s\n","_PC_FILESIZEBITS");
#endif
#ifdef LINK_MAX
	printf("LINK_MAX defined to be %d\n",LINK_MAX+0);
#else
	printf("no symbol for %s\n","LINK_MAX");
#endif
#ifdef _PC_LINK_MAX
	pr_pathconf("LINK_MAX=",argv[1],_PC_LINK_MAX);
#else
	printf("no symbol for %s\n","_PC_LINK_MAX");
#endif
#ifdef MAX_CANON
	printf("MAX_CANON defined to be %d\n",MAX_CANON+0);
#else
	printf("no symbol for %s\n","MAX_CANON");
#endif
#ifdef _PC_MAX_CANON
	pr_pathconf("MAX_CANON=",argv[1],_PC_MAX_CANON);
#else
	printf("no symbol for %s\n","_PC_MAX_CANON");
#endif
#ifdef MAX_INPUT
	printf("MAX_INPUT defined to be %d\n",MAX_INPUT+0);
#else
	printf("no symbol for %s\n","MAX_INPUT");
#endif
#ifdef _PC_MAX_INPUT
	pr_pathconf("MAX_INPUT=",argv[1],_PC_MAX_INPUT);
#else
	printf("no symbol for %s\n","_PC_MAX_INPUT");
#endif
#ifdef NAME_MAX
	printf("NAME_MAX defined to be %d\n",NAME_MAX+0);
#else
	printf("no symbol for %s\n","NAME_MAX");
#endif
#ifdef _PC_NAME_MAX
	pr_pathconf("NAME_MAX=",argv[1],_PC_NAME_MAX);
#else
	printf("no symbol for %s\n","_PC_NAME_MAX");
#endif
#ifdef PATH_MAX
	printf("PATH_MAX defined to be %d\n",PATH_MAX+0);
#else
	printf("no symbol for %s\n","PATH_MAX");
#endif
#ifdef _PC_PATH_MAX
	pr_pathconf("PATH_MAX=",argv[1],_PC_PATH_MAX);
#else
	printf("no symbol for %s\n","_PC_PATH_MAX");
#endif
#ifdef PIPE_MAX
	printf("PIPE_MAX defined to be %d\n",PIPE_MAX+0);
#else
	printf("no symbol for %s\n","PIPE_MAX");
#endif
#ifdef _PC_PIPE_MAX
	pr_pathconf("PIPE_MAX=",argv[1],_PC_PIPE_MAX);
#else
	printf("no symbol for %s\n","_PC_PIPE_MAX");
#endif
#ifdef SYMLINK_MAX
	printf("SYMLINK_MAX defined to be %d\n",SYMLINK_MAX+0);
#else
	printf("no symbol for %s\n","SYMLINK_MAX");
#endif
#ifdef _PC_SYMLINK_MAX
	pr_pathconf("SYMLINK_MAX=",argv[1],_PC_SYMLINK_MAX);
#else
	printf("no symbol for %s\n","_PC_SYMLINK_MAX");
#endif
	exit(0);
}
static void pr_sysconf(char *mesg, int name){
	long val;
	fputs(mesg,stdout);
	errno=0;
	if((val=sysconf(name)) < 0){
		if(errno > 0){
			if(errno == EINVAL){
				fputs("no supported \n",stdout);
			}else{
				err_sys("sysconf err");
			}
		}else{
			fputs("no limits",stdout);
		}
	}else{
		printf("%ld\n",val);
	}
}

static void pr_pathconf(char *mesg, char *path, int name){
	long val;
	fputs(mesg,stdout);
	errno=0;
	if((val=pathconf(path,name)) < 0){
		if(errno > 0){
			if(errno == EINVAL){
				fputs("no supported \n",stdout);
			}else{
				err_sys("path error:path=%s",path);
			}
		}else{
			fputs("no limits",stdout);
		}
	}else{
		printf("%ld\n",val);
	}
}

