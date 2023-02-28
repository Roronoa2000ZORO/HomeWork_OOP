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

char String::set_str(char sign, int j)
{
    return str[j] = sign;
}


                        /*Constructors*/

//Constructor № 1.1
String::String(int size)
{
    this->size = size;
    str = new char[size] {};
}
//Constructor № 1.2
String::String(const char str[80])
{
    size = 80;
    this->str = new char[size] {};
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        this->str[i] = str[i];
    }
}
//Copy Constructor
String::String(const String& other)
{
    size = other.size;
    str = new char[size] {};
    for (size_t i = 0; other.str[i] != '\0'; i++)
    {
        str[i] = other.str[i];
    }
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
    size = other.size;
    str = new char[size] {};
    for (size_t i = 0; other.str[i] != '\0'; i++)
    {
        str[i] = other.str[i];
    }
    return *this;
}




/*--------------------------------------end-Class--------------------------------------------------*/


                                        /*Operators*/

//Operator addition
String operator+(const String& left, const String& right)
{
    String result;
    int j = 0;
    for (size_t i = 0; left.get_str()[i] != '\0'; i++, j++)
    {
        
        result.set_str(left.get_str()[i], j);
    }
    for (size_t i = 0; right.get_str()[i] != '\0'; i++, j++)
    {
        
        result.set_str(right.get_str()[i], j);
    }
    return result;
}
//The insertion operator
ostream& operator<<(ostream& ost, const String& obj)
{
    for (size_t i = 0; obj.get_str()[i] != '\0'; i++)
    {
        ost << obj.get_str()[i];
    }
    return ost;
}
