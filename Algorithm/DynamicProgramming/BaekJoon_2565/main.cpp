#include <iostream>
#include <algorithm>
using namespace std;


class Line
{
public:
	Line() : ANum(0), BNum(0) {}
	int ANum;
	int BNum;//번호는 500이하자연수
};

bool Compare(Line A, Line B)
{
	return A.ANum < B.ANum;
}

int N;//전기줄개수(1<=N<=100)
Line lines[100];
int DP[100];//최장증가 부분수열 구하기 위한 DP배열(DP[i] => i번째 인덱스값을 마지막값으로 가지는 최장증가 부분수열 길이)


//전기줄이 교차하지 않는 상태가 될때까지 제거해야하는 전기줄의 최소개수 구하는 문제
//단순방법: 전기줄 빼보는 모든 경우 탐색-> N!의 시간복잡도(너무 오래걸려)
//그리디접근: 전기줄이 가장 사선인것부터 없애본다(최적의 해가 아닐수가 있다)
//DP접근: 반대로 전기줄이 없는상태에서 하나씩 넣어보면서 최대한 전기줄을 넣은상태를 만들어본다.


//https://mgyo.tistory.com/785 참고사이트
//이 포스팅에 따르면, 먼저전기줄을 좌측값에대한 오름차순으로 정렬하고
//정렬된 상태에서 우측값들에서 최장 증가 부분 수열을 구하는 것이다.
// (최장증가 부분수열은 다음과 같은 것들이다. {1,6,2,0,3,4,5} 에서 {1,2,3,4,5})
// 이미 정렬된 좌측값에 대응하는 우측값들을 선택하는 문제에서 이 최장증가 부분수열을 구하고 전체 전기줄개수에서 그 수열의 길이를 빼주면 답이다.
// 왜 이렇게 구하냐면, 우측값들이 항상 증가하는 값이 아니면 무조건 전기줄이 꼬이는 상태가 되기 때문



int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int aNum;
		int bNum;
		cin >> aNum;
		cin >> bNum;
		lines[i].ANum = aNum;
		lines[i].BNum = bNum;
	}
	sort(lines, lines + N, Compare);//A값에 대해 정렬



	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;//배열 초기화
	}
	for (int i = 1; i < N; i++)//LIS구하기
	{
		for (int j = 0; j < i; j++)
		{
			if (lines[i].BNum > lines[j].BNum)
			{
				DP[i] = max(DP[i], DP[j] + 1);//기존값과 j번째 원소를 포함한경우값중 큰값을 취함
			}
		}
	}
	cout << N - *max_element(DP, DP + 100);

}