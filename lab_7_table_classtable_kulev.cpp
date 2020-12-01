#include <iostream>
#include "Head_table_classtable.h"
#include <cmath>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

    cout << "----Программа реализации обобщенного алгоритма для работы с объектами иерархии классов Столов!----" << endl;
	Table* table = new Table(10, "Серый");
    cout << endl << "  Характеристики стола: " << endl; table->Show();
    cout << "    Объём стола - " << table->CalcVolume() << endl;
	cout << cost_table(table) << endl;

	CompTable* ctable = new CompTable(10, "белый", 2, "ДВП");
    cout << endl << "  Характеристики компьютерного стола: " << endl; ctable->ShowCT();
    cout << "    Объём компьютерного стола - " << ctable->CalcVolumeCT() << endl;
	
    cout << cost_comptable(ctable) << endl;

	delete table;
	table = nullptr;

    delete ctable;
	ctable = nullptr;

    return 0;
}

