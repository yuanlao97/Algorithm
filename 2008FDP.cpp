/**=====================================================================================
  @brief        ACM_ICPC2008_WorldFinal_F
  @author       bianqr
  @date         2019/11/25
  @description  将(n+4)/2(=r)个R与(n-4)/2(=o)个O组合,要求O不能同时出现且首尾不能同时为O
	        动态规划寻找出逆推关系,自底向上得出所有的结果
	        dp[i][j]表示还剩i个R，j个相邻的R(j最多为4，因为初始R-O=4),
	        递推关系：dp[i][j] = dp[i-1][j](向后面插入R)+dp[i-1][j-1](向后面插入OR)
	        边界情况：dp[1][0]=1 //还剩下一个R直接插入则结束(插入OR)
	        一共：dp[(n+4)/2][4](R__R)+2*dp[(n+4)/2][4](R__O或者O__R)
----------------------------------------------------------------------------------------
**/
#include<iostream>
using namespace std;

#define N 1000
long long dp[(N + 4) / 2 + 1][5];  //输入的数据是0-1000之间,而R的个数为(N+4)/2,O为(N-4)/2

int main()
{
	int number, index = 1;
	long long caseNum, r;

	dp[1][0] = 1;

	for (int i = 2; i <= (N + 4) / 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dp[i][j] = j > 0 ? (dp[i - 1][j] + dp[i - 1][j - 1]) : dp[i - 1][j];
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
			caseNum = dp[r][3] + 2*dp[r][4]; 
		}
		cout << "Case " << index++ << ": " << caseNum << endl;
	}

	return 0;
}
