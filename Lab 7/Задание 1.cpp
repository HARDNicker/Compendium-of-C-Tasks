#include <iostream>
using namespace std;

void Inputmas(int** mas, int strok,int stolb)  //ввод массива
{
	for (int count_strok = 0; count_strok < strok; count_strok++)
		for (int count_stolb = 0; count_stolb < stolb; count_stolb++)
			cin >> mas[count_strok][count_stolb];
}

void Outputmas(int** mas, int strok, int stolb) //вывод массива
{
	for (int count_strok = 0; count_strok < strok; count_strok++)
	{
		for (int count_stolb = 0; count_stolb < stolb; count_stolb++)
			cout << mas[count_strok][count_stolb] << "   ";
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Найти произведение всех положительных элементов, сумма индексов которых является четным числом." << endl;
	int strok, stolb;
	cout << "Колличество строк = ";
	cin >> strok;
	cout << "Колличество столбцов =  ";
	cin >> stolb;
	if (strok > 0 and stolb > 0)
	{
		int** mas = new int* [strok]; // строки в массиве
		for (int count = 0; count < strok; count++)
			mas[count] = new int[stolb]; // столбцы
		cout << "Введите матрицу: " << endl;
		Inputmas(mas, strok, stolb);
		cout << "Ваша введенная матрица: "<<endl;
		Outputmas(mas, strok, stolb);
		unsigned long long a = 1;
		int k = 0;
		int chetnye = 0;
		for (int i = 0; i < strok; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				if ((i + j) % 2 == 0)
				{
					chetnye += 1; //подсчет четных
					if (mas[i][j] > 0)
						a = a * mas[i][j]; // произведение 
					else
						k = k + 1;
				}		
			}
		}
		if (k == chetnye)
			cout << "Произведения нет ";
		else
		cout << "Произведение всех положительных элементов = " << a;

		for (int count = 0; count < strok; count++)
			delete[] mas[count];
		delete[] mas;
	}
	else
		cout << "Должно быть целое число столбцов и строк";
	return 0;

}
