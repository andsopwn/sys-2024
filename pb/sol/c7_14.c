#include <unistd.h>

int main() {
    char *args[] = {"vi", "/etc/hosts", NULL};
    execvp("vi", args);
    return 0;
}
