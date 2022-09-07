#include <iostream>
#include <limits.h> 
#include <vector>
using namespace std;

/*
인풋:
numbers:수들의 집합
operands:배치되는 연산자들(+,-,*,/)
numPlus:+연산자 개수
numMinus:-연산자 개수
numMultiply:*연산자 개수
numDivide:/연산자 개수

아웃풋
max:최댓값
min:최솟값
*/
void DFSSearch(
	vector<int>& numbers,
	vector<char>& operands,
	int numPlus,
	int numMinus,
	int numMultiply,
	int numDivide,
	int& max,
	int& min
)
{
	if (numPlus == 0 && numMinus == 0 && numMultiply == 0 && numDivide == 0)
	{//연산자 배치 완료시
		int sum = numbers[0];
		for (int i = 0; i < numbers.size()-1; i++)
		{
			switch (operands[i])
			{
			case '+':
				sum += numbers[i + 1];
				break;
			case '-':
				sum -= numbers[i + 1];
				break;
			case '*':
				sum *= numbers[i + 1];
				break;
			case '/':
				sum /= numbers[i + 1];
				break;
			}
		}
		if (max < sum)
			max = sum;
		if (min > sum)
			min = sum;
		return;//DFS종료
	}
	if (numPlus > 0)
	{
		operands.push_back('+');
		DFSSearch(numbers, operands, numPlus - 1, numMinus, numMultiply, numDivide, max, min);
		operands.pop_back();
	}
	if (numMinus > 0)
	{
		operands.push_back('-');
		DFSSearch(numbers, operands, numPlus , numMinus-1, numMultiply, numDivide, max, min);
		operands.pop_back();
	}
	if (numMultiply > 0)
	{
		operands.push_back('*');
		DFSSearch(numbers, operands, numPlus, numMinus, numMultiply-1, numDivide, max, min);
		operands.pop_back();
	}
	if (numDivide > 0)
	{
		operands.push_back('/');
		DFSSearch(numbers, operands, numPlus, numMinus, numMultiply, numDivide-1, max, min);
		operands.pop_back();
	}

}

int main()
{	
	//풀이방법: 모든 경우를 Search해야함
	//DFS이용
	int N;
	cin >> N;
	vector<int> numbers;
	vector<char> operands;
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		numbers.push_back(value);
	}
	int numPlus;
	cin >> numPlus;
	int numMinus;
	cin >> numMinus;
	int numMultiply;
	cin >> numMultiply;
	int numDivide;
	cin >> numDivide;
	
	int max = INT_MIN;
	int min = INT_MAX;

	DFSSearch(numbers, operands, numPlus, numMinus, numMultiply, numDivide, max, min);

	cout << max << "\n";
	cout << min;

	return 0;
}