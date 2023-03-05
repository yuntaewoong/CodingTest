#include <iostream>
#include <queue>
#include <algorithm>
#define INF 10001
using namespace std;


int N;//동전 개수
int Coins[100];
int K;//목표 가치합

int DP[10000][100];


//그리디쓰면 안됨(가치높은 동전을 최대한 쓰는게 최선의 해가 아닐수 있기때문)

//DP접근법
// 가로축: 동전 가치(오름차순 정렬)
// 세로축: 누적 가치(MAX값은 K)
// 값: 동전개수

//2차원 DP: 가로축 상의 동전까지 사용했을때, 세로축 값을 만들수 있는 동전의 최소개수
//왼쪽위부터 오른쪽 아래순으로 한줄씩 DP배열을 채운다.
//채울때는 min(새로운 동전을 쓴 최소값,안쓴 최솟값)으로 채움

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Coins[i] = temp;
	}
	sort(Coins, Coins + N);

	for (int j = 0; j < N; j++)//첫번째 행 처리
	{
		if (Coins[0] == 1)
			DP[0][j] = 1;
		else
			DP[0][j] = INF;
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = 1; i < K; i++)//초기 열 처리
		{
			int temp = (i + 1) / Coins[j];
			int mod = (i + 1) % Coins[j];
			if (mod == 0)
				DP[i][j] = temp;
			else
				DP[i][j] = INF;
		}
	}
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j < N; j++)//점화식 수행
		{
			if (i + 1 - Coins[j] >= 0)
				DP[i][j] = min(DP[i][j - 1], (i + 1 - Coins[j] == 0) ? 1 : DP[i - Coins[j]][j] + 1);//새로운 동전 안쓴경우 vs 새로운 동전 쓴경우(새로운 동전가치를 제외한 경우 + 1)
			else
				DP[i][j] = DP[i][j - 1];
		}
	}


	//for (int i = 0; i < K; i++)//디버그용
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << DP[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	if (DP[K - 1][N - 1] >= INF)
		cout << "-1";
	else
		cout << DP[K - 1][N - 1];
}