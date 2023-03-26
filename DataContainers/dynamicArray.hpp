#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include<iostream>
#include<random>

using namespace std;
using std::cout;
using std::cin;



/*----------------------------start-class-DinamicArray---------------------------*/

class DinamicArray
{
private:
    int size;
    int* data;
public:
    int get_size()const;
    int* get_data()const;

    void set_size(int size);

    
    //Конструктор класса
    DinamicArray(int size = int());

    //Конструктор копирования
    DinamicArray(const DinamicArray& other);
    //Конструктор переноса
    DinamicArray(DinamicArray&& other) noexcept;
    //Деструктор класса
    ~DinamicArray();



                            /*Методы*/
    //Заполнение массива
    void fillArray();

    //меняет адрес местами
    void assignAdress(int* buffer);

    //добавляет значение в конец массива
    void push_back(int value = int());
    //удаляет последний элемент массива
    void pop_back();

    //добавляет значение в начало массива
    void push_front(int value = int());
    //удаляет нулевой элемент массива
    void pop_front();

    //добавляет значение в массив по указанному индексу
    void insert(int pos, int value = int());
    //удаляет элемент из массива по заданному индексу
    void erase(int pos);


                            /*Перегрузка операторов*/

    //Оператор присваивания
    DinamicArray& operator=(const DinamicArray& other);
    //Оператор переноса
    DinamicArray& operator=(DinamicArray&& other) noexcept;


};
/*------------------------------end-class-DinamicArray---------------------------*/

//функция рандома
int MyRandom(int a, int b);

//Оператор вставки в поток
ostream& operator<<(ostream& ost, const DinamicArray& obj);


#define delimiter "\n--------------------------------------------------------------\n"
/*----------------------------start-class-DinamicArray2D-------------------------*/

class DinamicArray2D
{
private:
    int rows;
    int cols;
    int** data;
public:
    int get_rows()const;
    int get_cols()const;
    int** get_data()const;

    void set_rows(int rows);
    void set_cols(int cols);



    //Конструктор класса
    DinamicArray2D(int rows = int(), int cols = int());
    //Конструктор копирования
    DinamicArray2D(const DinamicArray2D& other);
    //Конструктор переноса
    DinamicArray2D(DinamicArray2D&& other) noexcept;
    //Деструктор класса
    ~DinamicArray2D();

                                    /*Методы*/

    //Заполнение массива
    void fillArray();

    //добавляет пустую строку в конец ДДМ
    void push_row_back();
    //удаляет последнюю строку из ДДМ
    void pop_row_back();

    //добавляет пустую строку в начало ДДМ
    void push_row_front();
    //удаляет нулевую строку из ДДМ
    void pop_row_front();

    //вставляет пустую строку в ДДМ по заданному индексу
    void insert_row(int pos);
    //удаляет строку из ДДМ по заданному индексу
    void erase_row(int pos);

    //добавляет пустой столбец в конец ДДМ
    void push_col_back();
    //удаляет последний столбец из ДДМ
    void pop_col_back();

    //добавляет пустой столбец в начало ДДМ
    void push_col_front();
    //удаляет нулевой столбец из ДДМ
    void pop_col_front();

    //вставляет пустой столбец в ДДМ по заданному индексу
    void insert_col(int pos);
    //удаляет столбец из ДДМ по заданному индексу
    void erase_col(int pos);


                                    /*Перегрузка операторов*/

    //Оператор присваивания
    DinamicArray2D& operator=(const DinamicArray2D& other);
    //Оператор переноса
    DinamicArray2D& operator=(DinamicArray2D&& other) noexcept;
};


/*------------------------------end-class-DinamicArray2D-------------------------*/

//Оператор вставки в поток для двумерного массива
ostream& operator<<(ostream& ost, const DinamicArray2D& obj);


#endif // !DYNAMICARRAY_HPP
