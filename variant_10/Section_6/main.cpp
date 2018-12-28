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

    // "вводим" переменные
    int n = rand(2, 5); //Длинна N для матрицы

    auto A = matrix(n, m_row(n)); // Создание переменной матрицы. я объявил эти типы ранее
    generateMatrix(A);            // Заполнение матрицы
    printMatrix(A, "A");          // Вывод матрицы.

    int max_sum,
        max_i;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int w = 0; w < n; w++)
        {
            sum += A[i][w];
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            max_i = i;
        }
    }
    cout << "Строка с максимальной суммой элементов: " << max_i << endl;

    return 0;
}

/*
Матрица A(2x2):
   7.15   9.47
   2.35   -9.17
Строка с максимальной суммой элементов: 0
*/

/*
Матрица A(4x4):
   1.22   0.242   -4.58   -9.95
   0.561   -7.52   4.89   -8.73
   8.05   -9.6   4.8   3.5
   -3.18   4.88   -0.295   3.1
Строка с максимальной суммой элементов: 2
*/