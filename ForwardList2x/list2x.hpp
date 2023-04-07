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
	
	class Iterator
	{
	private:
		Element* Temp;
	public:
		
		Iterator(Element* Temp);
		~Iterator();

		Iterator& operator++();
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);

		int& operator*();
	
	};

	size_t size;
public:

	Iterator begin();
	Iterator end();




	List();

	List(initializer_list<int> il);

	List(const List& other);
	List(List&& other)noexcept;

	~List();


	

	void print()const;
	void reverse_print()const;

	void push_front(int Data);
	void push_back(int Data);

	void pop_front();
	void pop_back();

	void insert(int Data, int pos);
	void erase(int pos);



	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;
};

#endif // !LIST2X

