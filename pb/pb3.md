###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 03

### 01. 파일명으로 파일 정보를 검색할 때 사용하는 함수는?
1. fstat()
2. **stat()**
3. inode()
4. fopen()

### 02. 매크로를 이용해 파일의 종류를 검색하려고 한다. 일반 파일인지 알아내는 매크로는?
1. S_ISLNK(m)
2. S_ISCHR(m)
3. S_ISFIFO(m)
4. **S_ISREG(m)**

### 03. access() 함수를 사용해 han.txt 파일이 존재하는지 확인하려고 한다. 올바르게 사용한 것은?
1. access("han.txt", R_OK)
2. access("han.txt", W_OK)
3. access("han.txt", IS_OK)
4. **access("han.txt", F_OK)**

### 04 chmod() 함수를 사용해 han.txt 파일의 권한을 소유자만 읽고 쓸 수 있도록 설정하려고 한다. 올바르게 설정한 것은?
1. chmod("han.txt", S_IRUSR | S_IWGRP)
2. chmod("han.txt", S_IRGRP | S_IWGRP)
3. **chmod("han.txt", S_IRUSR | S_IWUSR)**
4. chmod("han.txt", S_IRWXU | S_IWUSR)

### 05 han.ct 파일의 하드 링크로 han.ln 파일을 만들려고 한다. 맞게 사용한 것은?
1. symlink("han.txt", "han.ln")
2. **link("han.txt", "han.ln")**
3. lin("han.ln", "han.txt")
4. symlink("han.In", "han.txt")

### 06 명령행 인자로 받은 파일의 크기를 알려주는 프로그램을 작성하시오.

### 07. 명령행 인자로 받은 파일의 종류를 출력하는 프로그램을 작성하시오.

### 08. 명령행 인자로 받은 파일의 정보를 추출해 다음 예와 같이 출력하는 프로그램을 작성하시오.
실행 예
``` bash
파일명: a.c
inode 번호: 1020400
파일 종류: 일반 파일
접근 권한: 100644
UID: 1000
```
