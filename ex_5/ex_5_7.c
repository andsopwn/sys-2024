#include <pwd.h>
#include <stdio.h>

int main() {
    struct passwd *pw;

    for(int n = 0 ; n < 3 ; n++) {
        pw = getpwent();
        printf("UID : %d, LoginName : %s\n", (int)pw->pw_uid, pw->pw_name);
    }
}