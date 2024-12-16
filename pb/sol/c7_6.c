#include <stdio.h>
#include <stdlib.h>

int main() {
    if(system("pwd && ls -al") == -1) 
        perror("system");
}