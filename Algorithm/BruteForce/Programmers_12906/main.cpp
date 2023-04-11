#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int past = arr[0];
    answer.push_back(arr[0]);
    for(int i = 1;i<arr.size();i++)
    {
        if(arr[i] == past)
        {
            past = arr[i];
            continue;
        }
        else
        {
            past = arr[i];
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}