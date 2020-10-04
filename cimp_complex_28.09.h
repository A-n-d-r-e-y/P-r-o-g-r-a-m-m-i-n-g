class SimpComplex {
private:
	float real = 0;
	float imag = 0;

public:
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

	void set(float r, float i) {
		real = r;
		imag = i;
	}

	float get() {
		return 0;
	}

	SimpComplex sum(SimpComplex C2) {//������ ������� ����(�3=�1.sum(�2)
		SimpComplex C1;
		C1.set_real(real + C2.get_real());
		C1.set_imag(imag + C2.get_imag());
		return C1;
	}
	SimpComplex umn(SimpComplex C2) {//������ ������� ����(�3=�1.umn(�2)
		SimpComplex C1;
		C1.set_real(real * C2.get_real());
		C1.set_imag(imag * C2.get_imag());
		return C1;
	}
	SimpComplex umnCom(SimpComplex C2) {//������ ������� ����(�3=�1.umnCom(�2)
		SimpComplex C1;
		C1.set_real(real * C2.get_imag());
		C1.set_imag(imag * C2.get_imag());
		return C1;
	}

	/*
	friend SimpComplex operator+=(SimpComplex C1, SimpComplex C2) {//������ ������� �������� (�3+=�2) � (�3+=�2)
		SimpComplex C3;
		C3.set_real(C1.get_real() + C2.get_real());
		C3.set_imag(C1.get_imag() + C2.get_imag());
		return C3;
	}
	friend SimpComplex operator*=(SimpComplex C1, SimpComplex C2) {//������ ������� ��������� (�3*=�1, �2) � (�3*=�2)
		SimpComplex C3;
		C3.set_real(C1.get_real() * C2.get_real());
		C3.set_imag(C1.get_imag() * C2.get_imag());
		return C3;
	}
	friend SimpComplex operator%=(SimpComplex C1, SimpComplex C2) {//������ ������� ��������� �� �����. ����� (�3%=�1, �2) � (�3%=�2)
		SimpComplex C3;
		C3.set_real(C1.get_real() * C2.get_imag());
		C3.set_imag(C1.get_imag() * C2.get_imag());
		return C3;
	}

	SimpComplex operator *=(int& k) {//��������� �� �����
		real = real * k;
		imag = imag * k;
		return *this;
	}
*/
};
/*
SimpComplex operator*(SimpComplex C1, int k) {
	SimpComplex C3;
	C3.set_real(C1.get_real() + k);
	C3.set_imag(C1.get_imag() + k);
	return C3;
}*/