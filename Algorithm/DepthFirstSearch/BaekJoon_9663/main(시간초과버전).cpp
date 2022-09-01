#include <iostream>
#include <vector>
using namespace std;

bool IsSafeSpace(const vector<vector<int>>& chessBoard, int row, int col)
{


	for (int i = 0; i < chessBoard.size(); i++)
	{
		if (chessBoard[row][i] == 1)//행 검사
			return false;
		if (chessBoard[i][col] == 1)//열 검사
			return false;
		if (col - row + i >= 0 && col - row + i < chessBoard.size())//대각 검사
		{
			if (chessBoard[i][col - row + i] == 1)
				return false;
		}
		if (row + col - i >= 0 && row + col - i < chessBoard.size())//대각 검사
		{
			if (chessBoard[i][row + col - i] == 1)
				return false;
		}
	}
	return true;
}
bool GetNextRowCol(int* row, int* col, int width)
{
	if (*row >= width-1 && *col >= width-1)
		return false;

	if (*col == width-1)
	{
		*row = *row + 1;
		*col = 0;
	}
	else
	{
		*col = *col + 1;
	}
	return true;
}


void dfs(vector<vector<int>>& chessBoard,int row, int col,int numPlaced,int N,int* resultNum)
{
	if (numPlaced == N)
	{
		*resultNum = *resultNum + 1;
		return;//Search종료
	}
	int i = row;
	int j = col;
	while (true)
	{
		if (IsSafeSpace(chessBoard, i, j))
		{
			chessBoard[i][j] = 1;//(i,j)에 Queen배치
			dfs(chessBoard, i, j, numPlaced + 1, N, resultNum);
			chessBoard[i][j] = 0;//(i,j)에 배치했던 Queen치우기(다음 case를 위해서)
		}


		if (!GetNextRowCol(&i, &j, N))
			break;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int N;//N X N의 그 N
	cin >> N;
	vector<vector<int>> chessBoard(N, vector<int>(N, 0));
	//방법1: 조합이용, 최대 C(225,15) 즉 15중 포문!! 와! 이건 안돼
	//방법2: DFS 돌면서 퀸을 1칸씩 배치(순서는 2차원 배열의 오른쪽 아래 방향)
	//만약 퀸을 넣어서 죽는 위치면 다음 위치를 검사
	//N개를 다 배치하면 결과값을 1늘리고 마지막 퀸을 유효한 위치인 1칸 뒤로 배치
	
	int resultNum = 0;
	dfs(chessBoard, 0, 0, 0, N, &resultNum);
	cout << resultNum;
	return 0;
}
