// 디렉터리명을 명령행 인자로 입력받아 생성하고, 작업 디렉터리를 새로 생성한 디렉터리로 이동시키는 프로그램을 작성하시오.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    char *cur_dir;
    if(argc != 2) {
        puts("Usage : ./c2_11 {DIRECTORY}");
        exit(1);
    }
    if(mkdir(argv[1], 0755) == -1) {
        perror("mkdir");
        exit(1);
    }
    if(chdir(argv[1]) == -1) {
        perror("chdir");
        exit(1);
    }

    printf("현재 디렉터리 위치 : %s\n", cur_dir = getcwd(NULL, BUFSIZ));
    free(cur_dir);
}