###### 서준이의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# 리눅스 파일 정리 

### stat 구조체
```c
struct stat {
dev_t st_dev;           // 파일이 저장되어 있는 장치의 번호 저장
ino_t st_ino;           // 파일의 inode 번호 저장
mode_t st_mode;         // 파일의 종류와 접근 권한을 저장
nlink_t st_nlink;       // 하드 링크의 개수 저장
uid_t st_uid;           // 파일 소유자 UID를 저장
gid_t st_gid;           // 파일 소유 그룹의 GID를 저장
dev_t st_rdev;          // 장치 파일이면 주 장치 번호, 부 장치 번호를 저장
off_t st_size;          //
blksize_t st_blksize;   // 파일 입출력 시 사용하는 버퍼 크기 저장
blkcnt_t st_blocks;     // 파일에 할당된 파일 시스템의 블록 수로 블록의 크기는 512Bytes
struct timespec st_atim;            // 여기는 커널 2.6이후 나노초 제공하는데
struct timespec st_mtim;
struct timespec st_ctim;
#define st_atime st_atim.tv_sec     // 여기는 2.6 이전 버전 호환성을 위해 만들어둔 곳
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
}
```
+ st_atim  - 마지막 파일 읽거나 실행한 시각
+ st_mtim  - 마지막 파일 내용 변경(쓰기) 시각
+ st_ctim  - 마지막 inode 변경 시각

```man -s 2 stat``` 으로 확인할 것

#### timespec 구조체
```c
struct timespec {
    __kernel_time_t tv_sec; /* 초 (seconds) */
    long tv_nsec;           /* 나노초(nanoseconds) */
};
```
리눅스 커널 2.6부터 나노초 수준의 정밀도 지원

### stat 함수
파일명으로 파일 정보 탐색 목적
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);
```
pathname : 파일명 <br>
statbuf : 검색한 파일 정보를 저장할 구조체 주소

성공하면 0을 반환하고 stat 구조체에 파일 정보 저장, 오류 발생시 -1 반환


### inode 실습
```c
struct stat statbuf;
stat("linux.txt", &statbuf);

printf("Inode = %d\n", (int)statbuf.st_ino);
printf("Mode = %o\n", (unsigned int)statbuf.st_mode);
printf("Nlink = %o\n",(unsigned int) statbuf.st_nlink);
printf("UID = %d\n", (int)statbuf.st_uid);
printf("GID = %d\n", (int)statbuf.st_gid);
printf("SIZE = %d\n", (int)statbuf.st_size);
printf("Blksize = %d\n", (int)statbuf.st_blksize);
printf("Blocks = %d\n", (int)statbuf.st_blocks);

printf("** timespec Style\n");
printf("Atime = %d\n", (int)statbuf.st_atim.tv_sec);
printf("Mtime = %d\n", (int)statbuf.st_mtim.tv_sec);
printf("Ctime = %d\n", (int)statbuf.st_ctim.tv_sec);

printf("** old Style\n");
printf("Atime = %d\n", (int)statbuf.st_atime);
printf("Mtime = %d\n", (int)statbuf.st_mtime);
printf("Ctime = %d\n", (int)statbuf.st_ctime);
```

<details>
<summary> 출력값 보기 </summary>

```c
Inode = 744     inode 번호
Mode = 100770   st_mode 값
Nlink = 1       하드링크 개수는 1개이다.
UID = 1000      어떤 사용자인지 알고 싶으면 /etc/passwd
GID = 1000      <->
SIZE = 59       파일 크기는 59바이트
Blksize = 4096  BlockSize / Blocks = 512 bytes
Blocks = 8
** timespec Style
Atime = 1729060489  timepsec 구조체 형식의 tv_sec값 출력
Mtime = 1727851873
Ctime = 1729052602
** old Style
Atime = 1729060489  타임스탬프 이전 형식의 변수명 출력
Mtime = 1727851873
Ctime = 1729052602
```
</details>

### fstat 함수
잘 생각해보세요. stat이랑 요구하는 라이브러리가 같습니다.
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

fstat(int fd, struct stat *statbuf);
```
파일 경로 대신 현재 열려있는 파일의 **파일 기술자**를 인자로 받아 정보 검색 후 statbuf로 지정한 구조체 저장 <br>
실패할 경우 -1 반환

```c
/* 코드 생략 : fd는 이미 할당 받음 (open) */
fstat(fd, &statbuf);
printf("Inode = %d\n", (int)statbuf.st_ino); // Inode = 1048600
printf("UID = %d\n", (int)statbuf.st_uid);   // UID = 1000
close(fd);
```
