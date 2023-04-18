#include"binaryTree.hpp"

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

int Tree::Count(Element* Root, size_t size)
{
    if (Root == nullptr)return size;

    size = Count(Root->pLeft, size + 1);
    size = Count(Root->pRight, size + 1);
    return size - 1;
}

int Tree::Sum(Element* Root, int sum)
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

    cout << "BDestructor " << this << endl;
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


int Tree::Count(Element* Root)
{
    return Root == nullptr ? 0 : Count(Root, 0);
}

int Tree::Sum(Element* Root)
{
    return Root == nullptr ? 0 : Sum(Root, 0);
}

double Tree::Avg(Element* Root)
{
    return (double)Sum(Root) / Count(Root);
}

int Tree::Depth(Element* Root)
{
    if (Root == nullptr)return 0;

    /*if (Depth(Root->pLeft) + 1 > Depth(Root->pRight) + 1)return Depth(Root->pLeft) + 1;
    else return Depth(Root->pRight) + 1;*/

    int l_depth = Depth(Root->pLeft);
    int r_depth = Depth(Root->pRight);

    if (l_depth > r_depth)return l_depth + 1;
    else return r_depth + 1;
    //return l_depth > r_depth ? l_depth + 1 : r_depth + 1;        тернарный вариант
    
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
