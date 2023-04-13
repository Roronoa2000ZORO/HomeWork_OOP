#include<iostream>

using namespace std;


void elevator(int floor) 
{
    if (floor <= 0)
    {
        cout << "Вы в подвале";
        return;
    }
    cout << "Вы на" << floor << " этаже" << endl;
    elevator(floor - 1);
    cout << "Вы на" << floor << " этаже" << endl;
}

void Fibonacci(int limit, int first = 0, int second = 1) 
{
    if (second >= limit)
    {
        cout << first << "\t";
        return;
    }
    cout << first << "\t";
    Fibonacci(limit, second, first + second);
}

int main() 
{
    setlocale(LC_ALL, "");

    cout << "Hello Recursion!" << endl;

    int n;
    cin >> n;
    Fibonacci(n);

    return 0;
}