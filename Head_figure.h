#include "stdafx.h"
#include <iostream>

using namespace std;

class Figure {//----------------------------êëàññ ÔÈÃÓĞÀ
	float *sz;
public:
	Figure();
	Figure(float);
	virtual ~Figure();
	virtual void Show()=0;
	virtual double CalcArea()=0;
};

Figure::Figure() {
//	cout << "--Êîíñòğóêòîğ ÔÈÃÓĞÛ--" << endl;
	sz = new float;
}

Figure::Figure(float sz1) {
//	cout << endl << "---Êîíñòğóêòîğ ÔÈÃÓĞÛ (float)---" << endl;
	sz = new float;
	*sz = sz1;
}

void Figure::Show() {
//	cout << " Ğàçìåğ = " << *sz << endl;
}

double Figure::CalcArea() {
//	cout << " Ïëîùàäü ÔÈÃÓĞÛ - ";
	return *sz * *sz;
}

Figure::~Figure() {
//	cout << endl << "---Äåñòğóêòîğ ÔÈÃÓĞÛ" << endl;
	delete sz;
}


class Circle :public Figure {//----------------------------ÊĞÓÃ
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
//	cout << "---Êîíñòğóêòîğ ÊĞÓÃÀ" << endl;
	r = new int;
}

Circle::Circle(int r1) {
//	cout << "---Êîíñòğóêòîğ ÊĞÓÃÀ (int)" << endl;
	r = new int;
	*r = r1;
}

void Circle::Show() {
	cout << "   Ğàäèóñ ÊĞÓÃÀ - " << *r << endl;
}

double Circle::CalcArea() {
	cout << "   Ïëîùàäü ÊĞÓÃÀ - " << acos(-1) * *r * *r << endl;
	return acos(-1) * *r * *r;
}

Circle::~Circle() {
//	cout << endl << "~Äåñòğóêòîğ ÊĞÓÃÀ" << endl;
	delete r;
}


class Rectangle : public Figure {//----------------------------ÏĞßÌÎÓÃÎËÜÍÈÊ
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
//	cout << "-----Êîíñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ" << endl;
	a = new int;
	b = new int;
};

Rectangle::Rectangle(int a1, int b1) {
//	cout << "-----Êîíñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	if (a==b)cout << "Ñòîğîíû ÏĞßÌÎÓÃÎËÜÍÈÊÀ ğàâíû => ıòî ÊÂÀÄĞÀÒ!" << endl;
};

void Rectangle::Show() {
	cout << "     Ğàçìåğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ - ( " << *a << " * " << *b << " )" << endl;
}

double Rectangle::CalcArea() {
	cout << "     Ïëîùàäü ÏĞßÌÎÓÃÎËÜÍÈÊÀ - " << *a * *b << endl;
	return *a * *b;
}

Rectangle::~Rectangle() {
//	cout << endl << "~~Äåñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ" << endl;
	delete a; delete b;
};


class Square : public Figure {//----------------------------ÊÂÀÄĞÀÒ
	int *a;
public:
	Square();
	Square(int);
	virtual ~Square();
	virtual void Show();
	virtual double CalcArea();
};

Square::Square() {
//	cout << "-------Êîíñòğóêòîğ ÊÂÀÄĞÀÒÀ" << endl;
	a = new int;
}

Square::Square(int a1) {
//	cout << "-------Êîíñòğóêòîğ ÊÂÀÄĞÀÒÀ(int)" << endl;
	a = new int;
	*a = a1;
}

void Square::Show() {
	cout << "       Ğàçìåğ ÊÂÀÄĞÀÒÀ - (" << *a << " * " << *a << " )" << endl;;
}

double Square::CalcArea() {
	cout << "       Ïëîùàäü ÊÂÀÄĞÀÒÀ - " << *a * *a << endl;
	return *a * *a;
}

Square::~Square() {
//	cout << endl << "~~~Äåñòğóêòîğ ÊÂÀÄĞÀÒÀ" << endl;
	delete a;
}



class Cylinder : public Figure {//----------------------------ÖÈËÈÍÄĞ
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
	cout << "       Ğàçìåğ ÖÈËÈÍÄĞÀ - (" << *a << " * " << *b << " * " << *h << ") " << endl;
}

double Cylinder::CalcArea() {
	cout ;
	if (*a != 0 && *b != 0) {
		cout << "      Îñíîâàíèå öèëèíäğà - ÏĞßÌÎÓÃÎËÜÍÈÊ!" << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << *a * *b * *h;
	}
	else if (*b == 0) {
		cout << "      Îñíîâàíèå öèëèíäğà - ÊÂÀÄĞÀÒ! " << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << *a * *a * *h;
	}
	else if (*a == 0) {
		cout << "      Îñíîâàíèå öèëèíäğà - ÊĞÓÃ! " << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << acos(-1) * *b * *b * *h;
	}
	else { cout << "!!!Çíà÷åíèÿ ñòîğîí íóëåâûå!!!" << endl; return 0; };
}

Cylinder::~Cylinder() {
	delete a, b, h;
}