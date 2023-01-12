﻿#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Russian" );
	int choice;
	cout << "Выберите нужную программу" << endl;
	cout << "1-Решение квадратного уравнения" << endl;
	cout << "2-Определяет, какая из фигур имеет большую площадь." << endl;
	cout << "3-Определяет, является ли треугольник равнобедренным" << endl;
	cout << "4-Вывод правильной (с точки зрения русского языка) фразы,обозначающей возраст" << endl;
	cout << "5-Является ли введенный символ заглавной буквой латинского алфавита или цифрой?" << endl;
	cout << "6-Программа-калькулятор с двумя вещестенными  числами" << endl;
	cout << "7-Определяет принадлежит ли тока с координатами (x, y) треугольнику, заданному координатами его вершин" << endl;
	cout << "8-Не решено" << endl;
	cout << "9-Вычисляет дату, следующую за данной" << endl;
	cout << "10-Выход" << endl;
	while (true)
	{
		cout << endl;
		cout << "Ваш выбор программы = ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			double a, b, c;
			double D, x1, x2;
			cout << "Решение квадратного уравнения" << endl;
			cout << "Введите значения коэффициетнов уравнения" << endl;
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			cout << "c = ";
			cin >> c;
			D = b * b - 4.0 * a * c; //Вычисляем дискриминант
			if (D >= 0.0) //Если дискриминант неотрицателен
			{
				//Вычисляем корни уравнения
				x1 = (-b + sqrt(D)) / (2.0 * a);
				x2 = (-b - sqrt(D)) / (2.0 * a);
				//Если дискриминант положителен (вложенный условный оператор)
				if (D > 0)
				{
					//Выводим значения обоих корней
					cout << "x1 = " << x1 << endl;
					cout << "x2 = " << x2 << endl;
				}
				else //иначе (дискриминант равен нулю)
					//Выводим значения совпадающих корней
					cout << "x1 = x2 = " << x1 << endl;
			}
			else //иначе (дискриминант отрицателен)
				//Сообщаем, что нет решений
				cout << "No solution" << endl;
			break;
		}
		case 2:
		{
			double a, b, c, r, sT, sK, pp;
			cout << "Определяет, какая из фигур имеет большую площадь." << endl;
			cout << "Введите первую сторону треугольника = ";
			cin >> a;
			cout << "Введите вторую сторону треугольника = ";
			cin >> b;
			cout << "Введите третью сторону треугольника = ";
			cin >> c;
			if ((a + b <= c) or (a + c <= b) or (c + b <= a))
			{
				cout << "Такой треугольник не существует" << endl;
				return 0;
			}
			cout << "Введите радиус круга = ";
			cin >> r;
			pp = (a + b + c) / 2;
			sT = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
			sK = 3.14 * (r * r);
			cout << "Площадь треугольника = " << sT << endl;
			cout << "Площадь круга = " << sK << endl;
			if (sT >= sK)
			{
				if (sT == sK)
					cout << "Площадь треугольника и круга равны" << endl;
				else
					cout << "Площадь треугольника больше площади круга" << endl;
			}
			else
				cout << "Площадь круга больше площади треугольника"<<endl;
			break;
		}
		case 3:
		{
			int a, b, c;
			cout << "Определяет, является ли треугольник равнобедренным" << endl;
			cout << "Введите первую сторону треугольника = ";
			cin >> a;
			cout << "Введите вторую сторону треугольника = ";
			cin >> b;
			cout << "Введите третью сторону треугольника = ";
			cin >> c;
				if ((a + b <= c) or (a + c <= b) or (c + b <= a))
				{
					cout << "Такой треугольник не существует" << endl;
					return 0;
				}
			if ((a == b || b == c || a == c) && (a == b && b == c && a == c))
				cout << "Треугольник равнобедренный"<<endl;
			else
				cout << "Треугольник не равнобедренный"<<endl;
			break;
		}
		case 4:
		{
			int V, v100;
			cout << "Вывод правильной (с точки зрения русского языка) фразы,обозначающей возраст " << endl;
			cout << "Введите ваш возраст = ";
			if (V > 0 && V <= 200)
			{
				if ((V % 10 == 2 || V % 10 == 3 || V % 10 == 4) && (V / 10 % 10 != 1))
					cout << "Вам " << V << " года" << endl;
				else if (V % 10 == 1 && (V / 10 % 10 != 1))
					cout << "Вам " << V << " год" << endl;
				else
					cout << "Вам " << V << " лет" << endl;
			}
			else
					cout << "Неверный возраст " << endl;
			break;
		}
		case 5:
		{
			char ch;
			cout << "Является ли первый введенный символ заглавной буквой латинского алфавита или цифрой?" << endl;
			cout << "Введите один символ латинского алфавита или цифру = ";
			cin >> ch;
			if (ch >= 'A' && ch <= 'Z')
				cout << ch << " - это заглавная буква латинского алфавита " << endl;
			else if (ch >= '0' && ch <= '9')
				cout << ch << " - это цифра " << endl;
			else
				cout << "Это не заглавная буква латинского алфавита и не цифра" << endl;
			break;
		}
		case 6:
		{
			double a, b;
			char zn;
			cout << "Программа-калькулятор с двумя вещестенными  числами" << endl;
			cout << "Введите два вещественных числа" << endl;
			cout << "Первое вещественное число = ";
			cin >> a;
			cout << "Второе вещественное число = ";
			cin >> b;
			cout << "Символ операции ( + , - , * , / ) = ";
			cin >> zn;
			switch (zn)
			{
			case '+':
				cout << "A+B " << "Ответ = " << a + b << endl;
				break;
			case '-':
				cout << "A-B " << "Ответ = " << a - b << endl;
				break;
			case '*':
				cout << "A*B " << "Ответ = " << a * b << endl;
				break;
			case '/':
				cout << "A/B " << "Ответ = " << a / b << endl;
				break;
			default:
				cout << "Вы ввели неверный знак" << endl;
			}
			break;
		}
		case 7:
		{
			double x, y; //Заданная точка
			double first, aX, yB; //Точки треугольника
			cout << " Определяет принадлежит ли тока с координатами (x, y) треугольнику, заданному координатами его вершин " << endl;
			cout << "Введите координаты вершин треугольника в формате x.y" << endl;
			cout << "Первые координаты вершины треугольника = ";
			cin >> first;
			cout << "Вторые координаты вершины треугольника = ";
			cin >> aX;
			cout << "Третьи координаты вершины треугольника = ";
			cin >> yB;
			cout << "Ваша точка с координатами = " << endl;
			cin >> x >> y;
			if (first <= x && x <= aX && first <= y && y <= yB)
				cout << "Точка принадлежит" << endl;
			else
				cout << "Точка не принадлежит" << endl;
			break;
		}
		case 8:
			cout << "Не решено" << endl;
			break;
		case 9:
		{
			int d, m, y;
			cout << "Вычисляет дату, следующую за данной" << endl;
			cout << "Введите день = ";
			cin >> d;
			cout << "Введите месяц = ";
			cin >> m;
			cout << "Введите год = ";
			cin >> y;
			if ((d == 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
			{
				m = m + 1;
				d = 1;
			}
			else if ((d == 30) && (m == 4 || m == 6 || m == 9 || m == 11))
			{
				m = m + 1;
				d = 1;
			}
			else if (m == 2 && (d == 28 || d == 29))
			{
				if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && d == 28)//Проверка високосного года
				{
					d = 29;
					cout << "Ваша дата = " << d << " " << m << " " << y << endl;
					return 0;
				}
				if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && d == 29)//Проверка високосного года
				{
					m = m + 1;
					d = 1;
					cout << "Ваша дата = " << d << " " << m << " " << y << endl;
					return 0;
				}
				else
				{
					cout << "Ошибка даты,29 февраля не високосного года." << endl;
					return 0;
				}
			}
			else
				d = d + 1;
			if (m > 13)
				cout << "Ошибка";
			else if (d > 31)
				cout << "Ошибка даты ";
			else if (d >= 30 && m == 2)
				cout << "Ошибка даты ";
			else if (d < 1 || m < 1)
				cout << "Ошибка даты ";
			else
			{
				if (m > 12)
				{
					y = y + 1;
					m = 1;
					d = 1;
				}
				cout << "Ваша дата = " << d << " " << m << " " << y << endl;
			}
			break;
		}
		case 10:
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