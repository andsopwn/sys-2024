#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        printf("자식 1 PID: %d\n", getpid());
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            printf("자식 2 PID: %d\n", getpid());
        } else {
            printf("부모 PID: %d\n", getpid());
        }
    }
    return 0;
}
