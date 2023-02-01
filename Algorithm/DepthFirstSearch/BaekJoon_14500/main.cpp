#include <iostream>
#include <vector>
using namespace std;
int N;//세로 크기(>=4)
int M;//가로 크기(<=500)
vector<vector<int>> board;
int maxSum = 0;//테트로미노가 차지하는 최대합


void TException(int i, int j)//DFS로 서치못하는 T미노 예외처리
{
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    
    if(j-1 >= 0 && j+1 < M && i - 1 >= 0)//위
        sum1 = board[i][j] + board[i][j - 1] + board[i][j + 1] + board[i - 1][j];

    if ((j - 1 >= 0) && (j + 1 < M) && (i + 1 < N))//아래
        sum2 = board[i][j] + board[i][j - 1] + board[i][j + 1] + board[i + 1][j];

    if(j-1 >= 0 && i+1 < N && i-1 >= 0)//왼
        sum3 = board[i][j] + board[i][j - 1] + board[i+1][j] + board[i - 1][j];

    if(j+1 < M && i+1 < N && i-1 >= 0)//오
        sum4 = board[i][j] + board[i][j + 1] + board[i+1][j] + board[i - 1][j];
    maxSum = sum1 > maxSum ? sum1 : maxSum;
    maxSum = sum2 > maxSum ? sum2 : maxSum;
    maxSum = sum3 > maxSum ? sum3 : maxSum;
    maxSum = sum4 > maxSum ? sum4 : maxSum;
}


void DFS(int pastI,int pastJ,int i, int j,int depth,int sum)
{
    sum += board[i][j];
    if (depth == 4)//base condition(테트로미노 다 방문
    {
        maxSum = sum > maxSum ? sum : maxSum;//최대값 갱신
        return;
    }
    if (i - 1 >= 0 && i-1 != pastI)//위로
        DFS(i, j, i - 1, j, depth + 1,sum);
    if (i + 1 < board.size() && i + 1 != pastI)//아래로
        DFS(i, j, i + 1, j, depth + 1, sum);
    if (j - 1 >= 0 && j - 1 != pastJ)//위로
        DFS(i, j, i, j-1, depth + 1, sum);
    if (j + 1 < board[0].size() && j + 1 != pastJ)//위로
        DFS(i, j, i , j+1, depth + 1, sum);
    
}



int main()
{
    //정수가 적혀있는 2차원 보드위에 테트로미노를 올렸을때
    //차지하는 칸들에 적혀있는 수의 값의 최대값을 구하는 문제
    //간단하지만 오래걸릴것 같은 방법, 매 board 요소마다 DFS를 돈다.
    //상하좌우로 4칸 진행하면 테트로미노다
    //T미노는 예외로 4번 진행해주면 됨
    //그렇게 최대값 정수를 업데이트하면
    //해결
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;
    cin >> M;
    
    for (int i = 0; i < N; i++)
    {
        board.push_back(vector<int>());
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            board[i].push_back(temp);
        }
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            DFS(-1, -1, i, j, 1, 0);
            TException(i, j);
        }
    }
    cout << maxSum << "\n";
    return 0;
}