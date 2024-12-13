# 기말고사에 필요한 구조체 모음

## Swap 영역
하드디스크의 공간을 활용해 메모리 역할을 할 수 있게 하는 공간

## sysinfo
```c
struct sysinfo {
long uptime;    // 부팅 후 경과된 시간을 초 단위로 저장
unsigned long loads[3]; // 시스템 부하 평균을 저장하는 배열, 1, 5, 15분 계산
unsigned long totalram; // 사용 가능한 총 메모리 크기
unsigned long freeram; // 사용 가능한 메모리 크기
unsigned long sharedram; // 공유 메모리 크기
unsigned long bufferram; // 버퍼가 사용하는 메모리 크기 
unsigned long totalswap; // 스왑 영역 총 크기
unsigned long freeswap; // 사용 가능한 스왑 영역
unsigned short procs; // 현재 실행 중인 프로세스 수
unsigned long totalhigh; // 메모리 영역 총 크기
unsigned long freehigh; // 사용 가능한  사용자 메모리
unsigned int mem_unit; //메모리 크기를 바이트단위
char _f[20-2*sizeof(long)-sizeof(int)]; // 64비트 크기 패딩
};
```
