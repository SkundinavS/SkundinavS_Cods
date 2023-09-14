#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int banknots[6] = { 100,200,500,1000,2000,5000 };
    int bank[1000];
    string op;
    cout << "What kind of operation" << endl;
    cin >> op;
    ifstream in("C:\\skillbox\\bank.bin", ios::binary);
    if (in.is_open()) {
        in.read((char *) bank, sizeof(bank));
        in.close();
    }
    else {
        for (int i = 0; i < 1000; i++) {
            bank[i] = 0;
        }
    }
    if (op == "+") {
        for (int i = 0; i < 1000; i++) {
            if (bank[i] == 0) {
                bank[i] = banknots[rand() % 6];
            }
        }
        ofstream bankout("C:\\skillbox\\bank.bin", ios::binary);
        bankout.write((char *)bank, sizeof(bank));
        return 0;
    }
    else if (op == "-") {
        int cash;
        cout << "How much" << endl;
        cin >> cash;
        if ((cash % 100) != 0) {
            cerr << "Invalid summ" << endl;
            return 1;
        }
        int cashcollect = cash;
        for (int i = 5; i >= 0; i--) {
            int bill = banknots[i];
            for (int g = 0; g < 1000; g++) {
                if (bank[g] == bill) {
                    if (cashcollect >= bill) {
                        bank[g] = 0;
                        cashcollect -= bill;
                        if (cashcollect == 0) {
                            cout << "cash taken:" << cash << endl;
                            ofstream bankout("C:\\skillbox\\bank.bin", ios::binary);
                            bankout.write((char *)bank, sizeof(bank));
                            return 0;
                        }
                    }
                }
            }
        }
        cerr << "not banknotes" << endl;
        return 1;
    }
}