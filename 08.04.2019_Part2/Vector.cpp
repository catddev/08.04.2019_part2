#include"Vector.h"

Vector::Vector()
{
	els = 0;
	buf_size = cur_size = 0;
}

Vector::Vector(int size)
{
	cur_size = 0;
	buf_size = size;
	els = new Date[buf_size];
}

Vector::Vector(const Vector & obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.cur_size;
	this->els = new Date[buf_size];
	for (int i = 0; i < cur_size; i++) {
		els[i] = obj.els[i];
	}
}

int Vector::size()
{
	return cur_size;
}

void Vector::add(Date el)
{
	if (buf_size == 0) {
		buf_size = 4;
		els = new Date[buf_size];
	}
	else
	{
		if (cur_size == buf_size) {
			buf_size *= 2;
			Date* tmp = new Date[buf_size];
			for (int i = 0; i < cur_size; i++)
				tmp[i] = els[i];

			delete[] els;
			els = tmp;
		}
	}
	els[cur_size++] = el;
}

Date & Vector::operator[](int index)
{
	return els[index];
}
void Vector::print()
{
	for (int i = 0; i < cur_size; i++)
		els[i].print();
	cout << endl;
}
void Vector::print_american()
{
	for (int i = 0; i < cur_size; i++)
		els[i].print_american();
	cout << endl;
}
Vector::~Vector()
{
	cout << "DESTRUCTOR" << endl;
	delete[] els;
}