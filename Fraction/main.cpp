#include"fraction.hpp"

/*
1. ���������� ��� ��������� ��� ����������� ����������� ����� ������ ��� ��������
2. �������� ��������� main.cpp
3. ����������� ������ � �������������
4. ����������� ������������� ��������� ������
*/

int main() {
    setlocale(LC_ALL, "RU");

    Fraction A(0, 2, 5);// ����� �����, ���������, �����������.
    A.PrintFraction();
    cout << "\t";
    Fraction B(0, 3, 6);// ����� �����, ���������, �����������.
    B.PrintFraction();
    cout << "\t";
    Fraction D = A * B;
    D.PrintFraction();
    
    return 0;
}