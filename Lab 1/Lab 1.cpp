#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int choice;
	cout << "Select the desired program" << endl;
	cout << "1-Sum of two integers" << endl;
	cout << "2-Calculate area and perimeter of a triangle by 3 sides" << endl;
	cout << "3-Calculating the product of digits of a four-digit number" << endl;
	cout << "4-Calculate a number obtained by crossing out the digits of thousands and tens and then subtracting them from the resulting two-digit number" << endl;
	cout << "5-Changing the place values of two variables without using a third" << endl;
	cout << "6-Program that determines the angle of the minute hand from the angle of the hour hand" << endl;
	cout << "7-Returns the second digit after the decimal point of the entered real number." << endl;
	cout << "8-Exit." << endl;
	while (true)
	{
		cout << endl;
		cout << "Your choice of program = ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int a, b;
			cout << "1 - Sum of integers A and B" << endl << "A = ";
			cin >> a;
			cout << "B = ";
			cin >> b;
			cout << "A + B = " << a + b << endl;
			break;
		}
		case 2:
		{
			double S, P, p;
			double a, b, c;

			cout << "2-Calculate area and perimeter of a triangle by 3 sides" << endl;
			cout << "Enter the first side of a = ";
			cin >> a;
			cout << "Enter the second side of b = ";
			cin >> b;
			cout << "Enter the third side c = ";
			cin >> c;
			P = a + b + c;
			p = P / 2;
			cout << "Perimeter of a triangle =  " << P << endl;
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "The area of the triangle = " << S <<endl;
			break;
		}
		case 3:
		{
			int x, e, d, s, t, p;
			cout << "3-Calculating the product of digits of a four-digit number" << endl;
			cout << "Enter a four-digit number = ";
			cin >> x;
			e = x % 10; 
			d = (x / 10) % 10;
			s = (x / 100) % 10;
			t = x / 1000;
			p = e * d * s * t;
			cout << "The product of the digits of a four-digit number = " << p<<endl;
			break;
		}
		case 4:
		{
			int x, e, d, s, t, p, k1, k2;
			cout << "4-Calculate a number obtained by crossing out the digits of thousands and tens and then subtracting them from the resulting two-digit number  " << endl;
			cout << "Enter a four-digit number = ";
			cin >> x;
			e = x % 10;
			d = (x / 10) % 10;
			s = (x / 100) % 10;
			t = x / 1000;
			k1 = s * 10;
			cout << k1 << endl;
			k2 = t * 10;
			cout << k2 << endl;
			p = (k1 + e) - (k2 + d);
			cout << "Number = " << p<<endl;
			break;
		}
		case 5:
		{
			int a, b;
			cout << "5-Changing the place values of two variables without using a third" << endl;
			cout << "Enter the number a = ";
			cin >> a;
			cout << "Enter the number b = ";
			cin >> b;
			a = a + b;
			b = a - b;
			a = a - b;
			cout << "Modified numbers: " << "a = " << a << " " << "b = " << b<<endl;
			break;
		}
		case 6:
		{
			int hour_degree, angle, a;
			cout << "6-Program that determines the angle of the minute hand from the angle of the hour hand" << endl;
			cout << "Enter the clockwise angle= ";
			cin >> hour_degree;
			a = (hour_degree / 5); //5 divisions per hour
			angle = a % 6; //each division is 6 degrees per hour
			angle = angle * 72; // 72 degrees for each division of the hour relative to the minute hand
			cout << angle <<endl;
			break;
		}
		case 7:
		{
			double a;
			cout << "Returns the second digit after the decimal point of the entered real number" << endl;
			cout << "Enter a real number= ";
			cin >> a;
			a = a * 100;
			int b = a;
			b = b % 10;
			cout << "The second digit after the decimal point = " << b << endl;
			break;
		}
		case 8:
			cout << "Exits the program" << endl;
			return 0;
		default:
			cout << "Unknown program number" << endl;
			break;
		}
	}
}