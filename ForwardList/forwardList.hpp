#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP


#include<iostream>
#include <iterator>

using namespace std;
using std::cout;

class Element 
{
private:
    int Data;
    Element* pNext;
    static int count;
public:

    //Конструктор
    Element(int Data, Element* pNext = nullptr);
    //Деструктор
    ~Element();
    friend class ForwardList;
    friend class ConstIterator;
    friend class Iterator;
};

class ConstIterator
{
private:
    Element* Temp;
public:

    ConstIterator(Element* Temp);
    ~ConstIterator();

    ConstIterator& operator++();
    bool operator==(const ConstIterator& other);
    bool operator!=(const ConstIterator& other);

    const int& operator*()const ;

};

class Iterator
{
private:
    Element* Temp;
public:

    Iterator(Element* Temp);
    ~Iterator();

    Iterator& operator++();
    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);

    int& operator*();

};



class ForwardList 
{
private:
    Element* Head;
    size_t size;
public:
    Iterator begin();
    Iterator end();
    ConstIterator begin()const;
    ConstIterator end()const;

    size_t get_size()const;
    Element* get_Head()const;
    Element* get_Head_pNext()const;
    int get_Head_Data()const;

    void set_Head(Element* Head);

    //Конструктор по умолчанию
    ForwardList(size_t size = 0);
    //Конструктор копирования
    ForwardList(const ForwardList& other);

    ForwardList(initializer_list<int> il);
    //Конструктор переноса
    ForwardList(ForwardList&& other)noexcept;
    //Деструктор
    ~ForwardList();

    //добавляет значение в начало списка
    void push_front(int Data);
    //удаляет начальное значение списка
    void pop_front();

    //добавляет значение в конец списка
    void push_back(int Data);
    //удаляет последнее значение списка
    void pop_back();

    void insert(int Data, int pos);

    void erase(int pos);

    void reverse();

    void print()const;

    ForwardList& operator=(const ForwardList& other);
    ForwardList& operator=(ForwardList&& other)noexcept;

};

ForwardList operator+(ForwardList left, ForwardList right);

bool operator==(ForwardList left, ForwardList right);


void const print(const ForwardList& list);


#endif // !FORWARDLIST_HPP
