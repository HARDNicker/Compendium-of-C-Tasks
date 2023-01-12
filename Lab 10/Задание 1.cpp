﻿#include <iostream>
#include <algorithm>
#include <cstring>
#include <clocale>
#include <Windows.h>
using namespace std;

//Создаем две константы:
//maxSize - задает максимальное число элементов в базе;
const int maxSize = 20;

//Описываем структуру Bird со следующими полями: 
//vid - название вида;
//razmax - максимальный размах крыльев;
//country - основная страна обитания.

struct Bird
{
	string vid;
	double razmax;
	string country;
};

//Функция для ввода информации об очередной птице. Входные параметры:
//mas - массив птиц;
//i - номер создаваемой птицы в базе
Bird BirdInput(Bird mas[maxSize], int i)
{
	//Создаем переменную типа Bird и заполняем информацию о ней
	Bird bi;
	cout << "Вид птицы : ";
	cin >> bi.vid;
	cout << "Максимальный размах крыльев = ";
	cin >> bi.razmax;
	cout << "Основная страна обитания : ";
	cin >> bi.country;
	//Помещаем созданную структуру Bird в массив
	mas[i] = bi;
	return bi;
}

//Функция для сортировки массива птиц по максимальному размаху крыльев (полю razmax).
//Использован метод сортировки прямых вставок 
// Входные параметры:
//mas - массив птиц;
//n - число птиц в массиве
void BirdSort(Bird mas[maxSize], int n)
{
	int j;
	Bird bi;
	for (int i = 1; i < n; i++)
	{
		bi = mas[i];
		j = i - 1;
		while ((bi.razmax < mas[j].razmax) && (j >= 0))
		{
			mas[j + 1] = mas[j];
			j--;
		}
		mas[j + 1] = bi;
	}

}

//Функция для вывода массива птиц. Входные параметры:
//mas - массив птиц;
//n - число птиц в массиве
void BirdOutput(Bird mas[maxSize], int n)
{
	//Пробегаем по всем элементам массива
	for (int i = 0; i < n; i++)
	{
		//Выводим всю информацию о каждом студенте в отдельной строке
		cout << "Вид птицы : " << mas[i].vid << "--- " << "Максимальный размах крыльев = " << mas[i].razmax << "--- " << "Основная страна обитания : " << mas[i].country << "; " << endl;
	}
}

//Функция для поиска в базе птиц с определенной страной обитания.
//Выводит найденных птиц и возвращает их количество.
//Входные параметры:
//mas - массив птиц;
//n - число птиц в массиве
//country - страна для поиска;
int BirdSearch(Bird mas[maxSize], int n, string country)
{
	//Заводим счетчик найденных птиц - переменную num
	int num = 0;
	//Пробегаем по всем элементам массива
	for (int i = 0; i < n; i++)
	{
		//Если значение поля country совпадает с введенным Страной, 
		//увеличиваем значение счетчика на 1 и выводим информацию
		//о птице
		if (mas[i].country == country)
		{
			cout << "Вид птицы : " << mas[i].vid << " --- " << "Максимальный размах крыльев = " << mas[i].razmax << " --- " << "Основная страна обитания : " << mas[i].country << "; " << endl;
			num++;
		}
	}
	//Выводим число найденных птиц
	cout << num << " Птиц найдено ." << endl;
	//Возвращаем число найденных птиц
	return num;
}

//Функция удаления птицы по значению поля country. Входные параметры:
//mas - массив птиц;
//n - число птиц в массиве (передается по ссылке, так как меняется);
//delСountry - страна удаляемых птиц;
void BirdDelete(Bird mas[maxSize], int& n, string delСountry)
{
	int i = 0;
	//Просматриваем массив до тех пор, пока не достигнем его конца
	while (i < n)
	{
		//Если значение поля country элемента массива совпадает с
		//введенным, то...
		if (mas[i].country == delСountry)
		{
			//...удаляем этот элемент путем сдвига оставшихся элементов 
			//массива на одно положение влево
			for (int j = i; j < n - 1; j++)
			{
				mas[j] = mas[j + 1];
			}
			//Уменьшаем число элементов в массиве
			n--;
		}
		else
		{
			//Переходим к следующему элементу, если на данной итерации
			//удаления не произошло. Если произошло, текущее значение i
			//будет и так указывать на следующий элемент, поскольку он
			//сдвинулся на одно положение влево
			i++;
		}
	}
}

//Основная функция
int main()
{
	//Объявляем переменные:
	//n - число элементов в базе;
	//delCountry - индекс удаляемого элемента (используется при удалении);
	//mas - массив, хранящий информацию о птицах
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); //русский язык для консоли
	int n;
	string delCountry;
	Bird mas[maxSize];
	//Вводим число птиц, которые будем хранить в массиве
	cout << "Число птиц = ";
	cin >> n;
	//Вводим информацию о всех птицах с помощью реализованной функции
	for (int i = 0; i < n; i++)
	{
		BirdInput(mas, i);
	}
	//Сортируем массив птиц с помощью реализованной функции
	BirdSort(mas, n);
	//Выводим отсортированный массив
	BirdOutput(mas, n);
	//Вводим страну обитания птиц, которых нужно удалить
	cout << "Страна обитания удаленных птиц = ";
	cin >> delCountry;
	//Если птицы с такой страной обитания были найдены, удаляем их, пользуясь
	//реализованными функциям поиска и удаления элементов
	if (BirdSearch(mas, n, delCountry))
	{
		BirdDelete(mas, n, delCountry);
	}
	//Снова выводим измененный массив
	BirdOutput(mas, n);
	return 0;
}
