// '.'과 '..' 항목을 제외하고 디렉터리에 있는 파일이나 하위 디렉터리명을 출력하는 myls 프로그램을 작성하시오.

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    DIR             *dir;
    struct dirent   *entry;

    const char *current = (argc > 1) ? argv[1] : ".";

    if((dir = opendir(current)) == NULL) {
        perror("opendir");
        exit(1);
    }

    for(entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if(entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || (entry->d_name[1] == '.' && entry->d_name[2] == '\0'))) continue;
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}