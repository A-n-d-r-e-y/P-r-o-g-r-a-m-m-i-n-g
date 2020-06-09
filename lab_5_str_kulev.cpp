#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct smth {
	int n = 0, st=0;
	float sg = 0;
	string name = " ";
	string raion = " ";
};

bool cmpByFam(const smth& r1, const smth& r2)
{
	return r1.n < r2.n;
}

int main(){
	setlocale(LC_ALL, "rus");
	string x;
	smth s;
	ifstream file;
	file.open("file5lab.txt");
	int len(0);
	if (file.is_open()) {
		while (!file.eof()) {
			string s;
			getline(file, s);
			len++;
		}
	}
	smth* arr = new smth[len];
	file.seekg(0, ios_base::beg);
	for (size_t i = 0; i < len; i++)
	{
		getline(file, x);
		istringstream iss(x);
		iss >> s.n >> s.name >> s.sg >> s.st;
		arr[i] = s;
	}
	cout << "Цветы на складе: " << endl;
	for (size_t n = 0; n < len; n++)
	{
		cout << "Количество: " << arr[n].n << " "
			 << "  Название: " << arr[n].name << " "
			 << "  Срок годности: " << arr[n].sg << " "
			 << "  Стоимость: " << arr[n].st << endl;
	}
	cout << endl << "Информация о розах: " << endl;
	for (size_t n = 0; n < len; n++)
	{
		if (arr[n].name == "Rozi")
		{
			cout << "Количество: " << arr[n].n << " "
				 << "  Название: " << arr[n].name << " "
				 << "  Срок годности: " << arr[n].sg << " "
				 << "  Стоимость: " << arr[n].st << endl;
		}
	}
	cout << endl << "Информация о всех цветах, цена букета из 7 цветов которых не будет превышать 1000 рублей: " << endl;
	sort(arr, arr + len, cmpByFam);
	for (size_t n = 0; n < len; n++)
	{
		if (arr[n].st *7 < 1000)
		{
			cout << "Количество: " << arr[n].n << " "
				 << "  Название: " << arr[n].name << " "
				 << "  Срок годности: " << arr[n].sg << " "
				 << "  Стоимость: " << arr[n].st << endl;
		}
	}
	file.close();
}