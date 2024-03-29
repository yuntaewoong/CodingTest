# 문제
백준 2206번

# 링크
https://www.acmicpc.net/problem/2206

# 시도횟수
2회

N * M 사이즈의 보드에  0이라는 빈칸과  
1이라는 벽이 있을 때,  
벽을 단 1회 통과가능할 시  
우측하단까지의 최단경로의 칸수를  
구하는 문제  
우선 DFS로 시도해봤다가 시간초과가 발생했다.  
시간초과가 발생한 이유는 바로 한반 방문했던 노드를  
몇번이고 다시 반복해서 방문하면서  
모든 경우를 탐색한 후에 그 중 최솟값을 구했기 때문..  

그래서 BFS로 전환해서 해결해보다가 못해먹겠어서 구글의 도움을 얻어서  
해결했다.  
```cpp
int dx[] = { 0, 0, -1, 1 }; //상하좌우
int dy[] = { 1, -1, 0, 0 }; //상하좌우
for (int k = 0; k < 4; k++) 
{
    {
            int n_x = i + dx[k];
            int n_y = j + dy[k];
    }
}
```
2차원 배열을 탐색할때는 위와같은 코드를 쓰는게 코드가 한  
5배는 줄어드니까 꼭 쓰자  

그리고 이 문제는 3차원 배열을 쓰는게 핵심포인트인 문제.  
모든 배열칸마다 벽을 뚫고 온 경우와 벽을 안뚫고 온 경우 2가지를  
계산해서 누적해나가는 느낌임.