/**=====================================================================================
  @brief         ACM_ICPC2008_WorldFinal_F
  @author        bianqr
  @date          2019/11/20
  @description   将(n+4)/2(=r)个R与(n-4)/2(=o)个O组合,要求O不能同时出现且首尾不能同时为O
                   若以R开头则 R_R_R_R_R_R_ 在每个R后面选择位置将O插入,共r个R后位置选择o
				 个O插入,即C(r,o)=C(r,4)
				   若以O开头则 OR_R_R_R_R_R 在每个R后面选择位置将O插入,O开头则
				 末尾只能为R,r-1个位置选择o-1插入o-1个O，即C(r-1,o-1)=C(r-1,4)
				 因此共C(r,4)+C(r-1,4)=(r - 1) * (r - 2) * (r - 3) * (2*r - 4) / 24
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



