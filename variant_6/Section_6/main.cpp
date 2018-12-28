#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include "../include/matrix.h"
#include "../include/rand.h"

using namespace std;

/*
    Дана матрица А(NxN).
    Написать программу, которая упорядочивает элементы каждого столбца этой матрицы по убыванию
*/

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

    cout.precision(3); //Точность вывода переменных.

    // "вводим" переменные
    int n = rand(2, 5); //Длинна N для матрицы

    auto A = matrix(n, m_row(n)); // Создание переменной матрицы. я объявил эти типы ранее
    generateMatrix(A);            // Заполнение матрицы
    printMatrix(A, "A");          // Вывод матрицы.

    auto At = columnSort(A);                                           // Сортировка
    printMatrix(At, "Сортированная по столбцам и убыванию матрица A"); // Вывод матрицы.

    return 0;
}
