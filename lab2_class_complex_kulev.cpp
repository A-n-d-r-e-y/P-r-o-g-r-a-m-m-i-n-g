#include <iostream>
#include <stdlib.h>
#include "cimp_complex_28.09.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	SimpComplex C1, C2, C3;
	cout << "-----Класс 'Комплексные числа и операции над ними'-----" << endl;
	cout << "    Введите элементы уравнений (например a+b)" << endl;
	cout << "   Первое уравнение f - "; cin >> C1;
	cout << "  Второе уравнение g - "; cin >> C2;
	cout << "     Введёные уравнения:  (" << C1 << ")	(" << C2 <<")"<< endl;
	
	/*C1.set_real(1);//Заданные значения
	C1.set_imag(3);
	C2.set_real(2);
	C2.set_imag(4);
*/
	C3 = C1 + C2; 
	cout << "  Cумма действительных и мнимых комплексных чисел F1 = " << C3 << endl;
	
	
	C3 = C1 * C2;
	cout << "   Произведение действительных и мнимых комплексных чисел F2 = " << C3 << endl;
	
	
	C3 = C1 % C2;
	cout << "    Произведение действительных и мнимых комплексных чисел на комплексное число F3 = " << C3 << endl;
	
	cout << "     Модули  f = " << C1.fabs(C1) << " и  g = " << C2.fabs(C2) << endl;
	cout << "      Решение неравенства между модулями уравнений: ";
	if (C1.fabs(C1) > C2.fabs(C2)) cout << "|f(x)| > |g(x)|!" << endl;
	else if(C1.fabs(C1) < C2.fabs(C2)) cout << "|f(x)| < |g(x)|!" << endl;
	else if (C1.fabs(C1) == C2.fabs(C2)) cout << "|f(x)| = |g(x)|!" << endl;

	system("pause");
	return 0;
}