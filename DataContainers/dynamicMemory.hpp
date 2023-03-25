#ifndef DYNAMICMEMORY
#define DYNAMICMEMORY

#include<iostream>
#include<random>

using namespace std;


class DinamicArray {
private:
    int size;
    int* data;
public:
    int get_size()const;
    int* get_data()const;


    //Конструктор класса
    DinamicArray(int size = int());
    //Деструктор класса
    ~DinamicArray();



                            /*Методы*/
    //Заполнение массива
    void fillArray();

    //меняет адрес местами
    void swapAdress(int* buffer);

    //добавляет значение в конец массива
    void push_back(int value);
    //удаляет последний элемент массива
    void pop_back();

    //добавляет значение в начало массива
    void push_front(int value);
    //удаляет нулевой элемент массива
    void pop_front();

    //добавляет значение в массив по указанному индексу
    void insert(int value, int pos);
    //удаляет элемент из массива по заданному индексу
    void erase(int pos);

   /*Оператор преобразовании типа:*/
    operator int* ();


};

class DinamicArray2x : public DinamicArray
{
private:
    int rows;
    int cols;
    int** data;
public:
    int get_size()const;
    int** get_data()const;

    //Конструктор класса
    DinamicArray2x(int rows, int cols);
    //Деструктор класса
    ~DinamicArray2x();

                                    /*Методы*/

    //добавляет пустую строку в конец ДДМ
    void push_row_back();



};

//функция рандома
int MyRandom(int a, int b);

//Оператор вставки в поток
ostream& operator<<(ostream& ost, const DinamicArray& obj);

/*
//Выделяет память под двумерный динамический массив
int* Alocate(? ? ? );
//Освобождает память, занимаемую ДДМ
int* Clear(? ? ? );

//добавляет пустую строку в конец ДДМ
int* push_row_back(? ? ? );
//добавляет пустую строку в начало ДДМ
int* push_row_front(? ? ? );
//вставляет пустую строку в ДДМ по заданному индексу
int* insert_row(? ? ? );

//удаляет последнюю строку из ДДМ
int* pop_row_back(? ? ? );
//удаляет нулевую строку из ДДМ
int* pop_row_front(? ? ? );
//удаляет строку из ДДМ по заданному индексу
int* erase_row(? ? ? );

//добавляет пустой столбец в конец ДДМ
int* push_col_back(? ? ? );
//добавляет пустой столбец в начало ДДМ
int* push_col_front(? ? ? );
//вставляет пустой столбец в ДДМ по заданному индексу
int* insert_col(? ? ? );

//удаляет последний столбец из ДДМ
int* pop_col_back(? ? ? );
//удаляет нулевой столбец из ДДМ
int* pop_col_front(? ? ? );
//удаляет столбец из ДДМ по заданному индексу
int* erase_col(? ? ? );
*/
#endif // !DYNAMICMEMORY
