#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include<iostream>
#include<random>

using namespace std;
using std::cout;
using std::cin;



/*----------------------------start-class-DinamicArray---------------------------*/

template<typename T>
class DinamicArray
{
private:
    int size;
    T* data;
public:
    int get_size()const;
    T* get_data()const;

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
    void assignAdress(T* buffer);

    //добавляет значение в конец массива
    void push_back(T value = T());
    //удаляет последний элемент массива
    void pop_back();

    //добавляет значение в начало массива
    void push_front(T value = T());
    //удаляет нулевой элемент массива
    void pop_front();

    //добавляет значение в массив по указанному индексу
    void insert(int pos, T value = T());
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
template<typename T>T MyRandom(T a, T b);

//Оператор вставки в поток
template<typename T>ostream& operator<<(ostream& ost, const DinamicArray<T>& obj);


#define delimiter "\n--------------------------------------------------------------\n"
/*----------------------------start-class-DinamicArray2D-------------------------*/

template<typename T>
class DinamicArray2D
{
private:
    int rows;
    int cols;
    T** data;
public:
    int get_rows()const;
    int get_cols()const;
    T** get_data()const;

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
    DinamicArray2D& operator=(DinamicArray2D&& other);
};


/*------------------------------end-class-DinamicArray2D-------------------------*/

//Оператор вставки в поток для двумерного массива
template<typename T>ostream& operator<<(ostream& ost, const DinamicArray2D<T>& obj);


#endif // !DYNAMICARRAY_HPP
