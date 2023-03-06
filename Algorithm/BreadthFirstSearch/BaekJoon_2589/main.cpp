#include <iostream>
#include <queue>

using namespace std;

int Length;//세로길이(<=50)
int Width;//가로길이(<=50)
string Island[50][50];
bool Visited[50][50];
int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { -1,1,0,0 };//상하좌우

int result = 0;

class Node
{
public:
	Node(int i, int j, int depth)
		: i(i), j(j), depth(depth)
	{}
	int i;
	int j;
	int depth;
};

void InitVisited()
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Visited[i][j] = false;
		}
	}
}
void BFS(int i, int j)
{
	queue<Node> bfsQueue;
	Visited[i][j] = true;
	bfsQueue.push(Node(i, j, 0));
	while (!bfsQueue.empty())
	{
		int nodeI = bfsQueue.front().i;
		int nodeJ = bfsQueue.front().j;
		int nodeDepth = bfsQueue.front().depth;
		result = max(nodeDepth, result);
		bfsQueue.pop();
		for (int k = 0; k < 4; k++)
		{
			int nextI = nodeI + dy[k];
			int nextJ = nodeJ + dx[k];
			if (nextI < 0 || nextI >= 50 || nextJ < 0 || nextJ >= 50)
				continue;
			if (Island[nextI][nextJ] == "L" && !Visited[nextI][nextJ])
			{
				Visited[nextI][nextJ] = true;
				bfsQueue.push(Node(nextI, nextJ, nodeDepth + 1));
			}
		}
	}
}



//문제: 지도가 주어졌을때 보물2개가 묻혀있는 거리를 구하는 문제
//       이때 보물2개는 한 육지에서 최단거리로 이동시 가장 먼거리에 위치하게됨(지도당 2개)

//시간초과 날지도 모르지만 확실히 해결할수 있는 방법
//2중 포문을 돌면서 각각 BFS로 가중치를 구한다.
//가중치의 최댓값이 문제 해답
int main()
{
	cin >> Length >> Width;
	for (int i = 0; i < Length; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < Width; j++)
		{
			Island[i][j] = temp[j];
			Visited[i][j] = false;
		}
	}


	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (Island[i][j] == "L")
			{
				BFS(i, j);
				InitVisited();
			}
		}
	}
	cout << result;
}