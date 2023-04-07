#include"list2x.hpp"

using std::cout;
//#define HW_1
int main()
{
    setlocale(LC_ALL, "");

#ifdef HW_1
    int size;
    cout << "Введите размер списка: "; cin >> size;

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
    cout << "Введите позицию добовляемого элемента: "; cin >> pos;
    cout << "Введите значение добовляемого элемента: "; cin >> value;
    list.insert(value, pos);
    list.print();

    cout << "Введите позицию удаляемого элемента: "; cin >> pos;
    list.erase(pos);
    list.print();
#endif // HW_1


    /*List list = { 3, 5, 8, 13, 21 };

    for (int i : list)
    {
        cout << i << tab;
    }
    cout << endl;*/

    int a = 5;
    double b = 2;
    int c = a / b;
    cout << c;

    return 0;
}