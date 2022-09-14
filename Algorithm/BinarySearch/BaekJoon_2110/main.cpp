#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//housePositions는 정렬된 벡터, C는 공유기 배치할 개수
//리턴값은 가장 인접한 공유기사이의 간격의 최대값(이분탐색 대상)
int HouseIntervalBinarySearch(vector<int>& housePositions,int C)
{
	int minimumInterval = 0;
	int maximumInterval = housePositions[housePositions.size() - 1]-1;
	int resultInterval = 0;
	while (minimumInterval <= maximumInterval)//이분 탐색 범위가 최종 1개로 좁혀질때까지
	{
		int middleInterval = (maximumInterval + minimumInterval) / 2;
		//공유기들 middleInterval을 가장 인접한 간격의 최댓값으로 삼고 배치 진행
		int placedRouter = 1;//첫번째 공유기는 0번 인덱스에 설치했다고 가정하고 알고리즘 진행
		int start = housePositions[0];
		for (int i = 0; i < housePositions.size(); i++)
		{
			int end = housePositions[i];
			if (end - start >= middleInterval)
			{
				placedRouter++;
				start = end;
			}
		}
		//공유기를 다 할당하지 못했을 때(middleInterval이 결과값보다 큰경우)
		if (placedRouter < C)
		{
			maximumInterval = middleInterval - 1;
		}
		else//공유기를 다 할당했을 때(middleInterval이 결과값보다 작은경우
		{
			minimumInterval = middleInterval + 1;
			resultInterval = middleInterval;//마지막으로 공유기를 다 할당한경우가 값을 찾은 경우
		}
	}
	return resultInterval;
}


int main()
{	
	//N개의 집좌표(1차원)와 C개의 공유기가 있을때
	//C개의 공유기를 집에 설치함
	//근데, 가장 인접한 공유기 사이의 거리가 최대가 되게 배치해야함
	//이는 즉, 최대한 띄엄띄엄 공유기를 배치하라는 것
	//일단 처음좌표랑 마지막 좌표는 무조건 배치
	//힌트는 이분 탐색
	//일단 정렬하고 O(nlogn)
	//이분탐색 시작, 
	//이분탐색의 대상은 집들 사이의 최소 간격
	//집들 사이의 간격은 최소 1이고 최대는 마지막집-첫째집 좌표이다
	//중간값을 최소간격으로 잡았을때
	//	case1.공유기를 더 설치할 수 있는 경우
	//  case2.공유기가 모자란 경우
	//  case1이면, 간격이 더 넓은 범위를 이분탐색하고
	//  case2이면, 간격이 더 좁은 범위를 이분탐색하고
	//이때의 시간 복잡도는 O(clogn)
	//이진 탐색을 하지 않아도 풀수는 있는데 시간복잡도가 O(cn)이 나와서 시간초과 나올삘


	int N;
	int C;
	cin >> N;//집의 개수
	cin >> C;//공유기의 개수

	vector<int> housePosition(N, 0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		housePosition[i] = temp;
	}
	sort(housePosition.begin(), housePosition.end());//오름차순 정렬

	cout << HouseIntervalBinarySearch(housePosition, C);
	return 0;
}