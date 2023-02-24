#include"fraction.hpp"

/*
Доп. задание:
1. Реализовать манипуляции с отрицательными дробями
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction A(2, 3, 4);
    Fraction B(3, 4, 5);
    Fraction D = A + B;
    A.PrintFraction();
    B.PrintFraction();
    D.PrintFraction();
    cout << endl;
    Fraction E = A + B;
    A.PrintFraction();
    B.PrintFraction();
    E.PrintFraction();
    cout << endl;
    D += A + B;
    D.PrintFraction();
    cout << endl;
    if (A == B) {
        cout << "WoooooooooooW";
    }
    else {
        cout << "LoooooooooooL";
    }
    cout << endl;
    int a, b;
    cout << A << endl;
    cout << B << endl;
    Fraction U;
    cin >> U;


    return 0;
}