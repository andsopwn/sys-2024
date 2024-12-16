#include <stdlib.h>
#include <stdio.h>

void print_directory_contents() {
    system("ls -l");
}

int main() {
    atexit(print_directory_contents);
    printf("프로그램 실행 중...\n");
    return 0;
}
