#include <iostream>
#include <string>

using namespace std;

/*
    В заданный непустой текст входят только цифры и буквы. 
    Определить,удовлетворяет ли он следующему свойству:
    Текст начинается с некоторой ненулевой цифры, за которой следуют только буквы, 
    и их количество равно числовому значению цифры.
*/

bool test_text(string input)
{
    if (input.length() == 0) // В строке есть элементы
    {
        return false;
    }

    int one = (int)input[0] - (int)48;
    if (one <= 0 || one > 9) //Первый элемент больше 0 и число
    {
        return false;
    }

    string nums = "0123456789"; // В остальном тексте нет цифр. только буквы
    for (int i = 1; i < nums.length(); i++)
    {
        if (input.find(nums[i], 1) != string::npos)
        {
            return false;
        }
    }

    //количество букв равно числовому значению цифры.
    if ((input.length() - 1) != one)
    {
        return false;
    }

    return true;
}
int main()
{
    cout << "Введите строку: ";
    string x;
    getline(cin, x);

    cout << endl
         << "Исходная строка: " << x << endl;
    cout << (test_text(x) ? "Удобалетворяет" : "Не удобалетворяет") << endl;

    return 0;
}