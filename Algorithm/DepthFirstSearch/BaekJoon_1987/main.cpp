#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R;//세로 칸수
int C;//가로 칸수
char board[20][20];//board
int maxValue = 0;

void DFS(vector<bool>& steppedOnAlphabet, int i, int j, int numOfPlatforms)
{
    char toSteppingAlphabet;
    if (i - 1 >= 0)//위
    {
        toSteppingAlphabet = board[i - 1][j];
        if (!steppedOnAlphabet[toSteppingAlphabet-'A'])
        {
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = true;
            DFS(steppedOnAlphabet, i - 1, j, numOfPlatforms + 1);
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = false;
        }
    }
    if (i + 1 <= R-1)//아래
    {
        toSteppingAlphabet = board[i + 1][j];
        if (!steppedOnAlphabet[toSteppingAlphabet - 'A'])
        {
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = true;
            DFS(steppedOnAlphabet, i + 1, j, numOfPlatforms + 1);
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = false;
        }
    }
    if (j - 1 >= 0)//왼쪽
    {
        toSteppingAlphabet = board[i][j-1];
        if (!steppedOnAlphabet[toSteppingAlphabet - 'A'])
        {
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = true;
            DFS(steppedOnAlphabet, i, j - 1, numOfPlatforms + 1);
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = false;
        }
    }
    if (j + 1 <= C-1)//오른쪽
    {
        toSteppingAlphabet = board[i][j+1];
        if (!steppedOnAlphabet[toSteppingAlphabet - 'A'])
        {
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = true;
            DFS(steppedOnAlphabet, i, j + 1, numOfPlatforms + 1);
            steppedOnAlphabet[toSteppingAlphabet - 'A'] = false;
        }
    }
    maxValue = maxValue < numOfPlatforms ? numOfPlatforms : maxValue;
}


int main()
{
    //문제: 좌상단에서 시작해서 모든 경로에 있는 알파벳이 달라야함.
    // 이규칙을 따랐을때 최대 가능한 수는?
    // 
    // 일단 이론 상 가능한 최대횟수는 26번임 왜냐하면 알파벳은 26개밖에 없거든
    // 그러면 보드에 있는 알파벳의 종류를 안다면 그게 최대 제한 횟수가됨
    // 그런데 보드에 있는 모든 종류의 알파벳을 다 밟는건 불가능할수도 있음
    //         

    // DFS 해결방법: 좌상단에서 출발시켜서 경로가 4개(상하좌우)인 DFS 과정을 거침
    //                  매 과정마다 가고자 하는 발판이 이미 밟은 알파벳인지 확인하는 절차를 넣음(set을 쓰면 logN복잡도)
    //                  다음 4개 발판이 다 못가는 발판이면, 해당 분기는 탈락
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R;
    cin >> C;

    for (int i = 0; i < R; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = temp[j];
        }
    }
    vector<bool> steppedAlphabet(26,false);
    steppedAlphabet[board[0][0] - 'A'] = true;
    DFS(steppedAlphabet, 0, 0,1);
    cout << maxValue << "\n";
    return 0;
}