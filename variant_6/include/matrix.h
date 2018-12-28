#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <vector>
#include "rand.h"
using namespace std;

#define m_row std::vector<double>
#define matrix std::vector<m_row>

void generateMatrix(matrix &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int w = 0; w < mat.size(); w++)
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