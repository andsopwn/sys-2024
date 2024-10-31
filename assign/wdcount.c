#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define MAXLEN 100

int str_length(const char *s) {
    int         len = 0;
    while (*s++) {
        len++;
    }
    return len;
}

int main(int argc, char *argv[]) {
    struct stat ine;
    int         counts[3] = {0, 0, 0};
    int         fd;
    int         word_len = 0;
    int         read_num;
    char        buf[BUFSIZ];
    char        word_buf[MAXLEN];

    if(argc > 5) {
        puts("the number of keywords exceeds three");
        exit(1);
    }
    if(argc == 2) {
        puts("no searching keyword");
        exit(1);
    }
    if(argc == 1) {
        fprintf(stderr, "Usage : %s FILE KEYWORD1 ... KEYWORD3\n", argv[0]);
        exit(1);
    }
    if((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }
    if(fstat(fd, &ine) == -1) {
        perror("fd");
        close(fd);
        exit(1);
    }
    if(!S_ISREG(ine.st_mode)) {
        puts("target file is not regular file");
        close(fd);
        exit(1);
    }

    while((read_num = read(fd, buf, BUFSIZ)) > 0) {
        for(int i = 0 ; i < read_num ; i++) {
            if(buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\r' && buf[i] != '\n' && buf[i] != '\0') {
                if(word_len < MAXLEN - 1) word_buf[word_len++] = buf[i];
            } 
            else {
                if(word_len > 0) {
                    word_buf[word_len] = '\0';
                    for(int j = 0 ; j < argc - 2 ; j++) {
                        char *s1 = word_buf;
                        char *s2 = argv[j + 2];
                        int k;
                        for(k = 0; s1[k] && s1[k] == s2[k]; k++);
                        if(s1[k] == '\0' && s2[k] == '\0') {
                            counts[j]++;
                            break;
                        }
                    }
                    word_len = 0;
                }
            }
        }
    }

    if(word_len > 0) {
        word_buf[word_len] = '\0';
        for(int j = 0 ; j < argc - 2 ; j++) {
            char *s1    = word_buf;
            char *s2    = argv[j + 2];
            int k;
            for(k = 0; s1[k] && s1[k] == s2[k]; k++);
            if(s1[k] == '\0' && s2[k] == '\0') {
                counts[j]++;
                break;
            }
        }
    }
    close(fd);

    if((fd = open("wd.cnt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror("wd.cnt");
        exit(1);
    }

    for(int i = 0 ; i < argc - 2 ; i++) {
        buf[0] = '\0';
        snprintf(buf, sizeof(buf), "%s: %d\n", argv[i + 2], counts[i]);
        write(fd, buf, str_length(buf));
    }

    close(fd);
    
    return 0;
}