# 문제
백준 2178번

# 링크
https://www.acmicpc.net/problem/2178

# 시도횟수
1회

N X M 크기의 2차원 배열에서  
1은 이동가능, 0은 이동불가능을 나타낸다.  
(1,1)에서 (N,M)으로 가는 최소 칸수를 출력하는 문제  

너비우선탐색으로 2차원 배열에 너비우선 탐색 Level값을 부여한다.
탐색 종료후 (N,M)에 부여된 Level값이 결과값이 된다.