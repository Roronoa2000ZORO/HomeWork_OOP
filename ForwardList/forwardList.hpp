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

    size_t get_size()const;
    Element* get_Head()const;
    Element* get_Head_pNext()const;
    int get_Head_Data()const;

    void set_Head(Element* Head);

    //Конструктор по умолчанию
    ForwardList(size_t size = 0);
    //Конструктор копирования
    ForwardList(ForwardList& other);
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

    void print()const;

    ForwardList& operator=(const ForwardList& other);
    ForwardList& operator=(ForwardList&& other)noexcept;
};

ForwardList operator+(ForwardList left, ForwardList right);

bool operator==(ForwardList left, ForwardList right);


#endif // !FORWARDLIST_HPP
