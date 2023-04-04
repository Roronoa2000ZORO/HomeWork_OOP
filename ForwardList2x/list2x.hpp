#ifndef LIST2X_HPP
#define LIST2X_HPP

#include<iostream>
using namespace std;

#define tab "\t"

class List
{
private:
	class Element
	{
	private:
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	}*Head, *Tail;
	
	size_t size;
public:
	List();
	~List();


	void push_front(int Data);

	void print()const;

	void reverse_print()const;

	void push_back(int Data);


	void pop_front();
	void pop_back();

	void insert(int Data, int pos);
};

#endif // !LIST2X

