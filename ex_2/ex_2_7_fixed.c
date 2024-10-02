#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// ppt 코드를 오류없이 출력했습니다.
int main() {
    char *cwd;
    int fd;

    cwd = getcwd(NULL, BUFSIZ);
    if (cwd == NULL) {
        perror("getcwd");
        exit(1);
    }
    printf("1. Current Directory: %s\n", cwd);
    fd = open("bit", O_RDONLY);
    if (fd == -1) {
        perror("open");
        free(cwd);
        exit(1);
    }

    if (fchdir(fd) == -1) {
        perror("fchdir");
        close(fd);
        free(cwd);
        exit(1);
    }

    free(cwd);
    cwd = getcwd(NULL, BUFSIZ);
    if (cwd == NULL) {
        perror("getcwd");
        close(fd);
        exit(1);
    }
    printf("2. Current Directory: %s\n", cwd);

    close(fd);
    free(cwd);
}
