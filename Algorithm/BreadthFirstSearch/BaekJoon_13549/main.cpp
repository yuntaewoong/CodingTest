#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;



int N;//수빈 위치(0<=N<=100000)
int K;//동생 위치(0<=K<=100000)
int result = INT_MAX;
bool visited[200001];

//걷기(+-1), 순간이동(*2) 할때 수빈이가 동생을 찾는 최소시간을 구하는 문제

//해결과정
//       일단 최대 시간은 아주 쉬움 abs(N-K)하면됨(경로를 걷기만 할때)
//       최소시간은 이제 순간이동을 적절히 섞어주면 나오게됨
//       
// 아주 무식한 DFS:걷기2가지 순간이동 1가지 총 3가지 옵션으로 계속 분기시켜서 언젠가 동생위치 나오면 return
//              이때 수빈이가 동생보다 크다면 -걷기만 해주게됨
//              이슈: 근데 최소시간을 구해야하는거라 경우의수가 너무많아짐

//BFS접근법: 걷기2가지 순간이동1가지를 BFS로 시뮬레이션해서 동생위치가 처음으로 나올때의 가중치가 답이됨
class Node
{
public:
    Node(int index,int depth) 
        : index(index),depth(depth)
    {}
    int index;
    int depth;
};

bool Visit(int index)
{
    if (index < 0 || index >= 200001)
        return false;
    if (!visited[index])
    {
        visited[index] = true;
        return true;
    }
    return false;
}

void BFS()
{
    queue<Node> bfsQueue;
    bfsQueue.push(Node(N, 0));//수빈이 위치 push
    while (!bfsQueue.empty())
    {
        int index = bfsQueue.front().index;
        int depth = bfsQueue.front().depth;
        bfsQueue.pop();

        if (index == K)
        {
            if (depth < result)
            {
                result = depth;
            }
        }
        else
        {
            if (Visit(index * 2))//순간이동(0초걸림)
                bfsQueue.push(Node(index * 2, depth));
            if (Visit(index - 1))//뒤로 걷기
                bfsQueue.push(Node(index - 1, depth + 1));
            if (Visit(index + 1))//앞으로 걷기
                bfsQueue.push(Node(index + 1, depth + 1));
        }
    }
}
int main() 
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < 200001; i++)
    {
        visited[i] = false;
    }
    BFS();
    cout << result;
    return 0;
    
}