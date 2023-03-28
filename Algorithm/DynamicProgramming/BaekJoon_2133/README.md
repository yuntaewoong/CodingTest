# 문제
백준 2133번

# 링크
https://www.acmicpc.net/problem/2133

# 시도횟수
4회

3 X N의 타일공간에 2 X 1, 1 X 2의 타일을 붙이는 경우의수 구하는 문제  
처음에는 타일을 배치하는 특이 case가 3 X 4일때만 있는 줄 알았는데  
검색해보니 모든 경우에 특이 case가 2가지가 있는것을 알게되었다.  

문제 해결은 DP알고리즘으로 이전 case의 경우에 추가로 3 X 2타일을 붙이는 경우를 더해주고  
추가공간에 넣을수 있는 case들을 모두 더해주면된다.  
이 추가 case들을 구하기위해 이중 포문을 사용한다.