#include "iostream"
#include <cmath>
#include <clocale>
using namespace std;

class SimpComplex {
	float real, imag;
	public:
		SimpComplex(float a = 0, float b = 0) {
			real = a; imag = b;
		}
	void set_real(float x) {
		real = x;
	}
	float get_real() {
		return real;
	}

	void set_imag(float x) {
		imag = x;
	}
	float get_imag() {
		return imag;
	}

	friend ostream& operator<< (ostream &out, const SimpComplex &n);//�������� ������ ����������
	friend istream& operator>> (istream &in, SimpComplex &n);//�������� ����� ����������
	friend SimpComplex operator+(const SimpComplex &C1, const SimpComplex &C2) {//�������� 
		SimpComplex C3 = SimpComplex(C1.real + C2.real, C1.imag + C2.imag);
		return C3;
	}
	friend SimpComplex operator*(const SimpComplex &C1, const SimpComplex &C2) {//��������� 
		SimpComplex C3 = SimpComplex(C1.real * C2.real, C1.imag * C2.imag);
		return C3;
	}
	friend SimpComplex operator%(const SimpComplex& C1, const SimpComplex& C2) {//��������� �� �����. ����� 
		SimpComplex C3 = SimpComplex(C1.real * C2.imag, C1.imag * C2.imag);
		return C3;
	}

	float fabs(const SimpComplex& n){//������ ������������ �����
		float i;
		i = sqrt(real * real + imag * imag);
		return i;
	}
	SimpComplex operator<(int n){//��������� ���������
		SimpComplex C1;
		if ((this->real < n) && (this->imag < n)) {
			return C1;
		}
		return SimpComplex();
	}
	
	~SimpComplex(){}//����������
};
	ostream& operator<< (ostream& out, const SimpComplex &n) {//����� ����������
		if(n.imag>=0) out <<  n.real << "+" << n.imag << "*i";
		else out << n.real << n.imag << "*i";
		return out;
	}
	istream& operator>> (istream& in, SimpComplex &n) {//���� ����������
		in >> n.real; 
		in >> n.imag;
		return in;
	}