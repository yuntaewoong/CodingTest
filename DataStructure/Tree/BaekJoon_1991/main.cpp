#include <iostream>
#include <string>
#include <map>
using namespace std;
void PreorderTraversal(map<string, pair<string, string>>& bt, string rootValue)
{
	if (rootValue == ".")
		return;
	cout << rootValue;
	PreorderTraversal(bt, bt[rootValue].first);
	PreorderTraversal(bt, bt[rootValue].second);
}
void InorderTraversal(map<string, pair<string, string>>& bt, string rootValue)
{
	if (rootValue == ".")
		return;
	InorderTraversal(bt, bt[rootValue].first);
	cout << rootValue;
	InorderTraversal(bt, bt[rootValue].second);
}
void PostorderTraversal(map<string, pair<string, string>>& bt, string rootValue)
{
	if (rootValue == ".")
		return;
	PostorderTraversal(bt, bt[rootValue].first);
	PostorderTraversal(bt, bt[rootValue].second);
	cout << rootValue;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	map<string, pair<string, string>> binaryTree;
	for (int i = 0; i < N; i++)
	{
		string root, left, right;
		cin >> root;
		cin >> left;
		cin >> right;
		binaryTree[root] = make_pair(left, right);
	}
	//���� ��ȸ
	PreorderTraversal(binaryTree, "A");
	cout << "\n";
	//���� ��ȸ
	InorderTraversal(binaryTree, "A");
	cout << "\n";
	//���� ��ȸ
	PostorderTraversal(binaryTree, "A");
	cout << "\n";


	return 0;
}