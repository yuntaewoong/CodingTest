# 문제
백준 2294번

# 링크
https://www.acmicpc.net/problem/2294

# 시도횟수
9회

동전의 가지수가 주어졌을때  
어떠한 조합의 동전을 몇개씩 썼을때  
목표가치를 최소동전으로 맞출수 있는가 물어보는 문제  
일반적으로 10진법의 동전체계를 쓴다면(1원,10원,100원,500원,1000원,5000원 등등)  
가장 가치가 큰 동전을 가장 많이 쓰는 그리디 방법으로 풀수 있지만  
이 문제의 경우 그리디로 풀수 없다(ex/2원,3원 동전으로 7원을 만들기 위해서 3원을 2개 쓰는게 최선의 경우가 아니다).  

그래서 DP를 써서 풀어야 한다.  
그치만, 시간초과가 많이 발생했는데  
그 이유는 미리 계산한 DP테이블의 값을 이용해서 DP테이블을 업데이트 할 수 있는지 모르고  
각각의 경우에 O(logN)의 계산을 해서 시간초과가 났다.  

이 문제의 의의는 내가 처음부터 작성한 코드로  
처음 정답처리가 난 DP문제라는 것  
뿌듯하다.