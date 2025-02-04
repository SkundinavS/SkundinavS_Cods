#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<int, vector<string>> add(map<int, vector<string>> reestr) {
    int ind = 0; 
    string name;
    cout << "Input arcticul and name" << endl;
    cin >> ind >> name;
    bool check = true;
    for (auto iter = reestr.begin(); iter != reestr.end(); iter++) {
        if (ind == iter->first) {
            iter->second.push_back(name);
            check = false;
            break;
        }
    }
    if (check) {
        vector<string> names;
        names.push_back(name);
        reestr.insert({ ind, names });
    }
    return reestr;
}

map<int, vector<string>> remove(map<int, vector<string>> reestr) {
    int ind = 0;
    cout << "Input index" << endl;
    cin >> ind;
    reestr.erase(ind);
    return reestr;
}

void find(map<int, vector<string>> reestr) {
    int ind = 0;
    cout << "Input index" << endl;
    cin >> ind;
    cout << ind << ": ";
    for (auto iter = reestr.begin(); iter != reestr.end(); iter++) {
        if (iter->first == ind) {
            for (int i = 0; i < iter->second.size(); i++) {
                cout << iter->second[i] << endl;
            }
        }
    }
    cout << endl;
}


int main()
{
    map<int,vector<string>> reestr;
    int ind = 0;
    while (true) {
        string com;
        cout << "Input comand" << endl;
        cin >> com;
        if (com == "add") {
            reestr = add(reestr);
        }
        if (com == "remove") {
            reestr = remove(reestr);
        }
        if (com == "print") {
            for (auto iter = reestr.begin(); iter != reestr.end(); iter++) {
                cout << iter->first << endl;
                for (int i = 0; i < iter->second.size(); i++) {
                    cout << iter->second[i] << endl;
                }
                cout << endl;
            }
        }
        if (com == "find") {
            find(reestr);
        }
        if (com == "stop") {
            break;
        }
    }
}