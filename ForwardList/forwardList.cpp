#include"forwardList.hpp"

int Element::count = 0;
/*----------------------------start-class-Element-------------------------------*/
//Конструктор
Element::Element(int Data, Element* pNext)
    :Data(Data), pNext(pNext) 
{
    count++;
    cout << "EConstructor:\t" << this << endl;
}

//Деструктор
Element::~Element()
{
    count--;
    cout << "EDestructor:\t" << this << endl;
}
/*------------------------------end-class-Element---------------------------*/

/*----------------------------start-class-ForwardList---------------------------*/

size_t ForwardList::get_size() const
{
    return size;
}

Element* ForwardList::get_Head() const
{
    return Head;
}

Element* ForwardList::get_Head_pNext() const
{
    return Head->pNext;
}

int ForwardList::get_Head_Data() const
{
    return Head->Data;
}

void ForwardList::set_Head(Element* pNext)
{
    Head = pNext;
}

//Конструктор
ForwardList::ForwardList(size_t size):Head(nullptr), size(size)
{
    cout << "LConstructor:\t" << this << endl;
}
//Конструктор копирования
ForwardList::ForwardList(ForwardList& other) : ForwardList(other.size)
{
    Element* Temp = other.Head;

    while (Temp)
    {
        push_back(Temp->Data);
        Temp = Temp->pNext;
    }
}
//Конструктор переноса
ForwardList::ForwardList(ForwardList&& other) noexcept
    :size(other.size), Head(other.Head)
{
    other.Head = nullptr;
}


//Деструктор
ForwardList::~ForwardList()
{
    Element* Temp = Head;
    while (Temp)
    {
        Element* tmp = Temp->pNext;
        delete Temp;
        Temp = tmp;
    }
    cout << "LDestructor:\t" << this << endl;
}


///добавляет значение в начало списка
void ForwardList::push_front(int Data)
{
    Head = new Element(Data, Head);
    /*Element* New = new Element(Data);
    New->pNext = Head;
    Head = New;*/
    size++;
}
//удаляет начальный элемент списка
void ForwardList::pop_front()
{
    if (Head != nullptr) {
        //1) Запоминаем адрес следующего элемента
        Element* tmp = Head->pNext;
        //2) Удаляем первый элемент
        delete Head;
        //3) Делаем следующий элемент начальным
        Head = tmp;
    }
    size--;
}


//добавляет значение в конец списка

void ForwardList::push_back(int Data)
{
    //1) Создаем новый элемент
    //Element* New = new Element(Data);
    //2) Если список пустой до просто добавляем значение
    if (Head == nullptr) return push_front(Data);
    // В ином случаее
    else
    {
        //2) Создаем итератор
        Element* Temp = Head;
        //3) Создаем цикл для получения доступа к последнему элементу списка
        while (Temp->pNext != nullptr) {
            // Переходим на следующий элемент
            Temp = Temp->pNext;
        }
        //4) добовляем элемент в конец массива
        Temp->pNext = new Element(Data);
    }
    size++;
}

//удаляет последнее значение списка
void ForwardList::pop_back()
{
    //1) Если список пустой, то ничего не делаем
    if (Head == nullptr) return;

    //2) Если в списке один элемент, удаляем его
    if (Head->pNext == nullptr) pop_front();
    // В ином случаее
    else
    {
        //3) Создаем итератор
        Element* Temp = Head;
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

void ForwardList::insert(int Data, int pos)
{
    if (pos > size)return;
    if (pos == 0)return push_front(Data);
    //1) Создаем новый элемент
    Element* New = new Element(Data);

    //2) Доходим до нужного элемента
    Element* Temp = Head;
    for (size_t i = 0; i < pos - 1; i++)Temp = Temp->pNext;

    //3) поместить элемент в нужную позициию
    New->pNext = Temp->pNext;
    Temp->pNext = New;
    size++;
}

void ForwardList::erase(int pos)
{
    //1) Если список пустой, то ничего не делаем
    if (Head == nullptr) return;

    //2) Если в списке один элемент, удаляем его
    if (Head->pNext == nullptr) pop_front();
    else
    {
        //2) Доходим до нужного элемента
        Element* Temp = Head;
        for (size_t i = 0; i < pos - 1; i++)Temp = Temp->pNext;

        //3) удаляем элемент в нужной позициии

        Element* tmp = Temp->pNext->pNext;
        delete Temp->pNext;
        Temp->pNext = tmp;
        size--;
    }
}



//Вывод списка
void ForwardList::print() const
{
    /*Element* Temp = Head;

    while (Temp)
    {
        cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
        Temp = Temp->pNext;
    }*/
    for (Element* Temp = Head; Temp; Temp = Temp->pNext)
    {
        cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
    }
    cout << "Количество элементов списка: " << size  << endl;
    cout << "Общее количество элементов: " << Element::count  << endl;
}

ForwardList& ForwardList::operator=(const ForwardList& other)
{
    // если списки одинаковые нечего не делаем
    if (this == &other) return *this;
    // если список не пустой то удаляем из него все
    if (Head != nullptr) 
    {
        Element* Temp = Head;
        while (Temp)
        {
            Element* tmp = Temp->pNext;
            delete Temp;
            Temp = tmp;
        }
    }
    // Далее присваиваем
    Element* Temp = other.Head;

    while (Temp)
    {
        push_back(Temp->Data);
        Temp = Temp->pNext;
    }
    size = other.size;
    return *this;
}

ForwardList& ForwardList::operator=(ForwardList&& other) noexcept
{
    // если списки одинаковые нечего не делаем
    if (this == &other) return *this;
    // если список не пустой то удаляем из него все
    if (Head != nullptr)
    {
        Element* Temp = Head;
        while (Temp)
        {
            Element* tmp = Temp->pNext;
            delete Temp;
            Temp = tmp;
        }
    }
    size = other.size;
    Head = other.Head;
    other.Head = nullptr;

    return *this;
}


/*------------------------------end-class-ForwardList---------------------------*/

ForwardList operator+(ForwardList left, ForwardList right)
{
    while (right.get_Head())
    {
        left.push_back(right.get_Head_Data());
        right.set_Head(right.get_Head_pNext());
    }
    return left;
}

bool operator==(ForwardList left, ForwardList right)
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
