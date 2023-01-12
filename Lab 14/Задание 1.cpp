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

struct Stack {
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

void Push(Stack &S, Train* sk) //Добавление элемента на вершину стека
{
    PTrain NewNode;
    NewNode = new Train; // создать новый узел...
    NewNode = sk; // и заполнить его данными
    NewNode->next = S.Head;
    NewNode->prev = NULL;
    if (S.Head) // добавить в начало списка
        S.Head->prev = NewNode;
    S.Head = NewNode;
    if (!S.Tail) S.Tail = S.Head;


}

//Получение верхнего элемента с вершины стека
//Функция Pop удаляет верхний элемент и возвращает его данные.
Train* Pop(Stack& S)
{
    PTrain TopNode = S.Head;
    if (TopNode != NULL)
    {
        int t_number = TopNode->train_number;
        string stat = TopNode->station;
        double t = TopNode->time;
        S.Head = TopNode->next;
        if (S.Head) S.Head->prev = NULL; // переставить ссылки
        else S.Tail = NULL;
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
        cout << "1- добавление поезда "<< endl;
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
    Stack S;
    while (true) {
        switch (menu()) {
        case 1:
            Push(S, enter_train());
            break;
        case 2: Pop(S); break;
            break;
        case 3: return 0;
        default: cout << " Надо вводить от 1 до 3  " << endl; break;
        }
    }
    return 0;
}

