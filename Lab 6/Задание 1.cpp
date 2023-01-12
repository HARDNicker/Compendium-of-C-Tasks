#include <iostream>
#include <cmath>
using namespace std;

void Inputmas(int* mas, int n) //ввод массива
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите " << i + 1 << " элемент массива = ";
        cin >> mas[i];
    }
}
void Outputmas(int* mas, int n) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "В одномерном массиве, состоящем из N целых чисел, вычислить:" << endl;
    cout << "1.индекс элемента, наиболее близкого к среднему геометрическому элементов" << endl;
    cout << "2.сумму произведений всевозможных различных пар элементов массива." << endl;
    cout << "Введите длину массива N = ";

    int n;
    cin >> n;
    if (n > 0)
    {
        int* mas = new int[n];
        Inputmas(mas, n);
        double res = 1.;
        double maxmas = 0;
        for (int i = 0; i < n; i++) //подсчет среднего геометрического
        {
            res *= mas[i];
            if (mas[i] > mas[n - 1]) //подсчет максимального
                maxmas = mas[i];
            else
                maxmas = mas[n - 1];
        }
        double srgeom = pow(res, 1. / n); // среднее
        int index = 0;
        // алгоритм поиска неправильный!!(исправлено) обьяснить
        for (int i = 0; i < n; i++) //Нахождение индекса
        {
            if (abs(mas[i] - srgeom) < abs(mas[index] - srgeom))
            {
                index = i;
            }
        }
        cout << "Среднее геометрическое равно = " << srgeom << endl;
        cout << "Индекс элемента, наиболее близкого к среднему геометрическому элементов = " << index <<" (В списке как " << index+1 << " элемент)"<< endl;
        int sum = 0;
        int total = 0;
        for (int i = 0; i < n; i++) //Сумма произведений
        {
            total += sum * mas[i];//элемент умножается на сумму предыдущих 
            sum += mas[i];// +общая сумма
            cout << "Total = " << total << " " << "sum = " << sum<<endl; 
        }
        cout << "Cумма произведений всевозможных различных пар элементов массива = " << total << endl;;
        delete[] mas;
    }
    else
        cout << "Длинна массива не может быть отрицательной или нулевой";
    return 0;
}