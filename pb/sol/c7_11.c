#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("자식 프로세스에서 부모 PID: %d\n", getppid());
    } else {
        printf("부모 프로세스 PID: %d\n", getpid());
    }
    return 0;
}
