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

	SimpComplex sum(SimpComplex C2) {//первый вариант кода(с3=с1.sum(с2)
		SimpComplex C1;
		C1.set_real(real + C2.get_real());
		C1.set_imag(imag + C2.get_imag());
		return C1;
	}
	SimpComplex umn(SimpComplex C2) {//первый вариант кода(с3=с1.umn(с2)
		SimpComplex C1;
		C1.set_real(real * C2.get_real());
		C1.set_imag(imag * C2.get_imag());
		return C1;
	}
	SimpComplex umnCom(SimpComplex C2) {//первый вариант кода(с3=с1.umnCom(с2)
		SimpComplex C1;
		C1.set_real(real * C2.get_imag());
		C1.set_imag(imag * C2.get_imag());
		return C1;
	}

	/*
	friend SimpComplex operator+=(SimpComplex C1, SimpComplex C2) {//второй вариант сложения (с3+=с2) и (с3+=с2)
		SimpComplex C3;
		C3.set_real(C1.get_real() + C2.get_real());
		C3.set_imag(C1.get_imag() + C2.get_imag());
		return C3;
	}
	friend SimpComplex operator*=(SimpComplex C1, SimpComplex C2) {//второй вариант умножения (с3*=с1, с2) и (с3*=с2)
		SimpComplex C3;
		C3.set_real(C1.get_real() * C2.get_real());
		C3.set_imag(C1.get_imag() * C2.get_imag());
		return C3;
	}
	friend SimpComplex operator%=(SimpComplex C1, SimpComplex C2) {//второй вариант умножения на компл. число (с3%=с1, с2) и (с3%=с2)
		SimpComplex C3;
		C3.set_real(C1.get_real() * C2.get_imag());
		C3.set_imag(C1.get_imag() * C2.get_imag());
		return C3;
	}

	SimpComplex operator *=(int& k) {//умножение на число
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