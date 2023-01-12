#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct Nebo {
    string name;
    string city;
    int height;
    int year;
    int number;
    Nebo* next;
};


//Добавление записи
Nebo* add(Nebo*& spi, Nebo* sk) {
    sk->next = 0;
    if (spi) //Список не пуст
    {
        Nebo* temp = spi;
        while (temp->next)
            temp = temp->next;
        temp->next = sk;
    }
    else
    {
        spi = sk;
    }
        return spi;
}

Nebo* enter_nebo() {
    Nebo* nebo = new Nebo;
    cout << "Введите номер в списке = ";
    cin >> nebo->number;
    cout <<"Введите название небоскреба = ";
    cin >> nebo->name;
    cout << "Введите город небоскреба = ";
    cin >>nebo->city;
    cout << "Введите высоту небоскреба = ";
    cin >> nebo->height;
    cout << "Введите год построения небоскреба = ";
    cin >>nebo->year;
    return nebo;
}

void coutt(Nebo* sk){
                 cout << "----------------------------------------------------------" << endl;
                 cout << " Название небоскреба = " << sk->name 
                     << " Город небоскреба = " << sk->city 
                     << " Высота небоскреба  = " << sk->height 
                     << " Год построения небоскреба = " << sk->year<<endl;
                cout << "----------------------------------------------------------" << endl;
}

Nebo* cou(Nebo* sk)
{
    coutt(sk);
    return sk;
}

Nebo* find(Nebo* sk, string name_or_city, int height_or_year, int option) {  //поиск
    while (sk) {
        if (option == 1)
            if (sk->name == name_or_city)
                cou(sk);
        if (option == 2)
            if (sk->city == name_or_city)
                cou(sk);
        if (option == 3)
            if (sk->height == height_or_year)
                cou(sk);
        if (option == 4)
            if (sk->year == height_or_year)
                cou(sk);
        sk = sk->next;
        if (sk == NULL)
            return sk;
    }
    cout << "Нет таких небоскребов " <<endl;
    return 0;
}

// Поиск записей по некоторому полю
void find_nebo(Nebo* spi) { 
    string peremen;
    int option;
    do {
        cout << "----------------------------------------------------------" << endl;
        cout << "1 - поиск по имени, 2 - по городу, 3 - по высоте, 4 - по году, 5 - отмена "<<endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Ваш выбор = № ";
        cin >> peremen;
    } while (!(option = atoi(peremen.c_str())));
    switch (option) {
        case 1:
        {
            cout << "Введите название небоскреба = ";
            cin >> peremen;
            Nebo* sk = find(spi, peremen, atoi(peremen.c_str()),option);
        }
            break;
        case 2:
        {
            cout << "Введите город небоскреба = ";
            cin >> peremen;
            Nebo* sk = find(spi, peremen, atoi(peremen.c_str()),option);
        }
            break;
        case 3:
        {
            cout << "Введите высоту небоскреба = ";
            cin >> peremen;
            Nebo* sk = find(spi, peremen, atoi(peremen.c_str()), option);
        }
            break;
        case 4:
        {
            cout << "Введите год построения небоскреба = ";
           cin >> peremen;
            Nebo* sk = find(spi, peremen, atoi(peremen.c_str()), option);
        }
            break;
        case 5:
            return;
        default: cout << "Неверный режим " << endl;
    }
}

//Печать всех записей
void print_dbase(Nebo* spi) {
    Nebo* sk = spi;
    while (sk){
        coutt(sk);
        sk = sk->next;
    }
}

Nebo* find_number(Nebo* sk, int number, Nebo** prev) {
    *prev = 0;
    while (sk) {
        if (sk->number == number)
            return sk;
        *prev = sk;
        sk = sk->next;
    }
    cout << "Нет введенного небоскреба с таким номером " << endl;
    return 0;
}
// Удаление произвольной записи по ее номеру
Nebo* remove(Nebo*& spi) { 
    int number;
    cin >> number;
    Nebo* prev;
    Nebo* pv = find_number(spi, number, &prev);
    if (pv) {
        if (pv==spi) // удаление из начала списка
            spi = spi->next;
        else // удаление из середины или конца списка
            prev->next = pv->next;
        delete pv;
    }
    return spi;
}

int menu(){
    string peremen;
    int option;
    do {
       cout << "1- добавление небоскреба , 2 - удаление небоскреба, 3 - поиск небоскреба" << endl;
        cout << "4 - вывод быза на экран, 5 - выход " << endl;
        cout << "Ваш выбор = № ";
        cin >> peremen;
        option = atoi(peremen.c_str());
    } while (!option);
    return option;
}

int main()
{
    setlocale(LC_ALL, "russian");
    Nebo* nebo, * spi = 0;
    while (true) {
        switch (menu()) {
        case 1: 
        if(spi==NULL)// формирование первого элемента
        {
            nebo = enter_nebo();
            spi = add(spi, nebo);
        }
        else
            add(spi, enter_nebo()); 
        break;
        case 2: cout << "Введите номер удаляемого элемента = "; spi = remove(spi); break;
        case 3: find_nebo(spi); break;
        case 4: print_dbase(spi); break;
        case 5: return 0;
        default: cout << " Надо вводить от 1 до 5 " << endl; break;
        }
    }
    return 0;
}

