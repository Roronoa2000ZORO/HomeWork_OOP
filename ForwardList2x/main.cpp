//#include"list2x.hpp"
#include"list2x.cpp"

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


    List<int> list1 = { 3, 5, 8, 13, 21 };
    List<int> list2 = { 34, 55, 89 };
    List<int> list3 = list1 + list2;
    for (int i : list1) cout << i << tab;
    cout << endl;
    for (int i : list2) cout << i << tab;
    cout << endl;
    for (int i : list3) cout << i << tab;
    cout << endl;
    
    
    for (List<int>::ConstIterator it = list3.rbegin(); it != list3.rend(); --it)
    {
        cout << *it << tab;
    }

    return 0;
}