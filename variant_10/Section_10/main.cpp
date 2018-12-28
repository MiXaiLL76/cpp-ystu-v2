#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include "../include/matrix.h"
#include "../include/rand.h"

using namespace std;

string sDet(int a, int b, int c)
{
     return "Существует";
}

bool isDet(int a, int b, int c)
{
     return ((a + b > c || a + c > b || b + c > a) && (a > 0 && b > 0 && c > 0));
}

int main()
{
     srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

     cout.precision(3); //Точность вывода переменных.

     // "вводим" переменные
     int a = rand(1, 10),
         b = rand(1, 10),
         c = rand(1, 10),
         d = rand(1, 10);
     /*
     cout << "Треугольник (" << a << ";" << b << ";" << c << ") - " << (isDet(a, b, c) ? sDet(a, b, c) : "не существует.") << endl;
     cout << "Треугольник (" << a << ";" << b << ";" << d << ") - " << (isDet(a, b, d) ? sDet(a, b, d) : "не существует.") << endl;
     cout << "Треугольник (" << b << ";" << c << ";" << d << ") - " << (isDet(b, c, d) ? sDet(b, c, d) : "не существует.") << endl;
     cout << "Треугольник (" << a << ";" << c << ";" << d << ") - " << (isDet(a, c, d) ? sDet(a, c, d) : "не существует.") << endl;
*/
     a = 2;
     b = 4;
     c = 6;

     cout << "Треугольник (" << a << ";" << b << ";" << c << ") - " << (isDet(a, b, c) ? sDet(a, b, c) : "не существует.") << endl;
     cout << (a + b > c) << endl;
     cout << (a + c > b) << endl;
     cout << (b + c > a) << endl;
     return 0;
}
