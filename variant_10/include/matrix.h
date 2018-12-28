#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "rand.h"
using namespace std;

#define m_row std::vector<double>
#define matrix std::vector<m_row>

void generateMatrix(matrix &mat)
{
    if (mat.size() == 0)
    {
        return;
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int w = 0; w < mat[mat.size() - 1].size(); w++)
        {
            mat[i][w] = rand(0, 20) - 10;
        }
    }
}

void printMatrix(matrix &mat, string name = "")
{
    if (mat.size() != 0)
    {
        cout << "Матрица " << name << "(" << mat.size() << "x" << mat[mat.size() - 1].size() << "): " << endl;
        for (auto row : mat)
        {
            cout << "   ";
            for (auto coll : row)
            {
                cout << coll << "   ";
            }
            cout << endl;
        }
    }
}
matrix transposeMatrix(matrix mat)
{
    matrix tMat;

    if (mat.size() != 0)
    {
        int cells = mat[mat.size() - 1].size();
        tMat = matrix(cells, m_row(mat.size()));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int w = 0; w < cells; w++)
            {
                tMat[w][i] = mat[i][w];
            }
        }
    }
    return tMat;
}
bool isEqual(m_row x, m_row y)
{
    if (x.size() != y.size())
    {
        return false;
    }

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i])
        {
            return false;
        }
    }

    return true;
}

bool isSymmetryMatrix(matrix x)
{
    if (x.size() > 0 && x[x.size() - 1].size() == x.size())
    {
        matrix y = transposeMatrix(x);
        for (int i = 0; i < x.size(); i++)
        {
            if (!isEqual(x[i], y[i]))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
//desc = true сортирует по убыванию, по умолчанию.
matrix rowSort(matrix x, bool desc = true)
{
    matrix sortMat = x;
    for (int i = 0; i < sortMat.size(); i++)
    {
        std::sort(sortMat[i].rbegin(), sortMat[i].rend());
        if (desc)
        {
            std::reverse(sortMat[i].begin(), sortMat[i].end());
        }
    }
    return sortMat;
}
matrix columnSort(matrix x, bool desc = true)
{
    return transposeMatrix(rowSort(transposeMatrix(x), desc));
}

matrix multiplyMatrix(matrix x, matrix y)
{
    matrix pMat;
    if (x.size() != 0)
    {
        if (x[x.size() - 1].size() == y.size() && y[y.size() - 1].size() == x.size())
        {
            pMat = matrix(x.size(), m_row(x.size()));
            int cells = x[x.size() - 1].size();

            for (int i = 0; i < x.size(); i++)
            {
                for (int w = 0; w < x.size(); w++)
                {
                    double val = 0;
                    for (int l = 0; l < cells; l++)
                    {
                        val += x[i][l] * y[l][w];
                    }
                    pMat[i][w] = val;
                }
            }
        }
    }

    return pMat;
}
#endif