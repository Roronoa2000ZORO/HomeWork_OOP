#include"string.hpp"


/*--------------------------------------start-Class------------------------------------------------*/

int String::get_size() const
{
    return size;
}

const char* String::get_str() const
{
    return str;
}

char* String::get_str()
{
    return str;
}


                        /*Constructors*/

//Constructor № 1.1
String::String(int size) :size(size), str(new char[size] {})
{   
}
//Constructor № 1.2
String::String(const char* str):String((int)strlen(str) + 1)
{
    for (size_t i = 0; str[i]; i++)
    {
        this->str[i] = str[i];
    }
}
//Copy Constructor
String::String(const String& other): size(other.size), str(new char[size] {})
{
    for (size_t i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }
}
//Move constructor
String::String(String&& obj) noexcept : size(obj.size), str(obj.str)
{
    obj.str = nullptr;
}
//Destructor
String::~String()
{
    delete[] str;
    str = nullptr;
}
//Operator direct assignment
String& String::operator=(const String& other)
{
    if (this == &other) return *this;
    delete[] str;

    size = other.size;
    str = new char[size] {};
    for (size_t i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }
    return *this;
}
//Operator addition assignment
String& String::operator+=(const String& other)
{
    return *this = *this + other;
}
//Operator subscript
char String::operator[](int i) const
{
    return str[i];
}
//Operator subscript
char& String::operator[](int i)
{
    return str[i];
}
//Move assignment
String& String::operator=(String&& other) noexcept
{
    if (this == &other) return *this;

    delete[] str;
    size = other.size;
    str = other.str;
    other.str = nullptr;
    
    return *this;
}







/*--------------------------------------end-Class--------------------------------------------------*/


                                        /*Operators*/

//Operator addition
String operator+(const String& left, const String& right)
{
    String result(left.get_size() + right.get_size() - 1);
    
    for (int i = 0; i < left.get_size(); i++)
    { 
        result[i] = left[i];
    }
    for (int i = 0; i < right.get_size(); i++)
    { 
        result[i + left.get_size() - 1] = right[i];
    }
    return result;
}
//The insertion operator
ostream& operator<<(ostream& ost, const String& obj)
{
    return ost << obj.get_str();
}
