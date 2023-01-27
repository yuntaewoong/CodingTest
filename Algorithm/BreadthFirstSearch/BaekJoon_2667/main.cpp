#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFS(const int Map[25][25], bool visited[25][25], int i, int j)
{
    int numHouse = 0;
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(i, j));
    while (!bfsQueue.empty())
    {
        pair<int, int> node = bfsQueue.front();
        bfsQueue.pop();
        int row = node.first;
        int col = node.second;
        visited[row][col] = true;//방문처리
        numHouse++;
        if (row + 1 < 25)
        {
            if (Map[row + 1][col] == 1 && !visited[row+1][col])//아래 노드도 집이면
            {
                visited[row + 1][col] = true;
                bfsQueue.push(make_pair(row + 1, col));//아래노드도 방문
            }
        }
        if (col + 1 < 25)
        {
            if (Map[row][col+1] == 1 && !visited[row][col+1])//오른쪽 노드도 집이면
            {
                visited[row][col+1] = true;
                bfsQueue.push(make_pair(row, col+1));//오른쪽 노드도 방문
            }
        }
        if (row - 1 >= 0)
        {
            if (Map[row - 1][col] == 1 && !visited[row - 1][col])//위 노드도 집이면
            {
                visited[row - 1][col] = true;
                bfsQueue.push(make_pair(row - 1, col));//위노드도 방문
            }
        }
        if (col - 1 >= 0)
        {
            if (Map[row][col - 1] == 1 && !visited[row][col - 1])//왼쪽 노드도 집이면
            {
                visited[row][col-1] = true;
                bfsQueue.push(make_pair(row, col - 1));//왼쪽 노드도 방문
            }
        }
    }
    return numHouse;
}



int main() 
{
    //문제 해결방법: 구하고자 하는것은 총 단지수,그리고 각 단지의 집의수를 오름차순으로 출력하는것
    //           추가로 방문을 나타내는 2차원 배열을 선언해줌(방문하면 1, 안하면0)
    //           그리고 단지의 수를 의미하는 벡터를 선언해줌
    //           그리고 0,0부터 N-1,N-1까지 2중 for문을 돈다.(N^2 복잡도)
    //           만약 (i,j)가 집이 있으면, BFS방식으로 집을 방문처리하고 집 수를 세서 벡터에 추가해줌
    //           N-1,N-1까지 반복하면 알고리즘 종료, 시간복잡도는 클것 같지만 N이 25미만이니까 일단 ㄱ

    int N;//N은 N * N 지도의 한변길이 (5 <= N <= 25)
    int Map[25][25];//Map은 집이 있으면 1, 없으면 0을 표기
    bool visited[25][25];//true면 방문, false면 방문안함
    vector<int> towns;//인덱스는 단지이름, 아이템은 단지에있는 집
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            Map[i][j] = atoi(temp.substr(j,1).c_str());
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Map[i][j] == 1 && !visited[i][j])//집이 있고 아직 방문안했으면
            {
                int numHouse = BFS(Map, visited, i, j);
                towns.push_back(numHouse);
            }
        }
    }
    sort(towns.begin(), towns.end());
    cout << towns.size() << "\n";
    for (int i = 0; i < towns.size(); i++)
    {
        cout << towns[i] << "\n";
    }
    return 0;
}