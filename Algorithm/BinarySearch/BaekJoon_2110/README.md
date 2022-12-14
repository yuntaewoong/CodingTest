# 문제
백준 2110번

# 링크
https://www.acmicpc.net/problem/2110

# 시도횟수
1회

이진 탐색 문제이다.  
이진탐색의 대상은 여러가지 종류의 값이 될 수도 있는데,  
이 문제에서는 특이하게 `공유기 사이의 간격의 최솟값의 최댓값`이  
이진탐색의 대상값이 된다.  
최솟값의 최댓값이라니 참 헷갈리는 말이다. 

이 문제에 이진탐색을 적용해야 하는 이유는 시간복잡도 때문이다.  
이진 탐색을 적용하면 $O(clogn)$ c는 공유기 개수,n은 집 개수  
의 시간복잡도로 문제를 해결할 수 있는데  
이진 탐색을 적용하지 않으면 $O(cn)$ 의 시간복잡도가 되게 된다.  

그리고 이 문제에서 마지막까지 이해가 안되었던 부분이 한가지 있었는데,  
바로 이진탐색 결과 얻어낸 1개의 값이 최솟값의 최댓값이라는게 직관적으로 잘 이해가 되지 않았다.  
근데 잘 생각을 해보면 
>공유기를 다 배치했네? 최소 간격 middle값보다 1증가,  
 공유기가 부족하네? 최대 간격 middle값보다 1감소
 
 의 과정을 최종 1개가 나올때까지 반복하는 것이다.  
 최소값 1증가,최대값 1감소의 과정속에서 가능한 모든 Interval은 고려가 가능하다.  
 더 직관적으로 이해하려면 문제를 더 풀어볼 필요가 있는 것 같다.
