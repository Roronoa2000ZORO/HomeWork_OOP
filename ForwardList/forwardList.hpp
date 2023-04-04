#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP


#include<iostream>
#include <iterator>

using namespace std;
using std::cout;


template<typename T>class ForwardList;
template<typename T>class ConstIterator;
template<typename T>class Iterator;


template<typename T>
class Element 
{
private:
    T Data;
    Element<T>* pNext;
    static int count;
public:

    //Конструктор
    Element(T Data, Element<T>* pNext = nullptr);
    //Деструктор
    ~Element();
    friend class ForwardList<T>;
    friend class ConstIterator<T>;
    friend class Iterator<T>;
};

template<typename T>
class ConstIterator
{
private:
    Element<T>* Temp;
public:

    ConstIterator(Element<T>* Temp);
    ~ConstIterator();

    ConstIterator& operator++();
    bool operator==(const ConstIterator<T>& other);
    bool operator!=(const ConstIterator<T>& other);

    const T& operator*()const ;

};

template<typename T>
class Iterator
{
private:
    Element<T>* Temp;
public:

    Iterator(Element<T>* Temp);
    ~Iterator();

    Iterator& operator++();
    bool operator==(const Iterator<T>& other);
    bool operator!=(const Iterator<T>& other);

    T& operator*();

};


template<typename T>
class ForwardList 
{
private:
    Element<T>* Head;
    size_t size;
public:
    Iterator<T> begin();
    Iterator<T> end();
    ConstIterator<T> begin()const;
    ConstIterator<T> end()const;

    size_t get_size()const;
    Element<T>* get_Head()const;
    Element<T>* get_Head_pNext()const;
    T get_Head_Data()const;

    void set_Head(Element<T>* Head);

    //Конструктор по умолчанию
    ForwardList(size_t size = 0);
    //Конструктор копирования
    ForwardList(const ForwardList& other);

    ForwardList(initializer_list<T> il);
    //Конструктор переноса
    ForwardList(ForwardList&& other)noexcept;
    //Деструктор
    ~ForwardList();

    //добавляет значение в начало списка
    void push_front(T Data);
    //удаляет начальное значение списка
    void pop_front();

    //добавляет значение в конец списка
    void push_back(T Data);
    //удаляет последнее значение списка
    void pop_back();

    void insert(T Data, int pos);

    void erase(int pos);

    void reverse();

    void print()const;

    ForwardList& operator=(const ForwardList<T>& other);
    ForwardList& operator=(ForwardList<T>&& other)noexcept;

};

template<typename T>
ForwardList<T> operator+(ForwardList<T> left, ForwardList<T> right);

template<typename T>
bool operator==(ForwardList<T> left, ForwardList<T> right);

template<typename T>
void const print(const ForwardList<T>& list);


#endif // !FORWARDLIST_HPP
