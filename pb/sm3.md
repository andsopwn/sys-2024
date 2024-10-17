###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# 리눅스 파일 정리


##  파일 제어 함수
|기능|함수|라이브러리
|:-:|:-|-|
| 파일명으로 파일정보 검색 | int stat(const char *pathname, struct stat *statbuf); | <sys/types.h>, <sys/stat.h>, <unistd.h>
| 파일기술자로 파일정보 검색 | fstat(int fd, struct stat *statbuf); | <sys/types.h>, <sys/stat.h>, <unistd.h>
| 파일 접근 권한 검색 | int access(const char* pathname, int mode); | <unistd.h>
| 파일명으로 접근권한 변경 | int chmod(const char *pathname, mode_t mode); | <sys/stat.h>
| 파일기술자로 접근권한 변경 | int fchmod(int fd, mode_t mode); | <sys/stat.h>
| 하드 링크 생성 | int link(const char *oldpath, const char *newpath) | <unistd.h>
| 심볼릭 링크 생성 | int symlink(const char *target, const char *linkpath) | <unistd.h>
| 심볼릭 링크 파일 정보 검색 | int lstat(const char *pathname, struct stat *statbuf); | <unistd.h> 
| 심볼릭 링크 파일 내용 읽기 | ssize_t readlink(const char *pathname, char *buf, size_t bufsiz); | <unistd.h>
| 심볼릭 링크 원본 파일 경로 검색 | char *realpath(const char *path, char *resolved_path); | <limits.h>, <stdlib.h>
| 링크 끊기 | unlink(const char *pathname); | <unistd.h>


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

## 파일 정보 검색

### stat()
파일명으로 파일 정보 탐색 목적

pathname : 파일명 <br>
statbuf : 검색한 파일 정보를 저장할 구조체 주소

성공하면 0을 반환하고 stat 구조체에 파일 정보 저장, 오류 발생시 -1 반환


#### 파일명으로 inode 정보 검색 
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

## 파일 접근권한

### fstat();
```c
/* 코드 생략 : fd는 이미 할당 받음 (open) */
fstat(fd, &statbuf);
printf("Inode = %d\n", (int)statbuf.st_ino); // Inode = 1048600
printf("UID = %d\n", (int)statbuf.st_uid);   // UID = 1000
close(fd);
```

파일 경로 대신 현재 열려있는 파일의 **파일 기술자**를 인자로 받아 정보 검색 후 statbuf로 지정한 구조체 저장 <br>
실패할 경우 -1 반환

<hr>

### access()
```c
perm = access("file.txt", R_OK);
if(perm == 0)                           puts("is permitted");
else if(perm == -1 && errno == EACCES)  puts("not permitted");
```
+ 파일 접근 권한을 검색할 수 있는 시스템 호출
+ pathname에 지정된 파일이 mode로 지정한 권한을 지니고 있는지 확인하고 반환
+ 권한이 있으면 0, 오류시 -1 반환
  + ENOENT : 존재하지 않거나 심볼릭 링크의 경우 원본이 없음
  + EACCES : 권한 없음

+ 두 번째 인자 mode에 사용할 수 있는 상수
  + R_OK 읽기권한 확인
  + W_OK 쓰기권한 확인
  + X_OK 실행권한 확인
  + F_OK 파일존재 확인

<hr>

### chmod()
|기능|함수|라이브러리
|:-:|:-|-|
| 파일명으로 접근권한 변경 | int chmod(const char *pathname, mode_t mode); | <sys/stat.h>

chmod() 특징
+ 접근 권한을 변경할 파일의 경로를 받아 mode에 지정한 상숫값으로 권한 변경
+ 특수 접근 권한을 변경할 때 S_ISUID, S_ISGID, S_ISTVX 이용
+ 소유자/그룹/기타 접근 권한 변경시 상수 이용

상수 이용해 권한 생성 후 인자로 지정
```c
chmod("feeling", S_IRWXU);
chmod("feeling", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);
```
기존 접근 권한을 변경해서 권한 조정 가능
```c
mode |= S_IWGRP;
```
접근 권한 제거하려면 권한의 상숫값 NOT 연산 후 AND 연산

```c
chmod("feeling", mode);
```
mode 바꾸고 적용해줘야 권한이 적용됨

### fchmod()
|기능|함수|라이브러리
|:-:|:-|-|
| 파일기술자로 접근권한 변경 | int fchmod(int fd, mode_t mode); | <sys/stat.h>

<hr>

## 링크 파일 함수
+ 이미 있는 파일이나 디렉터리에 접근할 수 있는 새로운 이름
+ 하드링크는 기존 의 파일과 같은 inode 사용
+ 심벌릭 링크는 기존의 파일에 접근할 수 있는 다른 파일을 만든다. (다른 inode)

### link()

|기능|함수|라이브러리
|:-:|:-|-|
| 하드 링크 생성 | int link(const char *oldpath, const char *newpath) | <unistd.h>
```bash
> ls -il linux.*
744 -rwxrwx--- 2 xx xx 59 Oct  2 06:51 linux.ln
744 -rwxrwx--- 2 xx xx 59 Oct  2 06:51 linux.txt
```

### symlink()
|기능|함수|라이브러리
|:-:|:-|-|
| 심볼릭 링크 생성 | int symlink(const char *target, const char *linkpath) | <unistd.h>
```bash
> ls -il linux.*
2082 lrwxr-xr-x 1 xx xx  9 Oct 16 17:56 linux.sym -> linux.txt
744 -rwxrwx--- 1 xx xx 59 Oct  2 06:51 linux.txt
```

### lstat()
|기능|함수|라이브러리
|:-:|:-|-|
| 심볼릭 링크 파일 정보 검색 | int lstat(const char *pathname, struct stat *statbuf); | <unistd.h> 

심벌릭 링크 자체의 파일 정보를 검색, stat()을 사용하면 원본 파일에 대한 정보가 검색된다. stat()과 동일

[코드](../ex_3/ex_3_10.c)
```bash
> ls -li linux.*
 744 -rwxrwx--- 2 xx xx 59 Oct  2 06:51 linux.ln
2165 lrwxr-xr-x 1 xx xx  9 Oct 16 18:06 linux.sym -> linux.txt
 744 -rwxrwx--- 2 xx xx 59 Oct  2 06:51 linux.txt

> object
1. stat : linux.txt ---
linux.txt : Link Count = 2
linux.txt : Inode = 744
2. stat : linux.sym ---
linux.sym : Link Count = 2
linux.sym : Inode = 744
3. lstat : linux.sym ---
linux.sym : Link Count = 2
linux.sym : Inode = 744
```

### readlink()
|기능|함수|라이브러리
|:-:|:-|-|
| 심볼릭 링크 파일 내용 읽기 | ssize_t readlink(const char *pathname, char *buf, size_t bufsiz); | <unistd.h>

vi로 심벌릭 열면 원본이 열림 -> 심벌릭 자체의 데이터를 읽을려면 readlink()를 사용해야함. <br>
성공하면 데이터의 크기를 반환, 실패하면 -1을 반환한다. <br>

[코드](../ex_3/ex_3_11.c)
```c
> object
linux.sym : READLINK = linux.txt

> ls -l linux.sym
lrwxr-xr-x 1 xx xx 9 Oct 16 18:06 linux.sym -> linux.txt
```

### realpath()
|기능|함수|라이브러리
|:-:|:-|-|
| 심볼릭 링크 원본 파일 경로 검색 | char *realpath(const char *path, char *resolved_path); | <limits.h>, <stdlib.h>

realopen()이 있다면 realpath()도 있어야지, 실제 경로명을 확인하기 위해 쓰인다. <br>
성공하면 경로명이 저장된 곳의 주소, 실패하면 널이 리턴 <br>
[코드](../ex_3/ex_3_12.c)

### unlink()
|기능|함수|라이브러리
|:-:|:-|-|
| 링크 끊기 | unlink(const char *pathname); | <unistd.h>

[코드](../ex_3/ex_3_13.c)

```bash
> object
1.linux.ln : Link Count = 2
2.linux.txt : Link Count = 1

> ls -il linux.*
744 -rwxrwx--- 1 xx xx 59 Oct  2 06:51 linux.txt
```

<hr>