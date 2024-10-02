#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int opt;
    extern int optind;
    printf("%d\n", optind);
}