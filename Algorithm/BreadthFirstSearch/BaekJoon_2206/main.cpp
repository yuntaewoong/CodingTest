#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
int N, M;
int board[1000][1000] = { 0 };
bool visit[2][1000][1000]; //벽을 부수고 온지 아닌지 구별해서 저장
int dx[] = { 0, 0, -1, 1 }; //상하좌우
int dy[] = { 1, -1, 0, 0 }; //상하좌우
int result = INT32_MAX;

struct Node
{
    Node(int i, int j, int weight, bool bDestroyed)
        : i(i),j(j),weight(weight),bDestroyed(bDestroyed)
    {}
    int i;
    int j;
    int weight;
    bool bDestroyed;
};


void bfs(int i, int j, int weight, bool bDestoryed)
{
    queue<Node> bfsQueue;
    bfsQueue.push(Node(i, j, weight, bDestoryed));
    while (!bfsQueue.empty()) 
    {
        int i = bfsQueue.front().i;
        int j = bfsQueue.front().j;
        int weight = bfsQueue.front().weight;
        bool bDestroyed = bfsQueue.front().bDestroyed;
        bfsQueue.pop();

        if (i == M - 1 && j == N - 1)//끝까지 탐색한 경우 
        {
            result = weight;
            break;
        }

        for (int k = 0; k < 4; k++) 
        {
            int n_x = i + dx[k];
            int n_y = j + dy[k];
            if (n_x < M && n_x >= 0 && n_y < N && n_y >= 0)
            {
                if (bDestroyed) // 벽을 부수고 온 경우
                {
                    if (!visit[1][n_y][n_x]) 
                    {
                        if (board[n_y][n_x] == 0)
                        {
                            visit[1][n_y][n_x] = true;
                            bfsQueue.push(Node(n_x, n_y, weight+1, true));
                        }
                    }
                }
                else // 벽을 안부수고 온경우
                {
                    if (!visit[0][n_y][n_x]) 
                    {
                        if (board[n_y][n_x] == 0)//그냥 정상길 가기
                        {
                            visit[0][n_y][n_x] = true;
                            bfsQueue.push(Node(n_x, n_y, weight+1, false));
                        }
                        else if (board[n_y][n_x] == 1) //벽 부셔보기
                        {
                            visit[0][n_y][n_x] = true;
                            bfsQueue.push(Node(n_x, n_y, weight + 1, true));
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> N;
    cin >> M;
    string temp;
    for (int i = 0; i < N; i++) 
    {
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            if (temp[j] == '1') 
            {
                board[i][j] = atoi(temp.substr(j,1).c_str());
            }
        }
    }

    visit[0][0][0] = true;
    bfs(0, 0, 1, false);
    if (result == INT32_MAX) 
    {
        cout << -1;
    }
    else 
    {
        cout << result;
    }
    return 0;
}