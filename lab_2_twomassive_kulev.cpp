#include <fstream>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <random>

#include <string.h>
#include <locale.h>
using namespace std;


void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void max(int** mas, int n, int m, int& i_n, int& i_m) {
	int mx = mas[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] > mx) {
				mx = mas[i][j]; i_n = i; i_m = j;
			}
				
		}
	}
}

void min(int** mas, int n, int m, int& i_n, int& i_m) {
	int mn = mas[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] < mn) {
				mn = mas[i][j]; i_n = i; i_m = j;
			}

		}
	}
}

void output(int** mas, int n, int m) {//функция вывода массива
	int a = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(a); cout << mas[i][j] << ' '; 
		}cout << endl;
	}
}



int main() {
	setlocale(LC_ALL, "Russian");

	default_random_engine generate(random_device{}());

	int a, b, n, n1 = 0;
	
	cout << "-----1 задание варианта-----" << endl;

	do {
		cout << "Квадратная матрица, заполненная случайными числами из интервала [a,b]" << endl;
		cout << "Введите размер интервала(a,b): "; cin >> a; cin >> b;
	} while (a >= b);

	uniform_int_distribution<int> distribut(a, b);

	cout << "Введите размер двумерного массива: "; cin >> n; n1 = n;
	if (n <= 0 && n1 <= 0) {
		cout << "Размер массива не может быть равен нулю" << endl; return 0;
	}
	int** mas;
		mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[n1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n1; j++) mas[i][j] = distribut(generate);
	}

	cout << "Сформированный массив: " << endl;
	output(mas, n, n1);
	
	int n_max=0, n1_max=0, n_min=0, n1_min=0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n1; j++) {
			if (i + j + 1 > n && i > j) max(mas, n, n1, n_max, n1_max); 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n1; j++) {
			if (i + j + 1 < n && i > j) min(mas, n, n1, n_min, n1_min); 
		}
	}
	
	cout << "Минимальный положительный элемент: " << mas[n_max][n1_max] << endl;
	cout << "Максимальный отрицательный элемент: " << mas[n_min][n1_min] << endl;
	
	swap(mas[n_max][n1_max], mas[n_min][n1_min]);

	cout << "Изменённый массив: " << endl;
	output(mas, n, n1);


//-------------------------------------------------


	cout << "-----2 задание варианта-----" << endl;
	cout << "  Даны матрицы А, С и векторы В, D с элементами, считанными из файла. " << endl;
	cout << "Вычислить выражение: 2 * A(n,n) + B(n) * D(m) * C(m,n) " << endl;
	cout << "где n, m - натуральные числа. " << endl;

	ifstream NumFile("lab.txt");
	int q=0, N;
	if (!NumFile) {//если фаил не находится в папке с программным кодом
		cout << "файл не найден" << endl;
		return 0;
	}

	cout << "Элементы файла:" << endl;
	while (NumFile >> N) {
		cout << N << ' ';//вывод элементов из файла на экран
		if (N != 0) q++;//добавлять числа на экран до их окончания
		if (q == 0) {//если чисев в файле нет
			cout << "Файл пуст или не имеет ненулевых чисел" << endl;
			return 0;
		}
	}
	cout << endl;

	NumFile.clear();
	NumFile.seekg(0);
	n = 0; n1 = 0;
	int  m, m1, n2, n3;

	cout << "Введите размер массива А:"; cin >> n >> m; if (n == 0 || m == 0) { cout << "Размер массива не может быть равен нулю!" << endl; return 0; }
	cout << "Введите размер массива C:"; cin >> n1 >> m1; if (n1 == 0 || m1 == 0) { cout << "Размер массива не может быть равен нулю!" << endl; return 0; }
	cout << "Введите размер вектора B:"; cin >> n2; if (n2 == 0) { cout << "Размер вектора не может быть равен нулю!" << endl; return 0; }
	cout << "Введите размер вектора D:"; cin >> n3; if (n3 == 0) { cout << "Размер вектора не может быть равен нулю!" << endl; return 0; }

	int** A; 
	A = new int*[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			NumFile >>A[i][j];//вводим число в массив
		}
	}
	int** C;
	C = new int* [n1];
	for (int i = 0; i < n1; i++)
		C[i] = new int[m1];

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			NumFile >> C[i][j];//вводим число в массив
		}
	}

	vector <int> B(n2);
	for (int i = 0; i < n2; i++)
			NumFile >> B.at(i) ;//вводим число в вектор

	vector <int> D(n3);
	for (int i = 0; i < n3; i++)
		NumFile >> D.at(i);//вводим число в вектор
	



	output(A, n, m); 
	cout << endl;

	output(C, n1, m1);
	cout << endl;

	for (int i = 0; i < n2; i++)
		cout << B[i] << ' ';
	cout << endl;

	for (int i = 0; i < n3; i++)
		cout << D[i] << ' ';
	cout << endl;

	int r1, r2, R;
	cout << "Введите два натуральных числа n, m:" << endl;
	cin >> r1 >> r2;
	if (r1 != 0 || r2 != 0) {
		r1--; r2--;
		R = 2 * A[r1][r1] + B[r1] * D[r2] * C[r2][r1];
		cout << "Выражение R = " << R << endl;
	}
	else 
	cout << "Выражение R = 0" << endl;

	return 0;
}
