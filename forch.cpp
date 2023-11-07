#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
//185 182 185 109 120 150 154 155 190 160
//31.5 31.5 33.5 21.2 17.3 33.0 19.0 30.3 19.5 19.0
vector<double> filtr(vector<double> a) {
    for (int i = 1; i < a.size(); i++) {
        for (int g = 0; g < a.size()-1; g++) {
            if (a[g] > a[g+1]) {
                double st = a[g];
                double fn = a[g + 1];
                a[g] = fn;
                a[g + 1] = st;
            }
        }
    }
    return a;
}

vector<double> deletefirst(vector<double> a) {
    vector<double> b;
    for (int i = 1; i < a.size(); i++) {
        b.push_back(a[i]);
    }
    return b;
}

double findsrznch(vector<double> a, int ind) {
    a = filtr(a);
    if (ind == 0) {
        a = deletefirst(a);
        double sum = 0;
        double res = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
        }
        res = sum / a.size();
        cout << "Midle: " << res << endl;
        return res;
    }
    else if (ind == 1) {
        a.pop_back();
        double sum = 0;
        double res = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
        }
        res = sum / a.size();
        cout << "Midle: " << res << endl;
        return res;
    }
}

double findeps(vector<double> a,double srzn,int ind) {
    double eps;
    double summa = 0;
    a = filtr(a);
    if (ind == 0) {
        a = deletefirst(a);
        for (int i = 0; i < a.size(); i++) {
            summa += (a[i] - srzn) * (a[i] - srzn);
            cout << summa << " ";
        }
        double del = summa / a.size();
        double res = sqrt(del);
        cout << "Epsila: " << res << endl;
        return res;
    }
    if (ind == 1) {
        a.pop_back();
        for (int i = 0; i < a.size(); i++) {
            summa += (a[i] - srzn) * (a[i] - srzn);
            cout << summa << " ";
        }
        double del = summa / 9;
        double res = sqrt(del);
        cout << "Epsila:" << res << endl;
        return res;
    }
};

bool findtruth(double srzn,double krit, double chis,double eps) {
    cout << "Kriteri Sharlie" << krit << endl;
    cout << srzn << " " << krit << " " << chis << " " << eps << endl;
    double znach1 = abs(srzn - chis);
    double znach2 = krit * eps;
    if (znach1 > znach2) {
        return true;
    }
    else {
        return false;
    }
};

int main()
{
    vector<vector<double>> sharlie {{5, 10, 20, 30, 40, 50, 100}, { 1.3,1.65,1.96,2.13,2.24,2.32,2.58 }};
    while (true) {
        string com;
        cout << "Input com: 'start' or 'stop'" << endl;
        cin >> com;
        if (com == "start") {
            cout << "What lenght of vector" << endl;
            int lenght = 0;
            cin >> lenght;
            vector<double> chisla;
            for (int i = 0; i < lenght; i++) {
                double chis = 0;
                cout << "Input chislo" << endl;
                cin >> chis;
                chisla.push_back(chis);
            }
            cout << "Input index: 0 - start pos, 1 - end pos" << endl;
            int ind = 0;
            cin >> ind;
            double srzn = findsrznch(chisla, ind);
            double eps = findeps(chisla, srzn, ind);
            double krit = 0;
            for (int i = 0; i < sharlie.size(); i++) {
                if (sharlie[0][i] == chisla.size()) {
                    krit = sharlie[1][i];
                    break;
                }
            }
            chisla = filtr(chisla);
            for (int i = 0; i < chisla.size(); i++) {
                cout << chisla[i] << " ";
            }
            cout << endl;
            double chis = 0;
            if (ind == 0) {
                chis = chisla[0];
            }
            else {
                chis = chisla[chisla.size()-1];
            }
            if (findtruth(srzn, krit, chis, eps)) {
                cout << "Wrong chis is " << chis << endl;
            }
            else {
                cout << "This is`t wrong chis " << endl;
            }
        }
        else if (com == "stop") {
            break;
        }
    }
}