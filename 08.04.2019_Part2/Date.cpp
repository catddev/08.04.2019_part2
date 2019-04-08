#include"Date.h"
#include"Vector.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

void Date::setDate(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}




//внешняя для класса функция определения високосных годов
bool isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int Date::subtract_date(Date obj)
{
	int days = 0;
	int max_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int y1, y2;
	y1 = year > obj.year ? year : obj.year;
	y2 = year > obj.year ? obj.year : year;

	for (int i = y1; i > y2; i--) {
		if (isLeap(year))
			days += 366;
		else
			days += 365;
	}
	
	int m1, m2;
	m1 = month > obj.month ? month : obj.month;
	m2 = month > obj.month ? obj.month : month;
	for (int i = m1; i > m2; i--)
		days += max_days[month-1];

	if(month)//
	days += abs(day - obj.day);

	return days;
}

Date Date::sum_days(int days)
{
	int max_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	day += days;
	while (day > max_days[month - 1]) {
		if (isLeap(year))
			max_days[1] = 29;
		day -= max_days[month - 1];
		if (month == 12) {
			year += 1;
			month = 0;
		}
	month++;
	}
	return *this; //ЧТОБЫ ИЗМЕНИТЬ ТЕКУЩУЮ ДАТУ И ВЕРНУТЬ ЭТОТ ОБЪЕКТ ИЗМЕНЕННЫМ
}

Date Date::subtr_days(int days)
{
	int max_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (day == days) {
		if (isLeap(year))
			max_days[1] = 29;
		if (month == 1) {
			year -= 1;
			month = 13;
		}
		month--;
		day = max_days[month-1];
		return *this;
	}
	else if (day > days) {
		day -= days;
		return *this;
	}
	else {
		days -= day;
		while (days > 0) {
			if (isLeap(year))
				max_days[1] = 29;
			else
				max_days[1] = 28; //Иначе пока бегает по запущенному циклу, после первого високосного года все последующие считает вискокосными
			//нужно возвращать обычный год на 28 дней
			if (month == 1) {
				year -= 1;
				month = 13;
			}
			month--;
			days -= max_days[month-1];
			day = abs(days);
		}
		return *this;
	}
}
bool Date::isEqual(Date obj)
{
	return (day==obj.day && month==obj.month && year==obj.year);
}

void Date::print()
{
	cout << day << "." << month << "." << year << endl;
}

void Date::print_american()
{
	cout << month << "/" << day << "/" << year << endl;
}
