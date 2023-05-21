#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include<iostream>
#include<ctime>
#include <iomanip>

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
        
        Element(int Data = NULL, Element* pLeft = nullptr, Element* pRight = nullptr);
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

    int Count()const;
    int Sum()const;

    double Avg();

    int Depth();

    void Clear();
    void erase(int Data);
    void balance();
    void print_tree()const;
private:
    void get_Data(Element* Root, Element& elements, size_t i)const;

    int Count(Element* Root, int size)const;
    int Sum(Element* Root, int sum)const;

    void insert(int Data, Element* Root);

    void print(Element* Root)const;
    
    int minValue(Element* Root)const;
    int maxValue(Element* Root)const;

    double Avg(Element* Root);

    int Depth(Element* Root);

    void Clear(Element* Root);

    void erase(int Data, Element*& Root);

    void balance(Element* Root, const int SIZE);
    void printTree(Element* Root);
    
};


class UniqueTree :public Tree
{
    void insert(int Data, Element* Root);
public:
    void insert(int Data);
};


#endif // !BINARYTREE_HPP
