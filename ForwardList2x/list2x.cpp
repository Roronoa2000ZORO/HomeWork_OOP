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



// онструктор по умалчанию
List::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "LConstructor: " << this << endl;;
}
// онструктор принимающий список инициализации
List::List(initializer_list<int> il) : List()
{
    for (int const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}

// онструктор копировани€
List::List(const List& other) : List()
{
    *this = other;
}

// онструктор переноса
List::List(List&& other) noexcept: Head(other.Head), Tail(other.Tail), size(other.size)
{
    other.Head = other.Tail = nullptr;
    other.size = size_t();
}

//ƒеструктор
List::~List()
{
    while(Head) pop_back();
    cout << "LDestructor: " << this << endl;
}

//¬ывод списка
void List::print() const
{
    for (Element* Temp = Head; Temp;Temp = Temp->pNext)
    {
        cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
    }
    cout << " оличество элементов списка: " << size << endl;
}

//¬ывод списка задом наперед
void List::reverse_print()const
{
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
    {
        cout << Temp << tab << Temp->pNext << tab << Temp->Data << tab << Temp->pPrev << endl;
    }
    cout << " оличество элементов списка: " << size << endl;
}

//добавл€ет значение в начало списка
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

//добавл€ет значение в конец списка
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

//удал€ет начальный элемент списка
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

//удал€ет последнее значение списка
void List::pop_back()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)return pop_front();
    Tail = Tail->pPrev;

    delete Tail->pNext;

    Tail->pNext = nullptr;
    size--;
}

//добавл€ет значение по указанному индексу
void List::insert(int Data, int pos)
{
    if (pos > size)return;
    // ≈сли индекс добавлени€ указывает на начальный элемент
    if (pos == 0)return push_front(Data);
    // ≈сли индекс добавлени€ указывает на последний элемент
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

//удал€ет значение по указанному индексу
void List::erase(int pos)
{
    if (Head == nullptr && Tail == nullptr) return;
    if (pos > size)return;
    // ≈сли в списке один элемент или индекс удалени€ указывает на начальный элемент
    if (Head == Tail || pos == 0)return pop_front();
    // ≈сли индекс удалени€ указывает на последний элемент
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

    //1) ѕрисваиваем предедушему элементу удалаемого значени€ следующий его элемент
    Temp->pPrev->pNext = Temp->pNext;
    //2) ѕрисваиваем следующему элементу удал€емого значение предедущий его элемент
    Temp->pNext->pPrev = Temp->pPrev;

    //3) обнул€ем указатели удал€емого значение
    Temp->pNext = Temp->pPrev = nullptr;
    delete Temp;

    size--;
}

List& List::operator=(const List& other)
{
    // если списки одинаковые нечего не делаем
    if (this == &other)return *this;
    // если список не пустой то удал€ем из него все
    if (Head != nullptr)while (Head)pop_front();

    // ƒалее присваиваем
    for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
    {
        push_back(Temp->Data);
    }
    size = other.size;

    return *this;
}

List& List::operator=(List&& other) noexcept
{
    // если списки одинаковые нечего не делаем
    if (this == &other)return *this;
    // если список не пустой то удал€ем из него все
    if (Head != nullptr)while (Head)pop_front();

    Head = other.Head;
    Tail = other.Tail;
    size = other.size;

    other.Head = other.Tail = nullptr;
    other.size = size_t();

    return *this;
}
