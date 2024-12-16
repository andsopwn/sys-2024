###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 07

### 1. 다음과 같이 자식 프로세스 생성, 수행하는 부분은?
```c
int main() {
    pid_t pid;
    switch(pid = fork()) {
        case -1:
        case 1:
        case 0:
        default:
    }
}
```
1. case -1
1. case 1
1. **case 0**
1. default

### 2. 프로세스 종료시 clear_file() 함수를 실행하도록 지정하려면 어떤 함수 사용
1. _exit(clear_file)
1. **atexit(clear_file)**
1. clear_file(atexit)
1. cleaf_file(exit)

### 3. 현재 프로그램을 ls -l 명령으로 바꿔서 실행하려고 한다. 올바른 것은
1. execv("ls", "/usr/bin/ls -l", (char *)NULL)
1. execve("/usr/bin/ls", "-l", argv)
1. execlp("/usr/bin/ls", "-l", (char *)NULL)
1. **execlp("ls", "ls", "-l", (char \*)NULL)**
+ execlp은 첫 번째 인자로 주어진 프로그램 이름을 PATH에서 검색, 두 번째 인자는 실행할 프로그램, 이후는 전달할 인자.

### 4. fork() 함수로 자식 프로세스 만들고 execl() 함수를 사용해 pwd 사용하려고 한다.
1. **execl("/usr/pin/pwd", "pwd", (char \*)NULL)**
1. execl("pwd", "pwd", (char *)NULL)
1. execl("/usr/pin/pwd", (char *)NULL)
1. execl("pwd", (char *)NULL)
+ 지정된 경로에 있는 프로그램 실행, 첫 번째 인자는 경로, 두 번째 인자는 파일의 이름

### 5. 특정 자식 프로세스가 종료하기 기다리리면 어떤 함수
1. waitch()
1. **waitpid()**
1. pidwait()
1. waits()

### 6. system() 함수를 사용해서 현재 디렉터리의 절대 경로와 파일 목록 출력 프로그램 작성
[code](sol/c7_6.c)

### 7. system() 함수를 사용해 시스템에 로그인한 사용자 정보를 출력하는 프로그램 작성
[code](sol/c7_7.c)

### 8. fork() 함수를 사용해 자식 프로세스에서 현재 디렉터리의 절대 경로를 출력, 부모 프로세스에선 현재 디렉터리 내용 출력 프로그램 작성
[code](sol/c7_8.c)

### 9. vfork() 함수를 사용해 자식 프로세스에선 로그인한 사용자 정보 출력, 부모 프로세스에선 현재 시간 출력 프로그램
[code](sol/c7_9.c)

### 10. 한 프로그램은 fork() 함수를 여러 번 호출할 수 있고 fork() 함수로 생성된 자식 프로세스도 자식 프로세스를 가질 수 있다. 부모 프로세스는 자식 프로세스의 PID를 출력한다. 프로그램을 작성해 이것이 가능함을 보이시오.
[code](sol/c7_10.c)

### 11. 10번에서 작성한 프로그램에서 자식 프로세스는 부모 프로세스의 PID를 출력하도록 수정, 실행 결과 부모 프로세스의 PID는 무엇인가? 1이라면 왜? 그리고 부모 PID 출력하려면 어떻게?
[code](sol/c7_11.c)

### 12. atexit() 함수 사용해 프로그램 종료시 현재 디렉터리 내용 출력, 종료 작성
[code](sol/c7_12.c)

### 13. fork() 함수 생성한 자식 프로세스 execl() 함수 사용해서 who 명령 실행
[code](sol/c7_13.c)

### 14. execvp() 함수로 vi 실행, /etc/hosts 파일 열도록 프로그램 작성
[code](sol/c7_14.c)

### 15. 13번에서 생성한 자식 프로세스가 종료하기를 기다리도록 waitpid() 함수 사용 작성
[code](sol/c7_15.c)

### 16. 15번을 waitid() 를 사용해 작성
[code](sol/c7_16.c)
