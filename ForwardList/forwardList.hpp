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

    // онструктор
    Element(int Data, Element* pNext = nullptr);
    //ƒеструктор
    ~Element();
    friend class ForwardList;
};


class ForwardList 
{
private:
    Element* Head;
public:
    // онструктор
    ForwardList();
    //ƒеструктор
    ~ForwardList();

    //добавл€ет значение в начало списка
    void push_front(int Data);
    //удал€ет начальное значение списка
    void pop_front();

    //добавл€ет значение в конец списка
    void push_back(int Data);
    //удал€ет последнее значение списка
    void pop_back();

    void print()const;
};


#endif // !FORWARDLIST_HPP
