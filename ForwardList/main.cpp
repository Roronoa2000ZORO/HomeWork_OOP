#include"forwardList.hpp"

#define delimeter "\n-------------------------------------------------\n"

int main() {
    setlocale(LC_ALL, "");

    ForwardList list;

    list.push_front(5);
    cout << 5 << endl;
    list.push_front(99);
    cout << 99 << endl;
    list.push_front(21);
    cout << 21 << endl;
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
    cout << delimeter;



    ForwardList list2;

    list2.push_front(7);
    cout << 7 << endl;
    list2.push_front(2);
    cout << 2 << endl;
    list2.push_front(30);
    cout << 30 << endl;

    list2.insert(10, 3);
    list2.print();
    cout << delimeter;

    list2.erase(2);
    list2.print();
    cout << delimeter;

    ForwardList list3 = list2;
    list3.print();
    cout << delimeter;


    ForwardList list4 = list + list2;
    list4.print();
    cout << delimeter;
    return 0;
}