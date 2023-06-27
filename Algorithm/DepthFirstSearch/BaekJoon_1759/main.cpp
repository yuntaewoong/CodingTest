#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int	L;
int C;
char Characters[15];


//암호조건: 주어진 소문자만 사용,	최소1개의 모음(a,e,i,o,u) 최소 2개의 자음 사용
//
// 
// 문자 L개를 고르면 1가지 경우만 나옴-> 선택의 문제
// 최대 경우의 수: C(15,7) = 15*14*13*12*11*10*9/7! = 6485
// 풀이법: DFS
//	1. Characters배열 오름차순 정렬
//  2. 모음카운팅,자음카운팅 변수 선언
//  3. Characters배열 왼쪽부터 DFS순회
//  4. L개를 고른후 조건 만족 확인후 만족하면 출력
// 
//
bool CheckCondition(int numVowel, int numConsonant)
{
	return numVowel >= 1 && numConsonant >= 2;
}



void DFS(string sentence,int index,int numVowel,int numConsonant)
{
	char selectedChar = sentence[sentence.size()-1];
	if (
		selectedChar == 'a' ||
		selectedChar == 'e' ||
		selectedChar == 'i' ||
		selectedChar == 'o' ||
		selectedChar == 'u'
		)
	{
		numVowel++;
	}
	else
		numConsonant++;
	if (sentence.size() == L)
	{
		if (CheckCondition(numVowel, numConsonant))
		{
			cout << sentence;
			cout << "\n";
		}
	}
	
	if (index == C - 1)
		return;
	for (int i = index+1; i < C; i++)
	{
		string newSentence = sentence + Characters[i];
		DFS(newSentence, i, numVowel, numConsonant);
	}
	
	
}
int main()
{
	cin >> L;//암호에 사용되는 글자수
	cin >> C;//암호에 사용될 가능성이 있는 문자수
	for (int i = 0; i < C; i++)
	{
		cin >> Characters[i];
	}
	sort(Characters,Characters+C);
	for (int i = 0; i < C; i++)
	{
		string sentence;
		sentence += Characters[i];
		DFS(sentence, i, 0, 0);
	}
	return 0;
}