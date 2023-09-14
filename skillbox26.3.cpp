#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class Monitor {
private:
    vector<vector<int>> mon;
    int x1,x2;
    int y1,y2;
public:
    void null() {
        for (int i = 0; i < 50; i++) {
            for (int g = 0; g < 80; g++) {
                mon[i][g] = 0;
            }
        }
    }
    void creat() {
        for (int i = 0; i < 50; i++) {
            vector<int> str;
            for (int g = 0; g < 80; g++) {
                str.push_back(0);
            }
            mon.push_back(str);
        }
        while (true) {
            cout << "Input start cords" << endl;
            cin >> x1 >> y1;
            cout << "Input finish cords" << endl;
            cin >> x2 >> y2;
            if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
                cout << "Wrong input!!!" << endl;
            }
            else {
                break;
            }
        }
        for (int i = y1; i < y2; i++) {
            for (int g = x1; g < x2; g++) {
                mon[i][g] = 1;
            }
        }
    }
    void crwin() {
        int x3, y3, x4, y4;
        cout << "Input start cords" << endl;
        cin >> x3 >> y3;
        int dif1 = x1 - x3;
        int dif2 = y1 - y3;
        x4 = x2 - dif1;
        y4 = y2 - dif2;
        for (int i = y3; i < y4; i++) {
            for (int g = x3; g < x4; g++) {
                mon[i][g] = 1;
            }
        }
    }
    void dis() {
        for (int i = 0; i < 50; i++) {
            for (int g = 0; g < 80; g++) {
                cout << mon[i][g];
            }
            cout << endl;
        }
    }
    void res() {
        while (true) {
            cout << "Input start cords" << endl;
            cin >> x1 >> y1;
            cout << "Input finish cords" << endl;
            cin >> x2 >> y2;
            if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
                cout << "Wrong input!!!" << endl;
            }
            else {
                break;
            }
        }
        for (int i = y1; i < y2; i++) {
            for (int g = x1; g < x2; g++) {
                mon[i][g] = 1;
            }
        }
    }
};

class Window {
private:
    Monitor mon;
public:
    void open() {
        mon.creat();
    }
    void move() {
        mon.null();
        mon.crwin();
    }
    void display() {
        mon.dis();
    }
    void resize() {
        mon.null();
        mon.res();
    }
};

int main()
{
    Window win;
    win.open();
    string com;
    while (true) {
        cout << "Input command" << endl;
        cin >> com;
        if (com == "move") {
            win.move();
        }
        else if (com == "resize") {
            win.resize();
        }
        else if (com == "display") {
            win.display();
        }
        else if (com == "close") {
            break;
        }
        else {
            cout << "wrong input!!!" << endl;
        }
    }
}
