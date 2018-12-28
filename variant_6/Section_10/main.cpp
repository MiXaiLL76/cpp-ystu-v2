#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include "../include/matrix.h"
#include "../include/rand.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //Делаем переобновление случайных значений

    cout.precision(3); //Точность вывода переменных.

    auto A = matrix(2, m_row(2));
    generateMatrix(A);
    printMatrix(A, "A");
    cout << "Матрица " << (isSymmetryMatrix(A) ? "симметрична." : "не симметрична") << endl
         << endl;

    auto B = matrix(3, m_row(3));
    generateMatrix(B);
    B = {{1, 2, 1},
         {2, 2, 2},
         {1, 2, 1}};

    printMatrix(B, "B");
    cout << "Матрица " << (isSymmetryMatrix(B) ? "симметрична." : "не симметрична") << endl
         << endl;

    auto C = matrix(4, m_row(4));
    generateMatrix(C);
    printMatrix(C, "C");
    cout << "Матрица " << (isSymmetryMatrix(C) ? "симметрична." : "не симметрична") << endl
         << endl;

    return 0;
}
