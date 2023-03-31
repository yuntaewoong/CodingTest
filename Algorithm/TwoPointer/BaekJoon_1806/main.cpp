#include <iostream>
using namespace std;


int N;//(10 <= N <= 100000)
int S;//(0<= S <= 1억)
int Numbers[100000];

int lowPointer = 0;
int highPointer = 0;
int lengthResult = 100001;
int sum = 0;
//문제: 수열이 주어짐, 이 수열의 '연속된' 수들의 부분합중에서 S이상되는것중에 가장 짧은 것의 길이를 출력
//       불가능하면 0출력

//단순하지만 무조건 구할수 있는방법: 처음에는 길이가 1인 부분합을 모두체크, 다음에는 길이가 2인 부분합을 모두체크
//                      이렇게 길이가 N인 부분합까지 체크해봐서 가장 먼저 S이상이 될때의 길이를 출력함
//                      시간복잡도는 N + (N-1) + (N-2) + ... 1 = O(N^2)

//빠르게 구할수 있는방법:연속된 부분합은 10 10만 11 처럼 극단적인 경우로만 차있을수도 있음
//                  투포인터 이용   

//투포인터 작동방식: 초기포인터값은 둘다 0
//            루프) 부분합 구하기(종료조건은 low가 high보다 커지거나 high가 N보다 커지거나)
//                  S보다 크면->길이값 기록(계속 업데이트됨)
//						lowPointer값 1증가
//					S보다 작으면->    
//						highPointer값 1증가

//투포인터 이용하면 N^2보다 빠른 이유: 부분합을 모든 경우에 다시 구하는게 아니라 포인터 업그레이드할때마다 한개씩 더하고 빼주는데다가
//                           필요없는 경우를 생략할수있음(ex) 1-4부분합이 S보다 작은데 2-4는 볼필요없이 작다)


int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> Numbers[i];
	}

	sum += Numbers[0];
	while (lowPointer <= highPointer && highPointer < N)
	{
		if (sum >= S)
		{
			lengthResult = min(lengthResult, highPointer - lowPointer + 1);
			sum -= Numbers[lowPointer];
			lowPointer++;
		}
		else
		{
			highPointer++;
			sum += Numbers[highPointer];
		}
	}
	if (lengthResult == 100001)
		lengthResult = 0;
	cout << lengthResult;
}