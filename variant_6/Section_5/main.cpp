#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include "../include/matrix.h"
#include "../include/rand.h"

using namespace std;

/*
    Дана матрица А(nnxn). Написать программу нахождения матрицы Ат*А, где Ат - транспонированная матрица.
*/
int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

    cout.precision(3); //Точность вывода переменных.

    // "вводим" переменные
    int n = rand(2, 5); //Длинна N для матрицы

    auto A = matrix(n, m_row(n)); // Создание переменной матрицы. я объявил эти типы ранее
    generateMatrix(A);            // Заполнение матрицы

    printMatrix(A, "A"); // Вывод матрицы.

    auto At = transposeMatrix(A);                    // Транспонирование
    printMatrix(At, "Транспонированная матрица At"); // Вывод матрицы.

    auto At_A = multiplyMatrix(At, A);
    printMatrix(At_A, "Ат*А"); // Вывод матрицы.

    return 0;
}
