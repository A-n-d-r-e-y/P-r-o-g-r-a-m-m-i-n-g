
#include "stdafx.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <conio.h>

#include <locale.h>
#include <string.h>
using namespace std;

void Swap(int &a, int &b)//������� ������ ����������
{int c = a;
a = b;
b = c;}

void output(int *a, int n)//������� ������ �������
{for (int i=0; i<n; i++) cout<<a[i]<<' ';}



int main()
{setlocale(0,"rus");


//----------1 �������----------

cout<<"-----1 �������-----"<<endl;
cout<<"������������ ���������� ������ �� "<<endl;
cout<<"������������� �� ����������� ��������� �����, "<<endl;
cout<<"��������� �� �����. "<<endl;


ifstream NumFile("lab.txt");
int m=0,N;
if(!NumFile)//���� ���� �� ��������� � ����� � ����������� �����
{cout << "���� �� ������"<<endl;
 return 0;
}

cout << "����������� ��������"<<endl;
while(NumFile >> N)
{cout<<N<<endl;//����� ��������� �� ����� �� �����
 if(N != 0) m++;//��������� ����� �� ����� �� �� ���������
  if(m == 0)//���� ����� � ����� ���
  {cout << "���� ���� ��� �� ����� ��������� �����"<<endl;
   return 0;
  }
}

NumFile.clear();
NumFile.seekg(0);

int *c=new int[m];
for(int i = 0; NumFile >> N;)
{if(N != 0)//���� ����� � ����� �� �������...
	{c[i] = N;//������ ����� � ������
	 i++;
	}
}

for(int i=0; i<m-1; i++)
	{for(int j=0; j<m-1; j++)
		{if(c[j]>c[j+1]) Swap(c[j], c[j+1]);//���� ���������� ����� ������ ���������� ������ �� �������
		}
	}

cout<<"��������������� �� ����������� ������ ��������� �����\n";
for(int i=0; i<m; i++) 
cout<<c[i]<<endl;

delete[]c;//�������� �������
NumFile.close();


 

//----------2 �������----------

cout<<endl;
cout<<"-----2 �������-----"<<endl;



int *a, n, e, b;
cout<<"������������ ������ �� ���������� ������� �� ��������� [a,b] �������� n - ";
cin>>n;

if(n<=0) {cout<<"�� ������� ������ ������ �� ����� ���� ����� ����!"<<endl; return 0;}

cout<<"������� �������� ��������� ��������� ������� [a;b]"<<endl;
cin>>e>>b;
a=new int[n];
 for(int i=0; i<n; i++)//���������� ������� �� �������
	{a[i]=e + (b-e) * rand()/(int)RAND_MAX;};//������� ������� � ��������� [e,b]
cout<<"������ � ��������� ";
output(a,n);
int k;
cout<<endl<<"����� ������, ������ �� ���� ��� ��������, ������� ������  ��������� ����� k - "; cin>>k;
 for (int i=0; i<n; i++)
	{if (a[i]<k)
		{a[i]=0;}//�������� �������� �� �������� � � � ������������� ��� � ���� ���� ������
	}

 for(int i=0; i<n; i++)
	{for(int j=0; j<n-1; j++)
		{if (a[j]==0)
			{a[j]=a[j+1]; a[j+1]=0;}//����� ���� � ����� �������(������)
		}
	}
cout<<"������ ������ ";
output(a,n);


return 0;
}

