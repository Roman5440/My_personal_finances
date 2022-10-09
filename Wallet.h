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

	void withdraw(Spending* value)//сохраняет траты
	{
		if (balance < value->getAmount())//если баланс больше планируемой траты, то вывести сообщение об этом
		{
			cout << "Not enough money";
			return;
		}
		history.push_back(value);//если нет, то сохранить эту трату в историю
		balance -= value->getAmount();//вычет значения траты из значения баланса
	}

	void printHistory()//вывод истории
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

