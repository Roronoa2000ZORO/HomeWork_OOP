#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include<Windows.h>
#include<iostream>

using namespace std;


/*----------------------------start-class-Shape----------------------------*/
class Shape
{
public:
    virtual double get_area()const = 0;
    virtual double get_perimeter()const = 0;
    virtual void draw()const = 0;

    virtual ostream& print(ostream& ost)const;
};
/*------------------------------end-class-Shape------------------------------*/


ostream& operator<<(ostream& ost, const Shape& obj);

/*----------------------------start-class-Square----------------------------*/
class Square :public Shape
{
private:
    double side;
public:
    double get_side()const;
    void set_side(double side);


    Square(double side);
    ~Square();

    double get_area()const override;
    double get_perimeter()const override;
    void draw()const override;

    ostream& print(ostream& ost)const override;


};
/*------------------------------end-class-Square------------------------------*/


/*----------------------------start-class-Square----------------------------*/
class Rectangle : public Shape 
{
private:
    double length;
    double width;
public:
    double get_length()const;
    double get_width()const;

    void set_length(double length);
    void set_width(double width);

};


#endif // !GEOMETRY_HPP




