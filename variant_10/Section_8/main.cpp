#include <iostream>
#include <string>

using namespace std;

bool test_text(string input)
{
    if (input.length() == 0) // В строке есть элементы
    {
        return false;
    }

    string nums = "0123456789";
    return nums.find(input, 0) != string::npos;
}

int main()
{
    cout << "Введите строку: ";
    string x;
    getline(cin, x);

    cout << "Исходная строка: " << x << endl;
    cout << (test_text(x) ? "Удобалетворяет" : "Не удобалетворяет") << endl;

    return 0;
}

/*
Введите строку: 123
Исходная строка: 123
Удобалетворяет
*/

/*
Введите строку: 312
Исходная строка: 312
Не удобалетворяет
*/