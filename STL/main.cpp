﻿//STL
#include<iostream>
#include<array>
#include<vector>
#include<deque>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_DEQUE

template<typename T>void vector_properties(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	
	std::array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			cout << vec[i] << tab;
			//cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << endl << e.what() << endl;
	}
	vector_properties(vec);
	//vec.push_back(134);
	//vec.reserve(25);
	//vec.resize(17);
	vec.insert(vec.begin() + 3, { 1024, 2048, 3072, 4096 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	vector_properties(vec);

	cout << delimiter << endl;

	std::vector<int> vec2(100);
	vector_properties(vec2);
	vec2.push_back(1024);
	vec2.shrink_to_fit();
	vector_properties(vec2);
#endif // STL_VECTOR

#ifdef STL_DEQUE
	//deque - это контейнер который хранит данные в ввиде набора одномерных динамических массивов.
	//Этот контейнер позволяет добовлять элементы как в начала так и в конец за константное время.
#endif // STL_DEQUE

}

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Max size:" << vec.max_size() << endl;
}