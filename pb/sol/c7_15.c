#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/usr/bin/whoami", "whoami", (char *)NULL);
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
        printf("자식 프로세스 종료.\n");
    }
    return 0;
}
