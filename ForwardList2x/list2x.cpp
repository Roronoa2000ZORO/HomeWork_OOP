#include"list2x.hpp"

List::Element::Element(int Data, Element* pNext, Element* pPrev)
    :Data(Data), pNext(pNext), pPrev(pPrev)
{
    cout << "EConstructor: " << this << endl;
}
List::Element::~Element()
{
    cout << "EDestructor: " << this << endl;
}

List::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "LConstructor: " << this << endl;;
}

List::~List()
{
    while (Head)pop_back();
    cout << "LDestructor: " << this << endl;
}

void List::push_front(int Data)
{
    if (Head == nullptr && Tail == nullptr)
    {
        Head = Tail = new Element(Data);
    }
    else
    {
        Element* New = new Element(Data);

        New->pNext = Head;
        Head->pPrev = New;

        Head = New;
    }
    size++;
}

void List::print() const
{
    for (Element* Temp = Head; Temp;Temp = Temp->pNext)
    {
        cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

void List::reverse_print()const
{
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
    {
        cout << Temp << tab << Temp->pNext << tab << Temp->Data << tab << Temp->pPrev << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

void List::push_back(int Data)
{
    if (Head == nullptr && Tail == nullptr)return push_front(Data);
    else
    {
        Element* New = new Element(Data);

        New->pPrev = Tail;
        Tail->pNext = New;

        Tail = New;
    }
    size++;
}

void List::pop_front()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)
    {
        delete Head;
        Head = Tail = nullptr;
        return;
    }
    Head = Head->pNext;

    delete Head->pPrev;

    Head->pPrev = nullptr;
    size--;
}

void List::pop_back()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)return pop_front();
    Tail = Tail->pPrev;

    delete Tail->pNext;

    Tail->pNext = nullptr;
    size--;
}

void List::insert(int Data, int pos)
{
    if (pos > size)return;
    Element* Temp;
    if (pos < size / 2)
    {
        Temp = Head;
        for (size_t i = 0; i < pos; i++)Temp = Temp->pNext;
    }
    else
    {
        Temp = Tail;
        for (size_t i = 0; i < size - pos - 1; i++)Temp = Temp->pPrev;
    }
    Element* New = new Element(Data);
    
    New->pNext = Temp;
    New->pPrev = Temp->pPrev;

    Temp->pPrev->pNext = New;
    Temp->pPrev = New;

    size++;
}
