# 문제
백준 14503번

# 링크
https://www.acmicpc.net/problem/14503

# 시도횟수
1회

로봇청소기의 규칙을 구현해서 방을 청소하고  
청소한 칸수를 세는 문제  
최적의 경로를 계산하거나 하는게 아니라  
그냥 규칙그대로 로봇을 움직이는거라 쉬웠다.  
다만, 2가지 때문에 좀 시간이 걸렸는데  
1. 상하좌우를 명확히 정의하지 않아서 후진,전진이 잘못구현되었었음
2. 반시계방향 회전할때 Mod연산결과가 음수가 나오는것을 몰랐음  

이 2개를 해결하니 바로 문제가 풀렸다.