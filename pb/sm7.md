###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# Chapter 7

#  프로세스
|기능|함수|
|:-:|:-|
| 프로그램 실행 | int system(const char *command); |
| 프로세스 생성 | pid_t fork(void); |
| " | pid_t vfork(void); |
| 프로세스 종료 | void exit(int status); |
| " | void _exit(int status); |
| 종료시 수행할 작업 지정 | int atexit(void (*function)(void)); |
| " | on_exit(void (*function)(int , void *), void *arg); |


## exec 함수군
| 함수 이름      | 파일 지정 방식            | 인자 전달 방식       | 환경 변수 전달 | 특징 및 사용 상황                                                                                 |
|----------------|---------------------------|----------------------|----------------|---------------------------------------------------------------------------------------------------|
| **execl**      | 절대 경로 또는 상대 경로  | 가변 인자 (리스트)   | X              | `execl("/bin/ls", "ls", "-l", (char *)NULL)`<br>간단한 명령 실행에 적합. 마지막 인자는 NULL 지정 필요.|
| **execlp**     | 파일명만 지정 (PATH 사용) | 가변 인자 (리스트)   | X              | `execlp("ls", "ls", "-l", (char *)NULL)`<br>`PATH`에 정의된 디렉터리에서 파일 검색. 파일 경로 지정 불필요.|
| **execle**     | 절대 경로 또는 상대 경로  | 가변 인자 (리스트)   | O              | `execle("/bin/ls", "ls", "-l", (char *)NULL, envp)`<br>환경 변수(envp)를 명시적으로 전달.         |
| **execv**      | 절대 경로 또는 상대 경로  | 배열 (포인터 배열)   | X              | `execv("/bin/ls", argv)`<br>명령과 인자를 배열로 전달. 포인터 배열의 마지막은 NULL 지정.          |
| **execvp**     | 파일명만 지정 (PATH 사용) | 배열 (포인터 배열)   | X              | `execvp("ls", argv)`<br>`PATH`에서 파일을 검색해 실행. 파일명만 필요.                             |
| **execvpe**    | 파일명만 지정 (PATH 사용) | 배열 (포인터 배열)   | O              | `execvpe("ls", argv, envp)`<br>`PATH`에서 파일을 검색하며 환경 변수(envp)를 명시적으로 전달.       |
| **execve**     | 절대 경로 또는 상대 경로  | 배열 (포인터 배열)   | O              | `execve("/bin/ls", argv, envp)`<br>환경 변수와 명령 인자를 명시적으로 지정. 최상위 구현에 사용.    |

**주요 차이점**:
1. **파일 지정 방식**:
   - `execlp`, `execvp`, `execvpe`: 파일명을 `PATH`에서 자동 검색.
   - 나머지: 절대 경로 또는 상대 경로 직접 지정.
2. **인자 전달 방식**:
   - `execl`, `execlp`, `execle`: 가변 인자(리스트 형태).
   - `execv`, `execvp`, `execvpe`, `execve`: 배열(포인터 배열).
3. **환경 변수 전달**:
   - `execle`, `execvpe`, `execve`: 환경 변수(envp) 전달

