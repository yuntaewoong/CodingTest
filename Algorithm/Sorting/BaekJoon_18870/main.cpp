#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main()
{	
	//딱 봐도 틀릴것 같은 O(n^2)방법: 모든 값들을 Vector에 채워놓고
	// 각 Vector Item마다 또 Vector돌면서 자기보다 작은 값들 찾기

	// 정렬이 힌트, 정렬은 퀵소트 이용하면 O(nlogn)임
	// 저 vector를 바로 정렬한다고 답이 나오진 않음
	// 내 아이디어: 중복을 없앤 Vector를 만들어 퀵소트=> O(nlogn)
	// 그 후, Vector를 순회하며 Map생성(key: 값, value: 자기보다 작은 값 개수(순회할때의 Index) => O(n)
	// 최종 단계에서는 원래 Vector를 순회하며 값 출력 => O(nlogn)
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int N = 0;
	cin >> N;
	vector<int>	numbers(N, 0);
	set<int> numbersNoDuplicate;
	map<int, int> numberMap;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		numbers[i] = temp;
		numbersNoDuplicate.insert(temp);
	}

	set<int>::iterator iter;
	int idx = 0;
	for (iter = numbersNoDuplicate.begin() ; iter != numbersNoDuplicate.end() ; iter++)
	{
		numberMap.insert(make_pair(*iter, idx));
		idx++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << numberMap[numbers[i]] << " ";
	}

	return 0;
}