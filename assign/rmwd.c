#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXLEN 100

int main(int argc, char *argv[]) {
    struct stat ine;
    int         f_in, f_out;
    int         word_len = 0;
    int         num_keywords = argc - 2;
    int         read_num;

    int         is_tword = 0;
    int         in_word = 0;
    int         in_tskip = 0;

    char word_buf[MAXLEN];
    char buf[BUFSIZ];

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
    if((f_in = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }
    if(fstat(f_in, &ine) == -1) {
        perror("fd");
        close(f_in);
        exit(1);
    }
    if(!S_ISREG(ine.st_mode)) {
        puts("target file is not regular file");
        close(f_in);
        exit(1);
    }
    if((f_out = open("rmwd.d", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror("rmwd.d");
        close(f_in);
        exit(1);
    }

    while((read_num = read(f_in, buf, BUFSIZ)) > 0) {
        for(int i = 0 ; i < read_num ; ) {
            if(buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\r' && buf[i] != '\n' && buf[i] != '\f') {
                if(word_len < MAXLEN - 1) word_buf[word_len++] = buf[i];
                in_word     = 1;
                i++;
            } else {
                if(in_word) {
                    // EOF
                    word_buf[word_len] = '\0';

                    is_tword = 0;
                    for(int j = 0 ; j < num_keywords ; j++) {
                        char *s1    = word_buf;
                        char *s2    = argv[j + 2];
                        int k;
                        for(k = 0; s1[k] && s1[k] == s2[k]; k++);
                        if(s1[k] == '\0' && s2[k] == '\0') {
                            is_tword = 1;
                            break;
                        }
                    }
                    if(!is_tword) write(f_out, word_buf, word_len);
                    word_len    = 0;
                    in_word     = 0;
                    in_tskip    = is_tword;
                }

                if(!in_tskip) {
                    while(i < read_num && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\r' || buf[i] == '\n')) {
                        write(f_out, &buf[i], 1);
                        i++;
                    }
                } else {
                    while(i < read_num && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\r' || buf[i] == '\n')) {
                        i++;
                    }
                    in_tskip = 0;
                }
            }
        }
    }

    if(in_word) {
        word_buf[word_len]  = '\0';
        is_tword            = 0;
        for(int i = 0 ; i < num_keywords ; i++) {
            char *s1 = word_buf;
            char *s2 = argv[i + 2];
            int j;
            for(j = 0; s1[j] && s1[j] == s2[j]; j++);
            if(s1[j] == '\0' && s2[j] == '\0') {
                is_tword = 1;
                break;
            }
        }
        if(!is_tword) write(f_out, word_buf, word_len);
    }

    close(f_in);
    close(f_out);
    return 0;
}