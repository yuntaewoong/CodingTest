#include <iostream>
#define INF 10000001//가중치의 최대값은 100개의 노드를 1개1개 지나는 간선의 가중치가 100000인경우
using namespace std;

class Node
{
public:
	Node() {}
	int A;
	int B;
	int cost;//<=100,000
};


int n;//2<= n <= 100(도시의 수)
int m;//1 <= m <= 100000(버스의 수)
Node edges[100000];

int Floyd[100][100];//플로이드 알고리즘 테이블

//모든 도시의 쌍(A,B)에 대해서 도시 A에서 도시 B로 가는 비용의 최솟값을 2차원 배열로 출력하는 문제
//플로이드 알고리즘을 이용하는 문제

//플로이드 알고리즘 헷갈리는점: 특정도시에서 특정도시까지의 최솟값을 구하는데 왜 1번지나는 최솟값,2번지나는 최솟값...이렇게 업데이트 한값이
// 최적의 해인건지 이해가 잘 안됨, 
//                답: https://cloge.tistory.com/28 이 글이 직관이해에 도움되는듯

//플로이드 알고리즘을 코드로 구현하면, 삼중 for문이다. 가장 바깥부터 도시for문,행,열 이다.
int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].A >> edges[i].B >> edges[i].cost;//간선정보 저장
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				Floyd[i][j] = 0;
			else
				Floyd[i][j] = INF;//INF로 값 초기화
		}
	}
	for (int i = 0; i < m; i++)
	{
		Floyd[edges[i].A - 1][edges[i].B - 1] = min(Floyd[edges[i].A - 1][edges[i].B - 1], edges[i].cost);//간선1개를 지나는 최솟값 업데이트
	}


	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Floyd[i][j] = min(Floyd[i][k] + Floyd[k][j], Floyd[i][j]);//k를 거쳐간거랑 원래값이랑 최솟값 대입
			}
		}
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Floyd[i][j] >= INF)
				cout << 0;
			else
				cout << Floyd[i][j];
			
			if (j != n - 1)
				cout << " ";
		}
		if (i != n - 1)
			cout << "\n";
	}
}