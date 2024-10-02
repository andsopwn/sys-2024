#include <stdio.h>

int main(int argc, char **argv) {
    long long num0, num1;
    
    if(argc != 3) {
        puts("./p14 {integer} {integer}");
        return 1;
    }
    
    sscanf(argv[1], "%lld", &num0);
    sscanf(argv[2], "%lld", &num1);

    printf("%lld\n", (num0 + num1) * ((num1 - num0) + 1) / 2);
}