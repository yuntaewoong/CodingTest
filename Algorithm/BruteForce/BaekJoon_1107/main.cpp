#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


string N;//이동하고자 하는 채널(0<=N<=500000)
int M;//고장난 버튼의 개수(0<=M<=10)
char broken[10];//고장난 버튼 배열




bool Clickable(string input)//input이 고장난 리모컨으로 클릭가능하면 true리턴
{
    if (input[0] == '-')
        return false;//음수는 입력불가
    int match = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (input[i] == broken[j])
                match++;
        }
    }
    return match==0;
}


int main()
{
    //리모컨이 있는데, 버튼 일부가 고장날수 경우
    //목표로 하는 채널까지 가는데 최소 누르는 횟수 구하기
    //초기 위치는 100채널

    //기본적으로 고장나지 않으면 주어지는 N의 문자수가 최소횟수가 됨
    //더 기본적으로 목표채널이 100채널 주변인경우 +,-만 누르는  횟수가 최소횟수가됨
    //고장날때는 숫자키만 고장나는 것이니, +-로 최대한 N에 가까운 수를 누르는 횟수+ 차이값이 최소횟수가 됨


    //로직: 
    // 1. 목표 채널 문자수 구하기
    // 2. if(고장안남) then min(목표채널-100,목표채널 문자수)
    // 3. else(고장남) then min(목표채널-100,목표채널+-로 1씩 반복문 돌려가면서 고장안난 버튼으로 누룰수 있을때까지 루프, 버튼숫자+루프횟수 
    //
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char temp;
        cin >> temp;
        broken[i] = temp;
    }
    int numOfStr =  N.size();
    int result = 0;
    if (M == 0)
    {
        result = min(abs(stoi(N) - 100), numOfStr);
    }
    else
    {
        string input;//고장난키로 누를수있는 목표에 가장 근접한 채널
        if (M != 10)//모든 키가 고장난게 아닐때면
        {
            string plusInput = N;
            string minusInput = N;
            while (true)
            {
                if (Clickable(minusInput))
                {
                    input = minusInput;
                    break;
                }
                if (Clickable(plusInput))
                {
                    input = plusInput;
                    break;
                }
                
                int plusInputInt = stoi(plusInput);
                int minusInputInt = stoi(minusInput);
                plusInput = to_string(plusInputInt + 1);
                minusInput = to_string(minusInputInt - 1);
            }
            result = min(abs(stoi(N) - 100), abs(stoi(N) - stoi(input)) + (int)input.size());
        }
        else//모든 키가 고장난 경우면
        {
            result = abs(stoi(N) - 100);//+,-만 겁나게 누름
        }
        
    }

    cout << result;

    return 0;
}