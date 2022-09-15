#include <iostream>
#include <vector>
using namespace std;

void Combination(vector<int>& arr, vector<int> combination, int numItem, int index, int depth)
{
	if (numItem == 0)//base case, 조합을 완성한 경우
	{
		for (int i = 0; i < combination.size(); i++)
			cout << combination[i] << " ";
		cout << "\n";
	}
	else if (depth == arr.size())  
	{
		return;
	}
	else
	{
		//C(n,r) = C(n-1,r-1) + C(n-1,r), n개 중에 r개를 뽑는 경우는 n-1개중에 r-1개를 뽑는 경우랑
		// n-1개중에 r개 뽑는 경우의 합과 같음
		//예시-> 5개중에서 3개 뽑는 경우는 일단 1개를 지정해놓고 나머지 4개중에서 2개를 뽑는경우와
		// 나머지 4개중에서 3개를 뽑는 경우의 합임
		combination[index] = arr[depth];
		Combination(arr, combination, numItem - 1, index + 1, depth + 1);//arr[depth]를 뽑은 경우

		Combination(arr, combination, numItem, index, depth + 1);//arr[depth]를 안뽑은 경우
	}
}

int main()
{	
	int K = -1;
	vector<vector<int>> testCase;
	int testCaseIndex = 0;
	while (true)
	{
		cin >> K;
		if (K == 0)
			break;
		testCase.push_back(vector<int>());
		for (int i = 0; i < K; i++)
		{
			int value;
			cin >> value;
			testCase[testCaseIndex].push_back(value);
		}
		testCaseIndex++;
	}//입력
	
	for (int i = 0; i < testCase.size(); i++)//각 testCase경우에 대하여
	{
		vector<int> combination(6,0);
		Combination(testCase[i], combination, 6, 0, 0);
		cout << "\n";//각 테스트 case사이에는 빈줄 출력
	}

	return 0;
}