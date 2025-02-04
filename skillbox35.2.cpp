#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

auto swapvector = [](vector<int> counts) {
    unordered_set<int> ucounts;
    move(counts.begin(), counts.end(), std::inserter(ucounts, ucounts.end()));
    vector<int> rescou;
    for (auto& i : ucounts) {
        rescou.push_back(i);
    }
    auto unicounts = make_unique<vector<int>>(rescou);
    return unicounts;
    };

int main()
{
    vector<int> coun;
    cout << "how many counts" << endl;
    int len = 0;
    cin >> len;
    for (int i = 0; i < len; i++) {
        int c = 0;
        cout << "input count" << endl;
        cin >> c;
        coun.push_back(c);
    }
    cout << endl;
    unique_ptr<vector<int>> res = swapvector(coun);
    cout << endl;
    for (auto& c : *res) {
        cout << c << endl;
    }
}