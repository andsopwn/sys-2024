###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 06

### 1. 프로세스 그룹의 PID를 읽거나 설정하는 함수가 아닌 것은?
1. getpgrp()
1. **getpdid()**
1. getppid()
1. getpgid()

### 2. ps -f 명령의 결과가 다음과 같다. 실행 파일 a.out 에서 PID와 PPID를 출력하는데 a.out 프로세스의 PPID는 무엇이며 이는 어떤 명령을 실행하고 있는가?
``` bash
$ ps -f
UID     PID     PPID    C   STIME   TTY         TIME    CMD
jw      2785    2274    0   14:45   pts/0   00:00:00    bash
jw      46875   2785    0   20:20   pts/0   00:00:00    a.out
```
PPID는 2785이며 bash이다.

### 3. times() 함수는 시간을 측정해 클록 틱 값으로 돌려준다. 현재 시스템의 클록 틱 값이 얼마인지 알 수 있는 것은?
1. **sysconf(_SC_CLK_TCK)**
1. times(_SC_CLK_TCK)
1. time(_SC_CLK_TCK)
1. sysinfo(_SC_CLK_TCK)

### 4. 시스템은 환경 변수 전체에 대한 포인터로 전역 변수를 지정했다. 이 전역 변수를 사용하려면 코드에서 어떻게 선언해야 하는가?
1. char **environ
1. char *environ
1. extern char *environ
1. **extern char \*\*enviro**

### 5. C 언어의 main() 함수는 인자로 환경 변수를 받을 수 있다. 올바르게 선언한 것은?
1. main(char **envp)
1. main(int argc, char **envp)
1. **main(int argc, char \*\*argv, char \*\*envp)**
1. main(char **argv, char **envp)

### 6. sysinfo() 함수를 사용해 시스템을 부팅하고 경과된 시간을 시간, 분 단위로 출력하는 프로그램


### 7. sysinfo() 함수를 사용해 시스템의 메모리와 스왑 영역의 상태를 출력하는 프로그램 작성

### 8. 명령행 인자로 PID를 입력받아 해당 프로세스가 속한 프로세스 그룹 IP (PGID), 세션 ID를 출력하는 프로그램 작성, 명령행 인자로 PID가 0이면 현재 프로세스를 대상으로 PPID, PGID, 세션 ID 구함

### 9. 다음과 같이 파이프로 엮인 프로세스 그룹에서 PGID는 어떤 프로세스인지 프로그램을 작성해 확인
```ps -ef | grep ssh | more | sleep 200 &```

### 10. 다음과 같이 프로그램 내에서 sleep() 함수를 사용해 5초간 잠들게 했을 때 전체 수행 시간은 어떻게 되는지 프로그램을 작성해 확인
``` C
#include <stdio.h>

int main() {
    sleep(5);
}
```

### 11. 반복문을 사용해 저수준 파일 입출력 함수인 open()과 close()를 반복적으로 100000번 실행하는 프로그램작성, 사용자  모드 실행시간, 시스템 모드 실행시간을 출력해서 비교

### 12. 1~100000까지 더하면서 결괏값을 반복으로 출력하는 프로그램 작성, 이 프로그램 전체 실행시간, 사용자모드 실행시간, 시스템모드 실행시간 측정

### 13. 명령행 인자로 입력받은 환경 변수의 값을 출력하는 프로그램 작성

### 14. putenv() 함수를 통해 변수 SHELL 값 변경 프로그램 작성, 명령행으로 인자 받기

### 15. setenv() 함수를 사용해 환경변수 TESTENV 선언, 그 값을 ubuntu로 변경, getenv() 함수로 검색해 출력

### 16. 15번 프로그램에 TESTENV 삭제기능 추가

### 17. 명령행 인자로 환경 변수명과 변숫값을 입력받아 환경 변수를 설정하는 프로그램을 작성