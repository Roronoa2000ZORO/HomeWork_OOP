#include"list2x.hpp"

//#define HW_1
int main()
{
    setlocale(LC_ALL, "");

#ifdef HW_1
    int size;
    cout << "¬ведите размер списка: "; cin >> size;

    List list;
    for (size_t i = 0; i < size; i++)
    {
        list.push_front(rand() % 100);
    }
    list.print();
    cout << endl;
    list.reverse_print();

    int pos;
    int value;
    cout << "¬ведите позицию добовл€емого элемента: "; cin >> pos;
    cout << "¬ведите значение добовл€емого элемента: "; cin >> value;
    list.insert(value, pos);
    list.print();

    cout << "¬ведите позицию удал€емого элемента: "; cin >> pos;
    list.erase(pos);
    list.print();
#endif // HW_1


    List list = { 3, 5, 8, 13, 21 };

    for (int i : list)
    {
        cout << i << tab;
    }
    cout << endl;

    return 0;
}