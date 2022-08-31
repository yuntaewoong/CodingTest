#include <iostream>
#include <vector>
#include <queue>
using namespace std;



void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int index)
{

	visited[index] = true;
	cout << index + 1 << " ";
	for (int i = 0; i < graph[index].size(); i++)
	{
		if ((graph[index][i] == 1 || graph[i][index] == 1) && (visited[i] == false))
		{
			dfs(graph, visited, i);
		}
	}
}


void bfs(int index, vector<bool>& visited, const vector<vector<int>>& graph)
{
	queue<int> q;
	q.push(index);
	visited[index] = true;

	while (!q.empty())
	{
		int i = q.front();
		cout << i + 1 << " ";
		q.pop();
		for (int j = 0; j < graph.size(); j++)
		{
			if ((graph[i][j] == 1 || graph[j][i] == 1) && visited[j] == false)
			{
				q.push(j);
				visited[j] = true;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfVertex = 0;
	int numOfEdge = 0;
	int startIndex = 0;
	cin >> numOfVertex;
	cin >> numOfEdge;
	cin >> startIndex;

	vector<vector<int>> graph(numOfVertex, vector<int>(numOfVertex, 0));
	for (int i = 0; i < numOfEdge; i++)
	{
		int n1, n2;
		cin >> n1;
		cin >> n2;
		graph[n1 - 1][n2 - 1] = 1;
	}
	vector<bool> visited(numOfVertex, false);
	queue<int> visitedOrder;
	dfs(graph, visited, startIndex - 1);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);

	bfs(startIndex - 1, visited, graph);
	return 0;
}