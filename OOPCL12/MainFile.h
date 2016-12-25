#pragma once

class Vector {
private:
	string name;
	int x; //начало по х 
	int y; //начало по у
	int modul; //модуль вектора

public:
	void Vector::setCreate( string, int, int);
	void Vector::setAdd(int, int);
	void Vector::setProduct();
	void Vector::getPrint();
	void Vector::setModule(int);

	Vector();
	Vector(int, int);
	Vector(const Vector&);
	~Vector();
};

