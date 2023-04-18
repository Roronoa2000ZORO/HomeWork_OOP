#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include<iostream>
#include<ctime>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


class Tree
{
protected:
    class Element
    {
    private:
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr);
        ~Element();
        friend class Tree;
        friend class UniqueTree;
    }*Root;

    static int Count(Element* Root, size_t size);
    static int Sum(Element* Root, int sum);

public:
    Element* getRoot()const;

    Tree();
    Tree(const std::initializer_list<int>& il);
    ~Tree();



    void insert(int Data, Element* Root);

    void print(Element* Root)const;
    
    int minValue(Element* Root)const;
    int maxValue(Element* Root)const;

    static int Count(Element* Root);
    static int Sum(Element* Root);

    double Avg(Element* Root);

    int Depth(Element* Root);

    //void Clear(Element* Root);

    
};


class UniqueTree :public Tree
{
public:
    void insert(int Data, Element* Root);
};


#endif // !BINARYTREE_HPP
