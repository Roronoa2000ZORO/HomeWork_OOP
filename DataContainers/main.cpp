#include"dynamicMemory.hpp"



//#define HW_1_1
//#define HW_1_2
#define HW_1_3
int main() {
    setlocale(LC_ALL, "");

    int size, value, pos;
    cout << "������� ������ �������" << endl;
    cin >> size;

    DinamicArray dinArray(size);
    dinArray.fillArray();
    cout << dinArray << endl;


#ifdef HW_1_1
    cout << "������� �������� � ����� �������" << endl;
    cin >> value;
    dinArray.push_back(value);
    cout << dinArray << endl;

    dinArray.pop_back();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_1





#ifdef HW_1_2
    cout << "������� �������� � ������ �������" << endl;
    cin >> value;
    dinArray.push_front(value);
    cout << dinArray << endl;

    dinArray.pop_front();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_2


#ifdef HW_1_3
    cout << "������� �������� ������� ��� ������� ��������" << endl;
    cin >> pos;
    cout << "������� �������� ��� ������� �� �� ��������� ����� ������� �������" << endl;
    cin >> value;
    dinArray.insert(value, pos);
    cout << dinArray << endl;

    cout << "������� �������� ������� ��� �������� ��������" << endl;
    cin >> pos;
    dinArray.erase(pos);
    cout << dinArray << endl;

#endif // HW_1_3




    return 0;
}