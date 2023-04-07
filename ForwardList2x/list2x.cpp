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



//Конструктор по умалчанию
List::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "LConstructor: " << this << endl;;
}
//Конструктор принимающий список инициализации
List::List(initializer_list<int> il) : List()
{
    for (int const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}

//Конструктор копирования
List::List(const List& other) : List()
{
    *this = other;
}

//Конструктор переноса
List::List(List&& other) noexcept: Head(other.Head), Tail(other.Tail), size(other.size)
{
    other.Head = other.Tail = nullptr;
    other.size = size_t();
}

//Деструктор
List::~List()
{
    while(Head) pop_back();
    cout << "LDestructor: " << this << endl;
}

//Вывод списка
void List::print() const
{
    for (Element* Temp = Head; Temp;Temp = Temp->pNext)
    {
        cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

//Вывод списка задом наперед
void List::reverse_print()const
{
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
    {
        cout << Temp << tab << Temp->pNext << tab << Temp->Data << tab << Temp->pPrev << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

//добавляет значение в начало списка
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

        Head = Head->pPrev = new Element(Data, Head);
    }
    size++;
}

//добавляет значение в конец списка
void List::push_back(int Data)
{
    if (Head == nullptr && Tail == nullptr)return push_front(Data);
    else
    {
        /*Element* New = new Element(Data);
        New->pPrev = Tail;
        Tail->pNext = New;
        Tail = New;*/

        Tail = Tail->pNext = new Element(Data, nullptr, Tail);
    }
    size++;
}

//удаляет начальный элемент списка
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

//удаляет последнее значение списка
void List::pop_back()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)return pop_front();
    Tail = Tail->pPrev;

    delete Tail->pNext;

    Tail->pNext = nullptr;
    size--;
}

//добавляет значение по указанному индексу
void List::insert(int Data, int pos)
{
    if (pos > size)return;
    // Если индекс добавления указывает на начальный элемент
    if (pos == 0)return push_front(Data);
    // Если индекс добавления указывает на последний элемент
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

    Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);

    size++;
}

//удаляет значение по указанному индексу
void List::erase(int pos)
{
    if (Head == nullptr && Tail == nullptr) return;
    if (pos > size)return;
    // Если в списке один элемент или индекс удаления указывает на начальный элемент
    if (Head == Tail || pos == 0)return pop_front();
    // Если индекс удаления указывает на последний элемент
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

    //1) Присваиваем предедушему элементу удалаемого значения следующий его элемент
    Temp->pPrev->pNext = Temp->pNext;
    //2) Присваиваем следующему элементу удаляемого значение предедущий его элемент
    Temp->pNext->pPrev = Temp->pPrev;

    //3) обнуляем указатели удаляемого значение
    Temp->pNext = Temp->pPrev = nullptr;
    delete Temp;

    size--;
}

List& List::operator=(const List& other)
{
    // если списки одинаковые нечего не делаем
    if (this == &other)return *this;
    // если список не пустой то удаляем из него все
    if (Head != nullptr)while (Head)pop_front();

    // Далее присваиваем
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
    // если список не пустой то удаляем из него все
    if (Head != nullptr)while (Head)pop_front();

    Head = other.Head;
    Tail = other.Tail;
    size = other.size;

    other.Head = other.Tail = nullptr;
    other.size = size_t();

    return *this;
}
