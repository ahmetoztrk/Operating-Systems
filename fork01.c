#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <process.h>
int main(int argc,char **argv){
	pid_t Ana_pid,cocuk_pid;
	Ana_pid=getpid();
	printf("PID:%d\n",Ana_pid);
	cocuk_pid=fork();
	if(cocuk_pid==0){
		printf("Bu cocuk proses:%d\n",getpid());
	}else {
		printf("Bu ana proses:%d\n",getppid());
	}
	sleep(10);
	return 0;
}

