#include <iostream>
#include <cmath>
using namespace std;

double** create(int n,int m)
{
	double** matrix = new double* [n];
	for (int count = 0; count < n; count++)
		matrix[count] = new double[m];
	return matrix;
}

void Inputmas(double** mas, int n, int m)  //ввод массива
{
	for (int count_strok = 0; count_strok < n; count_strok++)
		for (int count_stolb = 0; count_stolb < m; count_stolb++)
			cin >> mas[count_strok][count_stolb];
}
void Outputmas(double** mas, int n, int m) //вывод массива
{
	for (int count_strok = 0; count_strok < n; count_strok++)
	{
		for (int count_stolb = 0; count_stolb < m; count_stolb++)
			cout << mas[count_strok][count_stolb] << "   ";
		cout << endl;
	}
}
int mini(double** mas, int m, int n)
{
	int min = 0;
	int flag = 0;
		for (int j = 1; j < m; j++)
		{
			if (mas[n][j] == mas[n][min])
				flag = 1;
			if (mas[n][j] < mas[n][min])
			{
				flag = 0;
				min = j;
			}
		}
		if (flag == 0)
			return min;
		else
			return -1;
}
int maxi(double** mas, int m, int min)
{
	int flag = 0;
	int max = 0;
	for (int j = 1; j < m; j++)
	{
		if (mas[j][min] == mas[max][min])
			flag = 1;
		if (mas[j][min] > mas[max][min])
		{
			flag = 0;
			max = j; 
		}
	}
	if (flag == 0)
		return max;
	else
		return -1;
}

void sedlo(double** mas, int m) 
{
	int net = 0;
	for (int i = 0; i < m; i++)
	{
		int min = mini(mas, m,i);
		if (min >= 0)
		{
			int max = maxi(mas, m, min);
			if (max == i)
			{
				cout << "Седловая точка " << "[" << max << "]" << "[" << min << "] = " << mas[max][min];
				net++;
			}
		}
	}
	if (net == 0)
		cout << ("Седловых точек нет");
}

void Clear_mas(double** mas, int n)
{
	for (int count = 0; count < n; count++)
		delete[] mas[count];
	delete[] mas;
}


int main()
{
	setlocale(LC_ALL, "russian");
	cout << "13)Дана действительная матрица A размера nxm. Найти все седловые элементы матрицы." << endl;
	cout << "Введите матрицу : " << endl;
	int n, m;
	cout << "Колличество строк матрицы = ";	cin >> n;
	cout << "Колличество столбцов матрицы =  "; cin >> m;
	if (n > 0 and m > 0)
	{
		double** matrix = create(n, m);
		Inputmas(matrix, n, m);
		cout << "Ваша введенная матрица: " << endl;
		Outputmas(matrix, n, m);
		sedlo(matrix, m);
		Clear_mas(matrix, n);
	}
	else
		cout << "Должно быть целое число столбцов и строк";

	return 0;
}
