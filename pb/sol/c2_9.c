//09. [예제 2-6]에는 getcwd() 함수가 오류를 리턴할 때 처리하는 코드가 없다. 오류가 발생할 경우 처리하는 코드를 추가해 예제를 작성하시오.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cwd;

    if((cwd = getcwd(NULL, BUFSIZ)) == NULL) {
        perror("getcwd");
        exit(1);
    }
    printf("1. Current Directory : %s\n", cwd);
    chdir("bit");

    free(cwd);
    
    if((cwd = getcwd(NULL, BUFSIZ)) == NULL) {
        perror("getcwd");
        exit(1);
    }
    printf("2. Current Directory : %s\n", cwd);

    free(cwd);
} 