#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
//    struct stat test;
    printf("%o\n", S_ISUID);
    printf("%o\n", S_ISGID);
    printf("%o\n", S_ISVTX);
}