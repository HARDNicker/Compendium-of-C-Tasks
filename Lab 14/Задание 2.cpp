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
    Train* next, * prev;
};
typedef Train* PTrain;

struct Queue {
    PTrain Head = NULL, Tail = NULL;
};


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

void PushTail(Queue& Q, Train* sk) //Добавление элемента на вершину стека
{
    PTrain NewNode;
    NewNode = new Train; // создать новый узел...
    NewNode = sk; // и заполнить его данными
    NewNode->prev = Q.Tail;
    NewNode->next = NULL;
    if (Q.Tail) // добавить в начало списка
        Q.Tail->next = NewNode;
    Q.Tail = NewNode;
    if (!Q.Head) Q.Head = Q.Tail;


}

//Получение крайнего элемента очереди
//Функция Pop удаляет крайний элемент и возвращает его данные.
Train* Pop(Queue& Q)
{
    PTrain TopNode = Q.Head;
    string stat;
    int t_number;
    double t;
    if (TopNode != NULL)
    {
        t_number = TopNode->train_number;
        stat = TopNode->station;
        t = TopNode->time;
        Q.Head = TopNode->next;
        if (Q.Head) Q.Head->prev = NULL; // переставить ссылки
        else Q.Tail = NULL;
        cout << t_number << " " << stat << " " << t << endl;
        delete TopNode; // освободить память 
    }
    else
        return 0;
}

int menu() {
    string peremen;
    int option;
    do {
        cout << "1- добавление поезда " << endl;
        cout << "2 - Вывести элемент, 3 - выход " << endl;
        cout << "Ваш выбор = № ";
        cin >> peremen;
        option = atoi(peremen.c_str());
    } while (!option);
    return option;
}


int main()
{
    setlocale(LC_ALL, "russian");
    Train* spi = 0;
    Queue Q;
    while (true) {
        switch (menu()) {
        case 1:
            PushTail(Q, enter_train());
            break;
        case 2: Pop(Q); break;
            break;
        case 3: return 0;
        default: cout << " Надо вводить от 1 до 3  " << endl; break;
        }
    }
    return 0;
}

