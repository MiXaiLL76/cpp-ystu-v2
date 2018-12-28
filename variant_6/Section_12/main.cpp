#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

class biblio
{
   private:
     string db_file;
     vector<vector<string>> books;
     int max_length = 10;

   public:
     vector<vector<string>> getBooks();
     biblio(string db_file);
     void get_lengthM(vector<string> book);
     void print(string autor = "*");
     string add_space(string in, int max);
     bool addBook(string autor, string name, string izdatel, string year, string price);
};
void biblio::get_lengthM(vector<string> book)
{
     for (auto s : book)
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

bool biblio::addBook(string autor, string name, string izdatel, string year, string price)
{
     vector<string> book;
     book.push_back(autor);
     book.push_back(name);
     book.push_back(izdatel);
     book.push_back(year);
     book.push_back(price);
     this->books.push_back(book);
     this->get_lengthM(book);

     ofstream out(this->db_file, ios_base::app);
     if (out.is_open())
     {
          ostringstream oss;
          if (!book.empty())
          {
               std::copy(book.begin(), book.end() - 1,
                         std::ostream_iterator<string>(oss, ","));
               oss << book.back();
               out << oss.str() << endl;
          }
     }
     out.close();
}

vector<vector<string>> biblio::getBooks()
{
     return this->books;
}

string biblio::add_space(string in, int max)
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

void biblio::print(string autor)
{
     for (int i = 0; i < (this->max_length + 2) * 6; i++)
     {
          cout << "_";
     }
     cout << endl;

     cout << this->add_space("Автор", this->max_length) << "|"
          << this->add_space("Название книги", this->max_length) << "|"
          << this->add_space("Издательство", this->max_length) << "|"
          << this->add_space("Год", this->max_length) << "|"
          << this->add_space("Цена", this->max_length) << endl;

     for (int i = 0; i < (this->max_length + 2) * 6; i++)
     {
          cout << "-";
     }
     cout << endl;

     int printed = 0;
     for (auto book : this->books)
     {
          if (book[0].find(autor) == std::string::npos && autor != "*")
          {
               continue;
          }
          printed++;
          cout << this->add_space(book[0], this->max_length) << "|"
               << this->add_space(book[1], this->max_length) << "|"
               << this->add_space(book[2], this->max_length) << "|"
               << this->add_space(book[3], this->max_length) << "|"
               << this->add_space(book[4], this->max_length) << endl;
     }
     if (printed == 0)
     {
          cout << "Книги не найдены.";
     }
     cout << endl
          << endl;
}

biblio::biblio(string db_file) : db_file(db_file)
{
     string line;
     std::ifstream in(db_file); // окрываем файл для чтения
     if (in.is_open())
     {
          while (getline(in, line))
          {
               vector<string> book;
               while (line.find(',') != std::string::npos)
               {
                    book.push_back(line.substr(0, line.find(',')));
                    line.erase(0, line.find(',') + 1);
               }
               if (book.size() > 0)
               {
                    for (int i = 0; i < 5 - book.size(); i++)
                    {
                         book.push_back("");
                    }
                    this->books.push_back(book);
                    this->get_lengthM(book);
               }
          }
     }
}

int main()
{
     biblio books_lib("db.dat");

     stringstream info;
     info << "Домашняя библиотека." << endl
          << "Чтобы выйти введите 'q'" << endl
          << "Чтобы добавить книгу введите 'a'" << endl
          << "Для вывода всех книг введите 'p'" << endl
          << "Для вывода всех книг по автору введите 'f'" << endl
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
               string autor, name, izdatel, year, price;
               cout << "Введите название книги:";
               getline(cin, name);

               cout << "Введите автора книги:";
               getline(cin, autor);

               cout << "Введите издательство книги:";
               getline(cin, izdatel);

               cout << "Введите год написания книги:";
               getline(cin, year);

               cout << "Введите цену книги:";
               getline(cin, price);
               books_lib.addBook(autor, name, izdatel, year, price);
          }
          else if (input_line == "p")
          {
               if (books_lib.getBooks().size() == 0)
               {
                    cout << endl
                         << ">       Библиотека пуста." << endl;
               }
               else
               {
                    books_lib.print();
               }
               cin;
          }
          else if (input_line == "f")
          {
               string autor;

               cout << "Введите автора книги:";
               getline(cin, autor);

               if (books_lib.getBooks().size() == 0)
               {
                    cout << endl
                         << ">       Библиотека пуста." << endl;
               }
               else
               {
                    books_lib.print(autor);
               }
               cin;
          }
     }

     return 0;
}
