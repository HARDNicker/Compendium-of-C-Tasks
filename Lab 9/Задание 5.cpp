#include <iostream>
using namespace std;

double form(int n, int x)
{
	if (n <= 1)
		return cos(x);
	else
		return cos(form(n - 1, x));
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Для заданного натурального числа и вещественного числа вычислить значение выражения "<<endl;
	int n;
	double a,x;
	cout << "Введите кол-во косинусов: "; cin >> n;
	cout << "Введите вещественное число: "; cin >> x;
	a=form(n, x);
	cout << a << endl;
	return 0;
}
