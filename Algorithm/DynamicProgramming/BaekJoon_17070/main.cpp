#include <iostream>
using namespace std;


class Value
{
public:
	int v1 = 0;//왼->오
	int v2 = 0;//왼위->오아래
	int v3 = 0;//위->아래
};

int N;//3<=N<=16
int board[17][17];
Value DP[17][17];

//풀이법: 2차원 DP에 각각 3개의 값을 저장하기
//        case를 생각해보면 각각의 칸에 파이프 머리가 있는 경우는 3가지로 나뉨(왼->오,왼위->오아래,위->아래)
//        이 3가지의 경우의수를 각각 저장하기
//점화식: 왼->오: 이전칸의 왼->오+왼위->오아래
//       왼위->오아래: 왼위칸의 왼->오+왼위->오아래+위->아래
//        위->아래: 위칸의 왼위->오아래+위아래
// 
//

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	{//DP알고리즘 적용
		DP[1][2].v1 = 1;
		for (int i = 3; i < N; i++)//1번째 행은 예외적 처리
		{
			if (board[1][i] != 1)//벽이 아닐때만
				DP[1][i].v1 = DP[1][i - 1].v1;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 3; j <= N; j++)//2번째행 3번째열 부터 진행
			{
				if (board[i][j] != 1)
					DP[i][j].v1 = DP[i][j - 1].v1 + DP[i][j - 1].v2;
				if (board[i][j] != 1 && board[i - 1][j] != 1 && board[i][j - 1] != 1)
					DP[i][j].v2 = DP[i - 1][j - 1].v1 + DP[i - 1][j - 1].v2 + DP[i - 1][j - 1].v3;
				if (board[i][j] != 1)
					DP[i][j].v3 = DP[i - 1][j].v2 + DP[i - 1][j].v3;
			}
		}
	}
	cout << DP[N][N].v1 + DP[N][N].v2 + DP[N][N].v3;
}