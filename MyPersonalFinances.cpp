#include <iostream>
#include "Card.h"
#include "Spending.h"
#include "Wallet.h"
#include <ctime>
#include "Date.h"
#include "Report.h"
#include <map>

using namespace std;

void start()
{
	Card test(Card::debit);
	test.add(600);
	test.withdraw(new Spending(Spending::home , 20, Date(2021, 1, 1)));
	test.withdraw(new Spending(Spending::subscribes, 20, Date(2022, 10, 1)));
	test.withdraw(new Spending(Spending::hobbies, 5, Date(2022, 9, 24)));
	test.withdraw(new Spending(Spending::home, 8, Date(2022, 10, 3)));
	test.withdraw(new Spending(Spending::hobbies, 9, Date(2022, 10, 3)));
	test.withdraw(new Spending(Spending::home, 10, Date(2022, 10, 7)));
	test.withdraw(new Spending(Spending::transport, 20, Date(2022, 10, 8)));
	test.withdraw(new Spending(Spending::hobbies, 21, Date(2022, 10, 8)));
	test.withdraw(new Spending(Spending::hobbies, 30, Date::getCurrent()));
	test.withdraw(new Spending(Spending::transport, 40, Date::getCurrent()));
	cout << endl;
	Report rep(test.getHistory());
	rep.print_per_day(Spending::hobbies);
	cout << "\n\n";
	rep.print_per_week(2022);
	rep.print_per_week(2021);
}

int main()
{
	start();
	//Date(2022, 10, 1);
	return 0;
}
/*
	class Card, Wallet, spending, report, rating

Создайте систему управления персональными финансами.
Система должна иметь следующие возможности:
■■ Наличие разных кошельков и карт (дебетовых/кредитных);
■■ Пополнение кошельков и карт;
■■ Внесение затрат. Каждая затрата относится к определенной категории;
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
■■ Сохранение отчетов и рейтингов в файл.

*/