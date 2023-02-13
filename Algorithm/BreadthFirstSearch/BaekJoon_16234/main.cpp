#include <iostream>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

int N;//N x N 사이즈의 N(1<=N<=50)
int L;//인구이동의 최소조건(1<=L<=R<=100)
int R;//..
int A[50][50];//인구수
int ACompare[50][50];//인구가 바뀌었는지 검사용배열
bool visited[50][50];//BFS방문용 배열
int result = 0;//결과값

int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { 1,-1,0,0 };//상하좌우

bool isMovingOccured = true;

class Node
{
public:
    Node(int i, int j)
        : i(i), j(j)
    {}
    int i;
    int j;
};

bool IsValidBetween(int i1, int j1, int i2, int j2)//(i1,j1),(i2,j2)사이의 국경을 열어도 되면 true
{
    int difference = abs(A[i1][j1] - A[i2][j2]);
    return difference >= L && difference <= R;
}

void BFS(int i, int j)
{
    queue<Node> bfsQueue;
    vector<Node> resultVector;//그룹화된 나라들의 인덱스 모음
    visited[i][j] = true;
    bfsQueue.push(Node(i, j));
    resultVector.push_back(Node(i, j));
    while (!bfsQueue.empty())//BFS방문
    {
        int i = bfsQueue.front().i;
        int j = bfsQueue.front().j;
        bfsQueue.pop();
        for (int k = 0; k < 4; k++)//상하좌우 4가지방향 검사
        {
            int goalI = i + dy[k];
            int goalJ = j + dx[k];
            if (goalI < 0 || goalI >= N || goalJ<0 || goalJ >= N)
                continue;
            if (!visited[goalI][goalJ] && IsValidBetween(i, j, goalI, goalJ))//아직 방문안했고 국경을 열어도 되면
            {
                visited[goalI][goalJ] = true;
                bfsQueue.push(Node(goalI, goalJ));
                resultVector.push_back(Node(goalI, goalJ));
            }
        }
    }
    int totalPopulation = 0;//국경이 열린 나라의 총인구수
    int populationPerCountry = 0;//국경이 열린 나라의 각 인구수
    for (int k = 0; k < resultVector.size(); k++)//각 인구수 계산
    {
        int i = resultVector[k].i;
        int j = resultVector[k].j;
        totalPopulation += A[i][j];
    }
    
    populationPerCountry = totalPopulation / resultVector.size();
    for (int k = 0; k < resultVector.size(); k++)//인구수 업데이트
    {
        int i = resultVector[k].i;
        int j = resultVector[k].j;
        A[i][j] = populationPerCountry;
    }
}
bool OneMove()//인구이동 1번하는 함수
{
    bool isPopulationMoved = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
            ACompare[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            
            if (!visited[i][j])
            {
                BFS(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] != ACompare[i][j])
                isPopulationMoved = true;
        }
    }
    result++;
    return isPopulationMoved;
}




int main()
{
    //2차원 배열에 각 나라의 인구수가 표기됨
    //인접한 나라 사이에 인구수 차이가 L이상 R이하라면 국경이 열리고 인구가 똑같은 비율로 나뉘게됨(A+B/2)
    //이런 과정을 거쳤을때 더이상 인구이동이 일어나지 않을때까지 며칠이 걸리는지 구하는 문제
    //더이상 인구이동이 일어나지 않는 상황은 모든 인접칸 사이의 인구수차이가 L미만 R초과인 경우


    //풀이방법: BFS를 써서 그룹화를 한다. 즉, 2중 for문을 돌면서 BFS로 그룹화하는게 가능함(이전에 해봄)
    //          그룹화한 구역은 인구수를 다시 계산해서 A[][]배열값을 업데이트함
    //          모든 구역을 그룹화하면 결과값을 1늘림
    //          위 과정이 하나의 시행이라 했을때, 하나의 시행후에 A[][]배열이 변화가 없다면 시뮬레이션 종료
    cin >> N;
    cin >> L;
    cin >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            A[i][j] = temp;
            visited[i][j] = false;
        }
    }
    while (OneMove())
    {}
    cout << result-1;
    return 0;
}