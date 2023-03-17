#include <iostream>
using namespace std;

//군대에서 만들어본 스도쿠 문제
//백트래킹으로 해결함
//좌측상단부터 우측하단의 빈칸을 차례로 채워나감
//그러다가 조건을 못맞추는 경우가 생기면 이전 칸의 수를 다음경우의수로 바꾸고 다시 백트래킹진행
//모든 빈칸을 채우면서 스도쿠 조건도 만족하면 알고리즘 종료

int board[9][9];
int numOfEmpty = 0;


bool IsSudoku(int i, int j, int value)
{
	bool isSudoku = true;
	board[i][j] = value;
	//(i,j)에 value를 집어넣었을때 스도쿠 조건을 만족하면 true
	{//가로조건
		bool numUsed[9] = {false,};
		for (int k = 0; k < 9; k++)
		{
			if (board[i][k] == 0)//빈칸 스킵
				continue;
			int value = board[i][k];
			if (!numUsed[value - 1])
			{
				numUsed[value - 1] = true;
			}
			else
			{
				isSudoku = false;
			}
		}
	}
	{//세로조건
		bool numUsed[9] = {false, };
		for (int k = 0; k < 9; k++)
		{
			if (board[k][j] == 0)//빈칸 스킵
				continue;
			int value = board[k][j];
			if (!numUsed[value - 1])
			{
				numUsed[value - 1] = true;
			}
			else
			{
				isSudoku = false;
			}
		}
	}
	{//3*3 조건
		bool numUsed[9] = { false, };
		for (int k = (i/3) * 3; k < (i / 3) * 3 + 3; k++)
		{
			for (int m = (j/3) * 3; m < (j / 3) * 3 + 3; m++)
			{
				if (board[k][m] == 0)//빈칸스킵
					continue;
				int value = board[k][m];
				if (!numUsed[value - 1])
				{
					numUsed[value - 1] = true;
				}
				else
				{
					isSudoku = false;
				}
			}
		}
	}
	board[i][j] = 0;
	return isSudoku;
}
void NextBlank(int initI,int initJ,int* nextI, int* nextJ)//다음 빈칸 좌표리턴(없으면 -1리턴)
{
	int i = initI;
	int j = initJ;
	*nextI = -1;
	*nextJ = -1;
	while (!(i > 8))
	{
		{//다음 좌표 이동
			if (j == 8)//j가 8이면 다음줄로
			{
				i++;
				j = 0;
			}
			else
			{
				j++;
			}
		}
		if (board[i][j] == 0)
		{
			*nextI = i;
			*nextJ = j;
			return;
		}
	}
}


bool BackTracking(int i,int j)
{
	int blankIndexI = 0;
	int blankIndexJ = 0;
	NextBlank(i, j, &blankIndexI, &blankIndexJ);
	for (int k = 1; k <= 9; k++)
	{
		if (IsSudoku(i, j, k))
		{
			board[i][j] = k;
			if (blankIndexI == -1 || blankIndexJ == -1)//백트래킹 종료
			{
				return true;
			}
			if (BackTracking(blankIndexI, blankIndexJ))
			{
				return true;
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}
	return false;
}



int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				numOfEmpty++;
		}
	}
	int initI, initJ;
	if (board[0][0] == 0)
	{
		initI = 0;
		initJ = 0;
	}
	else
	{
		NextBlank(0, 0, &initI, &initJ);
	}
	BackTracking(initI, initJ);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j];
			if (j != 8)
				cout << " ";
		}
		if(i != 8)
			cout << "\n";
	}

}