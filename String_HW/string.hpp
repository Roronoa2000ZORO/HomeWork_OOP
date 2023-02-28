#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
using namespace std;


class String {
    int size;
    char* str;
public:
                    /*get Methods*/
    int get_size()const;
    const char* get_str()const;

    char set_str(char sign, int j);

                    /*Constructors*/
    //Constructor ¹ 1.1
    String(int size = 80);
    //Constructor ¹ 1.2
    String(const char str[80]);
    //Copy Constructor
    String(const String& other);
    //Destructor
    ~String();


                    /*Methods*/

                    /*Operators*/
    //Operator direct assignment
    String& operator=(const String& other);
    


};

                    /*Function*/


                    /*Operators*/
//Operator addition
String operator+(const String& left, const String& right);

//The insertion operator
ostream& operator<<(ostream& ost, const String& obj);

#endif // !STRING_HPP
