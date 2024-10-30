#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int n;
    extern int optind;
    extern char *optarg;

    printf("CURRENT OPTION : %d\n", optind);
    while((n = getopt(argc, argv, "abc:")) != -1) {
        switch (n) {
            case 'a':
                puts("A");
                break;
            case 'b':
                puts("B");
                break;
            case 'c':
                puts("C");
                break;
        }
        printf("NEXT OPTIND : %d\n", optind);
    }
}