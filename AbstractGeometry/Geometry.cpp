#include"Geometry.hpp"

/*----------------------------start-class-Shape----------------------------*/

ostream& Shape::print(ostream& ost) const
{
    ost << "Площадь фигуры: " << get_area() << endl;
    ost << "Периметр фигуры: " << get_perimeter() << endl;
    draw();
    return ost;
}
/*------------------------------end-class-Shape------------------------------*/

ostream& operator<<(ostream& ost, const Shape& obj)
{
    return obj.print(ost);
}



/*----------------------------start-class-Square----------------------------*/

double Square::get_side() const
{
    return side;
}

void Square::set_side(double side)
{
    if (side < 2) side = 2;
    if (side > 100) side = 100;
    this->side = side;
}

Square::Square(double side)
{
    set_side(side);
}

Square::~Square()
{
}

double Square::get_area() const
{
    return side * side;
}

double Square::get_perimeter() const
{
    return side * 4;
}

void Square::draw() const
{
    for (size_t i = 0; i < side; i++)
    {
        for (size_t j = 0; j < side; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

ostream& Square::print(ostream& ost) const
{
    ost << typeid(*this).name() << endl;
    ost << "Длинна стороны квадрата" << side << endl;
    Shape::print(ost);
    return ost;
}

double Rectangle::get_length() const
{
    return length;
}

double Rectangle::get_width() const
{
    return width;
}

void Rectangle::set_length(double length)
{
    if (length < 3) length = 3;
    if (length > 30) length = 30;
    this->length = length;
}

void Rectangle::set_width(double width)
{
    if (width < 3)width = 3;
    if (width > 30) width = 30;
    this->width = width;
}
