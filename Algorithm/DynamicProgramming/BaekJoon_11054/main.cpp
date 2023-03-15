#include <iostream>

using namespace std;


//가장 긴 바이토닉 부분수열을 구하는 문제(ex/ 1 2 1 3 4 5 4 3 2 1에서 1,2,3,4,5,4,3,2,1)
//LIS와 비슷해보이지만 좀더 고려할게 많아보임
//일단 최대값을 무조건 쓰는게 맞는가? ㄴㄴ 반례존재 -> 5 1 2 3 4 3 2 1 에서 가장긴 바이토닉은 1 2 3 4 3 2 1
//LIS구하는 방법 remind: DP테이블에 '현재 원소를 포함한 LIS길이' 를 저장하고 그 값들중 가장 큰값으로 구한다
//비슷하게 추론한 가장 긴 바이토닉 부분수열 구하는 방법:똑같이 DP를 사용,
//DP테이블에 '현재 원소까지 사용한 가장 긴 바이토닉 부분수열 길이'를 저장한다.
//이 값을 구하려면 현재원소까지의 좌측원소들을 for문으로 돌아가면서 원소를 넣은게 바이토닉이니? 라는 과정을 거쳐야함
//LIS는 단순하게 arr[i] < arr[k] 식으로 새로 k를 넣은것이 lis인지 판단가능했는데
//바이토닉은 어캐하지? => 
//                    웹검색으로 힌트를 얻음, 왼쪽에서부터는 증가하는 부분수열
//                                           오른쪽에서부터는 감소하는 부분수열을 센다.
//                                     그러면 특정 원소 k에 대해서 좌측으로 증가하는 부분수열수랑 우측으로 감소하는 부분수열수가 나오는데
//                                     둘의 길이를 더한다음에 1을 빼주면 답



int N;//(1<= N <= 1000)
int Arr[1001];
int DP_LEFT[1001];
int DP_RIGHT[1001];
int result = -1;



int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
		DP_LEFT[i] = 1;
		DP_RIGHT[i] = 1;
	}
	{//DP알고리즘 적용
		for (int i = 1; i <= N; i++)
		{
			for (int k = 1; k < i; k++)
			{
				if (Arr[i] > Arr[k])
				{
					DP_LEFT[i] = max(DP_LEFT[i], DP_LEFT[k] + 1);
				}
			}
		}
		for (int i = N; i >= 1; i--)
		{
			for (int k = N; k > i; k--)
			{
				if (Arr[i] > Arr[k])
				{
					DP_RIGHT[i] = max(DP_RIGHT[i], DP_RIGHT[k] + 1);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int sum = DP_LEFT[i] + DP_RIGHT[i] - 1;
		result = max(sum, result);
	}
	cout << result;
}