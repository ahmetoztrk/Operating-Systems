#include <sys/sem.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
int main(int argc, char *argv[])
{
    key_t myKey;
    int msqID,shmID,semID ;

    myKey = ftok("/home/onder/.bashrc", 23);
    if(myKey == -1) {
      printf("ftok failed with errno = %d\n", errno);
      return -1;
    }
	printf("IPC_key:%x\n",myKey);
	msqID=msgget(myKey,0666 | IPC_CREAT | IPC_EXCL );
	shmID=shmget(myKey,50,0666 | IPC_CREAT | IPC_EXCL );
    	semID = semget(myKey, 1, 0666 | IPC_CREAT);
        if(semID == -1) {
           printf("semget failed with errno = %d\n", errno);
           return -1;
        }

return 0;
}
