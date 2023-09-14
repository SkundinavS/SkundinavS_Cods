#include <vector>
#include <iostream>
using namespace std;

class Branch {
    vector<string> homes;
public:
    void AddEldar() {
        while (true) {
            cout << "Input eldar's name" << endl;
            string elname;
            cin >> elname;
            if (elname != "None" && elname != "stop") {
                homes.push_back(elname);
            }
            if (elname == "stop") {
                break;
            }
        }
    }
    bool FindEldar(string name) {
        for (int i = 0; i < this->homes.size(); i++) {
            if (name == this->homes[i]) {
                return true;
            }
        }
        return false;
    }
    int GetNeibors() {
        return homes.size() - 1;
    }
};


int main()
{
    vector<vector<Branch>> tree;
    cout << "How many big branches on tree?" << endl;
    int bigtree;
    cin >> bigtree;
    for (int i = 0; i < bigtree; i++) {
        vector<Branch> bgbranch;
        tree.push_back(bgbranch);
    }
    for (int i = 0; i < bigtree; i++) {
        cout << "How many midle branches you want to add for " << i<< " big tree?" << endl;
        int count;
        cin >> count;
        for (int g = 0; g < count; g++) {
            Branch midbr;
            tree[i].push_back(midbr);
        }
    }
    while (true) {
        cout << "Input command" << endl;
        string com;
        cin >> com;
        if (com == "add") {
            int indi, indg;
            cout << "Input index of big branch" << endl;
            cin >> indi;
            cout << "Input index of midle branch" << endl;
            cin >> indg;
            if (indi > tree.size()-1) {
                cout << "Wrong index of big branch!!!" << endl;
            }
            else if (indg >= tree[indi].size()) {
                cout << "Wrong index of midle branch!!!" << endl;
            }
            else {
                tree[indi][indg].AddEldar();
            }
        }
        if (com == "find") {
            cout << "Input eldar's name" << endl;
            string name;
            cin >> name;
            for (int i = 0; i < tree.size(); i++) {
                bool check = false;
                for (int g = 0; g < tree[i].size(); g++) {
                    if (tree[i][g].FindEldar(name)) {
                        cout << "This eldar have " << tree[i][g].GetNeibors() << " neibors" << endl;
                        check = true;
                        break;
                    }
                }
                if (check) {
                    break;
                }
            }
        }
        if (com == "stop") {
            break;
        }
        if (com == "burn") {
            cout << "Eldar vilage was burned! For the Greater Good!!!" << endl;//Отсылка на вархаммер
            break;//Простите, нам не успели дать расписание пар в первую неделю, скучно! Развлекаюсь как могу
        }
    }
}
