#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	struct compare
	{
		bool operator()(int a, int b)// a>b, a<b가 둘다 true가 되는상황이면 runtime error발생 
		{
			if (abs(a) > abs(b))
				return true;
			if (abs(a) == abs(b))
			{
				return a > b;
			}
			return false;
		}
	};
	priority_queue<int, vector<int>, compare> priorityQueue;//기본 정렬방식은 내림차순(ex/ 7->5->1)
										//우선순위 큐는 힙 자료구조로 저장되며, 삽입 삭제의
										//시간복잡도는 O(logn)
	//STL의 우선순위큐 선언에서 underlying container타입을 선택가능하게 열어둔 이유
	//->https://stackoverflow.com/questions/9958180/advantages-of-setting-priority-queue-container
	//vector는 삽입되었다가 삭제가 되어도 벡터 할당메모리가 줄어들지 않음
	//이를 해결하기 위한 선택권을 주는것
	for (int i = 0; i < N; i++)
	{
		int value = 0;
		cin >> value;
		if (value == 0)
		{
			if (priorityQueue.empty())
			{
				cout << "0\n";
				continue;
			}
			int topValue = priorityQueue.top();
			cout << topValue << "\n";
			priorityQueue.pop();
		}
		else
		{
			priorityQueue.push(value);
		}
	}

	return 0;
}