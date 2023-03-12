#include <iostream>

using namespace std;

//N개의 행, 3개의 열로 이루어진 표를 내려가는 게임
// 이게임은 가장 위행에서 시작해서 가장 아래행에서 끝난다
// 내려가는 규칙은 바로아래칸or 1칸옆인 대각선칸으로만 갈수있다
// 이때 최대점수, 최소점수를 구하는 프로그램을 만드는것

//점수는 0~9중 하나임

int N;//1 <= N <= 100000
short board[100001][3];
int DP[100001][3];


//분석: 항상 큰숫자,작은숫자를 찾아가는게 최적의 해가아님(큰숫자를 찾아간결과 더 큰숫자를 놓치게 될수있어서)
//     때문에 greedy알고리즘으로는 풀수없다.
//그렇다고 모든경우를 찾아보는 브루트포스를 쓰기에는 너무 경우의수가 많다.(거의 3의 100000승)
// 
//DP방법: board와 동일한 크기의 2차원 배열을 선언
//       해당 행,열까지 진행한결과 누적된 값들의 최솟값,최댓값으로 DP테이블을 채운다.
//        점화식은 DP[i][0] = max(DP[i-1][0],DP[i-1][1]) + DP[i][0];
//        1행은 board와 동일

int main()
{
	int maxValue;
	int minValue;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> board[i][0];
		cin >> board[i][1];
		cin >> board[i][2];
	}
	{//1행 예외처리
		DP[1][0] = board[1][0];
		DP[1][1] = board[1][1];
		DP[1][2] = board[1][2];
	}
	{//최대값 구하기
		for (int i = 2; i <= N; i++)
		{
			DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + board[i][0];//1열값 업데이트
			DP[i][1] = max(max(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + board[i][1];//2열값 업데이트
			DP[i][2] = max(DP[i - 1][1], DP[i - 1][2]) + board[i][2];//3열값 업데이트
		}
		maxValue = max(max(DP[N][0], DP[N][1]), DP[N][2]);
	}
	{//최소값 구하기
		for (int i = 2; i <= N; i++)
		{
			DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + board[i][0];//1열값 업데이트
			DP[i][1] = min(min(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + board[i][1];//2열값 업데이트
			DP[i][2] = min(DP[i - 1][1], DP[i - 1][2]) + board[i][2];//3열값 업데이트
		}
		minValue = min(min(DP[N][0], DP[N][1]), DP[N][2]);
	}
	cout << maxValue << " " << minValue;
}