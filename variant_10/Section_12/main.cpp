#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

class school
{
   private:
     string db_file;
     vector<vector<string>> lessons;
     int max_length = 10;

   public:
     vector<vector<string>> getlessons();
     school(string db_file);
     void get_lengthM(vector<string> lesson);
     void print(string kab = "*");
     string add_space(string in, int max);
     bool addlesson(string time, string class_, string predmet, string cabinet, string prepod);
};
void school::get_lengthM(vector<string> lesson)
{
     for (auto s : lesson)
     {
          float length = 0;

          for (int i = 0; i < s.length(); i++)
          {
               if (static_cast<int>(s[i]) < 0)
               {
                    length += 0.5f;
               }
               else
               {
                    length += 1.0f;
               }
          }
          if (length > this->max_length)
          {
               this->max_length = (int)length + 1;
          }
     }
}
//(номер урока, время начала урока, класс, предмет, номер кабинета).
bool school::addlesson(string time, string class_, string predmet, string cabinet, string prepod)
{
     vector<string> lesson;
     lesson.push_back(time);
     lesson.push_back(class_);
     lesson.push_back(cabinet);
     lesson.push_back(prepod);
     this->lessons.push_back(lesson);
     this->get_lengthM(lesson);

     ofstream out(this->db_file, ios_base::app);
     if (out.is_open())
     {
          ostringstream oss;
          if (!lesson.empty())
          {
               std::copy(lesson.begin(), lesson.end() - 1,
                         std::ostream_iterator<string>(oss, ","));
               oss << lesson.back();
               out << oss.str() << endl;
          }
     }
     out.close();
}

vector<vector<string>> school::getlessons()
{
     return this->lessons;
}

string school::add_space(string in, int max)
{

     float length = 0;

     for (int i = 0; i < in.length(); i++)
     {
          if (static_cast<int>(in[i]) < 0)
          {
               length += 0.5f;
          }
          else
          {
               length += 1.0f;
          }
     }
     //cout << " - " << in << endl;

     while (length < max)
     {
          in += " ";
          length += 1.0f;
     }
     return " " + in + " ";
}

void school::print(string kab)
{
     for (int i = 0; i < (this->max_length + 2) * 6; i++)
     {
          cout << "_";
     }
     cout << endl;

     //(номер урока, время начала урока, класс, предмет, номер кабинета).
     cout << this->add_space("Номер урока", this->max_length) << "|"
          << this->add_space("Время начала урока", this->max_length) << "|"
          << this->add_space("Класс", this->max_length) << "|"
          << this->add_space("Предмет", this->max_length) << "|"
          << this->add_space("№ Кабинета", this->max_length) << endl;

     for (int i = 0; i < (this->max_length + 2) * 6; i++)
     {
          cout << "-";
     }
     cout << endl;

     int printed = 0;
     int num = 0;
     for (auto lesson : this->lessons)
     {
          if (lesson[3].find(kab) == std::string::npos && kab != "*")
          {
               continue;
          }
          printed++;

          ostringstream oss;
          num++;
          oss << num;

          cout << this->add_space(oss.str(), this->max_length) << "|"
               << this->add_space(lesson[0], this->max_length) << "|"
               << this->add_space(lesson[1], this->max_length) << "|"
               << this->add_space(lesson[2], this->max_length) << "|"
               << this->add_space(lesson[3], this->max_length) << endl;
     }
     if (printed == 0)
     {
          cout << "Уроки не найдены.";
     }
     cout << endl
          << endl;
}

school::school(string db_file) : db_file(db_file)
{
     string line;
     std::ifstream in(db_file); // окрываем файл для чтения
     if (in.is_open())
     {
          while (getline(in, line))
          {
               vector<string> lesson;
               while (line.find(',') != std::string::npos)
               {
                    lesson.push_back(line.substr(0, line.find(',')));
                    line.erase(0, line.find(',') + 1);
               }
               if (lesson.size() > 0)
               {
                    for (int i = 0; i < 5 - lesson.size(); i++)
                    {
                         lesson.push_back("");
                    }
                    this->lessons.push_back(lesson);
                    this->get_lengthM(lesson);
               }
          }
     }
}

int main()
{
     school lessons_lib("db.dat");

     stringstream info;
     info << "Рассписание учителя." << endl
          << "Чтобы выйти введите 'q'" << endl
          << "Чтобы добавить урок введите 'a'" << endl
          << "Для вывода всех уроков введите 'p'" << endl
          << "Для поиска по кабинету введите 'f'" << endl
          << ">> ";

     string input_line;
     while (1)
     {
          cout << info.str();
          getline(cin, input_line);

          if (input_line == "q")
          {
               break;
          }
          else if (input_line == "a")
          {
               string time, class_, predmet, cabinet, prepod;
               cout << "Введите время урока:";
               getline(cin, time);

               cout << "Введите класс:";
               getline(cin, class_);

               cout << "Введите предмет:";
               getline(cin, predmet);

               cout << "Введите кабинеты:";
               getline(cin, cabinet);

               cout << "Введите имя учителя:";
               getline(cin, prepod);
               lessons_lib.addlesson(time, class_, predmet, cabinet, prepod);
          }
          else if (input_line == "p")
          {
               if (lessons_lib.getlessons().size() == 0)
               {
                    cout << endl
                         << ">       Рассписание пусто." << endl;
               }
               else
               {
                    lessons_lib.print();
               }
               cin;
          }
          else if (input_line == "f")
          {
               string kab;

               cout << "Введите кабинет:";
               getline(cin, kab);

               if (lessons_lib.getlessons().size() == 0)
               {
                    cout << endl
                         << ">       Рассписание пусто." << endl;
               }
               else
               {
                    lessons_lib.print(kab);
               }
               cin;
          }
     }

     return 0;
}

/*
Рассписание учителя.
Чтобы выйти введите 'q'
Чтобы добавить урок введите 'a'
Для вывода всех уроков введите 'p'
Для поиска по кабинету введите 'f'
>> p
________________________________________________________________________
 Номер урока | Время начала урока | Класс      | Предмет    | № Кабинета
------------------------------------------------------------------------
 1          | 2          | 2b         | 402        | Михаил

*/

/*
Рассписание учителя.
Чтобы выйти введите 'q'
Чтобы добавить урок введите 'a'
Для вывода всех уроков введите 'p'
Для поиска по кабинету введите 'f'
>> a
Введите время урока:2
Введите класс:2b
Введите предмет:Математика
Введите кабинеты:402
Введите имя учителя:Михаил
*/