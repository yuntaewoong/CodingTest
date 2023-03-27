#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//아기상어 동작 매커니즘
//가장 가까운 먹을수 있는 물고기를 먹으러감(같은 위치라면 1. 위에있는놈 2.왼쪽에있는놈 우선순위)
//아기상어는 물고기를 자신의 크기만큼의 물고기를 먹으면 크기가 1 성장함

//아기상어의 처음크기는 2
//아기상어는 자기보다 작은물고기만 먹음
//아기상어는 자기보다 큰 물고기가있는칸은 지나갈수없음
//자기보다 작거나 같은 물고기가 있는칸은 지나갈수있음(크기가 같으면 안먹고 지나가기 가능)


//해결방법
//BFS:아기상어 위치 인풋, BFS로 가장가까우면서 상좌에 위치한 가장 가까운 다음 물고기 서치
//    찾으면 아기상어를 해당위치로 옮기고 각종 연산수행(이동시간,상어크기,board상태 업데이트)

//    위 과정을 더이상 먹을 물고기가 없을때까지 반복

int N;//공간의 크기(2<= N <=	20)
int board[20][20];//숫자의 의미 0:빈칸, 1~6:물고기 크기, 9: 아기상어 위치
int sharkSize = 2;//상어크기
int numOfToEat = 2;//성장할때까지 먹어야하는 물고기개수
int sharkI;//아기상어의 I
int sharkJ;//아기상어의 J
int resultDistance = 0;//상어가 이동한 거리

int dx[4] = {0,-1,0,1};//상좌하우
int dy[4] = {-1,0,1,0};//상좌하우

class Node
{
public:
	Node(int i,int j,int depth) : i(i),j(j),depth(depth) {}
	int i;
	int j;
	int depth;
};

void Eat(int i,int j)//상어가 i,j의 물고기를 먹음 처리
{
	if (numOfToEat == 1)//성장하면서 먹기
	{
		board[i][j] = 0;//먹음
		sharkSize++;
		if (sharkSize >= 7)
			sharkSize = 7;
		numOfToEat = sharkSize;
	}
	else//그냥 먹기
	{
		board[i][j] = 0;//먹음
		numOfToEat--;
	}
	board[sharkI][sharkJ] = 0;//기존위치 0으로 업데이트
	sharkI = i;
	sharkJ = j;//상어위치 업데이트
	board[sharkI][sharkJ] = 9;
}

bool BFS(int i,int j)//(i,j)에 아기상어 있을때 1회 시행,불가능하면 false리턴
{
	queue<Node> bfsQueue;
	vector<Node> ToEatNodes;//먹을 후보지
	bool Visited[20][20] = { false, };
	bool isFound = false;
	bfsQueue.push(Node(i, j, 0));
	Visited[i][j] = true;
	int depthRecord = 0;
	while (!bfsQueue.empty())
	{
		int topI = bfsQueue.front().i;
		int topJ = bfsQueue.front().j;
		int topDepth = bfsQueue.front().depth;
		bfsQueue.pop();

		if (board[topI][topJ] < sharkSize && board[topI][topJ] > 0)//방문한 노드가 상어크기보다 작으면 먹을 후보군에 등록
			ToEatNodes.push_back(Node(topI, topJ, topDepth));
		if (depthRecord != topDepth )//|| bfsQueue.empty())//디버깅: 이 if문이 4를 정상작동하지 못하게함 ->알아내기
		{
			if (!ToEatNodes.empty())
			{//i가 최소인것중에 j가 최소인거 먹기
				int minI = 21;
				for (int i = 0; i < ToEatNodes.size(); i++)
					minI = min(minI, ToEatNodes[i].i);//가장 작은 i값구하기
				int minJ = 21;
				for (int i = 0; i < ToEatNodes.size(); i++)
				{
					if (ToEatNodes[i].i == minI)
						minJ = min(minJ, ToEatNodes[i].j);
				}
				Eat(minI, minJ);
				resultDistance += ToEatNodes[0].depth;
				cout << minI << " " << minJ << " " << ToEatNodes[0].depth << endl;
				isFound = true;
				break;
			}
		}
		depthRecord = topDepth;
		for (int k = 0; k < 4; k++)
		{
			int nextI = topI + dy[k];
			int nextJ = topJ + dx[k];
			if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N)
				continue;
			if (!Visited[nextI][nextJ] && board[nextI][nextJ] <= sharkSize)//아직 방문안했고 상어보다 작거나 같은 물고기칸이나 빈칸이라면
			{
				Visited[nextI][nextJ] = true;
				bfsQueue.push(Node(nextI, nextJ, topDepth + 1));
			}
		}
	}
	return isFound;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				sharkI = i;
				sharkJ = j;
			}
		}
	}
	while (BFS(sharkI, sharkJ)) {}//불가능할때까지 BFS반복
	cout << resultDistance;//결과 거리 출력
	return 0;
}