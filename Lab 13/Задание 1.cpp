#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
using namespace std;
//•	обеспечивает первоначальный ввод данных в информационную систему и
//формирование линейного списка;
//•	производит вывод всего списка;
//•	вводит номер поезда и выводит все данные об этом поезде;
//•	вводит название станции назначения и выводит данные обо всех поездах,
//следующих до этой станции.


struct Train {
    int train_number;
    string station;
    double time;
    Train* next,*prev;
};
typedef Train* PTrain;
PTrain Head = NULL, Tail = NULL;

Train* enter_train() {
    Train* train = new Train;
    cout << "Введите номер поезда = ";
    cin >> train->train_number;
    cout << "Введите название станции назначения = ";
    cin >> train->station;
    cout << "Введите время отправления = ";
    cin >> train->time;
    return train;
}

void AddFirst(Train*& Head, Train*& Tail, Train* sk) //первое заполнение
{
    sk->next = Head;
    sk->prev = NULL;
    if (Head) Head->prev = sk;
    Head = sk;
    if (!Tail) Tail = Head; // этот элемент - первый
}
void AddLast(Train*& Head, Train*& Tail, Train* sk)
{
    sk->prev = Tail;
    sk->next = NULL;
    if (Tail) Tail->next = sk;
    Tail = sk;
    if (!Head) Head = Tail;
}

//Последующее добавление записи
void add(Train*& Head, Train*& Tail, Train* spi, Train* sk) {
    if (!spi->next)
        AddLast(Head, Tail, sk);// вставка в конец списка
    else {
        sk->next = spi->next; // меняем ссылки нового узла
        sk->prev = spi;
        spi->next->prev = sk; // меняем ссылки соседних узлов 
        spi->next = sk;
    }
}


void coutt(Train* sk) {
    cout << "----------------------------------------------------------" << endl;
    cout << "Номер поезда =  " << sk->train_number
        << " Название станции назначения = " << sk->station
        << " Время отправления = " << sk->time <<endl;
    cout << "----------------------------------------------------------" << endl;
}

Train* cou(Train* sk)
{
    coutt(sk);
    return sk;
}

Train* find(Train* Head,int number,string station,int option) {  //поиск
    while (Head) {
        if (option == 1)
            if (Head->train_number == number)
                cou(Head);
        if (option == 2)
            if (Head->station == station)
                cou(Head);
        Head = Head->next;
        if (Head == NULL)
            return Head;
    }
    cout << "Неверные данные " << endl;
    return 0;
}

// Поиск записей по некоторому полю
void find_Train(Train* Head) {
    string peremen;
    int option;
    do {
        cout << "----------------------------------------------------------" << endl;
        cout << "1 - поиск по номеру, 2 - по станции, 3 - отмена " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Ваш выбор = № ";
        cin >> peremen;
    } while (!(option = atoi(peremen.c_str())));
    switch (option) {
    case 1:
    {
        cout << "Введите номер поезда = ";
        cin >> peremen;
        Train* sk = find(Head, atoi(peremen.c_str()), peremen, option);
    }
    break;
    case 2:
    {
        cout << "Введите название станции = ";
        cin >> peremen;
        Train* sk = find(Head, atoi(peremen.c_str()), peremen, option);
    }
    case 3:
        return;
    default: cout << "Неверный режим " << endl;
    }
}

//Печать всех записей
void print_dbase(Train* Head) {
    if (Head != NULL) {
        coutt(Head);
        print_dbase(Head->next);
    }
    else cout << "\n";
}

// добавление после определенного 
int menu() {
    string peremen;
    int option;
    do {
        cout << "1- добавление поезда , 2 - поиск поезда" << endl;
        cout << "3 - вывод базы на экран,4 - добавить после определенного, 5 - выход " << endl;
        cout << "Ваш выбор = № ";
        cin >> peremen;
        option = atoi(peremen.c_str());
    } while (!option);
    return option;
}
Train* ptrain(Train* Head,int number)
{
    if (Head->train_number == number)
        return Head;
    else
        cout << "Нет такого ";
}

int main()
 {
    setlocale(LC_ALL, "russian");
    Train* spi = 0;
    
    while (true) {
        switch (menu()) {
        case 1:
                AddFirst(Head,Tail, enter_train());
            break;
        case 2: find_Train(Head); break;
        case 3: print_dbase(Head); break;
        case 4: 
            cout << "Введите поезд, после которого необходимо добавить поезд = ";
            int number;
            cin >> number;
            spi = ptrain(Head,number);
            if(spi!=NULL)
            add(Head, Tail, spi, enter_train());
            break;
        case 5: return 0;
        default: cout << " Надо вводить от 1 до 4 " << endl; break;
        }
    }
    return 0;
}

