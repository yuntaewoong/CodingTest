# Combination
조합, 고등학교 수학시간에 배우는 그 조합 맞다.
- 공식 : $nCr = n-1Cr-1 + n-1Cr$
- 공식의 직관적 설명 : n개중에서 r개를 뽑는 경우의 수는  
특정 1개를 미리 뽑아놓고 나머지 n-1개중에서 r-1개를 뽑거나  
특정 1개를 제외하고 나머지 n-1개를중에서 r개를 뽑는 경우의 합과 같다.  

- 재귀함수 구현
```cpp
void Combination(vector<int>& arr, vector<int> combination, int numItem, int index, int depth)
{
	if (numItem == 0)//base case
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
		combination[index] = arr[depth];
		Combination(arr, combination, numItem - 1, index + 1, depth + 1);//arr[depth]를 뽑은 경우

		Combination(arr, combination, numItem, index, depth + 1);//arr[depth]를 안뽑은 경우
	}
}
```
 - 시간복잡도 : 재귀함수에서 자신을 2번씩 호출하므로 $O(2^n)$  
