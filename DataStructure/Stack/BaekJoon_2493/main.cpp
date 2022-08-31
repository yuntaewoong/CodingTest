#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main()
{
	FAST_IO;
	int N;
	stack<pair<int, int>> st;
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && st.top().second < a[i])
			st.pop();
		if (st.empty())
			cout << 0 << ' ';
		else
			cout << st.top().first << " ";
		st.push({ i + 1, a[i] });
	}

	return 0;
}