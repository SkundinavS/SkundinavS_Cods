#include <iostream>
#include <vector>
using namespace std;

template <typename T1>

void input(vector<T1> array) {
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        T1 num = 0;
        cin >> num;
        array.push_back(num);
    }
    T1 sum = 0; 
    for (int i = 0; i < 8; i++) { 
        sum += array[i];
    }
    sum = sum / 8;
    cout << sum;
}

int main()
{
    vector<double> array;
    input(array);
}
