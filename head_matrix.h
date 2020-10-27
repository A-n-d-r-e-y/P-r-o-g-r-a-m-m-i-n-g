#include "iostream"
#include <cmath>
#include <clocale>
using namespace std;

class ClassMatrix;

class ClassVectors {
	friend ClassMatrix;
private:
	double sz, * el;
public:
	ClassVectors(int Nsz = 2) {
		sz = Nsz;
		el = new double[sz];
	}
	ClassVectors(const ClassVectors& t) {
		sz = t.sz; el = t.el;
	}

	void set_sz(float x) {
		sz = x;
	}
	int get_sz() {
		return sz;
	}

	void set_el(double* y) {
		el = y;
	}
	double* get_el() {
		return el;
	}

	void Arrsz(int Nsz1) {
		double* arr = new double[Nsz1];
		for (int i = 0; i < Nsz1; i++) arr[i] = el[i];//
		sz = Nsz1;
		delete[]el;
		el = arr;
	}
	~ClassVectors() {};//деструктор

	friend istream& operator>> (istream& in, ClassVectors& t) {//операция ввода перегрузки
		for (int i = 0; i < t.sz; i++)
			in >> t.el[i];
		return in;
	}
	friend ostream& operator<< (ostream& out, const ClassVectors& t) {//операции вывода перегрузки
		for (int i = 0; i < t.sz; i++) out << t.el[i] << " ";
		return out;
	}

	double& operator[](int index) {
		if (sz <= index || index < 0) {
			cout << "Ошибка, оно не работает с таким индексом!" << endl; exit(0);
		}
		else return el[index];
	}
};

class ClassMatrix {
private:
	double Mx, My;
	double** xy;
public:
	ClassMatrix(const ClassMatrix& ClassMatrix) : xy(ClassMatrix.xy), Mx(ClassMatrix.Mx), My(ClassMatrix.My) {}

	void Arrsz(double Nsz1, double Nsz2) {
		double** arr = new double* [Nsz1];
		for (int i = 0; i < Nsz1; i++) arr[i] = new double[Nsz2];
		for (int i = 0; (i < Mx) & (i < Nsz1); i++)
			for (int j = 0; (j < My) & (j < Nsz2); j++)
				arr[i][j] = xy[i][j];
		for (int i = 0; i < Mx; i++) delete[] xy[i];
		delete[]xy;//

		Mx = Nsz1; My = Nsz2; xy = arr;
	}

	void sz_set(int Nsz1, int Nsz2) {
		xy = new double* [Nsz1];
		for (int i = 0; i < Nsz1; i++)
			xy[i] = new double[Nsz2];
		Mx = Nsz1; My = Nsz2;
	}

	ClassMatrix(int NMx = 3, int NMy = 3) {
		Mx = abs(NMx);
		My = abs(NMy);
		xy = 0;
		if (Mx != 0 && My != 0) {
			xy = new double* [Mx];
			for (int i = 0; i < Mx; i++)
				xy[i] = new double[My];
			for (int i = 0; i < Mx; i++) {
				for (int j = 0; j < My; j++)
					xy[i][j] = 0;
			}
		}
	}
	~ClassMatrix() {}//Деструктор

	friend ClassMatrix operator+(const ClassMatrix& m1, const ClassMatrix& m2) {//сложение
		ClassMatrix matric;
		matric.Arrsz(m1.Mx, m1.My);
		for (int i = 0; i < matric.Mx; i++)
			for (int j = 0; j < matric.My; j++) matric.xy[i][j] = m1.xy[i][j] + m2.xy[i][j];
		return matric;
	}

	friend ClassMatrix operator*(const ClassMatrix& m1, const ClassMatrix& m2) {//умножение
		ClassMatrix matric;
		if (m1.Mx != m2.Mx || m1.My != m2.My) { cout << "Размерности векторов ДОЛЖНЫ СОВПАДАТЬ" << endl; exit(0); }
		else {
			ClassMatrix Arrsz(m1.Mx, m1.My);
			for (int i = 0; i < matric.Mx; i++)
				for (int j = 0; j < matric.My; j++) matric.xy[i][j] = m1.xy[i][j] * m2.xy[i][j];
		}
		return matric;
	}

	friend ClassMatrix operator*(const ClassMatrix& m1, int n) {//умножение на число
		ClassMatrix matric;
		matric.Arrsz(m1.Mx, m1.My);
		for (int i = 0; i < matric.Mx; i++)
			for (int j = 0; j < matric.My; j++) matric.xy[i][j] = m1.xy[i][j] * n;
		return matric;
	}

	friend ClassVectors operator*(const ClassMatrix& m1, ClassVectors& v1) {//умножение на вектор
		ClassVectors vector(v1.get_sz());
		if (m1.Mx != vector.get_sz() || m1.My != vector.get_sz()) { cout << "Размеры несопоставимы!" << endl; exit(0); }
		else {
			for (int i = 0; i < vector.get_sz(); i++)
				for (int j = 0; j < vector.get_sz(); j++) m1.xy[j][i] = m1.xy[j][i] * v1[i];
		}
		for (int i = 0; i < v1.get_sz(); i++) {
			int sum = 0;
			for (int j = 0; j < v1.get_sz(); j++)
				sum += m1.xy[i][j];
			vector[i] = sum;
		}
		return vector;
	}

	friend istream& operator>> (istream& in, ClassMatrix& matric) {//операция ввода перегрузки
		for (int i = 0; i < matric.Mx; i++)
			for (int j = 0; j < matric.My; j++) in >> matric.xy[i][j];
		return in;
	}
	friend ostream& operator<< (ostream& out, const ClassMatrix& matric) {//операции вывода перегрузки
		for (int i = 0; i < matric.Mx; i++) {
			for (int j = 0; j < matric.My; j++) out << matric.xy[i][j] << " ";
			out << endl;
		}
		return out;
	}
};