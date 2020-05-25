#include <iostream>
#include <locale>

using namespace std;


int kol(int a, int b, int* ms, int n, int i)
{
	if (n == i) 
		return 0;
	if (a <= ms[i] && ms[i] <= b) 
	return kol(a, b, ms, n, i + 1) + 1;
	else return kol(a, b, ms, n, i + 1);		
}

int per(int n)
{
	if (n == 0) return 0;
	else{
		per(n >> 1);
		cout << n % 2;
	}
}


int F(int n), G(int n);

int F(int n){
	if (n == 1) return 1;
	else return F(n - 1) - 3 * G(n - 1);
}

int G(int n){
	if (n == 1) return -1;
	else return F(n - 1) + 2 * G(n - 1);
}
	
int main() {
	setlocale(LC_ALL, "Russian");


	cout << "------Задание 1------" << endl;

	cout << "Рекурсивная функция, которая находит количество элементов массива,"<< endl;
	cout << "принадлежащих заданному отрезку. " << endl;
	cout << "Введите размер массива - "; int n; cin >> n;
	int a, b; 
	int* ms = new int[n];
	cout << "Введите элементы массива :" << endl;
	for (int i = 0; i < n; i++) {
		cin >> ms[i];
	}
	cout << "Введите грапницы отрезка a и b:" << endl; cin >> a >> b;
	int n1 = kol(a, b, ms, n, 0);
	cout << "Число элементов, принадлежащих отрезку - " << n1;
	cout << endl << endl;

	cout << "------Задание 2------" << endl;

	cout << "Написать процедуру перевода числа из десятичной системы счисления в двоичную." << endl;
	cout << "Введите число в делятичной СИ: "; int n2; cin >> n2;
	cout << "Число в двоичной системе - ";
	per(n2);
	cout << endl << endl;

	cout <<"------Задание 3------"<< endl;
	cout << "Aлгоритм вычисления значений функций F(n) и G(n), где n — натуральное число, задан следующими соотношениями: " << endl;
	cout << "F(1)=1, G(1)=-1, " << endl;
	cout << "F(n) = F(n – 1) - 3 * G(n – 1)" << endl;
	cout << "G(n) = F(n – 1) + 2 * G(n – 1),   при n >= 2 " << endl;
	cout << "Вычислите первые 10 значений F(i) и G(i), i=1,2,…,10. " << endl;

	cout << endl << "Значения F(n): ";
	for (int i = 1; i <= 10; i++) cout << F(i) << ' ';
	cout << endl << "Значения G(n): ";
	for (int i = 1; i <= 10; i++) cout << G(i) << ' ';


	return 0;
}