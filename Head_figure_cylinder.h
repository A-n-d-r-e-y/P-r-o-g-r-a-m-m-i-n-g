#include "stdafx.h"
#include <iostream>

using namespace std;

class Figure {//----------------------------êëàññ ÔÈÃÓĞÀ
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

Figure::Figure(float sz1, float h1) {
	sz = new float; *sz = sz1;
		h = new float; *h = h1;
}

double Figure::CalcArea_Cylinder() {
	cout << Figure::CalcArea()**h; return Figure::CalcArea()**h;
}

Figure::~Figure() {
	//	cout << endl << "---Äåñòğóêòîğ ÔÈÃÓĞÛ" << endl;
	delete sz;
}


class Circle :public Figure {//----------------------------ÊĞÓÃ
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
/**/
Circle::Circle(int r1, int h1) {
	//	cout << "---Êîíñòğóêòîğ ÊĞÓÃÀ (int)" << endl;
	r = new int; *r = r1;
	h = new int; *h = h1;
}
double Circle::CalcArea_Cylinder() {
	cout << "      Îñíîâàíèå öèëèíäğà - ÊĞÓÃ!" << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << Circle::CalcArea()**h<< endl; 
	return 0;
}

Circle::~Circle() {
	//	cout << endl << "~Äåñòğóêòîğ ÊĞÓÃÀ" << endl;
	delete r;
}


class Rectangle : public Figure {//----------------------------ÏĞßÌÎÓÃÎËÜÍÈÊ
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
	//	cout << "-----Êîíñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ" << endl;
	a = new int;
	b = new int;
};

Rectangle::Rectangle(int a1, int b1) {
	//	cout << "-----Êîíñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	if (a == b)cout << "Ñòîğîíû ÏĞßÌÎÓÃÎËÜÍÈÊÀ ğàâíû => ıòî ÊÂÀÄĞÀÒ!" << endl;
};

void Rectangle::Show() {
	cout << "     Ğàçìåğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ - ( " << *a << " * " << *b << " )" << endl;
}

double Rectangle::CalcArea() {
	cout << "     Ïëîùàäü ÏĞßÌÎÓÃÎËÜÍÈÊÀ - " << *a * *b << endl;
	return *a * *b;
}

Rectangle::Rectangle(int a1, int b1, int h1) {
	//	cout << "-----Êîíñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ (int, int)" << endl;
	a = new int; *a = a1;
	b = new int; *b = b1;
	h = new int; *h = h1;
	if (a == b && a == h)cout << "Ñòîğîíû ÏĞßÌÎÓÃÎËÜÍÈÊÀ ğàâíû âûñîòå => ıòî ÊÓÁ!" << endl;
};
double Rectangle::CalcArea_Cylinder() {
	cout << "      Îñíîâàíèå öèëèíäğà - ÏĞßÌÎÓÃÎËÜÍÈÊ!" << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << Rectangle::CalcArea()**h << endl; 
	return 0;
}

Rectangle::~Rectangle() {
	//	cout << endl << "~~Äåñòğóêòîğ ÏĞßÌÎÓÃÎËÜÍÈÊÀ" << endl;
	delete a; delete b;
};


class Square : public Figure {//----------------------------ÊÂÀÄĞÀÒ
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

Square::Square(int a1, int h1) {
	a = new int; *a = a1;
	h = new int; *h = h1;
}
double Square::CalcArea_Cylinder() {
	cout << "      Îñíîâàíèå öèëèíäğà - ÊÂÀÄĞÀÒ!" << endl << "     Ïëîùàäü ÖÈËÈÍÄĞÀ - " << Square::CalcArea()**h << endl; 
	return 0;
}

Square::~Square() {
	//	cout << endl << "~~~Äåñòğóêòîğ ÊÂÀÄĞÀÒÀ" << endl;
	delete a;
}