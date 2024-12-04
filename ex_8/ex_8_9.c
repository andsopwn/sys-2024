#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sig_handler(int signo) {
psignal(signo, "Received Signal");
}

int main() {
    signal(SIGALRM, sig_handler);

    alarm(2);
    printf("Wait...\n");
    sleep(3);
}