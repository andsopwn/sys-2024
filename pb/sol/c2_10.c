// 디렉터리가 비어 있는지 확인 후 디렉터리가 비어 있다는 메시지를 출력하고 해당 디렉터리를 삭제하는 프로그램을 작성하시오.

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

#define dir "./test"

char is_empty(const char *path) {
    struct  dirent *entry;
    DIR *em = opendir(path);
    
    if(!em) {
        perror(dir);
        exit(1);
    }
    int count = 0;
    while ((entry = readdir(em)) != NULL) { 
        if (++count > 2) break;
    }
    closedir(em);
    
    return count <= 2;
}

int main() {
    if (is_empty(dir)) {
        puts("디렉터리가 비어있습니다. 삭제합니다.");
        rmdir(dir);
    } else {
        puts("디렉터리가 비어있지 않습니다.");
    }

    return 0;
}
