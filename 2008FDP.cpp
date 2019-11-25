
/**=====================================================================================
  @brief        ACM_ICPC2008_WorldFinal_F
  @author       bianqr
  @date         2019/11/20
  @description  将(n+4)/2(=r)个R与(n-4)/2(=o)个O组合,要求O不能同时出现且首尾不能同时为O
				动态规划寻找出逆推关系,自底向上得出所有的结果
				dp[i][j][k]表示还剩i个R，还剩j对相邻的R,k表示以R还是O开头
				  递推关系：dp[i][j][k] = dp[i-1][j][k](向后面插入一对OR,没有增加相邻的R)
				+dp[i-1][j-1][k](如果还有相邻的R<j>0>则也可能向后面插入R)
				  边界情况：dp[1][0][0]=dp[1][0][1]=1(分别还剩R和OR)			
----------------------------------------------------------------------------------------
**/
#include<iostream>
using namespace std;

#define N 1000
long long dp[N+1][5][2];  //dp[i][j][k]表示还剩下i个R,还有j对相邻的R(一共有四对)，k=0表示R开头，=1表示1开头

int main()
{
	int number, index = 1;
	long long caseNum,r;

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
			r = (number + 4) / 2;
			caseNum = dp[r][3][0] + dp[r][4][0] + dp[r][4][1];
		}
		cout << "Case " << index++ << ": " << caseNum << endl;
	}
	return 0;
}
