﻿#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	cout << "Выберите нужную программу" << endl;
	cout << "1-(while)Определить, в каком году общий урожай, собранный за все время, начиная с первого года, превысит Y центнеров " << endl;
	cout << "2-(do-while)Определить, в каком году общий урожай, собранный за все время, начиная с первого года, превысит Y центнеров " << endl;
	cout << "3-Находит произведение первых двух наибольших  натуральных чисел, меньших n и делящихся на m " << endl;
	cout << "4-Находит число, получаемое из исходного отбрасыванием двух его старших цифр " << endl;
	cout << "5-Находит все простые делители данного натурального числа n " << endl;
	cout << "6-Возводит число A в степень N " << endl;
	cout << "7-Выход" << endl;
	while (true)
	{
		cout << endl;
		cout << "Ваш выбор программы = ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			double s, u, p, q;
			int g; //дни с первого
			int y; 
			cout << "В некотором году (назовем его условно первым) на участке в S га средняя урожайность ячменя составила u центнеров с га."<<
				"После этого каждый год площадь участка увеличивалась на p%, а средняя урожайность – на q% .Определить, в каком году общий "<<
				"урожай, собранный за все время, начиная с первого года, превысит Y центнеров.Получить ответ для S = 100 га, u = 20 центнеров с га, p = 5 %, q = 2 %, Y = 8000 центнеров." << endl;
			s = 100;
			u = 20;
			p = 5;
			q = 2;
			g = 1;
			y = 0;
			p /= 100.0;
			q /= 100.0;
			y = u * s;
			while (y <= 8000)  //y - собранный урожай
			{
				s = s * (1.0+p);  //формулы для процентов
				u = u * (1.0+q);
				y = u*s;
				g++;
			}
			cout << "За " << g << " дней"<<endl;

			break;
		}
		case 2:
		{
			double s, u, p, q;
			int g; //дни с первого
			int y;
			cout << "В некотором году (назовем его условно первым) на участке в S га средняя урожайность ячменя составила u центнеров с га." <<
				"После этого каждый год площадь участка увеличивалась на p%, а средняя урожайность – на q% .Определить, в каком году общий " <<
				"урожай, собранный за все время, начиная с первого года, превысит Y центнеров.Получить ответ для S = 100 га, u = 20 центнеров с га, p = 5 %, q = 2 %, Y = 8000 центнеров." << endl;
			s = 100;
			u = 20;
			p = 5;
			q = 2;
			g = 1;
			y = 0;
			p /= 100.0;
			q /= 100.0;
			y = u * s;
			do
			{
				s = s * (1.0 + p);  //формулы для процентов
				u = u * (1.0 + q);
				y = u*s;
				g++;
			} while (y <= 8000);
			cout << "За " << g << " дней" << endl;
			break;
		}
		case 3:
			int m, n, f1, s1, C;
			cout << "Находит произведение первых двух наибольших  натуральных чисел, меньших n и делящихся на m" << endl;
			cout << "Введите натуральное число n = ";
			cin >> n;
			cout << "Введите натуральное число m = ";
			cin >> m;
			f1 = n - 1; //Первое наибольшее натуральное число
			while (f1 % m != 0)
			{
				f1 = f1 - 1;
			}
			s1 = f1 - m;
			C = f1 * s1;
			cout << "Произведение чисел = " << C<<endl;
			break;
		case 4:
		{
			int a, b, s, o, c;
			cout << "Дано натуральное число.Находит число, получаемое из исходного отбрасыванием двух его старших цифр (до 9 значного числа)" << endl;
			cout << "Введите натуральное число = ";
			cin >> a;
				if (a > 999999999)
				{
					cout << "Введено слишком большое число";
					return 0;
				}
			b = 0;
			c = a;
				while (a >= 100)
				{
					b++;
					a = a / 10;
				}
			s = pow(10, b);
			o = c % s;
			cout << o <<endl;

			break;
		}
		case 5:
		{
			int n;
			cout << "Находит все простые делители данного натурального числа n" << endl;
			cout << "Введите натуральное число = ";
			cin >> n;
			if (n <= 1 || n > 999999999)
			{
				cout << "Неверное значение";
				return 0;
			}
			int a = 2;
			cout << "Простые делители числа " << n << " = ";
			while (n > 1)
			{
				while (n % a == 0)
				{
					while (n%a==0)
						n /= a;
					cout << a << "; ";
				}
				a++;
			}
			break;
		}
		case 6:
		{
			double a, n, c;
			cout << "Возводит число A в степень N " << endl;
			cout << "Введите число A = ";
			cin >> a;
			c = a;
			cout << "Введите степень N = ";
			cin >> n;
				for (int i = 0; i < n-1; i++)
				{
					a *= c;
				}
			cout << "Ответ = " << a<<endl;
			break;
		}
		case 7:
		{
			cout << "Производится выход из программы" << endl;
			return 0;
		}
		default:
		{
			cout << "Неизвестный номер программы" << endl;
			break;
		}
		}
	}
}