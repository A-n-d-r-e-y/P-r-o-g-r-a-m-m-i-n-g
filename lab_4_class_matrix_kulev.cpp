#include <iostream>
#include <stdlib.h>
#include <vector>
#include "head_matrix.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ClassMatrix m1, m2;
	int i, j, m;

	cout << "---- Класс 'Матрицы и операции над ними!' ----" << endl;
	cout << " Введите размер матриц n х n: - "; cin >> i;
	m1.sz_set(i, i);
	m2.sz_set(i, i);

	cout << "  Введите первую матрицу! Не ошибитесь с количеством элементов!" << endl;
	cout << "   Например: 1 2 3       5 6 7 " << endl << "             3 4 5   и   7 8 9" << endl << "             ...         ..." << endl;
	cin >> m1;
	cout << "    Введите вторую матрицу! Не ошибитесь с количеством элементов!" << endl;
	cin >> m2;

	cout << "   Матрица 1: " << endl << m1 << "  Матрица 2: " << endl << m2 << endl;
	cout << "    Сумма матриц: " << endl << m1 + m2;
	
	cout << endl << "     Произведение матриц: " << endl << m1 * m2;
	cout << endl << "      Введите число для произведения матрицы на него - "; cin >> m;
	cout << endl << "     Произведение матрицы на число: " << endl << m1 * m;
	
	cout << "    Введите размер вектора j: - " << endl; cin >> j;
	cout << "   Введите вектор!" << endl;
	cout << "  Например: 1 2" << endl;
	ClassVectors v0(j); cin >> v0;
	cout << "   Вектор: " << v0 << endl;
	cout << "    Произведение матрицы на вектор: " << endl << m1 * v0 << endl;

	return 0;
}