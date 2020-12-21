#include <iostream>
#include "Head_tables.h"
#include <cmath>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	cout << "----Программа реализации иерархии классов столов!----" << endl;
	
 	Table* table = new Table(10, "Серый");
    cout << endl << "  Характеристики стола: " << endl; table->Show();
    cout << "    Объём стола - " << table->CalcVolume() << endl;

	CompTable* ctable = new CompTable(10, "белый", 2, "ДВП");
    cout << endl << "  Характеристики компьютерного стола: " << endl; ctable->ShowCT();
    cout << "    Объём компьютерного стола - " << ctable->CalcVolumeCT() << endl;

	delete table;
	table = nullptr;

    delete ctable;
	ctable = nullptr;

    return 0;
}

