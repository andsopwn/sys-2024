<hr>
수고 많으십니다. 이*준입니다. 이 레파지토리는 저의 안락한 개념정리서가 필요하게 되어 만들었습니다.
<hr>

# Your Supernova ✨

## Chapter Summary
[2장 요약](pb/sm2.md) <br>
[3장 요약](pb/sm3.md) <br>

## Ans
[1강 해답보러 가기](pb/pb1.md) <br>
[2강 해답보러 가기](pb/pb2.md) <br>

<hr>

## 키워드 분류

#### 전역 정리
+ [mode_t](pb/sm1.md#mode_t) <br>
  + [파일 종류 플래그 (S_IF..)](pb/sm1.md#파일의-종류-검색-상수-flag)
  + [파일 종류 매크로 (S_IS..(m))](pb/sm1.md#파일의-종류-검색-매크로)
  + [파일권한 구분 (S_I..)](pb/sm1.md#파일-접근-권한-제어)

#### 디렉터리 관리
+ [리눅스 파일 구성 요소](https://pwned.tistory.com/80)
+ [mode_t](pb/sm2.md#mode_t) <br>
+ [디렉터리 관리](pb/sm2.md#디렉터리-관리-실습-부분)
  + [생성 및 삭제](pb/sm2.md#디렉터리-생성--삭제) <br>
  + [이름 변경](pb/sm2.md#디렉터리-이름-변경) <br>
  + [위치 검색](pb/sm2.md#디렉터리-위치-검색) <br>
  + [이동](pb/sm2.md#디렉터리-이동) <br>

#### 파일 관리
[stat 구조체](pb/sm3.md#stat-구조체) <br>
+ 파일 정보 검색
  + [stat()](pb/sm3#int-statconst-char-pathname-struct-stat-statbuf) <br>
  + [fstat()](pb/sm3#fstatint-fd-struct-stat-statbuf) <br>
+ 파일 접근 권한
  + [access()](pb/sm3.md#int-accessconst-char-pathname-int-mode)
  + [chmod()](pb/sm3.md#int-chmodconst-char-pathname-mode_t-mode)
  + [fchmod()](pb/sm3.md#int-fchmodint-fd-mode_t-mode)
+ 링크 파일 함수
  + [link](pb/sm3.md#link)
  + [symlink](pb/sm3.md#symlink)
  + [lstat](pb/sm3.md#lstat)
  + [readlink](pb/sm3.md#readlink)
  + [realpath](pb/sm3.md#realpath)
  + [unlink](pb/sm3.md#unlink)

### 파일 입출력
