#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if(pid == 0) {
        execl("/bin/pwd", "pwd", (char *)NULL);
    } else {
        wait(NULL);
        system("ls -l");
    }
}