#include"forwardList.hpp"

#define delimeter "\n-------------------------------------------------\n"

int main() {
    setlocale(LC_ALL, "");

    ForwardList list;

    list.push_front(5);
    cout << 5 << endl;
    list.push_front(12);
    cout << 12 << endl;
    list.push_front(20);
    cout << 20 << endl;

    list.print();
    cout << delimeter;

    list.pop_front();
    list.print();
    cout << delimeter;

    list.push_back(66);
    list.print();


    return 0;
}