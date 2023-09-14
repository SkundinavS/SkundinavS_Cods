#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fish, box;
    fish.open("C:\\skillbox\\fish.txt");
    box.open("C:\\skillbox\\box.txt");
    while (true) {
        string nfish;
        cout << "What kind of fish you want to catch?" << endl;
        cin >> nfish;
        string ffish;
        while (!fish.eof()) {
            fish >> ffish;
            if (nfish == ffish) {
                box << ffish << endl;
            }
        }
        fish.seekg(0);
        if (nfish == "-1") {
            break;
        }
    }
    fish.close();
    box.close();
}
