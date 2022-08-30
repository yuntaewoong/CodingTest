#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


char ChangeDirection(char currentDirection, char order)
{
    if (order == 'D')
    {
        if (currentDirection == 'U')
            return 'R';
        if (currentDirection == 'R')
            return 'D';
        if (currentDirection == 'D')
            return 'L';
        if (currentDirection == 'L')
            return 'U';
    }
    else if (order == 'L')
    {
        if (currentDirection == 'U')
            return 'L';
        if (currentDirection == 'L')
            return 'D';
        if (currentDirection == 'D')
            return 'R';
        if (currentDirection == 'R')
            return 'U';
    }
}
bool IsGameEnd(const int boardSize, const deque<pair<int, int>>& snakeInfo)
{
    //죽는 경우1: 벽에 박았는가?
    //죽는 경우2: 머리가 몸에 박았는가?
    int headRow = snakeInfo[0].first;
    int headCol = snakeInfo[0].second;

    for (int i = 0; i < snakeInfo.size(); i++)
    {
        int tempRow = snakeInfo[i].first;
        int tempCol = snakeInfo[i].second;
        if (tempRow < 0 || tempRow >= boardSize || tempCol < 0 || tempCol >= boardSize)
            return true;
        if (i != 0 && (tempRow == headRow) && (tempCol == headCol))
        {
            return true;
        }
    }
    return false;
}
bool MoveOneSecond(vector<vector<int>>& board, char& currentDirection, deque<pair<int, int>>& snakeInfo)
{
    int currentRow = snakeInfo.front().first + 1;
    int currentCol = snakeInfo.front().second + 1;
    if (currentDirection == 'R')
    {
        if (board[currentRow][currentCol + 1] == 1)
        {
            snakeInfo.push_front(make_pair(currentRow - 1, currentCol - 1 + 1));
            board[currentRow][currentCol + 1] = 0;
            return true;
        }
        else
        {
            snakeInfo.push_front(make_pair(currentRow - 1, currentCol - 1 + 1));
        }
    }
    else if (currentDirection == 'U')
    {
        if (board[currentRow - 1][currentCol] == 1)
        {
            snakeInfo.push_front(make_pair(currentRow - 1 - 1, currentCol - 1));
            board[currentRow - 1][currentCol] = 0;
            return true;
        }
        else
        {
            snakeInfo.push_front(make_pair(currentRow - 1 - 1, currentCol - 1));
        }
    }
    else if (currentDirection == 'D')
    {
        if (board[currentRow + 1][currentCol] == 1)
        {
            snakeInfo.push_front(make_pair(currentRow - 1 + 1, currentCol - 1));
            board[currentRow + 1][currentCol] = 0;
            return true;
        }
        else
        {
            snakeInfo.push_front(make_pair(currentRow - 1 + 1, currentCol - 1));
        }
    }
    else if (currentDirection == 'L')
    {
        if (board[currentRow][currentCol - 1] == 1)
        {
            snakeInfo.push_front(make_pair(currentRow - 1, currentCol - 1 - 1));
            board[currentRow][currentCol - 1] = 0;
            return true;
        }
        else
        {
            snakeInfo.push_front(make_pair(currentRow - 1, currentCol - 1 - 1));
        }
    }
    return false;
}

int main()
{
    FAST_IO;
    int N = 0;//보드 사이즈
    int K = 0;//사과 개수
    int L = 0;//방향전환 횟수
    vector<pair<int, char>> changeInfo;
    char currentDirection = 'R';
    deque<pair<int, int>> snakeInfo;
    snakeInfo.push_back(make_pair(0, 0));
    cin >> N;
    vector<vector<int>> board(N + 2, vector<int>(N + 2, 0));// 규칙: 빈칸은 0 사과는 1 + 런타임에러 방지용 행,열 2개씩 추가선언
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int tempRow = 0;
        int tempCol = 0;
        cin >> tempRow;
        cin >> tempCol;
        board[tempRow][tempCol] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int tempSec = 0;
        char tempDir = 0;
        cin >> tempSec;
        cin >> tempDir;
        changeInfo.push_back(make_pair(tempSec, tempDir));
    }


    int gameSec = 0;
    bool isGameEnd = false;
    while (true)
    {
        gameSec++;
        bool getApple = MoveOneSecond(board, currentDirection, snakeInfo);
        if (IsGameEnd(N, snakeInfo))
            break;
        if (!getApple)
            snakeInfo.pop_back();

        for (int i = 0; i < changeInfo.size(); i++)
        {
            int tempSec = changeInfo[i].first;
            if (tempSec == gameSec)
            {
                currentDirection = ChangeDirection(currentDirection, changeInfo[i].second);
            }
        }

    }
    cout << gameSec;
    return 0;
}