#pragma once
#include"Date.h"

class Vector
{
private:
	Date *els;
	int cur_size;
	int buf_size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector& obj);
	int size();
	void add(Date el);
	Date & operator[](int index);
	void print();
	void print_american();
	~Vector();
};