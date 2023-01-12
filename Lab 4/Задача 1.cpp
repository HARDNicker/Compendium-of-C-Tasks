#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Находит среднее геометрическое положительных последних цифр всех чисел от 1 до введенного n "<<endl;
    cout << "Введите n =  ";
    cin >> n;
        if (n < 1 || n>999999999)
            {
                cout << "Неверное значение";
                return 0;
            }
    double f = 1;
    for (int i = 1; i <= n; i++)
    {
        int s = i % 10;
        f = f * s;
    }
    cout <<"Ответ: " << pow(f, 1. / n);
    return 0;
}