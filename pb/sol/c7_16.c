#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스: who 명령 실행
        execl("/usr/bin/who", "who", (char *)NULL);
        perror("execl 실패");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // 부모 프로세스: 자식 프로세스가 종료할 때까지 대기
        siginfo_t info;
        if (waitid(P_PID, pid, &info, WEXITED) == -1) {
            perror("waitid 실패");
            exit(EXIT_FAILURE);
        }
        printf("자식 프로세스 종료, PID: %d, 종료 상태: %d\n", info.si_pid, info.si_status);
    } else {
        perror("fork 실패");
        exit(EXIT_FAILURE);
    }

    return 0;
}
