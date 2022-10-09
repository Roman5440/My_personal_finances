#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class Spending
{
public:
	
	enum SpendingCategory
	{
		subscribes,
		hobbies,
		transport,
		home
	};

private:

	SpendingCategory spendingCategory;
	double amount;
	Date date;

public:
	
	Spending(SpendingCategory s, double a, Date d) : spendingCategory {s}, amount {a}, date{d} {}

	SpendingCategory getSpeningCategory()
	{
		return spendingCategory;
	}

	Date getDate()
	{
		return date;
	}

	double getAmount()
	{
		return amount;
	}

	friend ostream& operator <<(ostream& out, Spending& s)
	{
		return out << "Category `" << s.resolveCategoryName() << "` --- Amount `" << s.amount << "`" << s.date;
	}

private:

	string resolveCategoryName()//возвращает текстом категорию трат
	{
		switch (this->spendingCategory)
		{
		case subscribes: return "subscribes";
		case hobbies: return "hobbies";
		case transport: return "transport";
		case home: return "home";
		}
	}
};

