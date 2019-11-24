
#include<iostream>
using namespace std;

#define N 1000
long long dp[N+1][5][2];  //dp[i][j][k]表示一共有i个R,j对相邻的R，k=0表示R开头，=1表示1开头

int main()
{
	int number, index = 1;
	long long caseNum;

	dp[1][0][1] = 1;       //OR 开头
	dp[1][0][0] = 1;       //R  开头

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//若R小于4对，则末尾可能挂or或者挂r，挂r则少一对R   R大于四对，则末尾只能挂OR
			dp[i][j][0] = j > 0 ? (dp[i - 1][j][0] + dp[i - 1][j - 1][0]) : dp[i - 1][j][0];
			dp[i][j][1] = j > 0 ? (dp[i - 1][j][1] + dp[i - 1][j - 1][1]) : dp[i - 1][j][1]; //同理
		}
	}


	while (cin >> number)
	{
		if (number == 0) {
			break;
		}
		if (number < 4 || number % 2 != 0)
			caseNum = 0;
		else if (number == 4)
			caseNum = 1;
		else
		{
			long long r = (number + 4) / 2;
			caseNum = dp[r][3][0] + dp[r][4][0] + dp[r][4][1];
		}
		cout << "Case " << index++ << ": " << caseNum << endl;
	}
	return 0;
}
