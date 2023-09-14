#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class Song {
public:
    string name;
    double len;
    string date;
};

class Track {
public:
    void play(int index, bool ch, vector<Song> vec) {
        int ind = index;
        if (ch) {
            cout << "Input name of song" << endl;
            string nam;
            cin >> nam;
            bool a = true;
            double pas = 0.0;
            for (int i = 0; i < vec.size(); i++) {
                if (nam == vec[i].name) {
                    ind = i;
                    break;
                }
            }
        }
        double paus = 0;
        time_t st = time(nullptr);
        for (int i = 0; true; i++) {
            time_t en = time(nullptr);
            if (difftime(en, st) >= vec[ind].len + paus) {
                cout << "Song end" << endl;
                break;
            }
            string com;
            cout << "Input command for song" << endl;
            cin >> com;
            if (com == "pause") {
                time_t pa = time(nullptr);
                paus = pause(pa);
            }
            if (com == "stop") {
                break;
            }
            if (com == "next") {
                
            }
        }
    }
    double pause(time_t a) {
        cout << "Print any word if you want song to play" << endl;
        string com;
        cin >> com;
        time_t b = time(nullptr);
        return difftime(b, a);
    }
    void next(vector<Song> vec) {
        Track h;
        bool f = false;
        h.play(rand() % vec.size(), f, vec);
    }
};

int main()
{
    Track playlist;
    cout << "If you wand to add songs print add" << endl;
    string m;
    cin >> m;
    vector<Song> vec;
    if (m == "add") {
        while (true) {
            string com;
            cout << "Input name of song or stop" << endl;
            cin >> com;
            if (com == "stop") {
                break;
            }
            else {
                Song a;
                a.name = com;
                double l;
                cout << "Input lenght of song" << endl;
                cin >> l;
                a.len = l;
                string d;
                cout << "Input release date of song" << endl;
                cin >> d;
                a.date = d;
                vec.push_back(a);
            }
        }
    }
    while (true) {
        cout << "Input command for player" << endl;
        string com;
        cin >> com;
        Track a;
        if (com == "play") {
            a.play(0, true, vec);
        }
        if (com == "stop") {
            break;
        }
    }
}
