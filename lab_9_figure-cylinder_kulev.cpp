#include "stdafx.h"
#include <iostream>
#include "Head_figure_cylinder.h"
#include <locale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "   Программа реализации обобщенного алгоритма для работы с объектами иерархии классов Фигур." << endl;
	//int r = 3, a = 4, b = 5, c = 6, hc = 7;//значения сторон круга, прямоугольника, квадрата и цилиндра по умолчанию
	int r, a, b, c, hc, choise;
	
	cout << " Введите радиус круга (r): "; cin >> r;
	if (r < 0) { 
		cout << "!!!Радиус КРУГА не может быть ОТРИЦАТЕЛЬНЫМ!!!" << endl; return 0; 
	}
	
	cout << "  Введите длины сторон прямоугольника (a, b): "; cin >> a >> b;
	if (a == b)cout << "!!!Стороны ПРЯМОУГОЛЬНИКА равны => это КВАДРАТ!" << endl;
	else if (a < 0 && b < 0) {
		cout << "!!!Стороны ПРЯМОУГОЛЬНИКА не могут быть ОТРИЦАТЕЛЬНЫМИ!!!" << endl; return 0; 
	}
	
	cout << "   Введите длину сторон квадрата (c): "; cin >> c;
	if (c < 0) { 
		cout << "!!!Стороны КВАДРАТА не могут быть ОТРИЦАТЕЛЬНЫМИ!!!" << endl; return 0; 
	}
	
	cout << "    Введите высоту будущего цилиндра (hc): "; cin >> hc;
	if (hc <= 0) {
		cout << "!!!Высота не может быть ОТРИЦАТЕЛЬНАЯ или РАВНА НУЛЮ!!! " << endl; return 0;
	}

	Figure *krug = new Circle(r, hc);
	Figure *prugol = new Rectangle(a, b, hc);
	Figure *kvadr = new Square(c, hc);
	
	krug->Show();
	prugol->Show();
	kvadr->Show();

	krug->CalcArea();
	prugol->CalcArea();
	kvadr->CalcArea(); 

	cout << " Выберете фигуру для нахождения площади циллиндра"<<endl<<"  (1-КРУГ, 2-ПРЯМОУГОЛЬНИК, 3-КВАДРАТ) - "; cin >> choise;
	
	if (choise == 1) krug->CalcArea_Cylinder();
	else if (choise == 2)prugol->CalcArea_Cylinder();
	else if (choise == 3)kvadr->CalcArea_Cylinder();
	else {cout << "!!!Введено неверное число!!!" << endl; return 0;}

	delete krug;
	delete prugol;
	delete kvadr;

	return 0;
}
