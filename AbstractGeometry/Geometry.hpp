#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#define _USE_MATH_DEFINES

//#include<Windows.h>
#include<iostream>
#include <cmath>

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


/*----------------------------start-class-Rectangle----------------------------*/
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


    Rectangle(double width, double length);
    ~Rectangle();

    double get_area()const override;
    double get_perimeter()const override;
    void draw()const override;

    ostream& print(ostream& ost)const override;
};
/*------------------------------end-class-Rectangle------------------------------*/


/*----------------------------start-class-Circle----------------------------*/
class Circle : public Shape
{
private:
    double diameter;
    double radius;
public:
    double get_diameter()const;
    double get_radius()const;

    void set_diameter(double diameter);
    void set_radius(double radius);

    Circle(double diameter);
    ~Circle();

    double get_area()const override;
    double get_perimeter()const override;
    void draw()const override;

    ostream& print(ostream& ost)const override;
};

/*------------------------------end-class-Circle------------------------------*/


#endif // !GEOMETRY_HPP




