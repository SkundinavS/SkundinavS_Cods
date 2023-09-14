#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Figure {
    double height;
    double lenght;
    double squere;
    string color;
public:
    void PrintPars(int inLenght, int inHeight, double sq) {
        for (int i = 0; i < inHeight; i++) {
            if (i == 0 || i == inHeight-1) {
                cout << "|";
                for (int g = 1; g < inLenght * 2 - 1; g++) {
                    cout << "-";
                }
                cout << "|" << endl;
            }
            else {
                for (int g = 0; g < inLenght * 2; g++) {
                    if (g == 0 || g == inLenght * 2 - 1) {
                        cout << "|";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        cout << "Squere of figure: " << sq << endl;
        cout << "Color of figure: " << this->color << endl;
    }
    void TakeCol() {
        cout << "Input color of figure" << endl;
        cin >> color;
    }
};

class Circle :public Figure {
    double radius;
    double squere;
    string color;
public:
    double TakeRadius() {
        cout << "Input radius" << endl;
        cin >> radius;
        return radius;
    }
    double Squere() {
        squere = atan(1) * 4 * radius;
        return squere;
    }
};

class Triagle :public Figure {
    double rebr;
    double squere;
    string color;
public:
    double Squere() {
        cout << "Input lenght" << endl;
        cin >> rebr;
        squere = sqrt(3) / 4 * rebr * rebr;
        cout << squere << endl;
        return squere;
    }
    double GetLeight() {
        return rebr;
    }
};

class Rectangle:public Figure {
    double height;
    double lenght;
    double squere;
    string color;
public:
    double Squere() {
        cout << "Input lenght and height" << endl;
        cin >> lenght >> height;
        squere = lenght * height;
        return squere;
    }
    double GetHeight() {
        return height;
    }
    double GetLeight() {
        return lenght;
    }
};

class Square :public Figure {
    double lenght;
    double squere;
    string color;
public:
    double Squere() {
        cout << "Input lenght" << endl;
        cin >> lenght;
        squere = lenght * lenght;
        return squere;
    }
    double GetLeight() {
        return lenght;
    }
};

int main()
{
    while (true) {
        string com;
        cout << "Input command" << endl;
        cin >> com;
        if (com == "circle") {
            Circle* circle = new Circle;
            double len = circle->TakeRadius();
            double squa = circle->Squere();
            circle->TakeCol();
            circle->PrintPars(len, len, squa);
            delete circle;
        }
        if (com == "triangle") {
            Triagle* triangle = new Triagle;
            double squa = triangle->Squere();
            triangle->TakeCol();
            triangle->PrintPars(triangle->GetLeight(),triangle->GetLeight(), squa);
            delete triangle;
        }
        if (com == "square") {
            Square* square = new Square;
            double squa = square->Squere();
            square->TakeCol();
            square->PrintPars(square->GetLeight(), square->GetLeight(),squa);
            delete square;
        }
        if (com == "rectangle") {
            Rectangle* rec = new Rectangle;
            double squa = rec->Squere();
            rec->TakeCol();
            rec->PrintPars(rec->GetLeight(), rec->GetHeight(), squa);
            delete rec;
        }
        if (com == "stop") {
            break;
        }
    }
}