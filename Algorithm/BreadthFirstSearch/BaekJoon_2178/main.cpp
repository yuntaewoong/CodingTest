#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


bool IsValidIndex(int row, int col, const vector<vector<int>>& map)
{
	return row >= 0 && row < map.size() && col >= 0 && col < map[0].size() && map[row][col] == 1;
}

int BFS(const vector<vector<int>>& map, vector<vector<int>>& weight, pair<int, int> startIndex)
{
	queue<pair<int, int>> bfsQueue;
	bfsQueue.push(startIndex);
	while (!bfsQueue.empty())
	{
		pair<int, int> node = bfsQueue.front();
		bfsQueue.pop();
		int row = node.first;
		int col = node.second;
		if (map[row][col] == 1)
		{
			if (IsValidIndex(row + 1, col, map) && weight[row + 1][col] == 0)
			{
				bfsQueue.push(make_pair(row + 1, col));
				weight[row + 1][col] = weight[row][col] + 1;
			}
			if (IsValidIndex(row, col + 1, map) && weight[row][col + 1] == 0)
			{
				bfsQueue.push(make_pair(row, col + 1));
				weight[row][col + 1] = weight[row][col] + 1;
			}
			if (IsValidIndex(row - 1, col, map) && weight[row - 1][col] == 0)
			{
				bfsQueue.push(make_pair(row - 1, col));
				weight[row - 1][col] = weight[row][col] + 1;
			}
			if (IsValidIndex(row, col - 1, map) && weight[row][col - 1] == 0)
			{
				bfsQueue.push(make_pair(row, col - 1));
				weight[row][col - 1] = weight[row][col] + 1;
			}
		}
	}
	return weight[weight.size() - 1][weight[0].size() - 1] + 1;
}


int main()
{
	FAST_IO;
	int N = 0;//За
	int M = 0;//ї­
	cin >> N;
	cin >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<int>> weight(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = stoi(temp.substr(j, 1));
		}
	}
	int result = 0;
	result = BFS(map, weight, make_pair(0, 0));
	cout << result;
	return 0;
}