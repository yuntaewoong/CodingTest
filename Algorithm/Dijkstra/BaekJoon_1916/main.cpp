#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Node
{
public:
    Node()
    {}
    Node(int number ,int cost)
        : number(number),cost(cost)
    {}
    int number;//방문 노드 번호(도시번호
    int cost;//해당 도시까지의 비용
};

struct cmp
{
    bool operator()(Node n1, Node n2)
    {
        return n1.cost > n2.cost;
    }
};
bool compare(Node n1, Node n2)
{
    return n1.cost < n2.cost;
}

int N;//도시 개수(1<= N <= 1000)
int M;//버스 개수(1<= M <= 100000)
vector<Node> Bus[100001];//ex: 1번 버스에서 출발하는 간선정보 vector에 대한 접근: Bus[1]
int minimumDistancs[1001];//startPoint에서 각 도시까지의 최단거리 배열

int startPoint;
int endPoint;

int main() 
{
    //버스는 시작-도착-비용 정보가 저장되어 있음
    //startPoint에서 endPoint까지 최소비용을 출력(무조건 갈수있는 입력만 주어진다 가정)

    //다익스트라 알고리즘임
    //다익스트라 알고리즘의 개념은 시작정점부터 모든 정점까지의 최단거리를 업데이트하는 과정이라는 것
    //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    priority_queue<Node, vector<Node>, cmp> priorityQueue;
    for (int i = 1; i <= N; i++)
    {
        minimumDistancs[i] = INT_MAX;//각 정류장에대한 최단거리 초기값은 INF값
    }
    for (int i = 0; i < M; i++)
    {
        int start;//시작 정점
        int number;//도착 정점
        int cost;
        cin >> start >> number >> cost;
        Bus[start].push_back(Node(number, cost));
    }
    for (int i = 1; i <= M; i++)
    {
        sort(Bus[i].begin(), Bus[i].end(),compare);
    }
    cin >> startPoint;
    cin >> endPoint;

    priorityQueue.push(Node(startPoint, 0));//다익스트라 알고리즘 시작 정점 Push
    while(!priorityQueue.empty())
    {
        int number = priorityQueue.top().number;//방문한 정점 번호
        int cost = priorityQueue.top().cost;//방문한 정점까지의 거리
        priorityQueue.pop();
        for (int i = 0; i < Bus[number].size(); i++)//방문한 정점에서 시작하는 정점들 순회
        {
            int nextNumber = Bus[number][i].number;
            int nextCost = Bus[number][i].cost;
            if (cost + nextCost < minimumDistancs[nextNumber])//최단거리 갱신조건 만족하면
            {
                minimumDistancs[nextNumber] = cost + nextCost;//최단거리 갱신
                priorityQueue.push(Node(nextNumber,cost+ nextCost));//갱신된 최단거리로 방문
            }
        }
    }
    cout << minimumDistancs[endPoint];
    

    return 0;
    
}