#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    pid_t parent_pid, child_pid1, child_pid2;

    parent_pid = getpid();
    printf("PID:%d\n", parent_pid);

    child_pid1 = fork();
    child_pid2 = fork();

    if (child_pid1 == 0) {
        child_pid2 = fork();
        printf("This is child process:%d\n", getpid());
    } else {
        printf("This is the parent process:%d\n", getpid());
    }

    sleep(10);
    return 0;
}

