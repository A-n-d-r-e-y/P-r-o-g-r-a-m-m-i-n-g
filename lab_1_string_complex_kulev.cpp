#include <iostream>
#include <locale>
using namespace std;

struct complex {//тело структуры
    float real, imag;
    complex operator +(complex a);
    complex operator *(complex a);
    void print();
    void set(float a, float b);
};
complex complex :: operator +(complex a) {//функция сложения
    complex x;
    x.real = real + a.real;
    x.imag = imag + a.imag;
    return x;
}
complex complex :: operator *(complex a) {//функция умножения
    complex x;
    x.real = real * a.real;
    x.imag = imag * a.imag;
    return x;
}
void complex::print() {//функция вывода на экран
    if (imag >= 0)cout << real << "+" << imag << "*i" << endl;
    else cout << real << imag << "*i" << endl;
}
void complex::set(float a, float b) {//функция ввода переменных
    cin >> a >> b;
    real = a; imag = b;
}

int main(){
    setlocale(LC_ALL, "rus");
    complex c1, c2, sum, umn;

    cout << "---Cтруктура 'Комплексное число'--- " << endl; 
    cout << "  Введите два уравнения с действительной и мнимой частями уравнения и знак между ними (+ или -)" << endl;
    cout << " Пример: a+b  c+d" << endl;   
    c1.set(0, 0); c2.set(0, 0);
    cout << "    Первое уравнение: "; c1.print();
    cout << "   Второе уравнение: "; c2.print(); 

    sum = c1 + c2; 
    umn = c1 * c2;
    cout << "  Сумма этих уравнений: "; sum.print(); 
    cout << " Произведение этих уравнений: "; umn.print(); 
    
    return 0;
}
