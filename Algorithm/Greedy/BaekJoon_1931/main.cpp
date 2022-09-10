#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int,int> a, pair<int, int> b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}

}

int main()
{	
	//회의실 배정문제
	//회의 스케줄정보가 주어졌을때, 가장 회의를 많이할수 있는 수를 구하는 것
	//방법: 끝나는 시간 순서대로 정렬(O(nlogn), 정렬의 이유: 빨리 끝나는 것부터 집어넣어야 회의를 가장 많이 할수있음
	//      정렬된 배열을 돌면서 회의를 배치할 수 있으면 배치(O(logn))
	//
	int N;
	cin >> N;
	vector<pair<int, int>> interviews;
	for (int i = 0; i < N; i++)
	{
		int startTime;
		int endTime;
		cin >> startTime;
		cin >> endTime;
		interviews.push_back(make_pair(startTime, endTime));
	}
	sort(interviews.begin(), interviews.end(), compare);

	int numInterviews = 0;
	int currentEndTime = 0;
	for (int i = 0; i < N; i++)
	{
		if (interviews[i].first >= currentEndTime )
		{
			currentEndTime = interviews[i].second;
			numInterviews++;
		}
	}

	cout << numInterviews;
	return 0;
}