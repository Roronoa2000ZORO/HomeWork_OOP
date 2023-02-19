#include"fraction.hpp"

/*
1. Доработать все операторы для возможности манипуляций целых частей над дробными
2. Оформить правильно main.cpp
3. Реализовать работу с пользователем
4. Реализовать корректировку ошибочных данных
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction A(0, 2, 5);// целая часть, числитель, знаменатель.
    A.PrintFraction();
    cout << "\t";
    Fraction B(0, 3, 6);// целая часть, числитель, знаменатель.
    B.PrintFraction();
    cout << "\t";
    Fraction D = A * B;
    D.PrintFraction();
    
    return 0;
}