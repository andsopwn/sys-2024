#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *fname;
    char fntmp[BUFSIZ];
    char template[32];

    tmpnam(fntmp);
    fname = tmpnam(NULL);
    printf("1. TMP File Name(tmpnam) : %s\n", fname);
    printf("2. TMP File Name(tmpnam) : %s\n", fntmp);
    strcpy(template, "/tmp/hanbitXXXXXX");
    fname = mktemp(template);
    printf("3. TMP File Name(mktemp) : %s\n", fname);
}