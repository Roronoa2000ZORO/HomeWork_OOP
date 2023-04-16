#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include<iostream>

using namespace std;



class BinaryTree
{
    class Element
    {
    private:
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr);
        ~Element();
        friend class BinaryTree;
    }*Root;

    static int Count(Element* Root, size_t size);
    static int Sum(Element* Root, int sum);

public:
    Element* getRoot()const;

    BinaryTree();
    ~BinaryTree();



    void insert(int Data, Element* Root);

    void print(Element* Root)const;
    
    int minValue(Element* Root)const;
    int maxValue(Element* Root)const;

    static int Count(Element* Root);
    static int Sum(Element* Root);
};


#endif // !BINARYTREE_HPP
