#include <iostream>
using namespace std;

int N;//트리의 노드 수(<=50)
int Tree[50];//트리 배열(배열에 저장되는 값은 부모노드의 인덱스)
int Reference[50];//해당 노드를 가리키는 노드의 개수 배열
int ToDeleteNode;
int Result = 0;


bool IsValid(int index)
{//부모노드를 찾아가서 중간에 ToDeleteNode가 있다면 false리턴
	if(index == -1)
		return true;
	else if(index == ToDeleteNode)
		return false;
	return IsValid(Tree[index]);
}

int main()
{
	//구하는거: 배열로 표현된 트리에서 1개의 노드와 그 하위 노드를 지웠을때, 리프노드의 총개수
	//일단 리프노드 개수 구하는 방법: 모든 노드 for문으로 순회하면서 레퍼런스 카운트 센 후에, 레퍼런스 카운트가 0인 노드가 리프노드
	//문제 해결 방법: 모든 리프노드마다 부모를 찾아가는 재귀호출, 중간에 삭제하려는 인덱스가 등장하면 총 카운트에서 제외
	
	//예외 케이스: 삭제하는 노드의 부모노드가 리프노드가 되는 경우
	cin >> N;
	for(int i = 0;i<N;i++)
	{
		cin >> Tree[i];
		Reference[i] = 0;
	}
	cin >> ToDeleteNode;
	for(int i = 0;i<N;i++)
	{
		if(Tree[i] == -1)
		{//부모가 없음)
			continue;
		}
		Reference[Tree[i]]++;
	}
	for(int i = 0;i<N;i++)
	{
		if(Reference[i] == 0)
		{
			if(IsValid(i))
				Result++;
		}
	}
	if(Reference[Tree[ToDeleteNode]] == 1)//예외 케이스
	{
		Result++;
	}

	cout << Result;
	return 0;
}