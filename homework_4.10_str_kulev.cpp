#include <iostream>
#include <stdlib.h>
#include "cimp_complex_28.09.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	SimpComplex C1, C2, C3;
	C1.set_real(1);
	C1.set_imag(3);
	C2.set_real(2);
	C2.set_imag(4);
	
	C3 = C1.sum(C2);
	cout << " Cумма действительных и мнимых комплексных чисел f(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	/*C3 += (C1, C2);
	cout << " Cумма действительных и мнимых комплексных чисел f(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	C3 += C2;
	cout << " Cумма действительных и мнимых комплексных чисел f(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	*/
	C3 = C1.umn(C2);
	cout << "  Произведение действительных и мнимых комплексных чисел g(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	/*C3 *= (C1, C2);
	cout << "  Произведение действительных и мнимых комплексных чисел g(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	C3 *= C2;
	cout << "  Произведение действительных и мнимых комплексных чисел g(x) = " << C3.get_real() << " + " << C3.get_imag() << "*i" << endl;
	*/
	C3 = C1.umnCom(C2);
	cout << "   Произведение действительных и мнимых комплексных чисел на комплексное число h(x) = " << C3.get_real() << "*i + " << C3.get_imag() << endl;
	/*C3 %= (C1, C2);
	cout << "   Произведение действительных и мнимых комплексных чисел на комплексное число h(x) = " << C3.get_real() << "*i + " << C3.get_imag() << endl;
	C3 %= C2;
	cout << "   Произведение действительных и мнимых комплексных чисел на комплексное число h(x) = " << C3.get_real() << "*i + " << C3.get_imag() << endl;
	
	int k; cout << "  Введите число для умножения уравнения на число - "; cin >> k;
	int i; cout << "  Введите уравнение для функции (1 или 2) - "; cin >> i;
	
	if (i == 1){C1 *= k;
		cout << " Произведение числа на уравнение с комплексным чисом q(x) = " << C1.get_real() << " + " << C1.get_imag() << "*i" << endl;
	}
	else if (i == 2) {C2 *= k;
		cout << " Произведение числа на уравнение с комплексным чисом q(x) = " << C2.get_real() << " + " << C2.get_imag() << "*i" << endl;
	}
	else if (i != 1 && i != 2)cout << "		ОШИБКА: ВВЕДЕНО НЕПРАВИЛЬНОЕ ЧИСЛО!!! ";
*/
	system("pause");
	return 0;
}