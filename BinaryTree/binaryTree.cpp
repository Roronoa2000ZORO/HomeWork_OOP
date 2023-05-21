#include"binaryTree.hpp"

#define DEBUG

Tree::Element::Element(int Data, Element* pLeft, Element* pRight)
    :Data(Data), pLeft(pLeft), pRight(pRight) 
{
#ifdef DEBUG
    cout << "EConstructor " << this << endl;
#endif // DEBUG

}

Tree::Element::~Element() 
{
#ifdef DEBUG
    cout << "EDestructor " << this << endl;
#endif // DEBUG
}

int Tree::Count(Element* Root, int size)const
{
    if (Root == nullptr)return size;

    size = Count(Root->pLeft, size + 1);
    size = Count(Root->pRight, size + 1);
    return size - 1;
}

int Tree::Sum(Element* Root, int sum)const
{
    if (Root == nullptr)return 0;
    sum += Sum(Root->pLeft, sum) + Sum(Root->pRight, sum);
    return sum + Root->Data;
}


Tree::Element* Tree::getRoot() const
{
    return Root;
}

Tree::Tree()
    :Root(nullptr) 
{
    cout << "BConstructor " << this << endl;
}

Tree::Tree(const std::initializer_list<int>& il) :Tree()
{
    for (int const* it = il.begin(); it != il.end(); ++it)
    {
        insert(*it, Root);
    }
}

Tree::~Tree() 
{
    this->Clear(Root);
    cout << "BDestructor " << this << endl;
}

void Tree::insert(int Data)
{
    return insert(Data, Root);
}

void Tree::print() const
{
    return print(Root);
}

int Tree::minValue() const
{
    return minValue(Root);
}

int Tree::maxValue() const
{
    return maxValue(Root);
}


void Tree::insert(int Data, Element* Root)
{
    if (this->Root == nullptr)this->Root = new Element(Data);
    if (Root == nullptr)return;
    if (Data < Root->Data)
    {
        if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
        else insert(Data, Root->pLeft);
    }
    else
    {
        if (Root->pRight == nullptr)Root->pRight = new Element(Data);
        else insert(Data, Root->pRight);
    }
}

void Tree::print(Element* Root) const
{
    if (Root == nullptr)return;
    print(Root->pLeft);
    cout << Root->Data << "\t";
    print(Root->pRight);
}

int Tree::minValue(Element* Root) const
{
    /*if (Root == nullptr)return 0;
    if (Root->pLeft == nullptr)return Root->Data;
    return minValue(Root->pLeft);*/
    return Root == nullptr ? 0 : Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
}

int Tree::maxValue(Element* Root) const
{
    /*if (Root == nullptr)return 0;
    if (Root->pRight == nullptr)return Root->Data;
    return maxValue(Root->pRight);*/
    return Root == nullptr ? 0 : Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
}


int Tree::Count() const
{
    return Root == nullptr ? 0 : Count(Root, 0);
}

int Tree::Sum()const
{
    return Root == nullptr ? 0 : Sum(Root, 0);
}

double Tree::Avg()
{
    return Avg(Root);
}

int Tree::Depth()
{
    return Depth(Root);
}

void Tree::Clear()
{
    Clear(Root);
    Root = nullptr;
}

void Tree::erase(int Data)
{
    erase(Data, Root);
}

void Tree::balance()
{ 
    balance(Root, Count());
}

void Tree::print_tree()const
{
    printTree(Root);
}

void Tree::get_Data(Element* Root, Element& elements, size_t i) const
{
    if (Root == nullptr)return;
    elements;
    get_Data(Root->pLeft, elements, i + 1);
    get_Data(Root->pRight, elements, i);

}

double Tree::Avg(Element* Root)
{
    return (double)Sum() / Count();
}

int Tree::Depth(Element* Root)
{
    if (Root == nullptr)return 0;

    /*if (Depth(Root->pLeft) + 1 > Depth(Root->pRight) + 1)return Depth(Root->pLeft) + 1;
    else return Depth(Root->pRight) + 1;*/

    int l_depth = Depth(Root->pLeft);
    int r_depth = Depth(Root->pRight);

    /*if (l_depth > r_depth)return l_depth + 1;
    else return r_depth + 1;*/
    return l_depth > r_depth ? l_depth + 1 : r_depth + 1;//     тернарный вариант
    
}

void Tree::Clear(Element* Root)
{
    if (Root == nullptr)return;
    Clear(Root->pLeft);
    Clear(Root->pRight);
    delete Root;
}

void Tree::erase(int Data, Element*& Root)
{
    if (Root == nullptr)return;
    erase(Data, Root->pLeft);
    erase(Data, Root->pRight);
    if (Data == Root->Data)
    {
        if (Root->pLeft == Root->pRight)
        {
            delete Root;
            Root = nullptr;
        }
        else
        {
            if (Count(Root->pLeft, 0) > Count(Root->pRight, 0))
            {
                Root->Data = maxValue(Root->pLeft);
                erase(maxValue(Root->pLeft), Root->pLeft);
            }
            else
            {
                Root->Data = maxValue(Root->pRight);
                erase(maxValue(Root->pRight), Root->pRight);
            }
        }
    }
}

void Tree::balance(Element* Root, const int SIZE)
{
    Element* elements = new Element[SIZE];

    //get_Data(Root, elements);
    delete[] elements;
}



void UniqueTree::insert(int Data, Element* Root)
{
    if (this->Root == nullptr)this->Root = new Element(Data);
    if (Root == nullptr)return;
    if (Data < Root->Data)
    {
        if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
        else insert(Data, Root->pLeft);
    }
    else if(Data > Root->Data)
    {
        if (Root->pRight == nullptr)Root->pRight = new Element(Data);
        else insert(Data, Root->pRight);
    }
}

void UniqueTree::insert(int Data)
{
    insert(Data, Root);
}

void Tree::printTree(Element* Root)
{
    if (Root == nullptr)return;
    print(Root->pLeft);
    cout << Root->Data << "\t";
    print(Root->pRight);

}