#include <iostream>
#include <vector>
using namespace std;

class RGBCost
{
public:
    int r;
    int g;
    int b;
};


int main() 
{
    int N = 0;
    int D[1001][3];//점화식 값 저장용
    cin >> N;//집의 수(맞닿는 집은 색깔이 서로 달라야함)
    //DP 점화식: D[i] = D[i-1] + MIN(paintingCosts[i].r,paintingCosts[i].g,paintingCosts[i].b
    //근데 paintingCosts[i]에 r을 선택하면 paintingCosts[i+1]에는 g,b만 선택가능함
    // 그에 맞게 점화식 수정해야함
    // 그러면 Min(D[N][0],D[n][1],D[n][2])가 최적의 해임 
    //
    //
    vector<RGBCost> paintingCosts(N, RGBCost());
    for (int i = 0; i < N; i++)
    {
        int r, g, b;
        cin >> r;
        cin >> g;
        cin >> b;
        paintingCosts[i].r = r;
        paintingCosts[i].g = g;
        paintingCosts[i].b = b;
    }
    //인풋
    D[0][0] = paintingCosts[0].r;
    D[0][1] = paintingCosts[0].g;
    D[0][2] = paintingCosts[0].b;
    //첫번째항 예외처리
    for (int i = 1; i < N; i++)
    {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + paintingCosts[i].r;
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + paintingCosts[i].g;
        D[i][2] = min(D[i - 1][0], D[i - 1][1]) + paintingCosts[i].b;
    }
    cout << min(min(D[N-1][0], D[N-1][1]), D[N-1][2]) << "\n";
    return 0;


}