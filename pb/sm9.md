###### 이*준의 시프 정리 <br> 스스로 공부하려면 직접 정리하는 것이 좋습니다.

# 메모리 매핑 정리

##  파일 제어 함수
|기능|함수|
|:-:|:-:|
| 메모리 매핑 | void *mmap(void *addr, size_t, int prot, int flags, int fd, off_t offset); |
| 메모리 매핑 해제 | int munmap(void *addr, size_t length);
| 매핑된 메모리 동기화 | int mysnc(void *addr, site_t length, int flags) |

### void *mmap(void *addr, size_t, int prot, int flags, int fd, off_t offset);
+ addr : 매핑할 메모리 주소
+ length : 메모리 공간 크기
+ prot : 보호 모드
+ fd : 파일 기술자
+ offset : 파일 오프셋

#### 함수 특징
페이지 단위 매핑 : fd가 가르키는 파일에서 offset로 지정한 파일에서 length만큼 데이터 읽고 addr에 가르키는 메모리 공간에 매핑

##### prot 인자에 사용할 수 있는 상수
+ PROT_READ : 매핑된 파일 읽기만 하기
+ PROT_WRITE : 매핑된 파일 쓰기 허용
+ PROT_EXEC : 매핑된 파일 실행
+ PROT_NONE : 매핑된 파일 접근 X

##### flag 인자는 매핑된 데이터를 처리하기 위핸 다른 정보 지정
MAP_SHARED와 MAP_PRIVATE 둘 중 하나는 무조건 지정해야 함. (같이 지정 X) 둘만 외울것
+ **MAP_SHARED** : 다른 프로세스와 데이터 변경 내용이 공유되고 매핑된 메모리 변경 사항이 파일 자체에 반영
+ **MAP_PRIVATE** : 데이터 변경 내용 공유 X, 매핑된 메모리 변경 사항이 프로세스 종료 후 파일에 반영하지 않음
+ MAP_SHARED_VALIDATE : 플래그 조합 유효한지 검사하고 잘못될 경우 에러처리 (SHARED는 무시만 함)
+ MAP_ANONYMOUS : fd 무시 및 영역 0으로 초기화, offset이 0이여야 함
+ MAP_ANON : ANONYMOUS와 동일, 호환성을 위헤 제공
+ MAP_FIXED : 주소 정확히 지정, 매핑된 파일 있다면 영역 해제되고 매핑 수행
+ MAP_NORESERVE : PRIVATE를 공간만큼 스왑을 할당하는데, NORESERVE은 스왑 영역 할당하지 않음

