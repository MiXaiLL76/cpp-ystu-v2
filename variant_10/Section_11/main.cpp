#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

double GeoMean(std::vector<double> x)
{
     double res = 1.;
     for (double var : x)
     {
          res *= var;
     }
     return pow(res, 1.0 / x.size());
}

int main()
{
     std::vector<double> list;

     std::string line,
         file = "input.txt";

     cout << "Читаем строки из файла: " << file << endl;
     std::ifstream in(file); // окрываем файл для чтения
     if (in.is_open())
     {
          while (getline(in, line))
          {
               double var = atof(line.c_str());
               if (var > 0)
               {
                    list.push_back(var);
                    cout << "   >   " << var << endl;
               }
          }
     }
     in.close(); // закрываем файл
     cout << "Среднее геометрическое: " << GeoMean(list) << endl;
     return 0;
}

/*
Читаем строки из файла: input.txt
   >   0.5
   >   5.8
   >   5.882
   >   0.99
Среднее геометрическое: 2.02717
*/