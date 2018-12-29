#include <iostream>
#include <ctime>
#include <cmath>
#include <sstream>
#include "../include/rand.h"

using namespace std;

string sDet(int a, int b, int c)
{
     double p = (a + b + c) / 2;
     double s = sqrt(p * (p - a) * (p - b) * (p - c));
     std::ostringstream oss;
     oss << s;
     return "существует! Площадь: " + oss.str();
}

bool isDet(int a, int b, int c)
{
     return ((a + b > c && a + c > b && b + c > a) && (a > 0 && b > 0 && c > 0));
}

int main()
{
     srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

     //cout.precision(3); //Точность вывода переменных.

     // "вводим" переменные
     int a = rand(1, 10),
         b = rand(1, 10),
         c = rand(1, 10),
         d = rand(1, 10);

     cout << "Треугольник (" << a << ";" << b << ";" << c << ") - " << (isDet(a, b, c) ? sDet(a, b, c) : "не существует.") << endl;
     cout << "Треугольник (" << a << ";" << b << ";" << d << ") - " << (isDet(a, b, d) ? sDet(a, b, d) : "не существует.") << endl;
     cout << "Треугольник (" << b << ";" << c << ";" << d << ") - " << (isDet(b, c, d) ? sDet(b, c, d) : "не существует.") << endl;
     cout << "Треугольник (" << a << ";" << c << ";" << d << ") - " << (isDet(a, c, d) ? sDet(a, c, d) : "не существует.") << endl;

     return 0;
}

/*
Треугольник (8;7;1) - не существует.
Треугольник (8;7;4) - существует! Площадь: 9.48683
Треугольник (7;1;4) - не существует.
Треугольник (8;1;4) - не существует.
*/