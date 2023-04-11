#include"list2x.hpp"

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev)
    :Data(Data), pNext(pNext), pPrev(pPrev)
{
    cout << "EConstructor: " << this << endl;
}
template<typename T>List<T>::Element::~Element()
{
    cout << "EDestructor: " << this << endl;
}

template<typename T>const typename List<T>::ConstIterator List<T>::begin() const
{
    return Head;
}

template<typename T>const typename List<T>::ConstIterator List<T>::end() const
{
    return nullptr;
}

template<typename T>typename List<T>::Iterator List<T>::begin()
{
    return Head;
}

template<typename T>typename List<T>::Iterator List<T>::end()
{
    return nullptr;
}

template<typename T>const typename List<T>::ConstIterator List<T>::rbegin() const
{
    return Tail;
}

template<typename T>const typename List<T>::ConstIterator List<T>::rend() const
{
    return nullptr;
}

template<typename T>typename List<T>::Iterator List<T>::rbegin()
{
    return Tail;
}

template<typename T>typename List<T>::Iterator List<T>::rend()
{
    return nullptr;
}


//Конструктор по умалчанию
template<typename T>List<T>::List()
{
    Head = Tail = nullptr;
    size = 0;
    cout << "LConstructor: " << this << endl;;
}
//Конструктор принимающий список инициализации
template<typename T>List<T>::List(initializer_list<T> il) : List()
{
    for (int const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}

//Конструктор копирования
template<typename T>List<T>::List(const List& other) : List()
{
    *this = other;
}

//Конструктор переноса
template<typename T>List<T>::List(List&& other) noexcept: Head(other.Head), Tail(other.Tail), size(other.size)
{
    other.Head = other.Tail = nullptr;
    other.size = size_t();
}

//Деструктор
template<typename T>List<T>::~List()
{
    while(Head) pop_back();
    cout << "LDestructor: " << this << endl;
}

//Вывод списка
template<typename T>void List<T>::print() const
{
    for (Element* Temp = Head; Temp;Temp = Temp->pNext)
    {
        cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

//Вывод списка задом наперед
template<typename T>void List<T>::reverse_print()const
{
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
    {
        cout << Temp << tab << Temp->pNext << tab << Temp->Data << tab << Temp->pPrev << endl;
    }
    cout << "Количество элементов списка: " << size << endl;
}

//добавляет значение в начало списка
template<typename T>void List<T>::push_front(T Data)
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
template<typename T>void List<T>::push_back(T Data)
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
template<typename T>void List<T>::pop_front()
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
template<typename T>void List<T>::pop_back()
{
    if (Head == nullptr && Tail == nullptr)return;
    if (Head == Tail)return pop_front();
    Tail = Tail->pPrev;

    delete Tail->pNext;

    Tail->pNext = nullptr;
    size--;
}

//добавляет значение по указанному индексу
template<typename T>void List<T>::insert(T Data, int pos)
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
template<typename T>void List<T>::erase(int pos)
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

template<typename T>List<T>& List<T>::operator=(const List& other)
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

template<typename T>List<T>& List<T>::operator=(List&& other) noexcept
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

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
    List<T> cat;
    for (typename List<T>::ConstIterator it = left.begin(); it != left.end(); ++it)  cat.push_back(*it);
    for (typename List<T>::ConstIterator it = right.begin(); it != right.end(); ++it)cat.push_back(*it);
    return cat;
}

template<typename T>bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other) const
{
    return this->Temp == other.Temp;
}

template<typename T>bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other) const
{
    return this->Temp != other.Temp;
}

template<typename T>const T& List<T>::ConstBaseIterator::operator*()const
{
    return Temp->Data;
}


template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
    ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
    return *this;
}

template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
    ConstIterator old = *this;
    ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
    return old;
}

template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
    ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
    return *this;
}

template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
    ConstIterator old = *this;
    ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
    return old;
}

template<typename T>T& List<T>::Iterator::operator*()
{
    return ConstBaseIterator::Temp->Data;
}
