#include <iostream>
#include <map>
using namespace std;


pair<int, int> binarySearchTree[1000000];//node값과 이에 대응하는 자식노드들의 배열


void InsertToBinarySearchTree(int value,int rootValue)
{
    int compareValue = rootValue;
    while (true)
    {
        if (value < compareValue)//비교 노드보다 작다면
        {
            if (binarySearchTree[compareValue].first == -1)//비교노드의 왼쪽자식노드가 존재하지 않는다면
            {
                binarySearchTree[value] = make_pair(-1, -1);//노드생성
                binarySearchTree[compareValue].first = value;//왼쪽 자식노드로 세팅
                break;//삽입 종료
            }
            compareValue = binarySearchTree[compareValue].first;//왼쪽 자식노드를 비교군으로
        }
        else//비교 노드보다 크다면 
        {
            if (binarySearchTree[compareValue].second == -1)//비교노드의 오른쪽 자식노드가 존재하지 않는다면
            {
                binarySearchTree[value] = make_pair(-1, -1);//노드생성
                binarySearchTree[compareValue].second = value;//오른쪽 자식노드로 세팅
                break;//삽입 종료
            }
            compareValue = binarySearchTree[compareValue].second;//오른쪽 자식노드를 비교군으로
        }
    }
}


void PostOrderPrint(int rootValue)
{
    if (rootValue == -1)
        return;
    PostOrderPrint(binarySearchTree[rootValue].first);
    PostOrderPrint(binarySearchTree[rootValue].second);
    cout << rootValue << "\n";
    
    
}


int main() 
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //입력: 트리의 전위 순회(루트,왼쪽,오른쪽) 결과
    //구하는 것: 트리의 후위 순회(왼쪽,오른쪽,루트) 결과
    //총 노드의 수는 10000개 이하
    int i = -1;
    int rootNode = -1;
    bool isSetRootNode = false;
    int temp;
    while (cin >> temp)
    {
        if (!isSetRootNode)//루트노드 삽입은 따로 처리
        {
            rootNode = temp;
            isSetRootNode = true;
            binarySearchTree[rootNode] = make_pair(-1, -1);
        }
        else
        {
            InsertToBinarySearchTree(temp, rootNode);
        }
        
    }
    PostOrderPrint(rootNode);


    return 0;
    
}