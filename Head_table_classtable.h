#include <iostream>
#include "cstring"
#include <cmath>

using namespace std;

class Table {
    int* sz; char* color;
public:
    Table();
    Table(int, const char*);
    Table(int);
    ~Table();
    
    void Show();
    int CalcVolume();
};

Table::Table() {
    cout << "---Table::Table()" << endl;
    sz = new int;
    color = new char[32];
}

Table::Table(int sz1, const char* color1) {
    cout << endl << "---Table::Table(int sz1, char *color1)" << endl;
    sz = new int;
    *sz = sz1;
    color = new char[strlen(color1) + 1];
    strcpy_s(color, strlen(color1) + 1, color1);
}

Table::Table(int sz1) {
    cout << endl << "---Table::Table(int sz1)" << endl;
    sz = new int; *sz = sz1;
    color = new char[32];
}

void Table::Show() {
    cout <<  "   Размер = " << *sz << endl << "   Цвет - " << color << endl;
}

int Table::CalcVolume() {
    return pow(*sz, 3);
}

Table::~Table() {
    cout << endl << "---Table::~Table() " << endl;
    delete sz; delete[] color;
}


class CompTable :public Table {
    int* h; char* matrl;
public:
    CompTable();
    CompTable(int, const char*, int, const char*);
    ~CompTable();
    
    void ShowCT();
    int CalcVolumeCT();
};

CompTable::CompTable() :Table() {
    cout << endl << "---CompTable::CompTable() :Table() " << endl;
    h = new int; matrl = new char[32];

}

CompTable::CompTable(int sz1, const char* color1, int h1, const char* mtrl1)
    :Table(sz1, color1) {
    cout << endl << "---CompTable::CompTable(int sz1, char* color1, int h1, char* mtrl1) :Table(sz1, color1) " << endl;
    h = new int; *h = h1;
    matrl = new char[strlen(mtrl1) + 1];
    strcpy_s(matrl, strlen(mtrl1) + 1, mtrl1);
}

CompTable::~CompTable() {
    cout << endl << "---CompTable::~CompTable() " << endl;
    delete h; delete[] matrl;
}

void CompTable::ShowCT() {
    cout <<  "   Высота подставки = " << *h << endl << "   Материал - " << matrl << endl;
    Table::Show();
}

int CompTable::CalcVolumeCT() {
    return pow(*h, 3) + Table::CalcVolume();
}

double  cost_table(Table* tabl) {
    cout << "     Стоимость стола в зависимости от объёма - ";
return tabl->CalcVolume() * 10;// 10 - стоимость за единицу объёма
}
double  cost_comptable(CompTable* tabl) {
    cout << "     Стоимость стола в зависимости от объёма - ";
    return tabl->CalcVolumeCT() * 10;// 10 - стоимость за единицу объёма
}
