#include <iostream>
#include "../include/any_func.h"

using namespace std;

int main()
{
    const string find = "б";
    const string rep = "ку";

    cout << "Программа заменит все '" << find << "' символом '" << rep << "'" << endl;
    cout << "Введите строку: ";
    string x;
    getline(cin, x);

    cout << "Исходная строка: " << x << endl;
    cout << "Итоговая строка: " << ReplaceAll(x, find, rep) << endl;

    return 0;
}

/*
Программа заменит все 'б' символом 'ку'
Введите строку: абв
Исходная строка: абв
Итоговая строка: акув
*/