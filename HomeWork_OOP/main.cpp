#include "distance_hw.hpp"

int main() {
    setlocale(LC_ALL, "RU");

    Point A(2, 3);
    Point B(4, 6);

    cout << "���������� ����� A: ";
    A.Print();
    cout << "\n���������� ����� B: ";
    B.Print();

    cout << "\n-------------------------------------------\n";
    PrintDistance(A, B);


    return 0;
}