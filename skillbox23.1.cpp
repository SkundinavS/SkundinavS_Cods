#include <iostream>
using namespace std;

#define mondey 1
#define tuesday 2
#define wednesday 3
#define thursday 4
#define friday 5
#define saturday 6
#define sunday 7

int main()
{
    int op;
    cout << "What day of the week is it today?" << endl;
    cin >> op;
    if (op == mondey) {
        cout << "mondey is now" << endl;
    }
    if (op == tuesday) {
        cout << "tuesday is now" << endl;
    }
    if (op == wednesday) {
        cout << "wednesday is now" << endl;
    }
    if (op == thursday) {
        cout << "thursday is now" << endl;
    }
    if (op == friday) {
        cout << "friday is now" << endl;
    }
    if (op == saturday) {
        cout << "saturday is now" << endl;
    }
    if (op == sunday) {
        cout << "sunday is now" << endl;
    }
}
