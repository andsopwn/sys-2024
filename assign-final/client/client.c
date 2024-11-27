#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define PORTNUM 50000
#define filename "sample.txt"

int main() {
    struct      stat st;

    int         sd;
    char        buf[BUFSIZ];
    char        data[BUFSIZ];
    struct      sockaddr_in sin;
    FILE        *fp;
    off_t       filesize;
    ssize_t     n;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("connect");
        exit(1);
    }

    if ((fp = fopen(filename, "rb")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if (stat(filename, &st) == -1) {
        perror("stat");
        exit(1);
    }
    filesize = st.st_size;

    if (send(sd, filename, strlen(filename) + 1, 0) == -1) {
        perror("send filename");
        exit(1);
    }

    sprintf(buf, "%ld", filesize);
    if (send(sd, buf, sizeof(buf), 0) == -1) {
        perror("send filesize");
        exit(1);
    }

    while ((n = fread(data, 1, sizeof(data), fp)) > 0) {
        if (send(sd, data, n, 0) == -1) {
            perror("send data");
            exit(1);
        }
    }

    fclose(fp);

    if (recv(sd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(1);
    }

    close(sd);
    return 0;
}
