#include <iostream>
#include <queue>
using namespace std;


int M;//가로(<=100)
int N;//세로(<=100)
int H;//높이(<=100)

int tomato[100][100][100];
bool visited[100][100][100];

int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int result = 0;
struct Node
{
    Node(int i,int j,int k,int weight) 
        : i(i),j(j),k(k),weight(weight)
    {}
    int i;
    int j;
    int k;
    int weight;
};


void BFS()
{
    queue<Node> bfsQueue;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[i][j][k] == 1)//처음에 익은 토마토들 큐에 넣기
                    bfsQueue.push(Node(i, j, k, 0));
            }
        }
    }
    while (!bfsQueue.empty())
    {
        int i = bfsQueue.front().i;//z축
        int j = bfsQueue.front().j;//y축
        int k = bfsQueue.front().k;//x축
        int weight = bfsQueue.front().weight;
        result = weight;
        bfsQueue.pop();
        for (int m = 0; m < 6; m++)//3d의 6방향으로의 가능성을 테스트
        {
            int goalI = i + dz[m];
            int goalJ = j + dy[m];
            int goalK = k + dx[m];
            if (goalI >= H || goalI < 0 || goalJ >= N || goalJ < 0 || goalK >= M || goalK < 0)//배열바깥은 조사X
                continue;
            if (!visited[goalI][goalJ][goalK] && tomato[goalI][goalJ][goalK] == 0)//방문하지않은 안익은 토마토라면
            {
                visited[goalI][goalJ][goalK] = true;
                tomato[goalI][goalJ][goalK] = 1;
                bfsQueue.push(Node(goalI, goalJ, goalK, weight + 1));
            }
        }
    }

}



int main()
{
    //익은 토마토는 1, 안익은 토마토는 0,토마토가 없으면 -1인 상태
    // 익은토마토가 옆칸에 있으면 1일후에 안익은 토마토는 익은토마토가됨
    //다 안익게되면 -1, 다 익게되면 익을때까지 걸리는 기간 리턴하는 문제

    //다 익는 기간문제니까 BFS적용 ㄱ
    //처음에 익은 토마토들을 모두 push
    //이후 weight값들을 업데이트하며 모든 그래프 방문
    //더이상 방문이 업데이트 되지 않을때의 weight값이 결과값

    cin >> M;//x
    cin >> N;//y
    cin >> H;//z

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int temp;
                cin >> temp;
                tomato[i][j][k] = temp;
                visited[i][j][k] = false;

            }
        }
    }

    BFS();

    bool bAllPolluted = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[i][j][k] == 0)//아직 안익은게 있다면
                    bAllPolluted = false;
            }
        }
    }
    if (bAllPolluted)
        cout << result;
    else
        cout << "-1";
    return 0;
}