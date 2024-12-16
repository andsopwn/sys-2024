###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# Chapter 6

#  파일 제어 함수
|기능|함수|
|:-:|:-:|
| 메모리와 스왑 상태 | int sysinfo(struct sysinfo *info) |
| PID 검색 | pid_t getpid(void); |
| 부모 PID 검색 | pid_t getppid(void); |
| 프로세스 그룹 ID 검색 | pid_t getpgrp(void); |
| " | pid_t getpgid(pid_t pid); |
| 프로세스 그룹 ID 변경 | int setpgid(pid_t pid, pid_t pgid); |
| 세션 리더 ID | pid_t getsid(pid_t pid); |
| 세션 생성 | pid_t setsid(void); |

# 실행 시간 측정
| 기능 | 함수 |
|:-:|:-:|
| 실행 시간 측정 | clock_t times(struct tms *buf) |

# 환경 변수
| 기능 | 함수 |
|:-:|:-:|
| 환경 변수 검색 | char *getenv(const char *name); |
| 환경 변수 설정 | int putenv(char *string); |
| " | int setenv(const char *name, const char *value, int overwrite); |




# 프로세스 정리
## 프로세스 기본
프로세스 : 실행 중인 프로그램 의미<br>
프로세스는 당연히 text, data, heap, stack, empty area가 있다. (일반적인 스택 생각하셈)<br>

1. 프로세스는 사용자 모드에서 먼저 실행
2. 사용자 모드에서 시스템 호출 시 커널 모드로 전환
3. 커널 모드에서 더 이상 실행 없을 경우 수면 상태

+ 수면 상태 : 입출력이 끝나거나 다른 프로세스가 종료되기 기다릴 때
+ 실행대기 : 수면 상태에서 기다리다 이벤트 발생 시 

## 프로세스 그룹
+ 여러 프로세스 논리적으로 묶어 관리
+ 모든 프로세스는 그룹 구성원, **PGID**로 분류됨
+ 프로세스 실행시 부모 프로세스의 그룹에 속함. 
+ 세션 : 프로세스 그룹의 고유한 세션 **SID**로 구분

<img src="pic/process_compare.png" width=80%>

+ 리더 : 프로세스 그룹의 첫 그룹

## sysinfo 구조체
```c
struct sysinfo {
long uptime;                // 부팅 후 경과된 시간을 초 단위로 저장
unsigned long loads[3];     // 시스템 부하 평균을 저장하는 배열, 1, 5, 15분 계산
unsigned long totalram;     // 사용 가능한 총 메모리 크기
unsigned long freeram;      // 사용 가능한 메모리 크기
unsigned long sharedram;    // 공유 메모리 크기
unsigned long bufferram;    // 버퍼가 사용하는 메모리 크기 
unsigned long totalswap;    // 스왑 영역 총 크기
unsigned long freeswap;     // 사용 가능한 스왑 영역
unsigned short procs;       // 현재 실행 중인 프로세스 수
unsigned long totalhigh;    // 메모리 영역 총 크기
unsigned long freehigh;     // 사용 가능한  사용자 메모리
unsigned int mem_unit;      //메모리 크기를 바이트단위
char _f[20-2*sizeof(long)-sizeof(int)]; // 64비트 크기 패딩
};
```

일단 sysinfo로 구조체를 불러오고 거기에 대해서 프로세스 관련 함수를 사용한다.

### setpgid(pid_t pid, pid_t pgid);
pid를 입력된 pgid로 설정

특이점 
+ pid와 pgid가 같으면 pid가 그룹 리더가 됨
+ pid가 0이면 이 함수를 호출하는 현재 프로세스의 PID
+ pgid가 0이면 pid로 프로세스를 PGID 설정 (새로운 프로세스 그룹)

### getsid(pid_t pid);
+ 자신이 속한 세션의 ID를 구하려는 프로세스의 ID

# 프로세스 실행 시간 측정 방법
## tms 구조체
``` c
struct tms {
    clock_t tms_utime;  // times() 호출 프로세스가 사용한 사용자 모드 실행 시간
    clock_t tms_stime;  // " 시스템(커널) 모드 실행 시간
    clock_t tms_cutime; // "의 모든 자식 프로세스가 사용한 사용자 모드 실행 시간과 tms_utime 합계
    clock_t tms_cstime; // " 의 모든 자식 프로세스가 사용한 시스템 모드 실행시간과 tms_stime 합계
};
```

### clock_t times(struct tms *buf) 함수
+ 프로세스 실행 시간을 인자로 지정한 tms 구조체에 저장
+ sysconf(_SC_CLK_TCK)로 클록 틱 값 검색, 초당 클록 틱 값은 100

# 환경변수
+ 환경 변수는 관례적으로 대문자 사용
+ 환경 변수를 shell 값을 변경할 수 있으며 함수를 이용해 읽거나 설정

### 전역 변수 extern char \*\*environ;
+ 전역 변수 environ 환경 변수 전체에 대한 포인터

```c
char **env;
env = environ;

while (*env) {
    printf("%s\n", *env);
    env++;
}
```

### char *getenv(const char *name);
+ 환경 변수 검색

```c
char *val = getenv("SHELL");
```
+ SHELL 값이 /bin/bash

### int putenv(char *string);
+ string : 설정한 환경 변수 값으로 구성한 문자열
+ '환경 변수명=값' 형태로 지정,
+ putenv() 함수는 기존 환경 변숫값 변경, 새로운 환경 변수는 malloc()을 통해 할당

```c
putenv("TERM=vt100");
```

### int setenv(const char *name, const char *value, int overwrite);
+ putenv() 처럼 환경 변수를 설정하지만 변ㅂ수와 환경변수 값을 각각 인자로 지정
<br><br>
+ name : 환경 변수
+ value : 환경 변숫값
+ overwrite : 덮어쓰기

```c
setenv("TERM","vt100", 1);
```