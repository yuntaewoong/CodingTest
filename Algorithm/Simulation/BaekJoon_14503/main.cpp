#include <iostream>
using namespace std;

int N;//방 세로길이(3 <= N <= 50)
int M;//방 가로길이(3 <=M <= 50)

int initI;//초기 세로좌표
int initJ;//초기 가로좌표
int d;//로봇 청소기가 바라보는 방향(0:북,1;동,2:남,3:서)

int room[50][50];//방 상태(0:청소되지 않은칸 1:벽)
int result = 0;//청소한 칸수

int dx[4] = {0,1,0,-1};//상우하좌
int dy[4] = {-1,0,1,0};//상우하좌

//풀이방법: BFS에 초기위치 집어넣고 돌린다.
//         


void CCWRotate()
{
    d = (d - 1) % 4;
    if (d < 0)
        d += 4;
}


void Clean()
{
    int robotI = initI;
    int robotJ = initJ;
    while (true)
    {
        if (room[robotI][robotJ] == 0)//청소안한칸이면
        {
            room[robotI][robotJ] = 2;//청소하기(청소값을 2로잡겠음)
            result++;
        }
        int isExistEmpty = false;
        for (int i = 0; i < 4; i++)
        {
            int goalI = robotI + dy[i];
            int goalJ = robotJ + dx[i];
            if (goalI < 0 || goalI >= N || goalJ < 0 || goalJ >= M)
                continue;
            if (room[goalI][goalJ] == 0)//주변 4칸중 청소되지 않은 빈칸 발견
            {
                isExistEmpty = true;
            }
        }
        if (isExistEmpty)
        {
            CCWRotate();//반시계 90도 회전
            int goalI = robotI + dy[d];
            int goalJ = robotJ + dx[d];
            if (goalI >= 0 && goalI < N && goalJ >= 0 && goalJ < M)//90도 돌고나서 보는방향이 청소되지 않은 빈칸이면
            {
                if (room[goalI][goalJ] == 0)
                {
                    robotI = goalI;
                    robotJ = goalJ;//한칸 전진
                }
            }
            continue;//1번으로 돌아가기
        }
        {
            int backI = robotI - dy[d];//바라보는 방향에서 후진한 I
            int backJ = robotJ - dx[d];//바라보는 방향에서 후진한 J
            if (backI < 0 || backI >= N || backJ < 0 || backJ >= M || room[backI][backJ] == 1)
            {
                break;//후진 못하니까 작동멈춤
            }
            robotI = backI;//후진
            robotJ = backJ;//후진
        }
    }
}


int main() 
{
    cin >> N;
    cin >> M;

    cin >> initI;
    cin >> initJ;
    cin >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            room[i][j] = temp;
        }
    }
    Clean();
    cout << result;
    return 0;
    
}