#include <iostream>
#include <algorithm>
using namespace std;

struct BagItem
{
    int W;//물건의 무게
    int V;//물건의 가치
};
BagItem Items[100];
int DP[101][100001];//DP 테이블, ROW는 Item을 의미, COL은 무게 제한을 의미
int main()
{
    //알분 전공과목에서 배운 자르지 않는(0-1) knapsack problem
    //Greedy 알고리즘으로 접근해보자
    //당연히 한번 물건을 넣을 때 무게당 가치가 가장 높은 물건을 먼저 넣어야 최대값을 얻을수 있다.
    //가성비 순으로  넣다가 물건을 못넣는 순간이 오면, 가성비는 낮지만 무게는 낮은 물건을 넣어야 최적이다.
    //이 방법은 잘못됨, 최적이 아님(자르는 knapsack problem 에서는 최적이지만)
    //
    //그렇다면 더 좋은 방법은? DP를 쓰자
    // DP는 다음과 같이 구성한다 .가로로는 (Item[0].....Item[100]을 나열하고)
    //                          세로로는 (해당 아이템을 넣은경우 안넣은 경우를 나열한다)
    //
    int N;//N은 물건의수(<=100)
    int K;//K는 버틸수 있는 무게한계(<=100000)
    //점화식은 다음과 같음
    // DP[i][w] = (i번째 Item까지 고려했을때 넣을수 있는 가치의 최대값은)
    //              DP[i-1][w](i번째 픽안한경우의 가치)거나 DP[i-1][w-weight[i]] + Value[i](i번째 픽한 경우의 가치)임 


    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
    {
        int weight;
        int value;
        cin >> weight;
        cin >> value;
        Items[i].W = weight;
        Items[i].V = value;
    }
    for (int i = 1; i <= K; i++)//DP첫번째 Row초기화
    {
        DP[1][i] = Items[0].W <= i ? Items[0].V : 0;//첫번째 아이템으로 N Kg제한일때의 가치값
    }
    for (int i = 2; i <= N; i++)//DP Table채우기
    {
        for (int j = 1; j <= K; j++)
        {
            if (Items[i-1].W > j)//j보다 무게가 크면 픽을 못함
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Items[i - 1].W] + Items[i - 1].V);//점화식 적용
        }
    }
    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << DP[N][K] << "\n";//DP[N][K]에 가능한 최대 가치가 저장됨
    return 0;
}