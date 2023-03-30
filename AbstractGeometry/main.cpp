#include"Geometry.hpp"


int main()
{
    setlocale(LC_ALL, "");
    
    Square S(8);

    cout << S << endl;

    Rectangle R(5,10);

    cout << R << endl;

    Circle C(50);

    cout << C << endl;

    return 0;
}