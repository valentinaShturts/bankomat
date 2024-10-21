#include <iostream>
#include <cstring>
using namespace std;

class Bankomat
{
	int current_sum;
	int min_sum;
	int max_sum;
public:
	static int identification_num;
	Bankomat()
	{
		identification_num++;
		current_sum = 5000;
		min_sum = 100;
		max_sum = 30000;
	}
	void Output() const
	{
		cout << "Bankomat " << identification_num << endl;
		cout << "Current Sum: " << current_sum << endl;
		cout << "Minimum Sum: " << min_sum << endl;
		cout << "Maximum Sum: " << max_sum << endl << endl;
	}
	void LoadingMoney()
	{

	}
	void WithdrawingMoney()
	{

	}
};
int Bankomat::identification_num = 1110;