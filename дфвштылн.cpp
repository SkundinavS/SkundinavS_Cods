#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

/*unsigned long seed = 1;

int my_rand() {
  seed = seed * 200383594 + 543219;
  return (seed / 73882) % 56920;//56919
}
*/
//если нужны будут истинно случайные числа
vector<int> filtr(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int g = 0; g < a.size()-1; g++) {
            if (a[g] > a[g+1]) {
                int tmp = a[g];
                a[g] = a[g+1];
                a[g+1] = tmp;
            }
        }
    }
    return a;
}

int main()
{
    int arr[10];
    vector<vector<int>> foral;
    for (int i = 0; i < 10; i++) {
        vector<int> ex;
        foral.push_back(ex);
    }
    for (int i = 0; i < 10; i++) {
        for (int g = 0; g < 10; g++) {
            foral[i].push_back(rand() % 101);//rand = my_rand
        }
    }
    for (int i = 0; i < 10; i++) {
        foral[i] = filtr(foral[i]);
    }
    for (int i = 0; i < 10; i++) {
        arr[i] = foral[i][9];
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}