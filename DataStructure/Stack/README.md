# Stack
LIFO(Last In First Out) 자료구조

# 구현

## 배열
연속된 메모리영역에 데이터를 저장하며  
Top을 가리키는 Index를 관리하게 구현  
처음에 할당한 크기 이상의  
메모리를 사용하려면  
메모리 재할당이 필요  

배열로 구현시 Cache Hit율을 높여서  
좀더 성능상 유리할 수 있음

## 링크드 리스트
새로 Item이 들어오면 메모리에 새로운 Node를 할당하고
이전 Node가 새로운 Node를 가리키게 하는 방식으로 구현  
배열 구현대비 구현이 간단함  
Node들이 다음 Node에 대한 Pointer를 보유해야 하므로  
배열구현대비 크기가 크다.