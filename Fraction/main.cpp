#include"fraction.hpp"

/*
1. Реализовать манипуляции с отрицательными дробями
2. Оформить правильно main.cpp
3. Реализовать работу с пользователем
4. Реализовать корректировку ошибочных данных
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction A(0, 1, 2);
    Fraction B(0, 2, 4);
    Fraction D = A * B;
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
    return 0;
}