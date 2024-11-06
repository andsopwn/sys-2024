#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

int main() {
    struct passwd *pw;

    pw = getpwnam("username");
    printf("UID : %d\n", (int)pw->pw_uid);
    printf("Home Directory : %s\n", pw->pw_dir);
}