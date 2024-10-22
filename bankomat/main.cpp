#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Bankomat
{
	static int id;
	int current_sum;
	int min_sum;
	int max_sum;
	int banknotes[4];
	int amount[4];
public:
	Bankomat(int sum, int min, int max) : current_sum(sum), min_sum(min), max_sum(max)
	{
		id++;
		banknotes[0] = 100;
		banknotes[1] = 200;
		banknotes[2] = 500;
		banknotes[3] = 1000;
		for (int i = 0; i < 4; i++)
		{
			amount[i] = 0;
		}
		
	}
	void Output() const
	{
		cout << endl;
		cout << "Bankomat " << id << endl;
		cout << "Current Sum: " << current_sum << endl;
		cout << "Minimum Sum: " << min_sum << endl;
		cout << "Maximum Sum: " << max_sum << endl << endl;
	}
	void LoadingMoney(int banknote, int count)
	{
		bool isFound = false;
		for (int i = 0; i < 4; i++) 
		{
			if (banknotes[i] == banknote) 
			{
				amount[i] += count;
				current_sum += banknote * count;
				isFound = true;
				for (int i = 0; i < count; i++)
				{
					Sleep(1000);
					cout << "Loading " << banknote << " banknote..." << endl;
				}
				break;
			}
		}
		if (!isFound) cout << "Incorrect banknote" << endl << endl;
	}
	void WithdrawingMoney(int sum)
	{
		if (sum < min_sum || sum > max_sum) 
		{
			cout << "Cannot proceed, withdrawal amount is out of range" << endl << endl;
			return;
		}
		if (sum > current_sum) 
		{
			cout << "Cannot proceed, there are not enough funds in the ATM" << endl << endl;
			return;
		}

		int balance = sum;
		for (int i = 3; i >= 0; i--) 
		{
			int needed = balance / banknotes[i];
			if (needed > 0) 
			{
				int withdraw = min(needed, banknotes[i]);
				amount[i] -= withdraw;
				balance -= withdraw * banknotes[i];
				for (int j = 0; j < needed; j++)
				{
					Sleep(1000);
					cout << "Withdraw " << banknotes[i] << " banknote..." << endl;
				}
			}
		}

		current_sum -= (sum-balance);
	}

	string toString()
	{
		string strSum;
		int intSum = current_sum;
		do 
		{
			char digit = '0' + (intSum % 10);
			strSum = digit + strSum;
			intSum /= 10;
		} while (intSum > 0);

		return strSum;
	}
};
int Bankomat::id = 1110;


int main()
{
	Bankomat atm(0, 100, 30000);
	atm.LoadingMoney(200, 5);
	atm.LoadingMoney(500, 3);
	atm.LoadingMoney(1000, 2);
	atm.LoadingMoney(100, 10);
	atm.Output();

	atm.WithdrawingMoney(2230);
	atm.Output();

	cout << "toString() : " << atm.toString() << endl << endl;
}