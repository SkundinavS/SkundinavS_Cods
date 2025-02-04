#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <exception>
using namespace std;

class Fish : public exception {
    const char* what() const noexcept override {
        return "Fish!!!";
    }
};

class Boot : public exception {
    const char* what() const noexcept override {
        return "Boot!!!";
    }
};

class Space : public exception {
    const char* what() const noexcept override {
        return "There is nothing here";
    }
};

int main()
{
    vector<string> field;
    srand(time(nullptr));
    string f = "fish";
    string b = "boot";
    string space = "-";
    for (int i = 0; i < 9; i++) {
        field.push_back(space);
    }
    int ran = rand() % 9;
    field[ran] = f;
    for (int i = 0; i < 3; i++) {
        ran = rand() % 9;
        if (field[ran] == f || field[ran] == b) {
            i -= 1;
        }
        else {
            field[ran] = b;
        }
    }
    for (int i = 0; i < field.size(); i++) {
        cout << field[i] << " ";
    }
    cout << endl;
    while (true) {
        int fi = 0;
        cout << "Input number" << endl;
        cin >> fi;
        fi -= 1;
        try {
            if (field[fi] == f) {
                throw Fish();
            }
        }
        catch (const Fish& fh) {
            cerr << "You catch a fish" << endl;
            break;
        }
        try {
            if (field[fi] == b) {
                throw Boot();
            }
        }
        catch (const Boot& fh) {
            cerr << "You catch a boot" << endl;
            break;
        }
        if (field[fi] == space) {
            cout << "It's nothing here" << endl;
        }
    }
}