#include <iostream>
using namespace std;


int N;//N개의 수(<=1000000)
long long Numbers[1000000];
long long SegmentTree[2100000];//곱을 저장하는 세그먼트 트리,1부터 인덱스 시작
int M;//수의 변경이 일어나는 횟수(<=10000)
int K;//구간의 곱을 구하는 횟수(<=10000)


long long CreateSegmentTree(int start, int end, int segmentTreeIndex)
{
	if (start == end)
	{
		SegmentTree[segmentTreeIndex] = Numbers[start];
		return SegmentTree[segmentTreeIndex];
	}
	int mid = (start + end) / 2;
	SegmentTree[segmentTreeIndex] = 
		(CreateSegmentTree(start, mid, segmentTreeIndex * 2)*
		CreateSegmentTree(mid+1, end, segmentTreeIndex * 2+1))
		% (long long)1000000007;
	return SegmentTree[segmentTreeIndex];
}
long long ModifySegmentTree(int start, int end, int segmentTreeIndex,int toModifyIndex,long long toModifyValue)
{
	if (start > toModifyIndex || end < toModifyIndex)//범위 바깥인 경우
		return SegmentTree[segmentTreeIndex];//리프노드까지 안가도됨
	if (start == end)
	{//leaf node일때
		if (start == toModifyIndex)
		{//수정반영
			SegmentTree[segmentTreeIndex] = toModifyValue;
		}
		return SegmentTree[segmentTreeIndex];
	}
	int mid = (start + end) / 2;
	SegmentTree[segmentTreeIndex] =
		(ModifySegmentTree(start, mid, segmentTreeIndex * 2, toModifyIndex, toModifyValue) *
			ModifySegmentTree(mid + 1, end, segmentTreeIndex * 2 + 1, toModifyIndex, toModifyValue))
		% (long long)1000000007;
	return SegmentTree[segmentTreeIndex];
}

//start ~ end까지의 부분곱 리턴
//start:탐색시작, end:탐색끝, numbersStart:number배열시작점, numbersEnd:number배열 종료점
long long GetSpatialMultiple(int start, int end, int segmentTreeIndex,int numbersStart,int numbersEnd)
{
	if (start > numbersEnd || end < numbersStart)//범위 초과
		return (long long)1;
	if (start >= numbersStart && end <= numbersEnd)
	{//범위에 속한 값일 때
		return SegmentTree[segmentTreeIndex];
	}
	int mid = (start + end) / 2;
	return (GetSpatialMultiple(start, mid, segmentTreeIndex * 2, numbersStart, numbersEnd) *
		GetSpatialMultiple(mid + 1, end, segmentTreeIndex * 2 + 1, numbersStart, numbersEnd))
		% (long long)1000000007;
}
int main()
{
	cin >> N;
	cin >> M;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Numbers[i];
	}
	CreateSegmentTree(0, N - 1, 1);
	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a;
		cin >> b;
		cin >> c;
		if (a == 1)
		{
			long long toModify = Numbers[b - 1];
			Numbers[b - 1] = c;
			ModifySegmentTree(0, N - 1, 1, b - 1,Numbers[b-1]);
		}
		else if(a == 2)
		{
			cout << GetSpatialMultiple(0, N-1, 1, b-1, c-1);
			cout << "\n";
		}
	}
	return 0;
}