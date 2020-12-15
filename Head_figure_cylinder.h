#include "stdafx.h"
#include <iostream>

using namespace std;

class Figure {//----------------------------����� ������
	float *sz, *h;
public:
	Figure();
	Figure(float);
	Figure(float, float);
	virtual ~Figure();
	virtual void Show() = 0;
	virtual double CalcArea() = 0;
	virtual double CalcArea_Cylinder() = 0;
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

Figure::Figure(float sz1, float h1) {
	sz = new float; *sz = sz1;
		h = new float; *h = h1;
}

double Figure::CalcArea_Cylinder() {
	cout << Figure::CalcArea()**h; return Figure::CalcArea()**h;
}

Figure::~Figure() {
	//	cout << endl << "---���������� ������" << endl;
	delete sz;
}


class Circle :public Figure {//----------------------------����
	int *r, *h;
public:
	Circle();
	Circle(int);
	Circle(int, int);
	//	int Get_r();
	virtual ~Circle();
	virtual void Show();
	virtual double CalcArea();
	virtual double CalcArea_Cylinder();
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
/**/
Circle::Circle(int r1, int h1) {
	//	cout << "---����������� ����� (int)" << endl;
	r = new int; *r = r1;
	h = new int; *h = h1;
}
double Circle::CalcArea_Cylinder() {
	cout << "      ��������� �������� - ����!" << endl << "     ������� �������� - " << Circle::CalcArea()**h<< endl; 
	return 0;
}

Circle::~Circle() {
	//	cout << endl << "~���������� �����" << endl;
	delete r;
}


class Rectangle : public Figure {//----------------------------�������������
	int *a, *b, *h;
public:
	Rectangle();
	Rectangle(int, int);
	Rectangle(int, int, int);
	//	int Get_a();
	//	int Get_b();
	virtual ~Rectangle();
	virtual void Show();
	virtual double CalcArea();
	virtual double CalcArea_Cylinder();
};

Rectangle::Rectangle() {
	//	cout << "-----����������� ��������������" << endl;
	a = new int;
	b = new int;
};

Rectangle::Rectangle(int a1, int b1) {
	//	cout << "-----����������� �������������� (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	if (a == b)cout << "������� �������������� ����� => ��� �������!" << endl;
};

void Rectangle::Show() {
	cout << "     ������ �������������� - ( " << *a << " * " << *b << " )" << endl;
}

double Rectangle::CalcArea() {
	cout << "     ������� �������������� - " << *a * *b << endl;
	return *a * *b;
}

Rectangle::Rectangle(int a1, int b1, int h1) {
	//	cout << "-----����������� �������������� (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	h = new int; *h = h1;
	if (a == b && a == h)cout << "������� �������������� ����� ������ => ��� ���!" << endl;
};
double Rectangle::CalcArea_Cylinder() {
	cout << "      ��������� �������� - �������������!" << endl << "     ������� �������� - " << Rectangle::CalcArea()**h << endl; 
	return 0;
}

Rectangle::~Rectangle() {
	//	cout << endl << "~~���������� ��������������" << endl;
	delete a; delete b;
};


class Square : public Figure {//----------------------------�������
	int *a, *h;
public:
	Square();
	Square(int);
	Square(int, int);
	virtual ~Square();
	virtual void Show();
	virtual double CalcArea();
	virtual double CalcArea_Cylinder();
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

Square::Square(int a1, int h1) {
	a = new int; *a = a1;
	h = new int; *h = h1;
}
double Square::CalcArea_Cylinder() {
	cout << "      ��������� �������� - �������!" << endl << "     ������� �������� - " << Square::CalcArea()**h << endl; 
	return 0;
}

Square::~Square() {
	//	cout << endl << "~~~���������� ��������" << endl;
	delete a;
}