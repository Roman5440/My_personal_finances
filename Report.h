#pragma once
#include "Spending.h"
#include <vector>
#include <map>
#include "Date.h"

using namespace std;
using Category = Spending::SpendingCategory;

#define loop(history) for (Spending* sp : history)

class Report
{
	vector<Spending*> history;
public:
	Report(vector<Spending*> history)
	{
		this->history = history;
	}

	void print_per_week(int year)//собирает историю по тратам за определенную неделю
	{
		map<int, vector<Spending>> per_week;
		loop(history)
		{
			if (sp->getDate().year == year)//собирает по определенному году
			{
				per_week[sp->getDate().weekNumber].push_back(*sp);
			}
		}
		for (const auto& m : per_week)
		{
			cout << '[' << m.first << "] = " << endl;
			for (Spending s : m.second)
			{
				cout << "\t" << s << endl;
			}
		}
	}

	void print_per_day(Category c = (Category) -1)//собирает историю по тратам за определенный день
	{
		map<Date, vector<Spending>> per_day;
		loop(history)
		{
			if (c != -1)
			{
				if (sp->getSpeningCategory() == c)
				{
					per_day[sp->getDate()].push_back(*sp);
				}
			}
			else
			{
				per_day[sp->getDate()].push_back(*sp);
			}
		}
		for (const auto& m : per_day) 
		{
			cout << '[' << m.first << "] = " << endl;
			for (Spending s : m.second)
			{
				cout << "\t" << s << endl;
			}
		}
	}
private:
	map<int, vector<Spending>> prepare_per_week(int year)//если нужна сортировка по году
	{
		map<int, vector<Spending>> per_week;
		loop(history)
		{
			if (sp->getDate().year == year)//собирает по определенному году
			{
				per_week[sp->getDate().weekNumber].push_back(*sp);
			}
		}
		return per_week;
	}

	map<int, vector<Spending>> prepare_per_week(int year, Category sc)//если нужна сортировка по году и категории (не виден в мэйне?)
	{
		map<int, vector<Spending>> per_week;
		loop(history)
		{
			if (sp->getDate().year == year && sp->getSpeningCategory() == sc)//собирает по определенному году и категории
			{
				per_week[sp->getDate().weekNumber].push_back(*sp);
			}
		}
		return per_week;
	}

	map<Date, vector<Spending>> prepare_per_day()//отчёт за день по всем тратам
	{
		map<Date, vector<Spending>> per_day;
		loop(history)
		{
			per_day[sp->getDate()].push_back(*sp);
		}
		return per_day;
	}

	map<Date, vector<Spending>> prepare_per_day(Category sc)//отчет за день по тратам в определенной категории
	{
		map<Date, vector<Spending>> per_day;
		loop(history)
		{
			if (sp->getSpeningCategory() == sc)
			{
				per_day[sp->getDate()].push_back(*sp);
			}
		}
		return per_day;
	}
};
/*
■■ Формирование отчетов по затратам и категориям:
• день;
• неделя; (итерация по пер дэю с разницей в 7 дней)
• месяц.
■■ Формирование рейтингов по максимальным суммам:
• ТОП-3 затрат:
ӽӽ неделя;
ӽӽ месяц.
• ТОП-3 категорий:
ӽӽ неделя;
ӽӽ месяц.
*/

