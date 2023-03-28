#include <iostream>
using namespace std;

//3 X N의 벽이 있을때
//2 X 1, 1 X 2타일로 채울수 있는 경우의수
//생각: 3 X 2를채우는 경우의수는 3가지, 3 X 4를 채우는 경우의수(3X2를 2번한거 제외)는 2가지
//     생각못한 고려요소: 3 X 6을 채우는 경우의수 2가지,이외에도 매 짝수번마다 2가지씩 더해짐
//점화식: N이 2가 늘어나면 이전경우에 3 X 2를 채우는 경우(3가지)를 곱해준수와  3 X 4를 채우는 경우(2가지)를 


int DP[31];
int N;//N <= 30
int main()
{
	cin >> N;
	DP[1] = 0;
	DP[2] = 3;
	DP[3] = 0;
	DP[4] = 11;
	DP[5] = 0;
	for (int i = 6; i <= N; i++)
	{
		if (i % 2 != 0)
		{
			DP[i] = 0;
			continue;
		}
		if (i == 2)
		{
			DP[i] = 3;
			continue;
		}
		else
		{
			DP[i] = DP[i - 2] * 3;//새로 추가된 2칸에 넣는 3가지경우
			for (int j = i - 4; j >= 2; j -= 2)
			{
				DP[i] += DP[j] * 2;//새로 추가된 2칸에 의해 가능해진 특이케이스들 합
			}
			DP[i] += 2;//전체를 특이케이스로 하는 2가지 경우
		}
	}
	cout << DP[N];
}