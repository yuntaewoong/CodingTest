#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int resultNum = 0;
vector<int> col(13,0);//해당 열에 Queen을 놓을수 있으면 1,없으면 0
vector<int> upDiagonal(27, 0);//해당 Diagonal에 Queen을 놓을수 있으면 1, 없으면 0(2차원 배열을 비스듬히 자르면 크기가 2배인 일차원배열화가능)
vector<int> downDiagonal(27, 0);//해당 Diagonal에 Queen을 놓을수 있으면 1, 없으면 0
void NQueen(int x)//x는 2차원 배열을 우측하단으로 순회할때의 index값을 의미함
{
	for (int i = 0; i < N; i++)//열들을 Search 
	{
		int up = x + i;
		int down = x + N - i - 1;

		if (!col[i] && !upDiagonal[up] && !downDiagonal[down])//놓고자 하는 곳은 놓을수 있음을 의미 
		{
			if (x == N - 1)//N개를 놓은 경우
			{
				resultNum++;
				break;
			}
			col[i] = 1; 
			upDiagonal[up] = 1;
			downDiagonal[down] = 1;

			NQueen(x + 1);

			col[i] = 0;
			upDiagonal[up] = 0;
			downDiagonal[down] = 0;
		}
	}

	return;
}

int main()
{
	
	cin >> N;
	NQueen(0);
	cout << resultNum;

	return 0;
}