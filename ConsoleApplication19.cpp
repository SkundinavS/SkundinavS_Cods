#include <iostream>
#include <cmath>
using namespace std;

struct vec
{
    int x = 0;
    int y = 0;
};

vec add(int a, int b, int c, int d) {
    int x1 = a + c;
    int x2 = b + d;
    vec i;
    i.x = x1;
    i.y = x2;
    return i;
}

vec subtract(int a, int b, int c, int d) {
    int x1 = a - c;
    int x2 = b - d;
    vec i;
    i.x = x1;
    i.y = x2;
    return i;
}

vec scale(int a, int b, int c, int d, int co) {
    int x1 = a + c;
    int x2 = b + d;
    vec i;
    i.x = x1 * co;
    i.y = x2 * co;
    return i;
}

int lenght(int a, int b) {
    int sc = sqrt(a ^ 2 + b ^ 2);
    return sc;
}

vec normalize(vec vec1, int norm) {
    double a = vec1.x / norm;
    double b = vec1.y / norm;
    return vec1;
}

int main()
{
    cout << "Input operation" << endl;
    string op;
    cin >> op;
    vec vector1, vector2;
    int x1, x2, y1, y2, x11, x12, y11, y12;
    cout << "Input cords of first vector (4 cords)" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Input cords of second vector (4 cords)" << endl;
    cin >> x11 >> y11 >> x12 >> y12;
    int xl1 = x2 - x1;
    int yl1 = y2 - y1;
    int xl2 = x12 - x11;
    int yl2 = y12 - y11;
    vector1.x = xl1;
    vector1.y = yl1;
    vector2.x = xl2;
    vector2.y = yl2;
    vec res;
    if (op == "add") {
        res = add(vector1.x, vector1.y, vector2.x, vector2.y);
        cout << "Summ of vectors:" << res.x << " " << res.y;
    }
    if (op == "subtract") {
        res = subtract(vector1.x, vector1.y, vector2.x, vector2.y);
        cout << "Difference of vectors:" << res.x << " " << res.y;
    }
    if (op == "scale") {
        int scl;
        cout << "Input scale" << endl;
        cin >> scl;
        res = scale(vector1.x, vector1.y, vector2.x, vector2.y, scl);
        cout << "Multiplication of vector and scale:" << res.x << " " << res.y;
    }   
    if (op == "lenght") {
        cout << "lenght of first vector:" << lenght(vector1.x, vector1.y) << endl;
        cout << "lenght of second vector:" << lenght(vector2.x, vector2.y);
    }
    if (op == "normalize") {
        int norm1 = sqrt(xl1 ^ 2 + yl1 ^ 2);
        int norm2 = sqrt(xl2 ^ 2 + yl2 ^ 2);
        vec res1 = normalize(vector1, norm1);
        vec res2 = normalize(vector2, norm2);
        cout << "Cords of normalized first vector" << res1.x << " " << res1.y << endl;
        cout << "Cords of normalized first vector" << res1.x << " " << res1.y << endl;
    }
}
