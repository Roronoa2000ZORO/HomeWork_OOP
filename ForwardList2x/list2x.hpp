#ifndef LIST2X_HPP
#define LIST2X_HPP

#include<iostream>
using namespace std;

#define tab "\t"

template<typename T>
class List
{
private:
	class Element
	{
	private:
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
		
	}*Head, *Tail;

	size_t size;
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp = nullptr) :Temp(Temp) {}
		~ConstBaseIterator() {}

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		

		const T& operator*()const;
	};
	
public:
	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstIterator() {}

		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :ConstIterator(Temp) {}
		~Iterator() {}
		T& operator*();
	};

	const ConstIterator begin()const;
	const ConstIterator end()const;
	Iterator begin();
	Iterator end();

	const ConstIterator rbegin()const;
	const ConstIterator rend()const;
	Iterator rbegin();
	Iterator rend();


	List();

	List(initializer_list<T> il);

	List(const List& other);
	List(List&& other)noexcept;

	~List();


	

	void print()const;
	void reverse_print()const;

	void push_front(T Data);
	void push_back(T Data);

	void pop_front();
	void pop_back();

	void insert(T Data, int pos);
	void erase(int pos);



	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

	
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);

#endif // !LIST2X

