#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main() {
    time_t tloc;
    time(&tloc);
    printf("TIme(sec): %d\n", (int)tloc);
}