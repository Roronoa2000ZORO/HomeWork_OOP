#include"forwardList.hpp"


/*----------------------------start-class-Element-------------------------------*/
//Конструктор
Element::Element(int Data, Element* pNext)
    :Data(Data), pNext(pNext) 
{
    cout << "EConstructor:\t" << this << endl;
}
//Деструктор
Element::~Element()
{
    pNext = nullptr;
    cout << "EDestructor:\t" << this << endl;
}
/*------------------------------end-class-Element---------------------------*/

/*----------------------------start-class-ForwardList---------------------------*/

//Конструктор
ForwardList::ForwardList():Head(nullptr)
{
    cout << "LConstructor:\t" << this << endl;
}
//Деструктор
ForwardList::~ForwardList()
{
    cout << "LDestructor:\t" << this << endl;
}


///добавляет значение в начало списка
void ForwardList::push_front(int Data)
{
    Element* New = new Element(Data);
    New->pNext = Head;
    Head = New;
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
}


//добавляет значение в конец списка

void ForwardList::push_back(int Data)
{
    //1) Создаем новый элемент
    Element* New = new Element(Data);
    //2) Если список пустой до просто добавляем значение
    if (Head == nullptr) Head = New;
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
        Temp->pNext = New;
    }
}

//удаляет последнее значение списка
void ForwardList::pop_back()
{
    //1) Если список пустой, то ничего не делаем
    if (Head == nullptr) return;

    //2) Если в списке один элемент, удаляем его
    if (Head->pNext == nullptr) 
    {
        delete Head;
        Head = nullptr;
    }
    // В ином случаее
    else
    {
        //3) Создаем итератор
        Element* Temp = Head;
        //4) Создаем цикл для получения доступа к последнему элементу списка
        while (Temp->pNext != nullptr) {
            // Переходим на следующий элемент
            Temp = Temp->pNext;
        }
        //5) удаляем последний элемент
        delete Temp;
        
    }
}



//Вывод списка
void ForwardList::print() const
{
    Element* Temp = Head;

    while (Temp)
    {
        cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
        Temp = Temp->pNext;
    }
}


/*------------------------------end-class-ForwardList---------------------------*/
