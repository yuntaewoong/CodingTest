#include <iostream>
using namespace std;

void crossProduct(int v_A[], int v_B[], int c_P[]) {
	c_P[0] = v_A[1] * v_B[2] - v_A[2] * v_B[1];
	c_P[1] = -(v_A[0] * v_B[2] - v_A[2] * v_B[0]);
	c_P[2] = v_A[0] * v_B[1] - v_A[1] * v_B[0];
}

//반시계면 1
//시계면 -1
//일직선이면 0
int Solve(
	int p1[],
	int p2[],
	int p3[]
)
{
	int p1p2[3];
	int p2p3[3];
	for (int i = 0; i < 3; i++)
	{
		p1p2[i] = p1[i] - p2[i];
		p2p3[i] = p2[i] - p3[i];
	}
	int crossVector[3];
	crossProduct(p1p2, p2p3, crossVector);
	if (crossVector[2] == 0)
		return 0;
	else if (crossVector[2] > 0)
		return 1;
	else
		return -1;
}	
int main()
{	
	//풀이법: p1->p2와 p2->p3벡터를 외적해서 z부호가 양수면 cw,음수면ccw,
	int p1[3];
	int p2[3];
	int p3[3];

	cin >> p1[0];
	cin >> p1[1];
	p1[2] = 0;
	cin >> p2[0];
	cin >> p2[1];
	p2[2] = 0;
	cin >> p3[0];
	cin >> p3[1];
	p3[2] = 0;
	cout << Solve(p1, p2, p3);
	return 0;
}