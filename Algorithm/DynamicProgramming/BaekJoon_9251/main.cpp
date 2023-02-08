#include <iostream>
using namespace std;

int DP[1001][1001];//LCS값이 저장되는 DP배열

int main()
{
    //문제 두 수열의 최대 부분 수열의 크기구하기
    //예시: ACAYKP와 CAPCAK의 LCS는 ACAK
    //시간제한: 0.4초(개빠르게 풀어야댐)

    //고민해도 방향성이 안보여서 답지보기로
    //와 이걸 어캐 DP로푸냐
    //점화식: dp[i][j] = dp[i-1][j-1]+1;(i번째 행, j번째 열이 같은 char일때)
    //        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);(다른 char일때)
    //점화식 해석: 결국 LCS라는게, 특정 문자열의 부분 문자열이 이루는 LCS값보다 항상 크게 되니까 이런 DP구성이 가능해짐
    //          
    string s1;//첫번째 문자열
    string s2;//두번째 문자열
    cin >> s1;
    cin >> s2;
    for (int i = 0; i <= s1.size(); i++)//0번째 열은 0
    {
        DP[i][0] = 0;
    }
    for (int i = 0; i <= s2.size(); i++)//0번째 행은 0
    {
        DP[0][i] = 0;
    }

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i-1] == s2[j-1])//DP테이블에서 행과열값이 같다면 LCS값 1증가
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);//이전값 2개중 큰값이 누적
            }
        }
    }
    cout << DP[s1.size()][s2.size()];

    return 0;
}