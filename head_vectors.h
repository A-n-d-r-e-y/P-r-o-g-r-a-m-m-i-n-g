//#include "pch.h"
#include "iostream"
#include <cmath>
#include <clocale>
using namespace std;

class ClassVectors {
	int sz;  float* el;
public:
	ClassVectors(int Nsz = 2) {
		sz = Nsz;
		el = new float[sz];
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
	~ClassVectors() {};//деструктор

	friend ClassVectors operator+(const ClassVectors& v1, const ClassVectors& v2) {//сложение
		ClassVectors vector(v1.sz);
		for (int i = 0; i < vector.sz; i++) vector.el[i] = v1.el[i] + v2.el[i];
		return vector;
	}

	friend ClassVectors operator*(const ClassVectors& v1, int a) {//умножение
		ClassVectors vector(v1.sz);
		for (int i = 0; i < vector.sz; i++) vector.el[i] = v1.el[i] * a;
		return vector;
	}

	bool operator==(ClassVectors& vector) {}

	friend istream& operator>> (istream& in, ClassVectors& t) {//операция ввода перегрузки
		for (int i = 0; i < t.sz; i++)
			in >> t.el[i];
		return in;
	}

	friend ostream& operator<< (ostream& out, const ClassVectors& t) {//операции вывода перегрузки
		for (int i = 0; i < t.sz; i++) out << t.el[i] << " ";
		return out;
	}

	float LengthVector() {
		float L = 0;
		for (int i = 0; i < sz - 1; i++)
			L += abs(sqrt((el[i] * el[i]) + (el[i + 1] * el[i + 1])));
		return L;
	}

	float sklr(ClassVectors v) {
		return ((el[0] * v.el[0]) + (el[1] * v.el[1]));
	}

	float angl(ClassVectors v) {
		return cos(sklr(v) / (LengthVector() * v.LengthVector()));
	}

	ClassVectors operator<(int n) {//сравнение уравнений
		ClassVectors v;
		if ((this->LengthVector() < n)) return v;
		return ClassVectors();
	}
};