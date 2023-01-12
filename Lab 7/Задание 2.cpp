#include <iostream>
using namespace std;

void Inputmas(int** mas, int strok, int stolb)  //ввод массива
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

	cout << "Дана действительная матрица A размера nxm. Найти все седловые элементы матрицы. " << endl;
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
		cout << "Ваша введенная матрица: " << endl;
		Outputmas(mas, strok, stolb);
		int net = 0;
		for (int i = 0; i < strok; i++)
		{
			int min = 0;
			int flag = 0; //определяет один или нет минимум в столбце и то же самое действие потом в строке
			for (int j = 1; j < stolb; j++)
			{
				if (mas[i][j] == mas[i][min])
					flag = 1;
				if (mas[i][j] < mas[i][min])
				{
					flag = 0;
					min = j; // номер столбца мин.элемента
				}
			}
			if (flag==0)
			{
				int max = 0;
				for (int j = 1; j < strok; j++)
				{
					if (mas[j][min] == mas[max][min])
						flag = 1;
					if (mas[j][min] > mas[max][min])
					{
						flag = 0;
						max = j; // номер строки макс.элемента в столбце
					}
				}
				if (max == i)
				{
					cout<<"Седловая точка "<<"[" << max<< "]" <<"[" << min << "] = " << mas[max][min];
					net++;
				}
			}
		}
		if (net == 0)
			cout << ("Седловых точек нет");
	}
	else
		cout << "Должно быть целое число столбцов и строк";
	return 0;

}