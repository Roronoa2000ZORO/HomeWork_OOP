#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP


#include<iostream>

using namespace std;


class Element 
{
private:
    int Data;
    Element* pNext;
    static int count;
public:

    //Конструктор
    Element(int Data, Element* pNext = nullptr);
    Element(Element* New);
    //Деструктор
    ~Element();
    friend class ForwardList;
};


class ForwardList 
{
private:
    Element* Head;
    size_t size;
public:
    //Конструктор
    ForwardList();
    ForwardList(Element* New, int Data);
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

    void print()const;
};


#endif // !FORWARDLIST_HPP
