#ifndef STRING_HPP
#define STRING_HPP
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


class String {
    int size;
    char* str;
public:
                    /*get Methods*/
    int get_size()const;
    const char* get_str()const;
    char* get_str();

                    /*Constructors*/
    //Constructor № 1.1
    String(int size = 80);
    //Constructor № 1.2
    String(const char* str);
    //Copy Constructor
    String(const String& other);
    //Move constructor
    String(String&& obj) noexcept;

    //Destructor
    ~String();


                    /*Methods*/

                    /*Operators*/
    //Operator direct assignment
    String& operator=(const String& other);
    //Addition assignment
    String& operator+=(const String& other);
    //Subscript
    char operator[](int i)const;
    char& operator[](int i);
    //Move assignment
    String& operator=(String&& other) noexcept;
    
                    /*Type - cast operators*/

    

};

                    /*Function*/


                    /*Operators*/
//Operator addition
String operator+(const String& left, const String& right);

//The insertion operator
ostream& operator<<(ostream& ost, const String& obj);

#endif // !STRING_HPP
