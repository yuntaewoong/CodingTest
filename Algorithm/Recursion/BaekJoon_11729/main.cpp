#include <iostream>
#include <vector>
using namespace std;
bool ValidIndex(vector<vector<int>>& lab, const int i, const int j)
{
	return (i >= 0) && (j >= 0) && (i < lab.size()) && (j < lab[i].size());
}
void PolluteLabSpace(vector<vector<int>>& lab, const int i, const int j)
{
	if (ValidIndex(lab, -1 + i, j))//����
	{
		if (lab[-1 + i][j] == 0)
		{
			lab[-1 + i][j] = 2;
			PolluteLabSpace(lab, -1 + i, j);
		}
	}
	if (ValidIndex(lab, 1 + i, j))//������
	{
		if (lab[1 + i][j] == 0)
		{
			lab[1 + i][j] = 2;
			PolluteLabSpace(lab, 1 + i, j);
		}
	}
	if (ValidIndex(lab, i, j - 1))//��
	{
		if (lab[i][j - 1] == 0)
		{
			lab[i][j - 1] = 2;
			PolluteLabSpace(lab, i, j - 1);
		}
	}
	if (ValidIndex(lab, i, j + 1))//�Ʒ�
	{
		if (lab[i][j + 1] == 0)
		{
			lab[i][j + 1] = 2;
			PolluteLabSpace(lab, i, j + 1);
		}
	}
}
void PolluteLab(vector<vector<int>>& lab)
{
	for (int i = 0; i < lab.size(); i++)
	{
		for (int j = 0; j < lab[i].size(); j++)
		{
			if (lab[i][j] == 2)//2�� ���̷������ ��
			{
				PolluteLabSpace(lab, i, j);//��������� lab�� ������Ŵ
			}
		}
	}
}




int GetSafeSpaceNum(const vector<vector<int>>& lab)
{
	int result = 0;
	for (int i = 0; i < lab.size(); i++)
	{
		for (int j = 0; j < lab[i].size(); j++)
		{
			if (lab[i][j] == 0)
				result++;
		}
	}
	return result;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int M, N;//M�� ������ N�� �ళ��
	cin >> N;
	cin >> M;
	vector<vector<int>> lab;
	vector<pair<int, int>> zeroIndexes;

	for (int i = 0; i < N; i++)
	{
		lab.push_back(vector<int>());
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 0)
				zeroIndexes.push_back(make_pair(i, j));
			lab[i].push_back(temp);
		}
	}//lab�Է�


	int maxNum = -1;
	for (int i = 0; i < zeroIndexes.size(); i++)
	{
		for (int j = i + 1; j < zeroIndexes.size(); j++)
		{
			for (int k = j + 1; k < zeroIndexes.size(); k++)//zeroIndexes[i],zeroIndexes[j],zeroIndexes[k]�� ���� ���� ����� ��
			{
				vector<vector<int>> tempLab = lab;
				tempLab[zeroIndexes[i].first][zeroIndexes[i].second] = 1;
				tempLab[zeroIndexes[j].first][zeroIndexes[j].second] = 1;
				tempLab[zeroIndexes[k].first][zeroIndexes[k].second] = 1;
				//���� ����

				PolluteLab(tempLab);//������Ŵ
				int safeSpaceNum = GetSafeSpaceNum(tempLab);
				if (maxNum == -1)
				{
					maxNum = safeSpaceNum;
				}
				else if (maxNum <= safeSpaceNum)
				{
					maxNum = safeSpaceNum;
				}
			}
		}
	}
	cout << maxNum;


	return 0;
}