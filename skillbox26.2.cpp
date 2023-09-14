#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class Phone {
private:
    vector<vector<string>> a;
public:
    void add() {
        vector<string> cont;
        cout << "Input name of contact" << endl;
        string name;
        cin >> name;
        cont.push_back(name);
        string num;
        cout << "Input number" << endl;
        cin >> num;
        while (true) {
            if (num.length() == 12 && num[0] == '+' && num[1] == '7') {
                cont.push_back(num);
                break;
            }
            else {
                num = "";
                cout << "Wrong number! Input right number" << endl;
                cin >> num;
            }
        }
        a.push_back(cont);
        cout << "Contact added" << endl;
    }
    void call() {
        string com;
        cout << "Input name or number of contact" << endl;
        cin >> com;
        bool check = false;
        for (int i = 0; i < a.size(); i++) {
            bool b = false;
            for (int g = 0; g < 2; g++) {
                if (a[i][g] == com) {
                    check = true;
                    b = true;
                    break;
                }
            }
            if (b) {
                break;
            }
        }
        if (check) {
            cout << "CALL CALL CALL" << endl;
        }
        else {
            cout << "Contact not found" << endl;
        }
    }
    void sms() {
        string com;
        cout << "Input name or number of contact" << endl;
        cin >> com;
        bool check = false;
        for (int i = 0; i < a.size(); i++) {
            bool b = false;
            for (int g = 0; g < 2; g++) {
                if (a[i][g] == com) {
                    check = true;
                    b = true;
                    break;
                }
            }
            if (b) {
                break;
            }
        }
        if (check) {
            string mes;
            cout << "Text message for contant" << endl;
            cin >> mes;
            cout << "Message has been sent" << endl;
        }
        else {
            cout << "Contact not found" << endl;
        }
    }
};

int main()
{
    Phone real;
    while (true) {
        string com;
        cout << "Input command for phone" << endl;
        cin >> com;
        if (com == "add") {
            real.add();
        }
        else if (com == "call") {
            real.call();
        }
        else if (com == "sms") {
            real.sms();
        }
        else if (com == "exit") {
            break;
        }
        else {
            cout << "Wrong command" << endl;
        }
    }
}
