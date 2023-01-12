#include <iostream>
#include <algorithm>
using namespace std;

void Inputmas(int* mas, int n)  //ввод массива
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
    cout << "Сортировка массива из N символов в невозрастающем порядке с помощью сортировки прямым обменом." << endl;;
    cout << "Введите длину массива N = ";
    int n;
    cin >> n;
    if (n > 0)
    {
        int* mas = new int[n];
        Inputmas(mas, n);

        for (int i = 0; i < n - 1; i++) //для всех i
        {
            for (int j = (n - 1); j > i; j--) // для всех элементов после i-ого
                if (mas[j - 1] < mas[j]) //сравнивает предпоследий элемент с последним
                    swap(mas[j - 1], mas[j]); // меняем их местами
        }

        Outputmas(mas, n);

        delete[] mas;
    }
    else
        cout << "Длинна массива не может быть отрицательной или нулевой";
    return 0;
}