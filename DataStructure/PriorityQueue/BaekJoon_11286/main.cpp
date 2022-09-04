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
		bool operator()(int a, int b)// a>b, a<b�� �Ѵ� true�� �Ǵ»�Ȳ�̸� runtime error�߻� 
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
	priority_queue<int, vector<int>, compare> priorityQueue;//�⺻ ���Ĺ���� ��������(ex/ 7->5->1)
										//�켱���� ť�� �� �ڷᱸ���� ����Ǹ�, ���� ������
										//�ð����⵵�� O(logn)
	//STL�� �켱����ť ���𿡼� underlying containerŸ���� ���ð����ϰ� ����� ����
	//->https://stackoverflow.com/questions/9958180/advantages-of-setting-priority-queue-container
	//vector�� ���ԵǾ��ٰ� ������ �Ǿ ���� �Ҵ�޸𸮰� �پ���� ����
	//�̸� �ذ��ϱ� ���� ���ñ��� �ִ°�
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