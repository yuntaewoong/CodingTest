#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool IsValidIndex(int row, int col, vector<vector<int>>& tomatoes)
{
	return row >= 0 && col >= 0 && row < tomatoes.size() && col < tomatoes[0].size();
}


void BFSTomatoPollute(
	vector<vector<int>>& tomatoes,
	vector<vector<int>>& weight, 
	vector<pair<int, int>>& startingPoints
)
{
	queue<pair<int, int>> bfsQueue;
	for (int i = 0; i < startingPoints.size(); i++)
	{
		bfsQueue.push(startingPoints[i]);//시작인덱스들 큐에 넣어주기
	}
	while (!bfsQueue.empty())
	{
		pair<int, int> node = bfsQueue.front();
		bfsQueue.pop();
		int row = node.first;
		int col = node.second;
		if (tomatoes[row][col] == 1)//익은 토마토면
		{
			if (IsValidIndex(row + 1, col, tomatoes) && weight[row + 1][col] == 0)//아래
			{
				if (tomatoes[row + 1][col] == 0)
				{
					tomatoes[row + 1][col] = 1;
					bfsQueue.push(make_pair(row + 1, col));
					weight[row + 1][col] = weight[row][col] + 1;
				}
			}
			if (IsValidIndex(row, col + 1, tomatoes) && weight[row][col + 1] == 0)//오른쪽
			{
				if (tomatoes[row][col + 1] == 0)
				{
					tomatoes[row][col + 1] = 1;
					bfsQueue.push(make_pair(row, col + 1));
					weight[row][col + 1] = weight[row][col] + 1;
				}
			}
			if (IsValidIndex(row - 1, col, tomatoes) && weight[row - 1][col] == 0)//위쪽
			{
				if (tomatoes[row - 1][col] == 0)
				{
					tomatoes[row - 1][col] = 1;
					bfsQueue.push(make_pair(row - 1, col));
					weight[row - 1][col] = weight[row][col] + 1;
				}
			}
			if (IsValidIndex(row, col - 1, tomatoes) && weight[row][col - 1] == 0)//왼쪽
			{
				if (tomatoes[row][col - 1] == 0)
				{
					tomatoes[row][col - 1] = 1;
					bfsQueue.push(make_pair(row, col - 1));
					weight[row][col - 1] = weight[row][col] + 1;
				}
			}
		}
	}
}



int main()
{	
	int M, N;
	cin >> M;//가로칸
	cin >> N;//세로칸
	vector<vector<int>> tomatoes(N, vector<int>(M, 0));
	vector<vector<int>> weight(N, vector<int>(M, 0));//BFS의 depth를 기록하는 2차원 배열
	vector<pair<int, int>> startingPoints;//처음에 주어지는 익은토마토들의 index
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tomatoStatus;
			cin >> tomatoStatus;
			tomatoes[i][j] = tomatoStatus;
			if (tomatoStatus == 1)//익은 토마토면
			{
				startingPoints.push_back(make_pair(i, j));
			}
		}
	}
	//구하는 것: 토마토가 모두 익을 때까지의 최소날짜
	//예외 조건: 처음부터 모두 익어있으면 0, 익을수 없으면 -1출력

	//구하는 방법 BFS사용
	//

	BFSTomatoPollute(tomatoes, weight, startingPoints);
	bool bPolluteFinished = true;
	int maxBFSDepth = 0;
	for (int i = 0; i < tomatoes.size(); i++)
	{
		for (int j = 0; j < tomatoes[0].size(); j++)
		{
			if (tomatoes[i][j] == 0)
				bPolluteFinished = false;
			if (weight[i][j] >= maxBFSDepth)
				maxBFSDepth = weight[i][j];
		}
	}

	//결과 출력
	if (bPolluteFinished)
	{
		cout << maxBFSDepth;
	}
	else
	{
		cout << "-1";
	}
	return 0;
}