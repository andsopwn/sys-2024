#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PORTNUM 50000

int main() {
    struct      sockaddr_in sin, cli;
    socklen_t clientlen = sizeof(cli);

    int         sd, ns;
    char        filename[BUFSIZ];
    char        buf[BUFSIZ];
    char        data[BUFSIZ];
    FILE        *fp;
    off_t       filesize = 0;
    off_t       received = 0;
    ssize_t     n;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }

    if (listen(sd, 5)) {
        perror("listen");
        exit(1);
    }

    if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
        perror("accept");
        exit(1);
    }

    if (recv(ns, filename, sizeof(filename), 0) == -1) {
        perror("recv filename");
        exit(1);
    }

    if ((fp = fopen(filename, "wb")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if (recv(ns, buf, sizeof(buf), 0) == -1) {
        perror("recv filesize");
        exit(1);
    }
    filesize = atol(buf);

    while (received < filesize) {
        n = recv(ns, data, sizeof(data), 0);
        if (n == -1) {
            perror("recv data");
            exit(1);
        }
        fwrite(data, 1, n, fp);
        received += n;
    }

    fclose(fp);

    strcpy(buf, "Upload Complete");
    if (send(ns, buf, strlen(buf) + 1, 0) == -1) {
        perror("send");
        exit(1);
    }

    close(ns);
    close(sd);
    return 0;
}
