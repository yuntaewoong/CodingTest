#include <iostream>
using namespace std;


int N;
int NumberTriangle[500][500];
int DPTable[500][500];
int Result = -1;

//풀이방법: 같은 크기의 DPTable만들어서
//          해당 아이템까지의 합의 최대값을 저장해나가고
//          마지막 DP테이블의 최대값을 출력함
//점화식: DPTable[i][j] = 부모 2명중 큰거 + 자기값
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> NumberTriangle[i][j];
			DPTable[i][j] = 0;
		}
	}
	DPTable[0][0] = NumberTriangle[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{//왼쪽 끝
				DPTable[i][0] = DPTable[i - 1][0] + NumberTriangle[i][0];
			}
			else if (j == N - 1)
			{//오른쪽 끝
				DPTable[i][j] = DPTable[i - 1][j-1] + NumberTriangle[i][j];
			}
			else
			{
				DPTable[i][j] = max(DPTable[i - 1][j - 1], DPTable[i - 1][j]) + NumberTriangle[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		Result = max(DPTable[N - 1][i], Result);
	}
	cout << Result;
	return 0;
}