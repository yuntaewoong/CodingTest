

//문제: N명의 학생이 있는데, 2명씩 키를 비교를 M번 했을때
//     가능한 학생들의 나열의 경우중 하나 출력(키작은거가 앞, 키큰거가 뒤)
//     (3,2), (2,3)처럼 두 학생의 키가 또이또이한 경우를 걸러야함

#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

vector<int> compare[MAX];//비교조건들을 저장하는 벡터들의 배열
//                        (ex/ compare[4] = {1,3,6}의 의미는 4번학생이 1,3,6보다 앞에선다는 의미)
int inDegree[MAX];

void topologySort(int n)//위상정렬
{
    int result[MAX];//위상정렬결과물
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)//어떤 학생 뒤여야한다는 조건이 없는 학생을 먼저 앞에 세움
            q.push(i);
    }
    for (int i = 1; i <= n; i++) //result배열을 1부터 n까지 채워나감
    {
        if (q.empty())
        {
            //cout<<"사이클이 발생"<<endl; 문제조건으로 위상정렬이 가능한case만 주어지므로 이 코드구간으로는 접근하지 않게됨
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;//큐의 가장 앞 아이템으로 i번째를 채움
        for (int i = 0; i < compare[x].size(); i++) //x학생 뒤에와야하는 학생들은 이제 조건1개가 만족되었으므로 inDegree값을 1줄임
        {
            int y = compare[x][i];
            inDegree[y]--;
            if (inDegree[y] == 0)//이제 어떤 학생뒤여야한다는 조건이 없는 학생이 생겼으니 큐에 push
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        cout << result[i] << " ";
    }
}


int main() 
{
    int n; // 학생 수
    int m; // 키를 비교한 횟수
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        int num1, num2;
        cin >> num1 >> num2;
        compare[num1].push_back(num2);
        inDegree[num2]++;
    }
    topologySort(n);

}