#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    map<string, int> ourmap;
    map<int, string> map2;//создаем словари
    map<int, string> fin;
    for (int i = 0; true; i++) {
        string op;
        cout << "Input operation or surename, if you want to stop prog, input -1" << endl;
        cin >> op;
        if (op == "next") {
            fin.erase(fin.begin());//удаление первого в очереди элемента
        } 
        else if (op == "-1") {
            break;
        }
        else {
            ourmap.insert(make_pair(op, i));
            map2.insert(make_pair(i, op));
            int i = 1;
            fin.clear();
            for (map<string, int>::iterator it = ourmap.begin(); it != ourmap.end(); it++) {
                for (map<int, string>::iterator itf = map2.begin(); itf != map2.end(); itf++) {
                    if (it->first == itf->second) {
                        fin.insert(make_pair(i, it->first));
                        i++;
                    }
                    else {
                        i++;
                    }
                }
            }
        }
        for (map<int, string>::iterator it = fin.begin(); it != fin.end(); it++) {
            cout<<it->second<<endl;
        }
    }
}
