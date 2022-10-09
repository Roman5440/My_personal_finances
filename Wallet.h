#pragma once
#include "Spending.h"
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Wallet
{
	double balance = 0;
	vector <Spending*> history;
public:
	Wallet() {}

	void withdraw(Spending* value)//��������� �����
	{
		if (balance < value->getAmount())//���� ������ ������ ����������� �����, �� ������� ��������� �� ����
		{
			cout << "Not enough money";
			return;
		}
		history.push_back(value);//���� ���, �� ��������� ��� ����� � �������
		balance -= value->getAmount();//����� �������� ����� �� �������� �������
	}

	void printHistory()//����� �������
	{
		for (Spending* i : history)
		{
			cout << *i << endl;
		}
	}

	void add(double amount)
	{
		balance += amount;
	}

	double getBalance()
	{
		return balance;
	}

	vector <Spending*> getHistory()
	{
		return history;
	}


};

