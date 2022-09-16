# Priority Queue
우선순위 큐

# 구현
STL의 우선순위 큐는 구현 자료구조를 선택할 수 있다(vector,deque등등)  
문법은 다음과 같다.  
```cpp
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp);
```
이때 내부 자료구조 선택의 의미는 vector의 단점인 메모리 해제를 안하는  
이슈를 해결하는 선택권을 주는 정도의 의미가 있다.  

# 시간복잡도
삽입 : $O(logN)$  
삭제 : $O(logN)$
