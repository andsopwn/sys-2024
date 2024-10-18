// 현재 디렉터리를 기억하고 있다가 다른 디렉터리로 이동해 작업한 후 원래 디렉터리로 돌아오도록 프로그램을 작성하시오.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char    saved_dir[BUFSIZ];
    char    *dir;

    // 오류처리 안 함
    printf("현재 디렉터리 위치 : %s\n", dir = getcwd(saved_dir, BUFSIZ));
    // 스택에 있는 saved_dir를 사용하므로 free하지 않음

    chdir("../");

    printf("현재 디렉터리 위치 : %s\n", dir = getcwd(NULL, BUFSIZ));
    free(dir);

    chdir(saved_dir);

    printf("현재 디렉터리 위치 : %s\n", dir = getcwd(NULL, BUFSIZ));
    free(dir);
    
}