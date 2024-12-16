#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = vfork();

    if (pid == 0) {
        execl("/usr/bin/who", "who", (char *)NULL);
    } else if (pid > 0) {
        time_t now = time(NULL);
        printf("현재 시간: %s", ctime(&now));
    }
    return 0;
}
