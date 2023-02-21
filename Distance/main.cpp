#include "distance_hw.hpp"

int main() {
    setlocale(LC_ALL, "RU");

    Point A(2, 3);
    Point B(4, 6);

    cout << "Координаты Точки A: ";
    A.Print();
    cout << "\nКоординаты Точки B: ";
    B.Print();

    cout << "\n-------------------------------------------\n";
    PrintDistance(A, B);


    return 0;
}