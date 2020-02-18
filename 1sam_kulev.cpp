
#include "stdafx.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <conio.h>

#include <locale.h>
#include <string.h>
using namespace std;

void Swap(int &a, int &b)//функция замены переменных
{int c = a;
a = b;
b = c;}

void output(int *a, int n)//функция вывода массива
{for (int i=0; i<n; i++) cout<<a[i]<<' ';}



int main()
{setlocale(0,"rus");


//----------1 задание----------

cout<<"-----1 задание-----"<<endl;
cout<<"Динамический одномерный массив из "<<endl;
cout<<"упорядоченных по возрастанию ненулевых чисел, "<<endl;
cout<<"считанных из файла. "<<endl;


ifstream NumFile("lab.txt");
int m=0,N;
if(!NumFile)//если фаил не находится в папке с программным кодом
{cout << "файл не найден"<<endl;
 return 0;
}

cout << "Изначальные значения"<<endl;
while(NumFile >> N)
{cout<<N<<endl;//вывод элементов из файла на экран
 if(N != 0) m++;//добавлять числа на экран до их окончания
  if(m == 0)//если чисев в файле нет
  {cout << "Файл пуст или не имеет ненулевых чисел"<<endl;
   return 0;
  }
}

NumFile.clear();
NumFile.seekg(0);

int *c=new int[m];
for(int i = 0; NumFile >> N;)
{if(N != 0)//если число в файле не нулевое...
	{c[i] = N;//вводим число в массив
	 i++;
	}
}

for(int i=0; i<m-1; i++)
	{for(int j=0; j<m-1; j++)
		{if(c[j]>c[j+1]) Swap(c[j], c[j+1]);//если предыдущее число меньше следующего меняем их местами
		}
	}

cout<<"Отсортированный по возрастанию массив ненулевых чисел\n";
for(int i=0; i<m; i++) 
cout<<c[i]<<endl;

delete[]c;//удаление массива
NumFile.close();


 

//----------2 задание----------

cout<<endl;
cout<<"-----2 задание-----"<<endl;



int *a, n, e, b;
cout<<"Динамический массив со случайными числами из интервала [a,b] размером n - ";
cin>>n;

if(n<=0) {cout<<"По условию задачи массив не может быть равен нулю!"<<endl; return 0;}

cout<<"Введите значения интервала элементов массива [a;b]"<<endl;
cin>>e>>b;
a=new int[n];
 for(int i=0; i<n; i++)//заполнение массива по порядку
	{a[i]=e + (b-e) * rand()/(int)RAND_MAX;};//задание массива в интервале [e,b]
cout<<"Массив в интервале ";
output(a,n);
int k;
cout<<endl<<"Сжать массив, удалив из него все элементы, которые больше  заданного числа k - "; cin>>k;
 for (int i=0; i<n; i++)
	{if (a[i]<k)
		{a[i]=0;}//проверка элемента на значение к к и приравнивание его к нулю если меньше
	}

 for(int i=0; i<n; i++)
	{for(int j=0; j<n-1; j++)
		{if (a[j]==0)
			{a[j]=a[j+1]; a[j+1]=0;}//сдвиг нуля в конец массива(вправо)
		}
	}
cout<<"Сжатый массив ";
output(a,n);


return 0;
}

