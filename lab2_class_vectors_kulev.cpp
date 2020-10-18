#include <iostream>
#include <stdlib.h>
#include <vector>
#include "head_vectors.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n=0, k=0;
	cout << "---- Класс 'Векторы и операции над ними!' ----" << endl;
	cout << " Введите размер вектора: - "; while (n == 0) cin >> n;
	
	cout << "  Введите два вектора! Не ошибитесь с количеством элементов!" << endl;
	cout << "   Например: 1 2 3 4 5... и 6 7 8 9 10..." << endl;
	ClassVectors v1(n), v2(n);
	cin >> v1 >> v2;
	cout << "     Вектор 1: " << v1 << endl << "     Вектор 2: " << v2 << endl;

	cout << "      Сумма векторов: " << v1 + v2 << endl;
	
	cout << "       Скалярное произведение: " << v1.sklr(v2) << endl;
	
	cout << "      Введите число для произведения вектора на него - "; cin >> n;
	cout << "     Выберете вектор (1 или 2) - "; cin >> k;
	if(k==1) cout << "    Произведение вектора на число: " << v1 * n << endl;
	else if(k==2) cout << "   Произведение вектора на число: " << v2 * n << endl;
	else cout << "   Введено неверное число!" << endl;
	
	cout << "  Угол между векторами: " << v1.angl(v2) << endl;

	if (v1.LengthVector() > v2.LengthVector()) cout << " Вектор v1 > v2!" << endl;
	else if (v1.LengthVector() < v2.LengthVector()) cout << " Вектор v1 < v2!" << endl;
	else if (v1.LengthVector() == v2.LengthVector()) cout << " Вектор v1 = v2!" << endl;

	return 0;
}
