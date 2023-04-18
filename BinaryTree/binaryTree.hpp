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

    

public:
    Element* getRoot()const;

    Tree();
    Tree(const std::initializer_list<int>& il);
    ~Tree();


    void insert(int Data);

    void print()const;

    int minValue()const;
    int maxValue()const;

    int Count();
    int Sum();

    double Avg();

    int Depth();

    void Clear();
    void erase(int Data);
private:
    int Count(Element* Root, size_t size);
    int Sum(Element* Root, int sum);

    void insert(int Data, Element* Root);

    void print(Element* Root)const;
    
    int minValue(Element* Root)const;
    int maxValue(Element* Root)const;

    double Avg(Element* Root);

    int Depth(Element* Root);

    void Clear(Element* Root);

    void erase(int Data, Element*& Root);

    
};


class UniqueTree :public Tree
{
    void insert(int Data, Element* Root);
public:
    void insert(int Data);
};


#endif // !BINARYTREE_HPP
