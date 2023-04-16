#include"binaryTree.hpp"

BinaryTree::Element::Element(int Data, Element* pLeft, Element* pRight)
    :Data(Data), pLeft(pLeft), pRight(pRight) 
{
    cout << "EConstructor " << this << endl;
}

BinaryTree::Element::~Element() 
{
    cout << "EDestructor " << this << endl;
}

int BinaryTree::Count(Element* Root, size_t size)
{
    if (Root == nullptr)return size;

    size = Count(Root->pLeft, size + 1);
    size = Count(Root->pRight, size + 1);
    return size - 1;
}

int BinaryTree::Sum(Element* Root, int sum)
{
    if (Root == nullptr)return 0;
    sum += Sum(Root->pLeft, sum) + Sum(Root->pRight, sum);
    return sum + Root->Data;
}


BinaryTree::Element* BinaryTree::getRoot() const
{
    return Root;
}

BinaryTree::BinaryTree()
    :Root(nullptr) 
{
    cout << "BConstructor " << this << endl;
}

BinaryTree::~BinaryTree() 
{
    cout << "BDestructor " << this << endl;
}

void BinaryTree::insert(int Data, Element* Root)
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

void BinaryTree::print(Element* Root) const
{
    if (Root == nullptr)return;
    print(Root->pLeft);
    cout << Root->Data << "\t";
    print(Root->pRight);
}

int BinaryTree::minValue(Element* Root) const
{
    /*if (Root == nullptr)return 0;
    if (Root->pLeft == nullptr)return Root->Data;
    return minValue(Root->pLeft);*/
    return Root == nullptr ? 0 : Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
}

int BinaryTree::maxValue(Element* Root) const
{
    /*if (Root == nullptr)return 0;
    if (Root->pRight == nullptr)return Root->Data;
    return maxValue(Root->pRight);*/
    return Root == nullptr ? 0 : Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
}


int BinaryTree::Count(Element* Root)
{
    return Count(Root, 0);
}

int BinaryTree::Sum(Element* Root)
{
    return Root == nullptr ? 0 : Sum(Root, 0);
}

