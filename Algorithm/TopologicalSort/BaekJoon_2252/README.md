# 문제
백준 2252번

# 링크
https://www.acmicpc.net/problem/2252

# 시도횟수
1회

위상정렬 알고리즘의 기초문제.  
개념이 하나도 없었기에 인터넷으로 공부하며 주석으로 정리했다.  
위상정렬의 컨셉은 주어진 규칙들을  
2차원 배열로 정리한다음에(compare[4] = {1,3,5} -> 4번이 1,3,5보다 앞이다)  
A아이템이 B아이템 뒤에 와야한다는 규칙이 있다면 B아이템에 count++를 해주고  
이 count값이 0인 아이템들을 queue에 집어넣어서  
위상정렬 결과물에 차곡차곡 쌓는 방식  
가장 중요한 컨셉은 
```
-뒤에 와야한다는 규칙에 얽매이지 않는 아이템은  
맨앞에 배치해도 무방하다
```
 이다.