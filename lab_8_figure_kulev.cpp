#include "stdafx.h"
#include <iostream>
#include "Head_figure.h"
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	cout << "   Программа реализации обобщенного алгоритма для работы с объектами иерархии классов Фигур." << endl;
	//int r = 5, a = 4, b = 2, c = 7, ac = 10, bc = 0, hc = 3;//значения сторон круга, прямоугольника, квадрата и цилиндра по умолчанию
	int r, a, b, c, ac, bc, hc;
	cout << "Введите радиус круга (r): "; cin >> r;
	cout << "Введите длины сторон прямоугольника (a, b): "; cin >> a >> b;
	cout << "Введите длину сторон квадрата (c): "; cin >> c;
	

	Figure *krug = new Circle(r);
		if (r < 0) { cout << "!!!Радиус КРУГА не может быть ОТРИЦАТЕЛЬНЫМ!!!" << endl; return 0; }
	Figure *prugol = new Rectangle(a, b);
		if (a==b)cout << "!!!Стороны ПРЯМОУГОЛЬНИКА равны => это КВАДРАТ!" << endl;
		else if(a<0 &&  b<0) { cout << "!!!Стороны ПРЯМОУГОЛЬНИКА не могут быть ОТРИЦАТЕЛЬНЫМИ!!!" << endl; return 0; }
	Figure *kvadr = new Square(c);
		if (c<0) { cout << "!!!Стороны КВАДРАТА не могут быть ОТРИЦАТЕЛЬНЫМИ!!!" << endl; return 0; }
	

	krug->Show();
	prugol->Show();
	kvadr->Show();

	krug->CalcArea();
	prugol->CalcArea();
	kvadr->CalcArea();

	delete krug;
	delete prugol;
	delete kvadr;
	
	cout << endl << "     Функция нахождения площади цилиндра из произведения площади произвольной плоской фигуры и высоты! " << endl;
	cout << "Введите высоту цилиндра hc: "; cin >> hc;
	cout << "В зависимости от введённых значений, основание цилиндра будет: " << endl;
	cout << "		a)КВАДРАТ - если bc = 0; " << endl << "		b) КРУГ - если ac = 0; " << endl << "		c) ПРЯМОУГОЛЬНИК - если ac != 0, bc != 0." << endl; 
	cout << "ac: "; cin >> ac; cout << "bc: "; cin >> bc;
	
	Figure *celindr = new Cylinder(ac, bc, hc);
	celindr->Show();
	celindr->CalcArea();

	delete celindr;

    return 0;
}

