#include <iostream>
#include <vector>
using namespace std;

int N;//수의 개수(<=1000000)
long long Numbers[1000000];//각 숫자는 -2의 63승 ~ 2의 63승 범위(8바이트 자료형)
int M;//수의 변경이 일어나는 횟수<=10000)
int K;//구간의 합을 구하는 횟수(<=10000)

int main()
{
	cin >> N;
	cin >> M;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Numbers[i];
	}
	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b;
		cin >> c;
		if (a == 1)
		{//a가 1이면 수정
			Numbers[b - 1] = c;
		}
		else if (a == 2)
		{//a가 2면 출력
			long long result = 0;//+,-의 결과는 long long범위인게 보장됨
			for (int i = b - 1; i < c; i++)
				result += Numbers[i];
			cout << result << "\n";
		}
	}
	return 0;
}