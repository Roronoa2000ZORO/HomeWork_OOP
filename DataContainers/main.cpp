#include"dynamicArray.hpp"


//#define HW_1
//#define HW_1_1
//#define HW_1_2
//#define HW_1_3

//#define HW_2
//#define HW_2_1
//#define HW_2_2
//#define HW_2_3
//#define HW_2_4
//#define HW_2_5
//#define HW_2_6
int main() {
    setlocale(LC_ALL, "");

#ifdef HW_1
    int size, value, pos;
    cout << "Введите длинну массива" << endl;
    cin >> size;

    DinamicArray<int> dinArray(size);
    dinArray.fillArray();
    cout << dinArray << endl;


#ifdef HW_1_1
    cout << "Введите значение в конец массива" << endl;
    cin >> value;
    dinArray.push_back(value);
    cout << dinArray << endl;

    dinArray.pop_back();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_1





#ifdef HW_1_2
    cout << "Введите значение в начала массива" << endl;
    cin >> value;
    dinArray.push_front(value);
    cout << dinArray << endl;

    dinArray.pop_front();
    cout << "-----------------\n" << dinArray << endl;
#endif // HW_1_2


#ifdef HW_1_3
    cout << "Введите позициию массива для вставки значения" << endl;
    cin >> pos;
    cout << "Введите значение для вставки ее на указанную ранее позицию массива" << endl;
    cin >> value;
    dinArray.insert(pos, value);
    cout << dinArray << endl;

    cout << "Введите позициию массива для удаления значения" << endl;
    cin >> pos;
    dinArray.erase(pos);
    cout << dinArray << endl;

#endif // HW_1_3  
#endif // HW_1



#ifdef HW_2
    int rows, cols, pos;
    cout << "Введите количество строк 2D массива" << endl; cin >> rows;
    cout << "Введите количество столбиков 2D массива" << endl; cin >> cols;

    DinamicArray2D DA2d(rows, cols);
    DA2d.fillArray();
    cout << DA2d;
    cout << delimiter;

#ifdef HW_2_1
    DA2d.push_row_back();
    cout << DA2d;
    cout << delimiter;

    DA2d.pop_row_back();
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_1

#ifdef HW_2_2
    DA2d.push_row_front();
    cout << DA2d;
    cout << delimiter;

    DA2d.pop_row_front();
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_2

#ifdef HW_2_3
    cout << "Введите позицию, для добавления строки в указанную позицию 2D массива" << endl; cin >> pos;
    DA2d.insert_row(pos);
    cout << DA2d;
    cout << delimiter;

    cout << "Введите позицию строки, для ее удаления в 2D массиве" << endl; cin >> pos;
    DA2d.erase_row(pos);
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_3


#ifdef HW_2_4
    DA2d.push_col_back();
    cout << DA2d;
    cout << delimiter;

    DA2d.pop_col_back();
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_4


#ifdef HW_2_5
    DA2d.push_col_front();
    cout << DA2d;
    cout << delimiter;

    DA2d.pop_col_front();
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_5

#ifdef HW_2_6
    cout << "Введите позицию, для добавления столбика в указанную позицию 2D массива" << endl; cin >> pos;
    DA2d.insert_col(pos);
    cout << DA2d;
    cout << delimiter;

    cout << "Введите позицию столбика, для ее удаления в 2D массиве" << endl; cin >> pos;
    DA2d.erase_col(pos);
    cout << DA2d;
    cout << delimiter;
#endif // HW_2_6  
#endif // HW_2




    return 0;
}