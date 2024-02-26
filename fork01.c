#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <process.h>

int main(int argc, char **argv) {
    pid_t parent_pid, child_pid;
    parent_pid = getpid();
    printf("PID: %d\n", parent_pid);
    
    child_pid = fork();
    
    if (child_pid == 0) {
        printf("This is the child process: %d\n", getpid());
    } else {
        printf("This is the parent process: %d\n", getppid());
    }
    
    sleep(10);
    return 0;
}

