# get_next_line

**프로젝트 개요**
get_next_line은 파일 디스크립터에서 BUFFER_SIZE만큼 데이터를 읽어 한 줄 단위로 반환하는 함수를 구현한 교육용 프로젝트입니다.

**프로젝트 의의**
- 연속된 `read` 호출을 통해 버퍼를 관리하고, 남은 데이터를 다음 호출로 전달하는 로직을 학습합니다.
- 정적 변수(`static`)를 활용하여 이전 호출의 상태를 유지하고, 효율적인 메모리 사용 기법을 익힙니다.
- 다양한 파일 입출력 상황에서 안정적으로 동작하도록 에러 처리와 메모리 누수 방지 기법을 강화합니다.

## 라이센스
이 프로젝트는 **Beerware License (Revision 42)**를 따릅니다.

```
THE BEER-WARE LICENSE (Revision 42)
As long as you retain this notice you can do anything with this stuff.
If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.
```
