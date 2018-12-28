#include <iostream>
#include <cmath>
#include <ctime>
#include "../include/rand.h"

using namespace std;

//http://www.cyberforum.ru/cpp-beginners/thread257973.html
int NOD(int a, int b)
{
    int t;
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

    cout.precision(3); //Точность вывода переменных.

    // "вводим" переменные
    int a = rand(1, 100),
        b = rand(1, 100),
        c = rand(1, 100);
    //Вывод их пользователю
    cout << "a: " << a << endl
         << "b: " << b << endl
         << "c:  " << c << endl
         << endl;

    cout << "NOD(a, b, c) = NOD(NOD(a, b), c) = " << NOD(NOD(a, b), c) << endl;
    return 0;
}
