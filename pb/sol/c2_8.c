// 현재 디렉터리를 기억하고 있다가 다른 디렉터리로 이동해 작업한 후 원래 디렉터리로 돌아오도록 프로그램을 작성하시오.

#include <stdio.h>
#include <unistd.h>
//#include <sys/stat.h>

int main() {
    char    buf[BUFSIZ];
    char    *cwd = getcwd(buf, BUFSIZ);

    printf("%s\n", cwd);
}