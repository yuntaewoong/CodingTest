# 문제
백준 2225번

# 링크
https://www.acmicpc.net/problem/2225

# 시도횟수
3회

DP로 푸는 문제  
0부터 N까지의 정수K개를 더해서 그 합이 N이 되는 경우의 수를 구하라는데  
문제 이해도 쉽지 않음..  
한 1시간 고민해보다가 모르겠어서  
구글링으로 DP테이블 값을 무엇으로 설정하는지 힌트를 얻고  
문제를 풀었다.  
이 문제는 정수 K개를 더해서 N이 되는 경우는 정수 K-1개를 더해서 N이하의 수가 되는  
모든 경우의 수의 합과 같다는 것을 적용해야 풀린다.  
그리고 인덱싱을 잘 신경써줘야 정답을 맞출수 있다.