#include <iostream>
using namespace std;

class complex {
private:
    double x,y;   
public:
    
    //complex(complex& ref_Point) { // конструктор копирования
    //        // копирование данных из одного объекта в другой
    //        this->x = ref_Point.x;
    //        this->y = ref_Point.y;
    //}

    complex(double number_x = 0, double number_y = 0) : x(number_x), y(number_y) { // конструктор с параметрами
    }

    void setComplex(double number_x, double number_y) {
        x = number_x; //инициализация x
        y = number_y;
    }

    void GetComplex(double& _x, double& _y)
    {
        _x = x;
        _y = y;
    }
    
    void CoutComplex() {
        cout << x << (y>0?"+":"") << y << "i. " << endl;
    }
    
    void InputComplex() {
        cout << "Введите действительную часть числа = "; cin >> x;
        cout << "Введите мнимую часть числа = "; cin >> y;
    }
    complex sum(complex &First, complex &Second) {
         complex Otvet = First + Second;
         return Otvet;
    }
    complex raz(complex& First, complex& Second) {
            complex Otvet = First - Second;
            return Otvet;
    }
    complex proiz(complex& First, complex& Second) {
        complex Otvet = First * Second;
        return Otvet;
    }
        
    double modul() {
        double r;
        r = sqrt((x * x) + (y * y));
        return r;
    }

    complex operator+ (complex& f)
    {
        return complex(this->x + f.x, this->y+f.y);
    }
    complex operator- (complex& f)
    {
        return complex(this->x - f.x, this->y - f.y);
    }
    complex operator* (complex& f)
    {
        return complex(this->x * f.x-this->y*f.y, this->x * f.y + this->x * f.y);
    }

};

//перегрузка операторов
int menu() {
    string peremen;
    int option;
    do {
        cout << "1 - Сложение двух комплексных чисел " << endl;
        cout << "2 - Разность двух комплексных чисел, 3 - Умножение двух комплексных чисел , 4 - Модуль комплексного числа, 5 - Выход" << endl;
        cout << "Ваш выбор = № ";
        cin >> option;
    } while (!option);
    return option;
}
void Enter(complex &a, complex& b) {
    cout << "Введите первое комплексное число : " << endl;
    a.InputComplex();
    cout << "Введите второе комплексное число : " << endl;
    b.InputComplex();
}


int main()
{
    setlocale(LC_ALL, "rus");
    double x, y;
    complex First(1,1),Second(1,1), Otvet(1, 1);
    while (true) {
        switch (menu()) {
        case 1:
        {
            Enter(First, Second);
            Otvet = Otvet.sum(First, Second);
            Otvet.CoutComplex();
            break;
        }
        case 2:
        {
            Enter(First, Second);
            Otvet = Otvet.raz(First, Second);
            Otvet.CoutComplex();
            break;
        }
        case 3:
        {
            Enter(First, Second);
            Otvet = Otvet.proiz(First, Second);
            Otvet.CoutComplex();
            break;
        }
        case 4:
        {
            cout << "Введите комплексное число : " << endl;
            First.InputComplex();
            cout<<"Модуль введенного комплексного числа = "<< First.modul() <<endl;
            break;
        }

        case 5: {cout << "Выход из программы ... ";  return 0; }
        default: cout << " Надо вводить от 1 до 4  " << endl; break;
        }
    }
    return 0;
}
