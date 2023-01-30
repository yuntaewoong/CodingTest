# 문제
백준 1149번

# 링크
https://www.acmicpc.net/problem/1149

# 시도횟수
1회(DP첫문제라 블로그 보고품 ㅎㅎ)

DP문제의 가장 기초적인 문제다.  
3가지 색이 존재하는데, 이전 집이랑 다른 색을 칠해야 할 때,  
칠할 수 있는 경우중에서 가장 비용이 작은 경우를 구하면된다.  
아주 직관적인 해결방법으로는 DFS로 모든 경우를 검색하는것이 되겠다.  
1번째 집에 초록-2번째 집에 빨강------.....  
이런식으로 하면 당연히 답은 나오지만,  
아마 시간초과가 걸릴것이다.(N=1000,0.5초 제한)  
그래서 접근할 수 있는 2번쨰 수단이 DP이다.  
DP로 검색하면 N의 시간복잡도로 최선의 경우만(각 단계에서의 최선을 찾으므로) 확인해 볼 수 있다.  