#include <iostream>
#include <cmath>
#include <ctime>
#include "../include/rand.h"

using namespace std;

//http://www.cyberforum.ru/cpp-beginners/thread257973.html
double FF(int a)
{
    double r = 1;
    if (a % 2 == 0)
    {

        for (int i = 2; i <= a; i += 2)
        {
            r *= i;
        }
    }
    else
    {
        for (int i = 1; i <= a; i += 2)
        {
            r *= i;
        }
    }
    return r;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

    cout.precision(3); //Точность вывода переменных.

    // "вводим" переменные
    int a = rand(1, 5),
        b = rand(1, 5),
        c = rand(1, 5);
    //Вывод их пользователю
    cout << "a: " << a << endl
         << "b: " << b << endl
         << "c:  " << c << endl
         << endl;

    cout << "Итог: " << ((FF(a) - a * b) / (FF(a) + a * b)) << endl;
    return 0;
}

/*
a: 3
b: 4
c:  2

Итог: -0.6
*/

/*
a: 4
b: 1
c:  3

Итог: 0.333
*/