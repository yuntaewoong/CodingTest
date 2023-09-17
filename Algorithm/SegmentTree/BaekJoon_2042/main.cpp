#include <iostream>
#include <vector>
using namespace std;

int N;//수의 개수(<=1000000)
long long Numbers[1000001];//각 숫자는 -2의 63승 ~ 2의 63승 범위(8바이트 자료형)
long long SegmentTree[2097152];
//세그먼트 트리,아이템 개수는 1 + 2 + 2^2 +...2^(트리높이)
// 트리 높이는 2의 20제곱이 1048576이니까 21이라는 것을 알 수 있음
// 그러므로 배열 크기는 트리를 전부 할당가능한 2의 21제곱으로 한다
// 1번 인덱스부터 아이템을 채움
// 1번에는 Numbers의 전체합
// 2번에는 1 ~ numbers수 절반, 
// 3번에는 numbers수 절반~마지막 합 저장
// 리프노드가 수의 합이 아니라 수 1개가 될때까지 재귀호출

int M;//수의 변경이 일어나는 횟수<=10000)
int K;//구간의 합을 구하는 횟수(<=10000)

//segmentTreeIndex-> 만들고자 하는 노드
//numStartIndex-> 부분합 시작 인덱스
//numEndIndex-> 부분합 종료 인덱스
long long CreateSegmentTree(int segmentTreeIndex,int numStartIndex,int numEndIndex)
{
	if (numStartIndex == numEndIndex)
	{//더이상 자식으로 분할 못하는 경우
		SegmentTree[segmentTreeIndex] = Numbers[numStartIndex];
		return Numbers[numStartIndex];
	}
	int middle = (numStartIndex + numEndIndex) / 2;
	SegmentTree[segmentTreeIndex] =
		CreateSegmentTree(segmentTreeIndex * 2, numStartIndex, middle) +
		CreateSegmentTree(segmentTreeIndex * 2 + 1, middle + 1, numEndIndex);
	return SegmentTree[segmentTreeIndex];
}

//Numbers의 start ~ end까지의 범위 안에서
//segmentTree[segmentTreeIndex]값을 재귀적으로 업데이트
void ModifySegmentTree(int start,int end,int segmentTreeIndex,int toModifyIndex,long long diff)
{
	if (toModifyIndex < start || toModifyIndex > end) 
		return;//Numbers의 start,end범위에 toModifyIndex가 없으면 작업할게 없음
	SegmentTree[segmentTreeIndex] += diff;
	if (start == end)
		return;//최하위 노드이므로 작업종료
	int mid = (start + end) / 2;
	ModifySegmentTree(start, mid, segmentTreeIndex*2, toModifyIndex, diff);
	ModifySegmentTree(mid + 1, end, segmentTreeIndex*2 + 1, toModifyIndex,diff);
}

//start ~ end까지의 합 리턴
long long GetSpatialSum(int start,int end,int segmentTreeIndex,int numbersStart,int numbersEnd)
{
	if (start > numbersEnd || end < numbersStart)
		return 0;//범위 바깥
	if (start >= numbersStart && end <= numbersEnd)
		return SegmentTree[segmentTreeIndex];//구하고자하는 범위안의 부분합인 경우 리턴
	int mid = (start + end) / 2;
	return GetSpatialSum(start, mid, segmentTreeIndex * 2, numbersStart, numbersEnd)
		+ GetSpatialSum(mid + 1, end, segmentTreeIndex * 2 + 1, numbersStart, numbersEnd);
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
	CreateSegmentTree(1, 0, N - 1);


	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b;
		cin >> c;
		if (a == 1)
		{//a가 1이면 수정
			//Numbers[b - 1] = c;
			long long diff = c - Numbers[b - 1];//세그먼트 트리에 해당하는 노드에 더해줄 차이값
			Numbers[b - 1] = c;//Number에 변경된 값 반영
			ModifySegmentTree(0, N - 1, 1,b - 1,diff);
		}
		else if (a == 2)
		{//a가 2면 출력
			/*for (int i = b - 1; i < c; i++)
				result += Numbers[i];*/
			cout << GetSpatialSum(0,N-1, 1, b - 1, c - 1);
			cout << "\n";
		}
	}
	return 0;
}