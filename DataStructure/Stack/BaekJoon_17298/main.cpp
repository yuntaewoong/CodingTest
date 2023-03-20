#include <iostream>
#include <stack>
using namespace std;




//배열의 모든 원소의 오큰수 구하기
//오큰수 정의: 해당원소보다 오른쪽에있으면서 큰 수중에서 가장 왼쪽에있는 수

//무식한 방법: 매 원소마다 처음으로 자기보다 큰수가 나올때까지 순회(O(N^2))
//              N이 백만인걸로 봐서 이 방법은 시간초과가 나올것

//생각한 방법: 일단 맨뒤에서부터 생각
//            가장 끝값은 오큰수가 항상 -1
//            가장 뒤에서 2번째 값은 뒷값보다 작으면 뒷값, 아니면 -1
//            가장 뒤에서 3번째 값은 2번째값보다 작으면 2번째값 아니면 뒤에 있는 모든 수보다 크면 -1, 아니면 

//어떻게 N^2이 아니게 될까? 
//https://suhwanc.tistory.com/58
//요약: 인덱스를 저장하는 스택을 선언 + 오큰수의 배열 선언
//      0부터 N까지 스택에 push하는데 조건이 있음
//      바로 스택의 가장 위에 저장된 index에 해당하는 값보다 크면 해당수를 오큰수로 설정하고 pop하기
//      찾지못하면 스택에 남게됨
//      찾지못한 인덱스들은 -1로 설정
//      직관적이진 않지만 쉽게 이해하자면, stack에 순서대로 쌓고 먼저 찾을수 있는 인덱스부터 찾고 스택 바닥에 있는 나중 인덱스들을 찾아주는것
//      

int N;//1<= N <= 1000000
int numbers[1000000];
stack<int> indexStack;
int results[1000000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	indexStack.push(0);//처음 인덱스 넣기
	for (int i = 1; i < N; i++)
	{
		while (!indexStack.empty() && numbers[indexStack.top()] < numbers[i])//오큰수 구하지 못한것들을 오른쪽부터 꺼내봐서 현재 수보다 작으면 현재수가 오큰수
		{
			int topIndex = indexStack.top();
			results[topIndex] = numbers[i];
			indexStack.pop();
		}
		indexStack.push(i);
	}
	while (!indexStack.empty())
	{
		results[indexStack.top()] = -1;
		indexStack.pop();
	}
	for (int i = 0; i < N; i++)
	{
		cout << results[i] << " ";
	}
	return 0;
}