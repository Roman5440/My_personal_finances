#pragma once
#include <ctime>
#include <iostream>


using namespace std;
//НЕ ДОБАВЛЯТЬ НОМЕР НЕДЕЛИ В ОПЕРАТОР СРАВНЕНИЯ. В ОСТРИМ ДОБАВИТЬ И ВСЁ
class Date
{
public:
	const int year;
	const int month;
	const int day;
	int weekNumber;
	Date (int y, int m, int d) : year {y}, month {m}, day {d} 
	{
		weekNumber = to_tm(y, m, d);
	}

	static Date getCurrent() //возвращает конкретную дату определенной траты по дням
	{
		struct tm newtime;//структура для показа даты
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int year = newtime.tm_year + 1900;
		int month = newtime.tm_mon + 1;
		int day = newtime.tm_mday;
		return Date(year, month, day);
	}
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		return out << "Year: " << d.year << " Month: " << d.month << " Day: " << d.day;
	}

	friend bool operator <(const Date& d, const Date& d1)
	{
		if (d.year < d1.year)
		{ 
			return true; 
		}
		else if(d.year == d1.year)
		{
			if (d.month < d1.month)
			{
				return true;
			}
			else if (d.month == d1.month)
			{
				if (d.day < d1.day)
				{
					return true;
				}
			}
		}
		return false;
	}

	friend bool operator ==(const Date& d, const Date& d1)
	{
		if (d.year == d1.year && d.month == d1.month && d.day == d1.day) return true;
		return false;
	}

	friend bool operator >(const Date& d, const Date& d1)
	{
		return !(d < d1 || d == d1);
	}
private:
	
	int to_tm(int year, int month, int day)//вывод трат по неделям в определенном году
	{
		tm given{};
		given.tm_year = year - 1900;
		given.tm_mon = month - 1;
		given.tm_mday = day;
		mktime(&given);
		int g = (given.tm_yday + 7 - given.tm_wday) / 7;
		return g == 0 ? 1 : g;
	}
};