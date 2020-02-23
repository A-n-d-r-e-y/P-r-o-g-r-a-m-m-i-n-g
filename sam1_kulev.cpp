

#include <fstream>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <random>

#include <locale.h>
#include <string.h>
using namespace std;

void Swap(int& a, int& b) { 
	int c = a;
	a = b;
	b = c;
}

void output(int* a, int n){//функция вывода массива
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

int main() {

	setlocale(LC_ALL, "Russian");

	//----------1 задание----------

	cout << "-----1 задание-----" << endl;
	cout << "Динамический одномерный массив из " << endl;
	cout << "упорядоченных по возрастанию ненулевых чисел, " << endl;
	cout << "считанных из файла. " << endl;


	ifstream NumFile("lab.txt");
	int m = 0, N;
	if (!NumFile) {//если фаил не находится в папке с программным кодом
		cout << "файл не найден" << endl;
		return 0;
	}

	cout << "Изначальные значения" << endl;
	while (NumFile >> N){
		cout << N << endl;//вывод элементов из файла на экран
		if (N != 0) m++;//добавлять числа на экран до их окончания
		if (m == 0){//если чисев в файле нет
			cout << "Файл пуст или не имеет ненулевых чисел" << endl;
			return 0;
		}
	}

	NumFile.clear();
	NumFile.seekg(0);

	int* c = new int[m];
	for (int i = 0; NumFile >> N;){
		if (N != 0){//если число в файле не нулевое...
			c[i] = N;//вводим число в массив
			i++;
		}
	}

	for (int i = 0; i < m - 1; i++){
		for (int j = 0; j < m - 1; j++){
			if (c[j] > c[j + 1]) Swap(c[j], c[j + 1]);//если предыдущее число меньше следующего меняем их местами
		}
	}

	cout << "Отсортированный по возрастанию массив ненулевых чисел"<<endl;
	for (int i = 0; i < m; i++)
		cout << c[i] << endl;

	delete[]c;//удаление массива
	NumFile.close();



	cout << endl;
	cout << "-----2 задание-----" << endl;



	default_random_engine generate(random_device{}());

	int a, b, n, negative = 0;

	do {

		cout << "Динамический массив со случайными числами из интервала [a,b]" << endl;
		cout << "Введите размер интервала(a,b): "; cin >> a; cin >> b;

	} while (a >= b);

	uniform_int_distribution<int> distribut(a, b);

	cout << "Введите размер массива: "; cin >> n;
		if (n <= 0) {
			cout << "Размер массива не может быть равен нулю" << endl; return 0;
		}
	int* Mas = new int[n]; //ввод массива

	cout << "Сформированный массив: "<<endl;

	for (int i = 0; i < n; i++) {

		Mas[i] = distribut(generate); //ввод элементов массива

		cout << Mas[i] << endl;

		if (Mas[i] == 0) negative++; //если число равно 0 добавляем счётчик нулевых чисел

	}
	int k;
	cout << endl << "Сжать массив, удалив из него все элементы, которые больше  заданного числа k - "; cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (Mas[i] > k) 
		{
			Mas[i] = 0; negative++;
		}//проверка элемента на значение к к и приравнивание его к нулю если меньше
	}

	for (int i = 0; i < n; i++) if (Mas[i] == 0) for (int j = n - 1; j > i; j--) if (Mas[j] != 0) Swap(Mas[i], Mas[j]); //циклы замены места нулевых и ненулевых чисел и сдвиг нулей вправо

	negative = n - negative; //замена размера счётчика нулевых чисел на новый размер массива без нулей

	Mas = (int*)realloc(Mas, negative * sizeof(int)); //сжатие массива - изменение размера и удаление нулей

	cout << "Конечный результат: \n";

	for (int i = 0; i < negative; i++) {

		cout << Mas[i] << endl;

	}

	delete[]Mas;

	return 0;

}