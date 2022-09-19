#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int main() 
{
	//다익스트라 알고리즘을 이용한 최단거리 문제
	//구글링해서 답지보고 분석하는 방식으로 공부

	vector<vector<pair<int, int>>> node(20003);//pair는 Edge들의 (종점,가중치)을 의미
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > priorityQueue;//pair의 의미는(가중치,버텍스번호)
	//queue<pair<int, int>> priorityQueue;
	vector<int> value(20003,INT_MAX);//각 Vertex의 가중치(루트는0, 각 엣지의 수만큼 더해서 다음 버텍스에 대입)
	
	int V;
	int E;
	int K;
	cin >> V;
	cin >> E;
	cin >> K;
	for (int i = 0; i < E; i++) 
	{
		int u, v, w;
		cin >> u;
		cin >> v;
		cin >> w;
		node[u].push_back(make_pair(v, w));
	}

	value[K] = 0;
	priorityQueue.push(make_pair(0, K));

	while (!priorityQueue.empty()) //value벡터에 루트노드기준 모든 노드의 가중치를 채우는 작업을 함(각 노드의 가중치는 가질수 있는 최솟값임)
	{//다익스트라 알고리즘이 priority queue를 사용하는 이유는 가중치가 작은 노드를 먼저 꺼내기 위해서
		//가중치가 큰 노드를 먼저 꺼낸다면, 
		
		int parentWeight = priorityQueue.top().first;
		int startVertexNum = priorityQueue.top().second;
		priorityQueue.pop();

		for (int i = 0; i < node[startVertexNum].size(); i++)
		{
			int goalVertexNum = node[startVertexNum][i].first;
			int weight = node[startVertexNum][i].second;

			if (parentWeight + weight < value[goalVertexNum])//더 작은 가중치가 가능하다면
			{
				value[goalVertexNum] = parentWeight + weight;
				priorityQueue.push(make_pair(parentWeight + weight, goalVertexNum));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (value[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << value[i] << "\n";
	}
	return 0;
}