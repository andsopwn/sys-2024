#include <shadow.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct spwd *spw;
    
    for(int n = 0; n < 3; n++) {
        spw = getspent();
        printf("LoginName: %s, Passwd: %s\n", spw->sp_namp, spw->sp_pwdp);
    }
}