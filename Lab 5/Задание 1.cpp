#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "russian");
    cout <<"Массив из 10 целых чисел, выводится все его положительные элементы. Определяет произведение положительных элементов массива." << endl;;
    const int n=10;
    int mas[n];
    unsigned long long a = 1;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите "<<i+1<< " элемент массива = ";
        cin >> mas[i];
        
    }
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0)
        {
            cout << mas[i] << " ";
            a = a * mas[i];        
        }
        else
            k = k+1;
    }
    if (k == 10)
    {
        cout << "Положительных чисел нет ";
    }
    else
        cout <<endl << " Произведение положительных элементов = " << a;
    return 0;
}