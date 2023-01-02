#include <iostream>
#include <math.h>
using namespace std;

int order(int NLevel,int r,int c)
{
    if (NLevel == 1)
    {
        if (r == 0 && c == 0)
            return 0;
        else if (r == 0 && c == 1)
            return 1;
        else if (r == 1 && c == 0)
            return 2;
        else
            return 3;
    }
    if (r / (int)pow(2,NLevel - 1) == 0 && c / (int)pow(2, NLevel - 1) == 0)
        return order(NLevel - 1,r,c);
    else if (r / (int)pow(2, NLevel - 1) == 0 && c / (int)pow(2, NLevel - 1) == 1)
        return order(NLevel - 1,r,c - (int)pow(2, NLevel - 1)) + (int)pow(2, NLevel - 1) * (int)pow(2, NLevel - 1);
    else if (r / (int)pow(2, NLevel - 1) == 1 && c / (int)pow(2, NLevel - 1) == 0)
        return order(NLevel - 1, r - (int)pow(2, NLevel - 1), c) + 2 * (int)pow(2, NLevel - 1) * (int)pow(2, NLevel - 1);
    else
        return order(NLevel - 1, r - (int)pow(2, NLevel - 1), c- (int)pow(2, NLevel - 1)) + 3 * (int)pow(2, NLevel - 1) * (int)pow(2, NLevel - 1);
}


int main() 
{
    //int arr[32768][32768]; 500메가 제한을 넘김(모든 배열을 쓰는 문제가아니다)
    int N;
    int r;
    int c;
    cin >> N;
    cin >> r;//r행
    cin >> c;//c열
    //2의 N승 * 2의 N승의 배열인데, 이 단계는
    //4개의 구역으로 나눌수있음(왼위,오위,왼아,오아), 그리고 이 4개의 구역은 왼위->오위->왼아->오아 순서로 검색함
    //즉, 일단 r행 c열이 각 단계의 어느 구역인지를 판단해나가면 문제가 풀림
    // N이 15라면, 4가지 구역중 어디에 (r,c)가 있나 파악하고, N이 14일때 파악하고
    //쭈우욱 하다가 N이 1이면 리턴함, 리턴할때는 N * (왼위:0,오위:1,왼아:2:오아:3)하면 됨
    int result = order(N, r, c);
    cout << result << "\n";
    return 0;
}