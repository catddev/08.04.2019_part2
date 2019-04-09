#include"Vector.h"
#include"menu.h"

int main() {

	//Date d(28, 2, 2000);

	//d.sum_days(15);
	//d.print();

	//Date d2(5, 1, 2015);
	////Date d2(d);
	//cout << d.isEqual(d2) << endl;

	//d.subtr_days(365);
	//d.print();
	//d.subtr_days(365);
	//d.print();

	//Date d1(28, 2, 2000);
	//d1.sum_days(15);
	//d1.print();
	//d1.subtr_days(365);
	//d1.print();


	//int k = d1.subtract_date(d);
	//cout << k << endl;

	/*Date d3(28, 2, 2000);
	Date d4(14, 3, 1999);
	d3.print();
	d4.print();
	int k;
	k = d4.subtract_date(d3);
	cout << k << endl;

	d3.subtr_days(60);
	d3.print();*/

	ifstream in_file("in.txt");
	int a, b, c;
	Date d;
	Vector v;

	while (!in_file.eof()) {
		in_file >> a >> b >> c;
		d.setDate(a, b, c);
		v.add(d);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << i << " - ";
		v[i].print();
	}
	cout << endl;

	menu(v);

	system("pause");
	return 0;
}