#include <string>
#include <iostream>
#include <stack>

using namespace std;



bool solution(string s)
{
    bool answer = true;
    stack<int> bracketStack;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '(')
        {
            bracketStack.push(1);
        }
        else
        {
            if(bracketStack.empty())
            {
                bracketStack.push(1);
                break;
            }
            bracketStack.pop();
        }
    }
    answer = bracketStack.empty();
    return answer;
}