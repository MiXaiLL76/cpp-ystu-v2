#include <iostream>
#include "../include/any_func.h"

using namespace std;

/*
    Написать программу, которая каждое встреченное сочетание 'аб' заменяет символом 'с'.
*/

int main()
{
    const string find = "аб";
    const string rep = "c";

    cout << "Программа заменит все '" << find << "' символом '" << rep << "'" << endl;
    cout << "Введите строку: ";
    string x;
    getline(cin, x);

    cout << "Исходная строка: " << x << endl;
    cout << "Итоговая строка: " << ReplaceAll(x, find, rep) << endl;

    return 0;
}
