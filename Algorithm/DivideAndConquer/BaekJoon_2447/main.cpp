#include <iostream>
using namespace std;
void PrintStars(int row,int col,int N)//(row,col)에 별을 찍어주라는 함수
{
	//Base Case
	//***
	//* *
	//*** 꼴을 출력
	if (N == 1) 
	{
		if (row % 3 == 1 && col % 3 == 1)//row,col이 1,4,7일때마다 공백 출력
			cout << " ";
		else
			cout << "*";
		return;
	}
	if ((row / N) % 3 == 1 && (col / N) % 3 == 1)//가운데부분이면 출력 X 
	{
		cout << " ";
		return;
	}
	else//문제 분할,분할 할때마다 공백이어야 하는 조건을 하나씩 검사하는 셈
	{
		PrintStars(row, col, N / 3);
	}
}


int main()
{	

	int N;
	cin >> N;//N은 3의 거듭제곱
	// N이 3일때-> 가운데 비워두고 별찍기
	// N이 3^2일때-> 가운데 비워두고 나머지 칸을 N이 3일때 방식으로 별찍기
	// N이 3^3일때-> 가운데 비워두고 나머지 칸을 N이 3^2일때 방식으로 별찍기
	//
	//Divide and Conquer알고리즘 적용
	// 분할: N이 3의 N승인 문제를 N이 3인 문제들로 분할
	// 정복: 재귀함수로 결과를 합침

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			PrintStars(i, j, N);
		}
		cout << "\n";
	}


	return 0;
}