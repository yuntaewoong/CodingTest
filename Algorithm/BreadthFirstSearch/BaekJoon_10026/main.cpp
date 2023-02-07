#include <iostream>
#include <queue>
using namespace std;

int N;//N X N 사이즈(1<=N<=100)
char board[100][100];
bool visited[100][100];
int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { 1,-1,0,0 };//상하좌우
int normalResult = 0;
int colorWeaknessResult = 0;

struct Node
{
    Node(int i, int j) :
        i(i), j(j)
    {}
    int i;
    int j;
};

void BFS(int x,int y,bool bIsColorWeak)
{
    queue<Node> bfsQueue;
    bfsQueue.push(Node(x, y));
    while (!bfsQueue.empty())
    {
        int i = bfsQueue.front().i;
        int j = bfsQueue.front().j;
        char pastChar = board[i][j];
        bfsQueue.pop();

        for (int k = 0; k < 4; k++)//상하좌우 테스트
        {
            int goalI = i + dx[k];
            int goalJ = j + dy[k];
            if (goalI >= N || goalI < 0 || goalJ >= N || goalJ < 0)//범위체크
                continue;
            if (!visited[goalI][goalJ])//방문을 아직 안했다면
            {
                if (bIsColorWeak)//적록색약인경우
                {
                    switch (pastChar)
                    {
                    case 'R':
                    case 'G':
                        if (board[goalI][goalJ] == 'R' || board[goalI][goalJ] == 'G')
                        {
                            visited[goalI][goalJ] = true;
                            bfsQueue.push(Node(goalI, goalJ));
                        }
                        break;
                    case 'B':
                        if (board[goalI][goalJ] == 'B')
                        {
                            visited[goalI][goalJ] = true;
                            bfsQueue.push(Node(goalI, goalJ));
                        }
                        break;
                    }
                }
                else//정상인인 경우
                {
                    if (board[goalI][goalJ] == pastChar)//방문했던 노드와 같은색이면
                    {
                        visited[goalI][goalJ] = true;
                        bfsQueue.push(Node(goalI, goalJ));
                    }
                }
            }
        }
    }

}


int main()
{
    //일반인: R,G,B를 각각 구역으로 구분
    //적록색약: RG, B를 각각 구역으로 구분

    //BFS해결방법: 0,0부터 시작해서 처음칸이랑 같은 값인 칸만 우선적으로 방문
    //            만약 상하좌우가 다 다른값이면? 구역개수를 1 늘리고 새로운 칸 방문
    //            적록색약버전은 RG를 같은색으로 보고 돌리기

    //백준 2667번에서 얻은 힌트, 구역을 나누는 문제는 전체 이중 포문 돌면서 각각 BFS돌리기
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = temp[j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                BFS(i, j,false);//같은 색인 구역 방문처리(정상인)
                normalResult++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                BFS(i, j, true);//같은 색인 구역 방문처리(색약버전)
                colorWeaknessResult++;
            }
        }
    }
    cout << normalResult << " " << colorWeaknessResult;
    return 0;
}