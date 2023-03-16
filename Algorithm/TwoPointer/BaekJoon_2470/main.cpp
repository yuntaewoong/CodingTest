#include <iostream>
#include <algorithm>
using namespace std;




int N;//용액 수 2<= N <= 100000
int Liquids[100000];//용액종류
pair<int, int> resultPoint;//결과 포인터
int minimum = 2000000001;
int leftPointer;
int rightPointer;

//산성도는 +, 염기성도는 -로 표현됨(범위는 -10억 ~ +10억)
//이때 두 용액을 선택했을때 가장 중성에 가까운 두 수를 출력하는 문제(오름차순으로)
//예시) -2 4 -99 -1 98입력시 -99 98
//


//단순한 방법 생각: 브루트포스로 N개중 2개를 고르고 그 절댓값이 가장 작은 쌍을 출력하면됨(시간복잡도는 N제곱)
// 하지만, 그런 문제는 아닐것

//시간복잡도 NlogN방법을 생각해보자면, 정렬을 이용하는것
//일단 용액배열을 정렬한다(NlogN). 그리고 포인터를 2개 둔다. 처음과 끝을 가리키는 포인터
//그리고 처음과 끝을 합한 결과에 따라 분기한다.
//합이 +면 우측포인터를 좌측으로 1칸이동, 합이-면 좌측포인터를 우측으로 1칸이동
//이렇게 두 포인터가 만날때까지 진행하면서의 합의 최솟값을 계속기록한다.
//결과 나오는 최솟값이 답이다.

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Liquids[i];
	}
	leftPointer = 0;
	rightPointer = N - 1;
	sort(Liquids, Liquids + N);//정렬(NlogN)
	{//포인터 1칸씩 이동하는 알고리즘 진행
		while (leftPointer < rightPointer)
		{
			int sumOfPair = Liquids[leftPointer] + Liquids[rightPointer];
			if (abs(sumOfPair) < minimum)
			{
				minimum = abs(sumOfPair);//최소값 업데이트
				resultPoint.first = Liquids[leftPointer];
				resultPoint.second = Liquids[rightPointer];
			}
			if (sumOfPair >= 0)
			{
				rightPointer--;
			}
			else
			{
				leftPointer++;
			}
		}
	}
	cout << resultPoint.first << " " << resultPoint.second;

}