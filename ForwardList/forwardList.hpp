#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP


#include<iostream>

using namespace std;


class Element 
{
private:
    int Data;
    Element* pNext;
public:

    //Конструктор
    Element(int Data, Element* pNext = nullptr);
    //Деструктор
    ~Element();
    friend class ForwardList;
};


class ForwardList 
{
private:
    Element* Head;
public:
    //Конструктор
    ForwardList();
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

    void print()const;
};


#endif // !FORWARDLIST_HPP
