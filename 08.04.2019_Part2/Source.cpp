#include"Vector.h"

int main() {

	Date d(28, 2, 2000);

	d.sum_days(15);
	d.print();

	//Date d2(5, 1, 2015);
	////Date d2(d);
	//cout << d.isEqual(d2) << endl;

	d.subtr_days(365);
	d.print();
	d.subtr_days(365);
	d.print();

	Date d1(28, 2, 2000);
	//d1.sum_days(15);
	//d1.subtr_days(730);
	//d1.print();

	int k = d.subtract_date(d1);
	cout << k << endl;

	system("pause");
	return 0;
}