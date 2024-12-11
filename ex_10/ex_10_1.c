#include <stdlib.h>
#include <stdio.h>

int main( ) {
    FILE *fp;
    int a;
    fp = popen("wc -l", "w"); //wc –ㅣ은 라인 수 리턴
    if (fp == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }
    for (a = 0; a < 100; a++)
        fprintf(fp, "test line\n");
    pclose(fp); //eof가 wc에 전달
}