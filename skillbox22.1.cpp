#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, string> phonebook;
    map<string, string> surename;
    for (int i = 0; true; i++) {
        string op,num,sur;
        cout << "If you want to add newbie input 1" << endl;
        cout << "If you want to collect surename input 2" << endl;
        cout << "If you want to collect number input 3" << endl;
        cout << "If you want to stop program input -1" << endl;
        cin >> op;
        if (op == "-1") {
            break;
        }
        else if (op == "1") {
            cout << "Input surename and number" << endl;
            cin >> sur >> num;
            phonebook.insert(make_pair(num, sur));
            surename.insert(make_pair(sur, num));
        }
        else if (op == "2") {
            cout << "Input number" << endl;
            cin >> num;
            cout << "Surename:" << phonebook[num] << endl;
        }
        else if (op == "3") {
            cout << "Input surename" << endl;
            cin >> sur;
            cout << "Number:" << surename[sur] << endl;
        }
        else {
            cout << "Wrong input" << endl;
        }
    }
}
