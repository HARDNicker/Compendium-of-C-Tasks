#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Заполнить массив из 10 элементов случайными числами, вывести его на экран и определить минимальный по модулю элемент." << endl;;
    const int n = 10;
    int mas[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 21 + (-10); //диапазон от 10 до -10
        cout << mas[i] << " ";
    }
   
    int min = abs(mas[0]);
    for (int i = 0; i < n; i++) //минимальный по модулю
        if (abs(mas[i]) < min)
            min = abs(mas[i]);
    cout << endl << "Минимальный по модулю элемент = " << min;
    return 0;
}