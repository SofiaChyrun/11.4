// ChyrunSofialab11.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_11_4.cpp
// < Чирун Софія >
// Лабораторна робота № 11.4
// Опрацювання бінарного файлу 
// Варіант 18

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h> 
using namespace std;
enum Type { IT, KN, ME, TN, FI };
string typeStr[] = { "Генератори" ,"Комп’ютери",  "Мобільники", "Ноутбуки", "Принтери" };
struct Price
{
	string ProdName;
	string ShopName;
	double cost;
	Type type;
};

void Create(Price* p, const int N);
void Print(Price* p, const int N);
double MinSerbal(Price* p, const int N);
int BinSearch(Price* p, const int N, const string iProdName);
void Sort(Price* p, const int N);
void CreateBIN(char* fname, Price* p, const int N) 
{
	ofstream fout(fname, ios::binary); 
	fout << "====================================================" << endl;
	fout << "| № | Товар | Магазин |   Тип товару   |   Ціна    |" << endl;
	fout << "----------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		fout << "|" << setw(2) << right << i + 1 << " ";
		fout << "| " << setw(6) << left << p[i].ProdName
			<< "| " << setw(7) << right << p[i].ShopName << " "
			<< "| " << setw(14) << left << typeStr[p[i].type] << " "
			<< "| " << setw(9) << setprecision(2) << fixed << right << p[i].cost << " | " << endl;
	}
	fout << "====================================================" << endl;
	fout << endl;
}

void PrintBIN(char* fname) 
{
	ifstream fin(fname, ios::binary); 
	char c; 
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c; 
	}
	cout << endl;
}

int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int N, found;
	cout << "Введіть N: "; cin >> N;
	Type type;
	string iShopName;
	Price* p = new Price[N];
	Create(p, N);
	Print(p, N);
	char fname[100]; 
	cout << "enter file name 1: "; cin >> fname;
	cout << endl << "Мінімaльна ціна: " << MinSerbal(p, N) << endl;
	cout << endl << endl;
	CreateBIN(fname, p, N); 
	cout << "\nВивід результату з файлу 1: " << endl;
	PrintBIN(fname); 
	cout << "\nфізичне впорядкування даних та вивід даних" << endl;
	Sort(p, N);
	Print(p, N);
	char gname[100]; 
	cout << "\nВивід результату з файлу 2" << endl;
	cout << "enter file name 2: "; cin >> gname;
	CreateBIN(gname, p, N);
	PrintBIN(gname);
	cout << endl << endl;
	char g2name[100];
	cout << "\nВивід результату з файлу 3" << endl;
	cout << "enter file name 3: "; cin >> g2name;
	ofstream fout(g2name, ios::binary);
	cout << "Введіть ключі пошуку:" << endl;
	cin.get(); 
	cin.sync(); 
	cout << " назва товару: "; cin >> iShopName;
	if ((found = BinSearch(p, N, iShopName)) != -1)
	{
		cout << "Знайдено товар в позиції " << found + 1 << endl;
		cout << "====================================================" << endl;
		cout << "| № | Товар | Магазин |   Тип товару   |   Ціна    |" << endl;
		cout << "----------------------------------------------------"<< endl;
		cout << "|" << setw(2) << right << found + 1 << " ";
		cout << "| " << setw(6) << left << p[found].ProdName
			<< "| " << setw(7) << right << p[found].ShopName << " "
			<< "| " << setw(14) << left << typeStr[p[found].type] << " "
			<< "| " << setw(9) << setprecision(2) << fixed << right << p[found].cost << " | " << endl;
		cout << "====================================================" << endl;
		cout << endl;
		fout << "Знайдено товар в позиції " << found + 1 << endl;
		fout << "====================================================" << endl;
		fout << "| № | Товар | Магазин |   Тип товару   |   Ціна    |" << endl;
		fout << "----------------------------------------------------" << endl;
		fout << "|" << setw(2) << right << found + 1 << " ";
		fout << "| " << setw(6) << left << p[found].ProdName
			<< "| " << setw(7) << right << p[found].ShopName << " "
			<< "| " << setw(14) << left << typeStr[p[found].type] << " "
			<< "| " << setw(9) << setprecision(2) << fixed << right << p[found].cost << " | " << endl;
		fout << "====================================================" << endl;
		fout << endl;
	}
	else 
	{
		cout << "Шуканого товару не знайдено" << endl;
		fout << "Шуканого товару не знайдено" << endl;
	}
	PrintBIN(g2name);
	cout << endl << endl;
	return 0;
}

void Create(Price* p, const int N)
{
	int type;
	for (int i = 0; i < N; i++)
	{
		cout << "Товар № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync();
		cout << " назва товару: "; getline(cin, p[i].ProdName);
		cout << " тип (0 - Генератори, 1 - Комп’ютери, 2 - Мобільники, 3 - Ноутбуки, 4 - Принтери ): ";
		cin >> type;
		p[i].type = (Type)type;
		cout << " назва магазину: "; cin >> p[i].ShopName;
		cout << " ціна: "; cin >> p[i].cost;
		cout << endl;
	}
}

double MinSerbal(Price* p, const int N)
{
	double s = 100000000;
	for (int i = 0; i < N; i++)
	{
		if (p[i].cost < s)
		   s = p[i].cost;
	}
	return s;
}

void Print(Price* p, const int N)
{
	cout << "====================================================" << endl;
	cout << "| № | Товар | Магазин |   Тип товару   |   Ціна    |" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(6) << left << p[i].ProdName
			<< "| " << setw(7) << right << p[i].ShopName << " "
			<< "| " << setw(14) << left << typeStr[p[i].type] << " "
			<< "| " << setw(9) << setprecision(2) << fixed << right << p[i].cost << " | " << endl;
	}
	cout << "====================================================" << endl;
	cout << endl;
}

int BinSearch(Price* p, const int N, const string iProdName) {
	
	int L = 0, R = N - 1, m;
	do 
	{
		m = (L + R) / 2;
		if (p[m].ProdName == iProdName)
		   return m;
		if (p[m].ProdName < iProdName)
		{
		   L = m + 1;
		}
		else
		{
		   R = m - 1;
		}
	} while (L <= R);
	return -1;
}

void Sort(Price* p, const int N)
{
	Price tmp;
	for (int i0 = 0; i0 < N - 1; i0++) 
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].ShopName >  p[i1 + 1].ShopName)
			{
			   tmp = p[i1];
			   p[i1] = p[i1 + 1];
			   p[i1 + 1] = tmp;
			}
}