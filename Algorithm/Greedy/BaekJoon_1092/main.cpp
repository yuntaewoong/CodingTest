#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void OneTimeCrainWork(const vector<int>& crainTalent,vector<int>& boxWeight)
{
    //가장 일잘하는 크레인부터 차례차례 따져보기
    for (int i = 0; i < crainTalent.size(); i++)
    {   
        if (boxWeight.empty())//옮길 박스가 없다면 알고리즘 종료
            return;
        for (int j = 0; j < boxWeight.size(); j++)
        {
            if (crainTalent[i] >= boxWeight[j])//능력이 카바가 되면
            {
                boxWeight.erase(boxWeight.begin() + j);//해당 박스 옮김 처리
                break;//다음 크레인으로 넘어감
            }
        }
    }
}




int main() 
{
    //문제: N대의 크레인이 존재, N대의 크레인은 들수있는 무게제한이 있음.
    // 크레인이 한번드는데 1분이고 모든 크레인은 병렬작업이 가능함
    //M개의 박스가 존재, M개의 박스의 무게가 주어질때
    //모든 박스를 옮기는데 드는 최소시간은?
    //불가능하면(크레인 최대능력보다 무거운 박스존재) -1출력해라
    //
    // 그리디 알고리즘을 쓰자
    //최대 능력을 가진 크레인이 최대 무게를 가진 박스를 들어야지 최적의 해를 구할 수 있다.
    //그래서 일단 능력배열,무게배열을 정렬을 하고
    //
    //무게 배열에 존재하면 안옮긴 박스
    // 알고리즘 종료조건은 무개배열이 empty인것
    //
    //크레인으로 한번 실행하는 함수를 정의함
    //이 함수는 가장 이상적인 1회를 시행하고 옮긴 박스들을 무게배열에서 삭제함
    //

    int N;// <= 50
    vector<int> CrainTalent;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        CrainTalent.push_back(temp);
    }
    sort(CrainTalent.begin(), CrainTalent.end(),greater<int>());

    int M;// <= 10000
    vector<int> BoxWeight;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        BoxWeight.push_back(temp);
    }
    sort(BoxWeight.begin(), BoxWeight.end(), greater<int>());


    int result = 0;
    while (!BoxWeight.empty())
    {
        if (BoxWeight[0] > CrainTalent[0])//가장 쩌는 크레인이 가장 무거운 박스를 못들면 영영불가능
        {
            result = -1;
            break;
        }
        OneTimeCrainWork(CrainTalent, BoxWeight);
        result++;
    }
    cout << result << "\n";
    return 0;