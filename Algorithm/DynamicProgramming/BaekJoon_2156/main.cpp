#include <iostream>
using namespace std;



//문제: 포도주들이 1렬로 나열되어있을때, 최대한 많은양의 포도주를 먹는것
// 조건: 연속된 3개의 포도주는 먹으면 안됨

//생각: 도중까지 최선인 경우가 항상 최선의 경우가 아님
//예시 : 6 10 13 14이면 13까지는 10,13이 최선이지만 14까지로 하면 6,13,14가 초선임
//    -> 그리디로 해결불가
// 
//풀이 : DP, 저장값-> 해당 포도주까지 마셨을때의 최대값
//점화식 : DP[N] = max(DP[N-3] + Drink[N] + Drink[N-2], DP[N-3] + Drink[N] + DP[N-1],DP[N-1])
//        
int N;
int Drink[10000];
int DP[10000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Drink[i] = temp;
		DP[i] = 0;
	}
	DP[0] = Drink[0];
	if(N >= 1)
		DP[1] = Drink[0] + Drink[1];
	if(N >= 2)
		DP[2] = max(max(Drink[0] + Drink[1], Drink[0] + Drink[2]), Drink[1] + Drink[2]);
	for (int i = 3; i < N; i++)
	{
		DP[i] = max(max(DP[i - 2]  + Drink[i], DP[i - 3] + Drink[i-1] + Drink[i]), DP[i - 1]);
	}
	cout << DP[N - 1];
	return 0;
}