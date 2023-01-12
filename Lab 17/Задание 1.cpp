#include <iostream>

using namespace std;

class Reagent {
protected:
    string name,color,status;
    double weight;
public:
    Reagent() {
        name = color = status = "";
        weight = 0.0;
    }

    Reagent(string name_x, double weight_x, string color_x, string status_x) : name(name_x), weight(weight_x), color(color_x), status(status_x) {
    }

    ~Reagent() {}

    void setComplex(string name_x, double weight_x, string color_x, string status_x) {
        name = name_x; //инициализация x
        weight = weight_x;
        color = color_x;
        status = status_x;
    }

    void GetComplex(string& _name, double& _weight, string& _color, string& _status)
    {
        _name = name;
        _weight = weight;
        _color = color;
        _status = status;
    }

    virtual void CoutComplex() {
        cout << "Наименование реагента =  " << name <<endl;
        cout << "Вес реагента =  " << weight << endl;
        cout << "Цвет реагента =  " << color << endl;
        cout << "Агрегатное состояние реагента =  " << status << endl;
    }

  /*  void InputComplex(string& _name, double& _weight, string& _color, string& _status) {
        cout << "Наименование реагента =  "; cin >> name;
        cout << "Вес реагента =  "; cin >> weight;
        cout << "Цвет реагента =  "; cin >> color;
        cout << "Агрегатное состояние реагента =  "; cin >> status;
    }*/

};

class Carbon : public Reagent {
protected:
    string form;
public:
    Carbon() {
        form = "";
    }

    Carbon(string name_x, double weight_x, string color_x, string status_x,string form_x) : Reagent(name_x, weight_x,color_x, status_x){
        form = form_x;
    }

    ~Carbon() {}
    //спецификатор override гарантирует, что эта функция является виртуальной, и переопределяет виртуальную функцию из базового класса.Если это не так, то в программе ошибка(при компиляции генерируется сообщение об ошибке).
    void CoutComplex() override
    {
        cout << "Название класса: Carbon " << endl;
        Reagent::CoutComplex();
        cout << "Форма кристалической решетки =  " << form << endl;
    }
};

class Iron : public Reagent {
protected:
    int clear;
public:
    Iron() {
        clear = 0;
    }

    Iron(string name_x, double weight_x, string color_x, string status_x,int clear_x) : Reagent(name_x, weight_x, color_x, status_x) {
        clear = clear_x;
    }

    ~Iron() {}

    void CoutComplex() override
    {
        cout << "Название класса: Iron " << endl;
        Reagent::CoutComplex();
        cout << "Чистота выработки руды  =  " << clear << endl;
    }
};

void CoutAll(Reagent &a, Carbon &b, Iron &c) {
    Reagent *mas[3];
    mas[0] = new Reagent(a);
    mas[1] = new Carbon(b);
    mas[2] = new Iron(c);
    for (int i = 0; i < 3; i++)
        mas[i]->CoutComplex();
}

int main()
{
    setlocale(LC_ALL, "rus");
    Reagent Element1("Reagent", 2.1, "Red", "Liquid");
    Carbon Element2("Carbon", 11.5, "Grey", "Solid", "List");
    Iron Element3("Iron", 30.1, "Black", "Hard", 12);
    cout << "Название класса: Reagent " << endl;
    CoutAll(Element1, Element2, Element3);
    return 0;
}

