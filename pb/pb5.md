###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 05

### 1. 다음과 같이 uname()  함수를 사용해 운영체제 정보를 검색했다. 운영체제 이름을 출력할 수 있도록 올바르게 작성한 것은?
```c
struct utsname uts;
uname(&uts);
```
1. printf("%s"\n", uts.nodename)
1. printf("%s"\n", uts.osname)
1. printf("%s"\n", uts.sysname)
1. printf("%s"\n", uts.uname)

### 02. sysconf() 함수를 사용해 로그인 명의 최대 길이를 알아보려고 한다. 올바르게 작성한 것
1. sysconf(_SC_NAME_MAX)
1. sysconf(_SC_LOGIN_NAME_MAX)
1. sysconf(_SC_LOGINNAME_MAX)
1. sysconf(_SC_LOGIN_MAX)

### 03. 로그인 명이 hanbit인 사용자 정보를 패스워드파일에서 읽어오려고 한다 올바르게 작성한것
1. getspname("hanbit")
1. getspnam("hanbit")
1. getpwname("hanbit")
1. getpwnam("hanbit")

### 04. /etc/group 파일을 순차적으로 읽다가 파일의 오프셋을 처음으로 위치시키려고 한다. 이때 사용하는 함수
1. getgrent()
2. lseek()
2. setgrent()
2. fseek()

### 05. localtime() 함수로 시간정보 분해하고 출력, 120으로 연도가 나옴 이건 몇년 의미 ?
1. 2020
1. 2030
1. 2010
1. 1200

### 06. uname 함수를 사용해서 myuname 명령 만드시오
명령 ```myuname```
옵션 ```-a: 전체정보 -k: 커널 릴리즈출력 -r : 커널 버전 번호 출력 -n :호스트 이름 출력 -h : 하드웨어명 출력 -s : 운영체제명 출력```

### 07. uname과 gethostname 함수로 호스트 이름을 검색해 출력하시오. ㄷ이때 두 함수가 출력하는 이름 같은지 다른지 적으시오. 

### 08. syconf 함수 호스트명 최대길이 최대프로세스 개수 로그인명의 최대길이 프로세스당 열 수 있는 파일 수, 시스템이 지원하는 POSIX.1의 버전 정보를 출력하는 mysys 명령을 작성하시오.
```명령``` mysys
```옵션``` -a : 전체 정보 -h : 호스트명 최대 길이 -p : 최대 프로세스 개수 -l : 로그인명의 최대길이 -x : posix 버전

### 09. sysconf 함수 사용자가 입력한 로그인 아이디 길이가 시스템 로그인 이름의 최대 길이보다 큰지 확인

### 10. 사용자 아이디를 통해 홈 디렉터리와 로그인 쉘 출력 프로그램 작성

### 11. 사용자 아이디를 입력받아 패스워드 에이징 정보 출력 

### 12. 사용자 이름 받아 1차 그룹 2차그룹 검색 프로그램

### 13. 사용자 이름을 입력받아 사용자 암호 변경 시간 연월일 형태로 출력

### 14. /var/log/wtmp 파일의 정보를 통해 로그인 명과 터미널 정보 로그아웃 시각 원격 접속 정보 출력 프로그램

### 15. 날짜와 시간 출력하는 명령 mydate 작성 