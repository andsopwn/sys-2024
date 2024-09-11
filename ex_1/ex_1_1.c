#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern int errno;

int main() {
    FILE *fp;

    if(access("test.txt", F_OK) == -1) {
        printf("errno = %d\n", errno);
        exit(1);
    }
    printf("%d\n", errno);
}