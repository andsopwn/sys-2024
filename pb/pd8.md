###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 08

### 1. 실행 중인 프로세스를 ```ctrl```+```c```로 종료시켰다. 이때 프로세스에 전달되는 시그널
1. SIGHUP
1. SIGINT
3. SIGQUIT
4. SIGKILL

### 2. 시그널 집합 sigst에 SIGQUIT 시그널 추가
1. signal(&sigst, SIGQUIT)
1. sigset(&sigst, SIGQUIT)
1. sigsetadd(&sigst, SIGQUIT)
1. sigaddset(&sigst, SIGQUIT)

### 3. 시그널 집합 sigst에 모든 시그널 설정, 어떤 함수 설정
1. sigfemptyset(&sigst)
2. sigfillset(&sigst)
3. sigaddset(&sigst)
4. sigsetadd(&sigst)

### 4. 시스템에서 알람 시그널과 관련해 타이머 제공, 이중 SIGALRM 시그널 발생 타이머
1. ITIMER_VIRTUAL
1. ITIMER_PROF
1. ITIMER_REAL
1. ITIMER_READLPROF

### 5. 특정 시그널 블로킹 또는 해제 함수가 아닌 것
1. sighold()
1. sigrelse()
1. sigprocmask()
1. strsignal()

### 6. 자신에게 SIGUSR1 시그널 보내는 프로그램 작성.

### 7. SIGILL 시그널 기본 처리는 코어 덤프, SIGILL 시그널 처리 시그널 핸들러 작성해서 코어덤프 확인

### 8. 리눅스는 시그널 핸들러가 한 번 실행된 후 다시 기본 처리로 리셋하지 않음. 7번 문제를 수정해서 두 번째 SIGILL 처리 실행

### 9. 시그널 집합 정의하고 여기에 SIGQUIT, SIGILL, SIGTRAP 시그널 설정, SIGILL 시그널이 설정되었는지 확인하는 프로그램 작성

### 10. 시그널 집합을 이용해 모든 시그널 집합 설정, SIGBUS가 설정되었는지 확인하고 삭제하는 프로그램 작성

### 11. sigaction()을 이용해 SIQUIT 시그널 붙잡고 처리 함수 작성, SIGQUIT 시그널 한 번 처리하면 다시 기본 처리 방법으로 바꿀 것

