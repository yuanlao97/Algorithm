/**=====================================================================================
  @brief         ACM_ICPC2008_WorldFinal_F
  @author        bianqr
  @date          2019/11/20
  @description   将(n+4)/2(=r)个R与(n-4)/2(=o)个O组合,要求O不能同时出现且首尾不能同时为O
                   若不考虑O同时在开头跟结尾则 _R_R_R_R_R_R_ 在每个R前后选择位置将O插入,
		 共r+1个R后位置选择o个O插入,即C(r+1,o)=C(r+1,5)
		   若以O开头跟结尾则 OR_R_R_R_R_RO 在每个R(除去最后)后面选择位置将O-2插入,
		 共r-1个位置选择O-2个位置()，即C(r-1,o-2)=C(r-1,5)
		 因此共C(r+1,5)+C(r-1,5)=(r - 1) * (r - 2) * (r - 3) * (r - 2) / 12
----------------------------------------------------------------------------------------
**/
#include<iostream>
using namespace std;

int main()
{
	int number;                   //待输入数
	long long caseNum,r;         //r为90°角个数,caseNum统计所有可能数
	int index = 1;              //计数
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
			//即C(r,4)+C(r-1,4)
			caseNum =(r - 1) * (r - 2) * (r - 3) * (2*r - 4) / 24;
		}
		cout << "Case " << index++ << ": " << caseNum << endl;
	}
	return 0;
}



