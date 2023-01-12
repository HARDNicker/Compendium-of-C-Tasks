#include <iostream>

using namespace std;

class Reagent {
protected:
    virtual string name() = 0;
    virtual string color() = 0;
    virtual string status() = 0;
    virtual double weight() = 0;
public:
    ~Reagent();
    virtual void CoutComplex() = 0;

    //virtual void setComplex(string name_x, double weight_x, string color_x, string status_x) {
    //    name() = name_x; //инициализация x
    //    weight() = weight_x;
    //    color() = color_x;
    //    status() = status_x;
    //}

    //virtual void GetComplex(string& _name, double& _weight, string& _color, string& _status)
    //{
    //    _name = name();
    //    _weight = weight();
    //    _color = color();
    //    _status = status();
    //}
};

class Carbon : public Reagent {
protected:
    string name() { return "Carbon"; }
    string color() { return "Grey"; }
    string status() { return "Solid"; }
    double weight() { return 11.5; }
    string form() { return "List"; }
public:
    Carbon() : Reagent() {};
    ~Carbon(){};
    //спецификатор override гарантирует, что эта функция является виртуальной, и переопределяет виртуальную функцию из базового класса.Если это не так, то в программе ошибка(при компиляции генерируется сообщение об ошибке).
   void CoutComplex() override {
            cout << "Название класса: Carbon " << endl;
            cout << "Наименование реагента =  " << name() << endl;
            cout << "Вес реагента =  " << weight() << endl;
            cout << "Цвет реагента =  " << color() << endl;
            cout << "Агрегатное состояние реагента =  " << status() << endl;
            cout << "Форма кристалической решетки =  " << form() << endl;
    }
};

class Iron : public Reagent{
protected:
    string name() { return "Iron"; }
    string color() { return "Black"; }
    string status() { return "Hard"; }
    double weight() { return 30.1; }
    int clear() { return 12; }
public:
    Iron() : Reagent() {};
    ~Iron() {};
    void CoutComplex() override {
        cout << "Название класса: Iron" << endl;
        cout << "Наименование реагента =  " << name() << endl;
        cout << "Вес реагента =  " << weight() << endl;
        cout << "Цвет реагента =  " << color() << endl;
        cout << "Агрегатное состояние реагента =  " << status() << endl;
        cout << "Чистота выработки руды  = " << clear() << endl;
    }
};




int main()
{
    setlocale(LC_ALL, "rus");
    Carbon* k = new Carbon();
    Iron* p = new Iron();
    Reagent* mas[2];
    mas[0] = k;
    mas[1] = p;
    for (int i = 0; i < 2; i++)
        mas[i]->CoutComplex();
    return 0;
}

