###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# 리눅스 디렉터리 정리

### 리눅스 파일 구성 요소 
파일명 -> inode -> 데이터블록 <br>
https://pwned.tistory.com/80

# 디렉터리 관리

|기능|함수|라이브러리
|:-:|:-|-|
|디렉터리 생성 | int mkdir(const char *path, mode_t_ mode); |<sys/stat.h>, <sys/types.h> ,*<unistd.h>*
|디렉터리 삭제 | int rmdir(const char *path); | <unistd.h>
|현재 위치 확인 | char *getcwd(char *buf, size_t size); | <unistd.h>
||char *get_current_dir_name(void);|<unistd.h>
|디렉터리명 변경| int rename(const char *oldpath, const char *newpath);|<stdio.h>
|디렉터리 이동|int chdir(const char *path);|<unistd.h>
||int fchdir(int fd);|<unistd.h>
|디렉터리 열기|DIR *opendir(const char *name);|<sys/types.h>, <dirent.h>
|디렉터리 닫기|int closedir(DIR *drip);|<sys/types.h>, <dirent.h>
|디렉터리 내용 읽기|struct dirent *readdir(DIR *dirp);|<dirent.h>
|디렉터리 오프셋|long telldir(DIR *drip);|<dirent.h>
||void seekdir(DIR *dirp, long loc);|<dirent.h>
||void rewinddir(DIR *dirp);|<sys/types.h>, <dirent.h>

\* 함수는 기본적으로 다 외우기

## 디렉터리 생성 & 삭제
```c    
mkdir("test", 0755);
```
성공하면 0, 실패하면 -1 반환
오류 내용은 외부변수 ```errno``` 에 들어감

```c
rmdir("rmdir");
```
성공하면 0, 실패하면 0보다 큰 값을 반환한다.

## 디렉터리 위치 검색
```c
char *cdw = getcwd(wd1, BUFSIZ);
```
해당 함수는 이렇게 call을 했어도 포인터 값이 바뀌지 않고 ```NULL```로 유지될 경우 ```perror()```로 오류 메시지를 확인할 것
```c
char *cwd = get_current_dir_name();
```
<b>정말 중요</b> get_current_dir_name() 함수는 인자가 void로 아무것도 없음. 시스템이 메모리를 자동으로 할당해 경로를 저장하고 리턴하는 형식이다.

## 디렉터리 이름 변경
```c
int rename("dbwlstm", "sbwlstm");
``` 
인자 순서는 (변경할 파일/디렉터리명, 새파일/디렉터리명)이다.
성공시 0, 실패하면 -1을 반환한다.

## 디렉터리 이동
```c
chdir("cat"); // 상대경로
chdir("/usr/local/pwned/"); // 절대경로
```
디렉터리 이동은 직접 쉘에 쳐서 가는 것이 아닌, 프로그램이 동작하는 내부에서만 진행되는 것이므로, 프로그램을 종료했을 때 실제로 그 위치로 가있진 않는단다. 

```c
int fd = open("asm", O_RDONLY);
fchdir(fd);
```
함수 앞에 f가 붙은 것들은 웬만하면 파일 디스크립터임
성공시 0, 실패하면 -1을 반환한다.

