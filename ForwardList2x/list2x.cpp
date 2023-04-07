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

List::Iterator List::begin()
{
    return Head;
}

List::Iterator List::end()
{
    return nullptr;
}


List::Iterator::Iterator(Element* Temp) :Temp(Temp) {}
List::Iterator::~Iterator() {}

List::Iterator& List::Iterator::operator++()
{
    Temp = Temp->pNext;
    return *this;
}
bool List::Iterator::operator==(const Iterator& other)
{
    return this->Temp == other.Temp;
}
bool List::Iterator::operator!=(const Iterator& other)
{
    return this->Temp != other.Temp;
}
int& List::Iterator::operator*()
{
    return Temp->Data;
}



//����������� �� ���������
List::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "LConstructor: " << this << endl;;
}
//����������� ����������� ������ �������������
List::List(initializer_list<int> il) : List()
{
    for (int const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}

//����������� �����������
List::List(const List& other) : List()
{
    *this = other;
}

//����������� ��������
List::List(List&& other) noexcept: Head(other.Head), Tail(other.Tail), size(other.size)
{
    other.Head = other.Tail = nullptr;
    other.size = size_t();
}

//����������
List::~List()
{
    while(Head) pop_back();
    cout << "LDestructor: " << this << endl;
}

//����� ������
void List::print() const
{
    for (Element* Temp = Head; Temp;Temp = Temp->pNext)
    {
        cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
    }
    cout << "���������� ��������� ������: " << size << endl;
}

//����� ������ ����� �������
void List::reverse_print()const
{
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
    {
        cout << Temp << tab << Temp->pNext << tab << Temp->Data << tab << Temp->pPrev << endl;
    }
    cout << "���������� ��������� ������: " << size << endl;
}

//��������� �������� � ������ ������
void List::push_front(int Data)
{
    if (Head == nullptr && Tail == nullptr)
    {
        Head = Tail = new Element(Data);
    }
    else
    {
        /*Element* New = new Element(Data);
        New->pNext = Head;
        Head->pPrev = New;
        Head = New;*/

        Head->pPrev = new Element(Data, Head);
        Head = Head->pPrev;
    }
    size++;
}

//��������� �������� � ����� ������
void List::push_back(int Data)
{
    if (Head == nullptr && Tail == nullptr)return push_front(Data);
    else
    {
        /*Element* New = new Element(Data);
        New->pPrev = Tail;
        Tail->pNext = New;
        Tail = New;*/

        Tail->pNext = new Element(Data, nullptr, Tail);
        Tail = Tail->pNext;
    }
    size++;
}

//������� ��������� ������� ������
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

//������� ��������� �������� ������
void List::pop_back()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)return pop_front();
    Tail = Tail->pPrev;

    delete Tail->pNext;

    Tail->pNext = nullptr;
    size--;
}

//��������� �������� �� ���������� �������
void List::insert(int Data, int pos)
{
    if (pos > size)return;
    // ���� ������ ���������� ��������� �� ��������� �������
    if (pos == 0)return push_front(Data);
    // ���� ������ ���������� ��������� �� ��������� �������
    if (pos == size - 1)return push_back(Data);

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

    /*Element* New = new Element(Data);
    New->pNext = Temp;
    New->pPrev = Temp->pPrev;
    Temp->pPrev->pNext = New;
    Temp->pPrev = New;*/

    Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
    Temp->pPrev = Temp->pPrev->pNext;

    size++;
}

//������� �������� �� ���������� �������
void List::erase(int pos)
{
    if (Head == nullptr && Tail == nullptr) return;
    if (pos > size)return;
    // ���� � ������ ���� ������� ��� ������ �������� ��������� �� ��������� �������
    if (Head == Tail || pos == 0)return pop_front();
    // ���� ������ �������� ��������� �� ��������� �������
    if (pos == size - 1)return pop_back();

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

    //1) ����������� ����������� �������� ���������� �������� ��������� ��� �������
    Temp->pPrev->pNext = Temp->pNext;
    //2) ����������� ���������� �������� ���������� �������� ���������� ��� �������
    Temp->pNext->pPrev = Temp->pPrev;

    //3) �������� ��������� ���������� ��������
    Temp->pNext = Temp->pPrev = nullptr;
    delete Temp;

    size--;
}

List& List::operator=(const List& other)
{
    // ���� ������ ���������� ������ �� ������
    if (this == &other)return *this;
    // ���� ������ �� ������ �� ������� �� ���� ���
    if (Head != nullptr)while (Head)pop_front();

    // ����� �����������
    for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
    {
        push_back(Temp->Data);
    }
    size = other.size;

    return *this;
}

List& List::operator=(List&& other) noexcept
{
    // ���� ������ ���������� ������ �� ������
    if (this == &other)return *this;
    // ���� ������ �� ������ �� ������� �� ���� ���
    if (Head != nullptr)while (Head)pop_front();

    Head = other.Head;
    Tail = other.Tail;
    size = other.size;

    other.Head = other.Tail = nullptr;
    other.size = size_t();

    return *this;
}
