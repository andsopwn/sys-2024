#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int rfd, wfd, n;
    char buf[BUFSIZ];

    rfd = open("linux.txt", O_RDONLY);

    if(rfd == -1) {
        perror("Open linux.txt");
        exit(1);
    }

    wfd = open("linux.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(wfd == -1) {
        perror("Open linux.bak");
        exit(1);
    }
    while((n = read(rfd, buf, 6)) > 0) {
        if(write(wfd, buf, 6) != n) perror("Write");
        for(int i = 0 ; i < 10 ; i++) printf("%02x ", buf[i]);
        printf("\t buf : %s\n", buf);
    }
    if(n == -1) perror("Read");
    close(rfd);
    close(wfd);
}