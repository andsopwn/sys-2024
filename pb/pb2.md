###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 풀어보는 것이 좋습니다.

## Chapter 02

### 01. 리눅스에서 파일의 정보를 저장하고 있는 자료구조는?
1. **inode**
2. anode
3. fnode
4. unode

### 02. mkdir은 명령과 시스템 호출에서 같은 이름을 사용한다. man 명령으로 mkdir 시스템 호출을 보는 올바른 방법은?
시스템 호출은 ```man -s 2 mkdir``` , 명령어 확인은 ```man -s 1 mkdir```

### 03. opendir() 함수가 디렉터리를 열고 리턴하는 디렉터리 스트림 객체 이름은?
1. dir
2. dirp
3. dirent
4. **DIR**

### 04. 디렉터리 내용을 읽어서 해당 디렉터리에 있는 파일명을 출력하려고 한다. 디렉터리의 내용을 가져오는 함수는?
1. opendir()
2. telldir()
3. **readdir()**
4. seekdir()

```
opendir() : 디렉터리 열기 위한 함수
telldir() : 디렉터리 스트림에서 현재 위치를 반환
readdir() : 디렉터리에서 파일의 정보를 읽어들임<
seekdir() : telldir()을 통해 얻은 위치로 디렉터리 스트림의 위치를 설정
```

### 05. 디렉터리의 정보를 읽으면 디렉터리의 내용을 읽는 위치가 변경된다. 디렉터리의 특정 위치로 이동할 때 사용하는 함수는?
1. telldir()
2. **seekdir()**
3. readdir()
4. godir()

### 06. mkdir() 함수를 사용해 디렉터리를 2개(dir1, dir2) 만들고, 이중 dir1은 rmdir() 함수로 삭제하고 dir2는 rename() 함수를 사용해 hanbit으로 바꾸는 프로그램을 작성하시오.
```c
mkdir("dir1", 0755);
mkdir("dir2", 0755);

rmdir("dir1");
rename("dir2", "hanbit");
```


### 07. rmdir() 함수를 사용해 존재하지 않는 디렉터리를 삭제하려고 하면 어떤 오류 메시지가 출력되는지 확인하시오.
```bash
No such file or directory
```

### 08. 현재 디렉터리를 기억하고 있다가 다른 디렉터리로 이동해 작업한 후 원래 디렉터리로 돌아오도록 프로그램을 작성하시오.
[코드](sol/c2_8.c)

### 09. [예제 2-6]에는 getcwd() 함수가 오류를 리턴할 때 처리하는 코드가 없다. 오류가 발생할 경우 처리하는 코드를 추가해 예제를 작성하시오.
[코드](sol/c2_9.c)

### 10. 디렉터리가 비어 있는지 확인 후 디렉터리가 비어 있다는 메시지를 출력하고 해당 디렉터리를 삭제하는 프로그램을 작성하시오.
[코드](sol/c2_10.c)

### 11. 디렉터리명을 명령행 인자로 입력받아 생성하고, 작업 디렉터리를 새로 생성한 디렉터리로 이동시키는 프로그램을 작성하시오.
[코드](sol/c2_11.c)

### 12. '.'과 '..' 항목을 제외하고 디렉터리에 있는 파일이나 하위 디렉터리명을 출력하는 myls 프로그램을 작성하시오.
[코드](sol/myls.c)
