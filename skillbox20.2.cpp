#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("C:\\skillbox\\input.txt");
    cout << "input picture lenght and weight" << endl;
    int lenght, weight;
    cin >> lenght >> weight;
    for (int i = 0; i < lenght; i++) {
        for (int g = 0; g < weight; g++) {
            int f = rand() % 3 + 1;
            file << f;
        }
        file << endl;
    }
    file.close();
}
