#include "stdafx.h"
#include <iostream>

using namespace std;

class Figure {//----------------------------����� ������
	float *sz;
public:
	Figure();
	Figure(float);
	virtual ~Figure();
	virtual void Show()=0;
	virtual double CalcArea()=0;
};

Figure::Figure() {
//	cout << "--����������� ������--" << endl;
	sz = new float;
}

Figure::Figure(float sz1) {
//	cout << endl << "---����������� ������ (float)---" << endl;
	sz = new float;
	*sz = sz1;
}

void Figure::Show() {
//	cout << " ������ = " << *sz << endl;
}

double Figure::CalcArea() {
//	cout << " ������� ������ - ";
	return *sz * *sz;
}

Figure::~Figure() {
//	cout << endl << "---���������� ������" << endl;
	delete sz;
}


class Circle :public Figure {//----------------------------����
	int *r;
public:
	Circle();
	Circle(int);
//	int Get_r();
	virtual ~Circle();
	virtual void Show();
	virtual double CalcArea();
};

Circle::Circle() {
//	cout << "---����������� �����" << endl;
	r = new int;
}

Circle::Circle(int r1) {
//	cout << "---����������� ����� (int)" << endl;
	r = new int;
	*r = r1;
}

void Circle::Show() {
	cout << "   ������ ����� - " << *r << endl;
}

double Circle::CalcArea() {
	cout << "   ������� ����� - " << acos(-1) * *r * *r << endl;
	return acos(-1) * *r * *r;
}

Circle::~Circle() {
//	cout << endl << "~���������� �����" << endl;
	delete r;
}


class Rectangle : public Figure {//----------------------------�������������
	int *a, *b;
public:
	Rectangle();
	Rectangle(int, int);
//	int Get_a();
//	int Get_b();
	virtual ~Rectangle();
	virtual double CalcArea();
	virtual void Show();
};

Rectangle::Rectangle(){
//	cout << "-----����������� ��������������" << endl;
	a = new int;
	b = new int;
};

Rectangle::Rectangle(int a1, int b1) {
//	cout << "-----����������� �������������� (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	if (a==b)cout << "������� �������������� ����� => ��� �������!" << endl;
};

void Rectangle::Show() {
	cout << "     ������ �������������� - ( " << *a << " * " << *b << " )" << endl;
}

double Rectangle::CalcArea() {
	cout << "     ������� �������������� - " << *a * *b << endl;
	return *a * *b;
}

Rectangle::~Rectangle() {
//	cout << endl << "~~���������� ��������������" << endl;
	delete a; delete b;
};


class Square : public Figure {//----------------------------�������
	int *a;
public:
	Square();
	Square(int);
	virtual ~Square();
	virtual void Show();
	virtual double CalcArea();
};

Square::Square() {
//	cout << "-------����������� ��������" << endl;
	a = new int;
}

Square::Square(int a1) {
//	cout << "-------����������� ��������(int)" << endl;
	a = new int;
	*a = a1;
}

void Square::Show() {
	cout << "       ������ �������� - (" << *a << " * " << *a << " )" << endl;;
}

double Square::CalcArea() {
	cout << "       ������� �������� - " << *a * *a << endl;
	return *a * *a;
}

Square::~Square() {
//	cout << endl << "~~~���������� ��������" << endl;
	delete a;
}



class Cylinder : public Figure {//----------------------------�������
	int *a, *b, *h;
public:
	Cylinder();
	Cylinder(int, int, int);
	virtual~Cylinder();
	virtual void Show();
	virtual double CalcArea();
};
Cylinder::Cylinder() {
	a = new int;
	b = new int;
	h = new int;
}

Cylinder::Cylinder(int a1, int b1, int h1) {
	a = new int;
	*a = a1;
	b = new int;
	*b = b1;
	h = new int;
	*h = h1;
}

void Cylinder::Show() {
	cout << "       ������ �������� - (" << *a << " * " << *b << " * " << *h << ") " << endl;
}

double Cylinder::CalcArea() {
	cout ;
	if (*a != 0 && *b != 0) {
		cout << "      ��������� �������� - �������������!" << endl << "     ������� �������� - " << *a * *b * *h;
	}
	else if (*b == 0) {
		cout << "      ��������� �������� - �������! " << endl << "     ������� �������� - " << *a * *a * *h;
	}
	else if (*a == 0) {
		cout << "      ��������� �������� - ����! " << endl << "     ������� �������� - " << acos(-1) * *b * *b * *h;
	}
	else { cout << "!!!�������� ������ �������!!!" << endl; return 0; };
}

Cylinder::~Cylinder() {
	delete a, b, h;
}