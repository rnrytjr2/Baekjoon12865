// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int N, K;
pair<int, int> obj[100];
int DP[100000];
int answer = 0;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> obj[i].first >> obj[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = K; j >0; j--)
		{
			if (obj[i].first <= j)
			{
				DP[j] = max(DP[j], DP[j - obj[i].first] + obj[i].second);
				answer = max(answer, DP[j]);
			}
		}
	}
	cout << answer;
}