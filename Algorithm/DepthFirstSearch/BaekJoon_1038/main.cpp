#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> decreasingNumbers;

void DFS(long long input)//인풋은 1-9사이 수(0은 초기 인풋)
{
    if (input == 0)
    {
        decreasingNumbers.push_back(0);
        decreasingNumbers.push_back(1);
        DFS(1);
        decreasingNumbers.push_back(2);
        DFS(2);
        decreasingNumbers.push_back(3);
        DFS(3);
        decreasingNumbers.push_back(4);
        DFS(4);
        decreasingNumbers.push_back(5);
        DFS(5);
        decreasingNumbers.push_back(6);
        DFS(6);
        decreasingNumbers.push_back(7);
        DFS(7);
        decreasingNumbers.push_back(8);
        DFS(8);
        decreasingNumbers.push_back(9);
        DFS(9);
        return;
    }
    long long inputX10 = input * 10;//인풋의 10배
    long long input1 = input % 10;//인풋의 1의 자리
    for (long long i = 0; i < input1; i++)
    {
        if (inputX10 + i <= 9876543210)
        {
            decreasingNumbers.push_back(inputX10 + i);
            DFS(inputX10 + i);
        }
    }
    
}


int main() 
{
    //문제: N번째 감소하는 수는? 
    //패턴: 0, 1, 2, 3 ... 10, 11, 20, 21, 30, 31,32
    //가장 큰 감소하는 수: 9876543210
    // 감소하는 수의 규칙:
    // 0,1,2,3,4,5,6,7,8,9(+0)
    // 10
    // 21,20
    // 32,31,30
    // 43,42,41,40
    // 54,53,52,51,50(+1)
    // ...
    // 
    // 
    // 210
    // 321,320,310
    // 432,431,430,421,420,410
    // 543,542,541,540,532,531,530,521,520,510
    // 654,653,652,651,650,643,642,641,640,632,631,630,621,620,610(+n)
    // 
    //방법1: 특정수가 감소하는 수인지 판단하는 함수 제작,
    //      그리고 N번 루프를 돌고 N번째 감소하는 수 출력 
    //방법1은 너무 오래걸림

    //방법2: 완전 탐색하는 방법
    //       DFS를 이용한다.
    //       인풋은 0-9사이의 수다.
    //       1,2,3,4,5,6,7,8,9를 인풋으로 DFS호출한다(가장 큰 자리로 해당 숫자를 Pick한다는 의미)
    //       재귀호출 반복(만들어지는 숫자가 최대값이상이면 종료)  
    //       정렬한다.
    //       출력한다(N이 1023이상이면 바로 -1리턴)
    int N;
    cin >> N;
    DFS(0);//수 다 넣기
    sort(decreasingNumbers.begin(), decreasingNumbers.end());//정렬
    if (N >= 1023)
        cout << "-1" << "\n";
    else
        cout << decreasingNumbers[N] << "\n";//N번째 수 출력
    

    return 0;
}