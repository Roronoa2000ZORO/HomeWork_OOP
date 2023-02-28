#include"fraction.hpp"

/*
Доп. задание:
1. Реализовать манипуляции с отрицательными дробями
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction C(2, 3, 4);
    cout << C << endl;
    int c = C;
    cout << c << endl;

    Fraction A(2, 3, 4);
    cout << A << endl;
    double a = A;
    cout << a << endl;
    

    Fraction B = 2.76;
    cout << B << endl;

    return 0;
}