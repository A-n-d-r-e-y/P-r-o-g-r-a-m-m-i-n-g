#include <fstream>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <random>

#include <locale.h>
#include <string.h>
using namespace std;


void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	setlocale(LC_ALL, "Russian");


	//-----1 задание-----

	cout << "-----1 задание-----" << endl;
	cout << "Вектор из упорядоченных " << endl;
	cout << "по возрастанию ненулевых чисел, " << endl;
	cout << "считанных из файла. " << endl;

	ifstream NumFile("lab.txt");
	int m = 0, N;
	if (!NumFile) {//если фаил не находится в папке с программным кодом
		cout << "файл не найден" << endl;
		return 0;
	}

	cout << "Изначальные значения" << endl;
	while (NumFile >> N) {
		cout << N << ' ';//вывод элементов из файла на экран
		if (N != 0) m++;//добавлять числа на экран до их окончания
		if (m == 0) {//если чисел в файле нет
			cout << "Файл пуст или не имеет ненулевых чисел" << endl;
			return 0;
		}
	}


	NumFile.clear();
	NumFile.seekg(0);


	vector <int> vecktor(12); //ввод вектора 

	for (int i = 0; NumFile >> N; i++) {
		if (N != 0) {//если число в файле не нулевое...
			vecktor.at(i) = N;//вводим число в вектор
		}
	}


	for (int i = 0; i < m - 1; i++) { //предыдущее число
		for (int j = 0; j < m - 1; j++) { //следующее число
			if (vecktor.at(j) > vecktor.at(j + 1)) Swap(vecktor.at(j), vecktor.at(j + 1));//если предыдущее число меньше следующего меняем их местами
		}
		if (vecktor.at(i) == 0) vecktor.erase(vecktor.begin() + i); //удаление нулевого элемента
	}

	cout << endl << "\nОтсортированный по возрастанию вектор ненулевых чисел" << endl;

	for (int i = 0; i < m; i++)
		cout << vecktor[i] << ' ';
	cout << endl;
	vecktor.clear();

	//-----2 задание-----
	cout << endl;
	cout << "-----2 задание-----" << endl;

	default_random_engine generate(random_device{}());

	int a, b, n, negative = 0;

	do {

		cout << "Вектор со случайными числами из интервала [a,b]" << endl;
		cout << "Введите размер интервала(a,b): "; cin >> a; cin >> b;

	} while (a >= b); //верхняя грань не может быть меньше или равна нижней грани

	uniform_int_distribution<int> distribut(a, b);

	cout << "Введите размер вектора: "; cin >> n;
	if (n <= 0) {
		cout << "Размер мвектора не может быть равен нулю" << endl; return 0;
	}
	vector <int> Vector_2(n);
	cout << "Сформированный вектор: " << endl;

	for (int i = 0; i < n; i++) {
		Vector_2.at(i) = distribut(generate); //ввод элементов вектора
		cout << Vector_2.at(i) << ' ';
	}
	int k;
	cout << endl << "Сжать вектор, удалив из него все элементы, которые больше  заданного числа k - "; cin >> k;
	for (int i = 0; i < n; i++) {
		if (Vector_2.at(i) > k)
			Vector_2.at(i) = 0; //если число больше k то зануляем его
	}

	for (int i = 0; i < n; i++) { //предыдущее число 
			for (int j = n - 1; j > i; j--) { //следующее число
				if (Vector_2.at(j) != 0)  Swap(Vector_2.at(i), Vector_2.at(j));//если предыдущее число меньше следующего меняем их местами
			}
		if (Vector_2.at(i) == 0) negative++; //счётчик нулевых чисел
	}

	int n1 = n - negative;//новая переменная нового размера вектора
	Vector_2.resize(n1);//новый размер вектора

	cout << "Конечный результат: \n";
	for (int i = 0; i < n1; i++) {
		cout << Vector_2.at(i) << ' ';
	}


return 0;
}