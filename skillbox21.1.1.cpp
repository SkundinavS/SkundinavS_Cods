#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct pers {//вводим структуру, по которой будет происходить запись в файл
    string name;
    string surename;
    string date;
    int summ = 0;
};

int main()
{
    cout << "What kin of operation" << endl;
    string op;
    cin >> op;
    if (op == "add" || op == "Add") {
        fstream file,in;
        file.open("C:\\skillbox\\otchet.txt", ios::app);//открываем файл на запись
        string name1, surename1, date1;
        int summ1;
        cout << "Input name, surename, date and summ" << endl;
        cin >> name1 >> surename1 >> date1 >> summ1;
        pers man = { name1,surename1,date1,summ1 };
        if (file.is_open()) {//проверка на открытие, вроде открыавет
            file << name1 << " " << surename1 << " " << date1 << " " << summ1 << endl;
        }
        else {
            cerr << "error" << endl;
            return 1;
        }
        file.close();
    }
    else if (op == "list" || op == "List") {
        fstream in;
        in.open("C:\\skillbox\\otchet.txt");
        string line;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                cout << line << std::endl;
            }
        }
        else {
            cerr << "error" << endl;
            return 1;
        }
        in.close();
    }
}
