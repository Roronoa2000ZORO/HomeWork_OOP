#include"fraction.hpp"

/*
Доп. задание:
1. Реализовать манипуляции с отрицательными дробями
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction C(3, 5, 6);
    cout << C << endl;

    Fraction A(0, 7, 12);
    cout << A << endl;
    cout << C+A << endl;
    

    Fraction B = 2.76;
    cout << B << endl;

    return 0;
}