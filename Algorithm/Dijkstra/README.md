# Dijkstra
Graph자료구조에서 Edge가 가중치를 가질 때, 기준 Vertex에서  
다른 모든 Vertex로의 최단 거리를 구하는 알고리즘  

# 구현
```cpp
vector<vector<pair<int, int>>> node(20003);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > priorityQueue;
vector<int> value(20003,INT_MAX);
while (!priorityQueue.empty())
	{
		int parentWeight = priorityQueue.top().first;
		int startVertexNum = priorityQueue.top().second;
		priorityQueue.pop();

		for (int i = 0; i < node[startVertexNum].size(); i++)
		{
			int goalVertexNum = node[startVertexNum][i].first;
			int weight = node[startVertexNum][i].second;

			if (parentWeight + weight < value[goalVertexNum])
			{
				value[goalVertexNum] = parentWeight + weight;
				priorityQueue.push(make_pair(parentWeight + weight, goalVertexNum));
			}
		}
	}
```
- BFS와 거의 똑같다(우선순위 큐를 사용하는 것만 다르다)
- 최단 거리 : `value[index]`
- 우선순위 큐를 사용해야만 하는 이유: 우선순위 큐 말고 그냥 큐를 써도 결과는 똑같이 나온다. 다만, 우선순위큐를 사용하면 weight값이 가장 작은 노드부터  
작업을 진행해서 특정 i에 대해 value[i]가 2번이상 업데이트 되는 경우를 막아준다.(처음 1번 업데이트되는 값을 계속 사용)
# 시간복잡도
$O((V+E)logV)$ -> BFS에서 우선순위큐의 POP연산 복잡도를 곱한것과 같음