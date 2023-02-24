#include <iostream>
#include <cmath>
#include <string>
using namespace std;


//문제: 초기 톱니상태와 톱니 회전방법이 주어질때
//최종 톱니바퀴의 상태를 구하는 프로그램

//톱니바퀴는 고정 4개
//톱니는 8개가있고 N극은 0, S극은 1로 표현

//회전은 2개의 숫자로 표시, 첫번째 숫자는 어떤 톱니인지
//두번째 숫자는 어떤 방향인지(1은 시계방향 -1은 반시계방향)

//구하는 것은 최종 톱니바퀴상태에서 12시 방향의 톱니날 점수의 합계
//구하는 규칙은 문제에 정의됨


class Circle
{
public:
	Circle() {}
	int item[8];
};
class Rotation
{
public:
	Rotation() {}
	int circleNum;
	int direction;
};

Circle circles[4];
Rotation rotations[200];//회전정보
int K;//회전횟수


//회전 판단은 1번 톱니의 2번톱날, 2번 톱니의 6번톱날
//           2번 톱니의 2번톱날, 3번 톱니의 6번 톱날
//           3번 톱니의 2번톱날, 4번톱니의 6번 톱날에서
//           일어남


//Rotate함수는 circleNum번째 톱니를 direction방향으로 회전시키는 함수
void Rotate(int circleNum, int direction)
{
	int temp;
	switch (direction)
	{
	case -1://반시계
		temp = circles[circleNum].item[0];
		for (int i = 1; i < 8; i++)
		{
			circles[circleNum].item[i - 1] = circles[circleNum].item[i];
		}
		circles[circleNum].item[7] = temp;
		break;
	case 1://시계
		temp = circles[circleNum].item[7];
		for (int i = 7; i > 0; i--)
		{
			circles[circleNum].item[i] = circles[circleNum].item[i - 1];
		}
		circles[circleNum].item[0] = temp;
		break;
	}
}




//RotateAll함수는 특정 톱니를 어떻게 회전할지 정의되었을때
//4개의 톱니가 돌아가는 방법을 정의함
void RotateAll(int circleNum, int direction)
{
	int rotateDir[4];//rotateDir은 0이면 회전x,-1이면 반시계,1이면 시계방향 회전한다는뜻
	rotateDir[circleNum] = direction;
	int upTest = circleNum + 1;
	int downTest = circleNum - 1;
	while (upTest < 4)//circleNum보다 큰경우로 테스트
	{
		if (circles[upTest - 1].item[2] == circles[upTest].item[6])//같은 극이면
		{
			rotateDir[upTest] = 0;//회전 안함
		}
		else if (circles[upTest - 1].item[2] != circles[upTest].item[6] && rotateDir[upTest - 1] != 0)
		{
			rotateDir[upTest] = rotateDir[upTest - 1] * (-1);//왼쪽꺼랑 역방향 회전걸림
		}
		else
		{
			rotateDir[upTest] = 0;
		}
		upTest++;
	}
	while (downTest >= 0)//circleNum보다 작은 경우로 테스트
	{
		if (circles[downTest].item[2] == circles[downTest + 1].item[6])//같은 극이면
		{
			rotateDir[downTest] = 0;//회전 안함
		}
		else if (circles[downTest].item[2] != circles[downTest + 1].item[6] && rotateDir[downTest + 1] != 0)
		{
			rotateDir[downTest] = rotateDir[downTest + 1] * (-1);//오른쪽꺼랑 역방향 회전걸림
		}
		else
		{
			rotateDir[downTest] = 0;
		}
		downTest--;
	}


	for (int i = 0; i < 4; i++)//회전처리
	{
		if (rotateDir[i] != 0)
			Rotate(i, rotateDir[i]);
	}
}



int Score()
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (circles[i].item[0] == 1)
			result += pow(2, i);
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			circles[i].item[j] = atoi(input.substr(j, 1).c_str());
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> rotations[i].circleNum;
		cin >> rotations[i].direction;
	}
	for (int i = 0; i < K; i++)
	{
		RotateAll(rotations[i].circleNum - 1, rotations[i].direction);
	}
	cout << Score();
}