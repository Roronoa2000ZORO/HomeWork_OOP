#include"forwardList.cpp"

#define delimeter "\n-------------------------------------------------\n"
//#define HW_1
//#define HW_2

int main() {
    setlocale(LC_ALL, "");

#ifdef HW_1
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
#endif // HW_1




#ifdef HW_2
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
#endif // HW_2



    ForwardList<int> list5 = {1,2};


    /*for (int i : list5)
    {
        cout << i << "\t";
    }
    cout << endl;*/

    ForwardList<double> list;
    list.push_back(9);
    print(list);
    return 0;
}