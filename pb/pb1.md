###### 서준이의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 01

### 01. 다음 중 리눅스/유닉스 시스템 프로그래밍과 관련이 있는 표준이 아닌 것은?
1. ANSI C 표준
2. POSIX
3. **다중 유닉스 명세**
4. 시스템 V 인터페이스 정의

### 02. man 페이지 번호에서 시스템 호출을 나타내는 섹션 번호는?
1. 1
2. **2**
3. 3
4. 5

+ 1 - 리눅스에서 사용하는 일반적인 명령에 대한 설명
+ 2 - 시스템 호출
+ 3 - 라이브러리 함수

### 03. 시스템 호출이 실패하면 -1을 리턴한 뒤 오류 코드를 특정 변수에 저장한다. 이 변수명은?
1. eno
2. error
3. enum
4. **errno**

### 04. 리눅스 기본 명령 중 패턴을 검색할 때 사용하는 명령은?
1. ls
2. cat
3. **grep**
4. which

### 05. han.c를 컴파일 할 때 실행 파일명을 han 으로 하려한다. 옵션 바르게 설정한 것은?
1. gcc han.c
2. gcc -c han han.c
3. gcc -a han han.c
4. **gcc -o han han.c**

### 06. 시스템 호출과 라이브러리 함수의 차이점을 동작 과정 비교를 통해 설명하시오.
시스템 호출은 커널의 해당 모듈을 직접 호출해 작업하고 결과를 리턴한다. <br>
라이브러리 함수는 커널 모듈을 직접 호출하지 않고 함수 내부에서 시스템 호출을 사용한다.

### 07. man write 명령을 실행했는데, write() 함수가 아니라 write 명령에 대한 메뉴얼이 출력 되었다. write() 함수의 메뉴얼을 보려면 어떻게 해야 할까?
man을 호출할 때 섹션을 호출하지 않으면 가장 낮은 버전이 출력된다. `man write` 명령을 입력했다면 함수의 설명을 호출한 것이다. <br> 우리는 `man -s 3 write`를 통해 함수의 메뉴얼을 호출해야 한다.

### 08. 시스템 호출에서 오류가 발생하면 errno 변수에 오류의 원인을 설명하는 숫자가 저장된다. 오류 번호가 1이라면 어떤 오류일까?
오류 번호가 1일 경우 Operation not permitted로 권한 문제이다.

### 09. [예제 1-1]을 수정해 errno 번호 뿐만이 아니라 오류 메시지도 출력되도록 코드를 수정하시오 ([예제 1-4] 참조)
``` c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main() {
   if(access("test.txt", F_OK) == -1) {
      perror("test.txt");
      exit(-1);
   }
}
```

``` bash
test.txt: No such file or directory
```

### 10. gcc로 소스 코드를 컴파일했더니 실행 파일 a.out이 만들어졌다. 실행 파일을 ex10.exe로 만들려면 어떻게 해야할까?
``` bash
gcc -o ex10.exe {code}.c
```

### 11. gcc로 소스코드를 컴파일해 실행파일인 ex11.exe를 만들었다. ls 명령으로 확인하면 ex11.exe가 보이는데, ex11.exe를 실행하면 파일을 찾을 수 없다고 한다. 무엇이 문제이고 어떻게 해결하는가.
실행 권한 문제일 가능성이 있다. <br>
또는 컴파일시 디렉토리를 잘못 입력하여 엉뚱한 디렉토리에 컴파일된 파일이 있을 수 있다.
``` bash
gcc {file}.c -o {dir}/ex11.exe 
```

### 12. [예제 1-3]에서 인자로 받은 두 정수의 뺄셈을 계산해 리턴하는 subnum() 함수를 subnum.c 파일로 만들고 Makefile을 수정해 실행 파일을 생성한 뒤 실행 결과를 확인하시오.

Makefile
``` Makefile
# Makefile
CC=gcc
CFLAGS=
OBJS=ex_1_3.o subnum.o
LIBS=
all : add.out

add.out : $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

ex1_3.o : ex_1_3.c
	$(CC) $(CFLAGS) -c ex_1_3.c
subnum.o : subnum.c
	$(CC) $(CFLAGS) -c subnum.c

clean:
	rm -f $(OBJS) add.out *.o core
```

ex_1_3.c
``` C
#include <stdio.h>

extern int subnum(int a, int b);

int main() {
    printf("subnum - %d\n", subnum(10, 5));
}
```

subnum.c
``` C
int subnum(int a, int b) {
    return a - b;
}
```
이제 make해준다.

### 13. 프로그램을 실행하는 도중에 정숫값 200개를 저장할 수 있도록 메모리를 할당하려면 어떻게 해야할까?
``` C
int   *new_malloc = malloc(200 * sizeof(int));
int   *new_calloc = (int *)calloc(200, * sizeof(int));
free(new_malloc);
free(new_calloc);
```


### 14. 명령행 인자로 정숫값(작은 수, 큰 수) 2개를 받아서 앞의 값부터 뒤의 값까지 합계를 구하는 프로그램을 작성하시오.
``` C
#include <stdio.h>

int main(int argc, char **argv) {
    long long num0, num1;
    
    if(argc != 3) {
        puts("./p14 {integer} {integer}");
        return 1;
    }
    
    sscanf(argv[1], "%lld", &num0);
    sscanf(argv[2], "%lld", &num1);

    printf("%lld\n", (num0 + num1) * ((num1 - num0) + 1) / 2);
}
```


### 15. 명령행 인자와 getopt() 함수를 사용해 다음 명령을 처리하는 프로그램을 작성하시오.
1. 명령의 이름 : ex1_15.out
2. 명령의 옵션과 동작
   +  인자가 없을 경우 : -h 처럼 사용 가능한 옵션의 목록 출력
   +  -p : "Welcome Linux System Programming!" 출력
   +  -h : 사용 가능한 옵션의 목록 출력

