#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("C:\\skillbox\\input.txt");
    while (true) {
        string name, surename, date;
        int money = 0;
        cin >> name;
        if (name == "-1") {
            break;
        }
        cin >> surename >> date >> money;
        file << name << " " << surename << " " << date << " " << money << endl;
    }
    file.close();
}
