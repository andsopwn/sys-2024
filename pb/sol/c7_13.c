#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <wait.h>


int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/usr/bin/whoami", "whoami", (char *)NULL);
    } else if (pid > 0) {
        wait(NULL);
    }
    return 0;
}
