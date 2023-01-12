#include <iostream>
#include <cmath>
using namespace std;

struct triangle {
    double a, b, c;
};

double space(triangle A) // функция для расчета площади треугольника по трем его сторонам
{
    double a = A.a;
    double b = A.b;
    double c = A.c;
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

int main()
{
    const int N = 3;
    triangle mas[N];
    double triangle1, triangle2, triangle3;
    setlocale(LC_ALL, "russian");
    cout << "13.Даны три треугольника, заданные длинами своих сторон. Выяснить, какой из них имеет наибольшую площадь." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Введите три стороны " << i + 1 << "-го  треугольника : ";
        cout << "a = "; cin >> mas[i].a; cout << "b = "; cin >> mas[i].b; cout << "c = "; cin >> mas[i].c;
    }
    triangle1 = space(mas[0]);
    triangle2 = space(mas[1]);
    triangle3 = space(mas[2]);
    if (triangle1 > triangle2 and triangle1 > triangle3)
        cout << "Первый треугольник имеет наибольшую площадь";
    else if(triangle2 > triangle1 and triangle2 > triangle3)
        cout << "Второй треугольник имеет наибольшую площадь";
    else
        cout << "Третий треугольник имеет наибольшую площадь";
    return 0;
}
