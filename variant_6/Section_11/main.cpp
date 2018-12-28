#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
     std::string line,
         line_nums,
         file = "input.txt",
         nums = "0123456789";

     cout << "Читаем строку из файла: " << file << endl;
     std::ifstream in(file); // окрываем файл для чтения
     if (in.is_open())
     {
          while (getline(in, line))
          {
               for (int i = 1; i < line.length(); i++)
               {
                    for (int w = 1; w < nums.length(); w++)
                    {
                         if (line[i] == nums[w])
                         {
                              line_nums += line[i];
                              line_nums += ";";
                         }
                    }
               }
          }
     }
     in.close(); // закрываем файл
     cout << "Исходная строка: " << line_nums << endl;

     std::stringstream line_out;
     double y[line_nums.length()];
     for (int i = 0; i < line_nums.length(); i++)
     {
          int x = (int)line_nums[i] - (int)48;
          y[i] = (pow(x, 2) + 1) / (pow(x, 3) + 2);
          line_out << y[i] << ";";
     }
     cout << "Итоговая строка: " << line_out.str() << endl;

     std::ofstream out;
     out.open("out_" + file);
     if (out.is_open())
     {
          out << line_out.str();
     }
     out.close();
     cout << "Файл "
          << "out_" + file << " сформирован." << endl;
     return 0;
}
