#include<iostream>
using namespace std;

int main()
{
	int number;
	long long caseNum;
	int index = 1;
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
			long long R = (number + 4) / 2;
			caseNum =(R - 1) * (R - 2) * (R - 3) * (2*R - 4) / 24;
		}
		cout << "Case " << index++ << ": " << caseNum << endl;
	}
	return 0;
}