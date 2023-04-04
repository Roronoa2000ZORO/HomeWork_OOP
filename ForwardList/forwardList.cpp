#include"forwardList.hpp"


template<typename T>
int Element<T>::count = 0;
/*----------------------------start-class-Element-------------------------------*/
//Конструктор
template<typename T>Element<T>::Element(T Data, Element<T>* pNext)
    :Data(Data), pNext(pNext) 
{
    count++;
    cout << "EConstructor:\t" << this << endl;
}

//Деструктор
template<typename T>Element<T>::~Element()
{
    count--;
    cout << "EDestructor:\t" << this << endl;
}
/*------------------------------end-class-Element---------------------------*/

/*----------------------------start-class-ForwardList---------------------------*/

//Iterator ForwardList::begin()
//{
//    return Head;
//}

template<typename T>Iterator<T> ForwardList<T>::begin()
{
    return Head;
}

template<typename T>Iterator<T> ForwardList<T>::end()
{
    return nullptr;
}

template<typename T>ConstIterator<T> ForwardList<T>::begin() const
{
    return Head;
}

template<typename T>ConstIterator<T> ForwardList<T>::end()const
{
    return nullptr;
}

template<typename T>size_t ForwardList<T>::get_size() const
{
    return size;
}

template<typename T>Element<T>* ForwardList<T>::get_Head() const
{
    return Head;
}

template<typename T>Element<T>* ForwardList<T>::get_Head_pNext() const
{
    return Head->pNext;
}

template<typename T>T ForwardList<T>::get_Head_Data() const
{
    return Head->Data;
}

template<typename T>void ForwardList<T>::set_Head(Element<T>* pNext)
{
    Head = pNext;
}

//Конструктор
template<typename T>ForwardList<T>::ForwardList(size_t size):Head(nullptr), size(size)
{
    cout << "LConstructor:\t" << this << endl;
}
//Конструктор копирования
template<typename T>ForwardList<T>::ForwardList(const ForwardList<T>& other) : ForwardList(other.size)
{
    *this = other;
}
template<typename T>ForwardList<T>::ForwardList(initializer_list<T> il):ForwardList<T>()
{
    for (T const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}
//Конструктор переноса
template<typename T>ForwardList<T>::ForwardList(ForwardList<T>&& other) noexcept
    :size(other.size), Head(other.Head)
{
    other.Head = nullptr;
    other.size = 0;
}


//Деструктор
template<typename T>ForwardList<T>::~ForwardList()
{
    while (Head)pop_front();
    cout << "LDestructor:\t" << this << endl;
}


///добавляет значение в начало списка
template<typename T>void ForwardList<T>::push_front(T Data)
{
    Head = new Element<T>(Data, Head);
    /*Element* New = new Element(Data);
    New->pNext = Head;
    Head = New;*/
    size++;
}
//удаляет начальный элемент списка
template<typename T>void ForwardList<T>::pop_front()
{
    if (Head != nullptr) {
        //1) Запоминаем адрес следующего элемента
        Element<T>* tmp = Head->pNext;
        //2) Удаляем первый элемент
        delete Head;
        //3) Делаем следующий элемент начальным
        Head = tmp;
    }
    size--;
}


//добавляет значение в конец списка

template<typename T>void ForwardList<T>::push_back(T Data)
{
    
    if (Head == nullptr) return push_front(Data);
    // В ином случаее
    else
    {
        //2) Создаем итератор
        Element<T>* Temp = Head;
        //3) Создаем цикл для получения доступа к последнему элементу списка
        while (Temp->pNext != nullptr) {
            // Переходим на следующий элемент
            Temp = Temp->pNext;
        }
        //4) добовляем элемент в конец массива
        Temp->pNext = new Element<T>(Data);
    }

    size++;
}

//удаляет последнее значение списка
template<typename T>void ForwardList<T>::pop_back()
{
    //1) Если список пустой, то ничего не делаем
    if (Head == nullptr) return;

    //2) Если в списке один элемент, удаляем его
    if (Head->pNext == nullptr) pop_front();
    // В ином случаее
    else
    {
        //3) Создаем итератор
        Element<T>* Temp = Head;
        //4) Создаем цикл для получения доступа к последнему элементу списка
        while (Temp->pNext->pNext != nullptr) {
            // Переходим на следующий элемент
            Temp = Temp->pNext;
        }
        //5) удаляем последний элемент
        delete Temp->pNext;
        Temp->pNext = nullptr;
        
    }

    size--;
}

template<typename T>void ForwardList<T>::insert(T Data, int pos)
{
    if (pos > size)return;
    if (pos == 0)return push_front(Data);
    //1) Создаем новый элемент
    Element<T>* New = new Element<T>(Data);

    //2) Доходим до нужного элемента
    Element<T>* Temp = Head;
    for (size_t i = 0; i < pos - 1; i++)Temp = Temp->pNext;

    //3) поместить элемент в нужную позициию
    New->pNext = Temp->pNext;
    Temp->pNext = New;
    size++;
}

template<typename T>void ForwardList<T>::erase(int pos)
{
    //1) Если список пустой, то ничего не делаем
    if (Head == nullptr) return;
    if (pos > size)return;
    //2) Если в списке один элемент, удаляем его
    if (Head->pNext == nullptr) pop_front();
    else
    {
        //2) Доходим до нужного элемента
        Element<T>* Temp = Head;
        for (size_t i = 0; i < pos - 1; i++)Temp = Temp->pNext;

        //3) удаляем элемент в нужной позициии

        Element<T>* tmp = Temp->pNext->pNext;
        delete Temp->pNext;
        Temp->pNext = tmp;
        size--;
    }
}

template<typename T>void ForwardList<T>::reverse()
{
    ForwardList<T> buffer;
    while (Head)
    {
        buffer.push_front(Head->Data);
        pop_front();
    }

    Head = buffer.Head;
    buffer.Head = nullptr;
}



//Вывод списка
template<typename T>void ForwardList<T>::print() const
{
    /*Element* Temp = Head;

    while (Temp)
    {
        cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
        Temp = Temp->pNext;
    }*/
    for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
    {
        cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
    }
    cout << "Количество элементов списка: " << size  << endl;
    cout << "Общее количество элементов: " << Element<T>::count  << endl;
}

template<typename T>ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
    // если списки одинаковые нечего не делаем
    if (this == &other) return *this;
    // если список не пустой то удаляем из него все
    if (Head != nullptr)while (Head)pop_front();
    // Далее присваиваем
    
    for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
    {
        push_front(Temp->Data);
    }
    reverse();
    size = other.size;
    return *this;
}

template<typename T>ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other) noexcept
{
    // если списки одинаковые нечего не делаем
    if (this == &other) return *this;
    // если список не пустой то удаляем из него все
    if (Head != nullptr)while (Head)pop_front();


    size = other.size;
    Head = other.Head;
    other.Head = nullptr;

    return *this;
}


/*------------------------------end-class-ForwardList---------------------------*/

template<typename T>ForwardList<T> operator+(ForwardList<T> left, ForwardList<T> right)
{
    while (right.get_Head())
    {
        left.push_back(right.get_Head_Data());
        right.set_Head(right.get_Head_pNext());
    }
    return left;
}

template<typename T>bool operator==(ForwardList<T> left, ForwardList<T> right)
{
    if (left.get_size() == right.get_size())
    {
        while (left.get_Head())
        {
            if (left.get_Head_Data() != right.get_Head_Data()) return false;
            left.set_Head(left.get_Head_pNext());
            right.set_Head(right.get_Head_pNext());
        }
        return true;
    }else return false;
}


template<typename T>ConstIterator<T>::ConstIterator(Element<T>* Temp):Temp(Temp)
{
}

template<typename T>ConstIterator<T>::~ConstIterator()
{
}

template<typename T>ConstIterator<T>& ConstIterator<T>::operator++()
{
    Temp = Temp->pNext;
    return *this;
}

template<typename T>bool ConstIterator<T>::operator==(const ConstIterator<T>& other)
{
    return this->Temp == other.Temp;
}

template<typename T>bool ConstIterator<T>::operator!=(const ConstIterator<T>& other)
{
    return this->Temp != other.Temp;
}

template<typename T>const T& ConstIterator<T>::operator*()const
{
    return Temp->Data;
}

template<typename T>Iterator<T>::Iterator(Element<T>* Temp):Temp(Temp)
{
}

template<typename T>Iterator<T>::~Iterator()
{
}

template<typename T>Iterator<T>& Iterator<T>::operator++()
{
    Temp = Temp->pNext;
    return *this;
}

template<typename T>bool Iterator<T>::operator==(const Iterator<T>& other)
{
    return this->Temp == other.Temp;
}

template<typename T>bool Iterator<T>::operator!=(const Iterator<T>& other)
{
    return this->Temp != other.Temp;
}

template<typename T>T& Iterator<T>::operator*()
{
    return Temp->Data;
}


template<typename T>void const print(const ForwardList<T>& list)
{
    for (const T& i : list)
    {
        cout << i << "\t";
    }
    cout << endl;
}
