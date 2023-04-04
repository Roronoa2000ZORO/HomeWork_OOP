#include"list2x.hpp"


int main()
{
    setlocale(LC_ALL, "");

    int size;
    cout << "Введите размер списка: "; cin >> size;

    List list;
    for (size_t i = 0; i < size; i++)
    {
        list.push_back(rand() % 100);
    }
    list.print();
    cout << endl;
    list.reverse_print();

    int pos;
    int value;
    cout << "Введите значение добовляемого элемента: "; cin >> pos;
    cout << "Введите размер списка: "; cin >> value;
    list.insert(value, pos);
    list.print();
    return 0;
}