#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<vector<int>> a;
    string foo;
    while (true){
        cout << "enter 'date' or write 'date' to stop recording dates" << endl;
        cin >> foo;
        if (foo == "date") {
            time_t date = time(nullptr);
            cout << "enter date whit deliver :" << endl;
            tm* d = localtime(&date);
            cin >> get_time(d, "%Y:%m:%d");
            int day = d->tm_wday;
            int mon = d->tm_mon;
            int yer = d->tm_year;
            vector<int> data = { yer,mon,day };
            a.push_back(data);
        }
        else if (foo == "stop") {
            break;
        }
    }
    int ind = 0;
    bool check = true;
    for (int i = 0; i < a.size()-1; i++) {
        int y1 = a[i][0];
        int m1 = a[i][1];
        int d1 = a[i][2];
        int y2 = a[i+1][0];
        int m2 = a[i+1][1];
        int d2 = a[i+1][2];
        if (y2 < y1) {
            ind = i + 1;
        }
        else if (m2 < m1) {
            ind = i + 1;
        }
        else if (d2 < d1) {
            ind = i + 1;
        }
        else if (y2 == y1 && m2 == m1 && d1 == d2) {
            check = false;
            cout << "It's birthday today" << endl;
        }
    }
    if (check == true) {
        cout << "The nearest birthday date: " << a[ind][0] << ":" << a[ind][1] << ":" << a[ind][2] << endl;
    }
}

