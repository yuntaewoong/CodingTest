#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

//0:빈칸, 1:집, 2:치킨집
//집의 치킨거리: 가장 가까운 치킨집까지의 거리
//도시의 치킨거리: 도시에 속하는 집들의 치킨거리 합

// 문제: 도시의 치킨집중에서 M개를 픽해서 도시의 치킨거리의 최솟값을 구할때 그 최솟값 출력
// 해결방법: 일단 도시의 치킨거리를 빠르게 구하는 방법이 필요, 치킨집 리스트를 만들고 for문으로 최소거리가 구하기
//           M개를 픽하는 방법은 최대 13 C M이라 그렇게 안큼
//           조합을 백트래킹으로 구현하기-> DFS이용

int N;//2<= N <= 50
int M;//1<= M <= 13
int City[50][50];
vector<pair<int,int>> ChickenIndex;
bool CombinationVisited[13] = {false,};
int result = INT_MAX;


int CityChickenDifference()
{
	//인풋으로 주어진 city2차원 배열의 도시의 치킨거리 return
	int result = 0;
	vector<pair<int,int>> chickenIndex;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (City[i][j] == 2)
				chickenIndex.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (City[i][j] == 1)
			{
				int leastDifference = INT_MAX;
				for (int k = 0; k < chickenIndex.size(); k++)
				{
					int chickenI = chickenIndex[k].first;
					int chickenJ = chickenIndex[k].second;
					leastDifference = min(leastDifference, abs(chickenI - i) + abs(chickenJ - j));
				}
				result += leastDifference;
			}
		}
	}
	return result;
}
void DFSCombination(int index, int count)
{
	if (count == M)//조합 완성
	{
		for (int i = 0; i < ChickenIndex.size(); i++)
		{
			int chickenI;
			int chickenJ;
			if (CombinationVisited[i])
			{
				chickenI = ChickenIndex[i].first;
				chickenJ = ChickenIndex[i].second;
				City[chickenI][chickenJ] = 2;
			}
		}
		result = min(result, CityChickenDifference());//최솟값 업데이트
		for (int i = 0; i < ChickenIndex.size(); i++)
		{
			int chickenI;
			int chickenJ;
			if (CombinationVisited[i])
			{
				chickenI = ChickenIndex[i].first;
				chickenJ = ChickenIndex[i].second;
				City[chickenI][chickenJ] = 0;
			}
		}
		return;
	}
	for (int i = index; i < ChickenIndex.size(); i++)
	{
		if (CombinationVisited[i])
			continue;
		CombinationVisited[i] = true;
		DFSCombination(i, count + 1);
		CombinationVisited[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> City[i][j];
			if (City[i][j] == 2)
			{
				ChickenIndex.push_back(make_pair(i, j));
				City[i][j] = 0;
			}
		}
	}
	DFSCombination(0, 0);
	cout << result;
}