#pragma once
#include <iostream>
#include "Spending.h"
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Card
{
public:
	enum CardType
	{
		debit,
		credit
	};
private:
	CardType cardType;
	double balance = 0;
	vector <Spending*> history;
public:

	Card(CardType c) : cardType {c} {}

	void withdraw(Spending* value)//аналог метода в Wallet`e
	{
		if (balance < value->getAmount())
		{
			cout << "Not enough money" << endl;
			return;
		}
		history.push_back(value);
		balance -= value->getAmount();
	}

	void add(double amount)
	{
		balance += amount;
	}

	vector <Spending*> getHistory()
	{
		return history;
	}

	void printHistory()
	{
		for (Spending* i : history)
		{
			cout << *i << endl;
		}
	}

	double getBalance()
	{
		return balance;
	}

	CardType getCardType()
	{
		return cardType;
	}
private:
	string resolveCardType()//возвращает текстом тип карты
	{
		switch (this->cardType)
		{
		case debit: return "debit";
		case credit: return "credit";
		}
	}
};

