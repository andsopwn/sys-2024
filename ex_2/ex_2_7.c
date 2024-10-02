#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    char *cwd;
    int fd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("1. Current Directory: %s\n", cwd);

    fd = open("bit", O_RDONLY);
    fchdir(fd);

    cwd = getcwd(NULL, BUFSIZ);
    printf("2. Current Directory: %s\n", cwd);

    close(fd);
    free(cwd);
}

/*
1. Current Directory: /home/projects/sys-2024/ex_2_1
2. Current Directory: /home/projects/sys-2024/ex_2_1/bit

=================================================================
==2323==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 8192 byte(s) in 1 object(s) allocated from:
    #0 0x7f69a18b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x7f69a151522e in __GI___getcwd ../sysdeps/unix/sysv/linux/getcwd.c:68
    #2 0x5637af958283 in main (/home/projects/sys-2024/ex_2_1/ex_2_7+0x1283)
    #3 0x7f69a1429d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: 8192 byte(s) leaked in 1 allocation(s).
*/