# 문제
백준 1038번

# 링크
https://www.acmicpc.net/problem/1038

# 시도횟수
1회

아주 어렵고 재미있었던 문제,
일단 최대 수가 9876543210인걸 파악해야 한다.

가장 처음 취한 방법이 단순히 숫자 1부터 더해가며 해당 수가  
감소하는 수인지 파악하는 방법을 썼는데 이러면 시간복잡도가 O(n^2)을 넘어가서  
시간초과가 걸린다.  

그래서 인터넷에서 힌트를 얻은게,  
일단 모든 경우의 수를 다 구하고 정렬해서 구한다는 것이다.  
이러면 O(nlogn)이라 문제가 풀린다.  

그리고 나만의 방법을 생각해 봤는데,  
일단 수를 하나 뽑고 DFS로 수를 붙여가면서 Vector에 모든 경우를 추가하고  
나중에 정렬해주는 방법이었다.  
방법은 좋았는데, 실제 코드 구현이 좀 오래걸렸다(1시간30분).  
다음부터는 빠르게 할 수 있곘지.

