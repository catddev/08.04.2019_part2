#include "Date.h"
#include"menu.h"

void menu(Vector v)
{
	int x, y;
	while (true) {
		int choice;
		cout << " Enter 1 to subtract two dates one from another" << endl;
		cout << " Enter 2 to add some days to the given date " << endl;
		cout << " Enter 3 to subtract some days from the given date" << endl;
		cout << " Enter 4 to compare if 2 dates are equal" << endl;
		cout << " Enter 5 to print out information in needed format" << endl;
		cout << " Enter 0 to exit" << endl;
		cin >> choice;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			cout << "Enter indexes of dates from the array to subtract. Fisrt earlier date" << endl;
			cin >> x >> y;
			cout << v[x].subtract_date(v[y]) << endl;
			break;
		case 2:
			cout << "Enter index of date to change and amount of days to add: ";
			cin >> x >> y;
			v[x].sum_days(y);
			v[x].print();
			break;
		case 3:
			cout << "Enter index of date to change and amount of days to subtract: ";
			cin >> x >> y;
			v[x].subtr_days(y);
			v[x].print();
			break;
		case 4:
			cout << "Enter indexes of dates from the array to compare: ";
			cin >> x >> y;
			if (v[x].isEqual(v[y]))
				cout << "The same date" << endl << endl;
			else
				cout << "Date are not equal" << endl << endl;
			break;
		case 5:
			int cc = 0;
			cout << "Enter 1 to print dates in standart format" << endl;
			cout << "Enter 2 to print dates in american format" << endl;
			cin >> cc;
			if (cc == 1)
				v.print();
			else if (cc == 2)
				v.print_american();
			break;
		}
	}
}