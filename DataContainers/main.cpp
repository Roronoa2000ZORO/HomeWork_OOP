#include"dynamicMemory.hpp"



//#define HW_1_1
//#define HW_1_2
#define HW_1_3
int main() {
    setlocale(LC_ALL, "");

    int size, value, pos;
    cout << "¬ведите длинну массива" << endl;
    cin >> size;

    DinamicArray dinArray(size);
    dinArray.fillArray();
    cout << dinArray << endl;


#ifdef HW_1_1
    cout << "¬ведите значение в конец массива" << endl;
    cin >> value;
    dinArray.push_back(value);
    cout << dinArray << endl;

    dinArray.pop_back();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_1





#ifdef HW_1_2
    cout << "¬ведите значение в начала массива" << endl;
    cin >> value;
    dinArray.push_front(value);
    cout << dinArray << endl;

    dinArray.pop_front();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_2


#ifdef HW_1_3
    cout << "¬ведите позициию массива дл€ вставки значени€" << endl;
    cin >> pos;
    cout << "¬ведите значение дл€ вставки ее на указанную ранее позицию массива" << endl;
    cin >> value;
    dinArray.insert(value, pos);
    cout << dinArray << endl;

    cout << "¬ведите позициию массива дл€ удалени€ значени€" << endl;
    cin >> pos;
    dinArray.erase(pos);
    cout << dinArray << endl;

#endif // HW_1_3




    return 0;
}