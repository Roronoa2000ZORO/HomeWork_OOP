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

    //�����������
    Element(int Data, Element* pNext = nullptr);
    //����������
    ~Element();
    friend class ForwardList;
};


class ForwardList 
{
private:
    Element* Head;
public:
    //�����������
    ForwardList();
    //����������
    ~ForwardList();

    //��������� �������� � ������ ������
    void push_front(int Data);
    //������� ��������� �������� ������
    void pop_front();

    //��������� �������� � ����� ������
    void push_back(int Data);
    //������� ��������� �������� ������
    void pop_back();

    void print()const;
};


#endif // !FORWARDLIST_HPP
