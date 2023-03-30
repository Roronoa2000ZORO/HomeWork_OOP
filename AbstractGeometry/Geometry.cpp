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
    ost << "Длинна стороны квадрата " << side << endl;
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

Rectangle::Rectangle(double width, double length)
{
    set_width(width);
    set_length(length);
}

Rectangle::~Rectangle()
{
}

double Rectangle::get_area() const
{
    return length * width;
}

double Rectangle::get_perimeter() const
{
    return (length + width) * 2;
}

void Rectangle::draw() const
{
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

ostream& Rectangle::print(ostream& ost) const
{
    ost << typeid(*this).name() << endl;
    ost << "Длинна прямоугольника " << length << endl;
    ost << "Ширина прямоугольника " << width << endl;
    Shape::print(ost);
    return ost;
}


double Circle::get_diameter() const
{
    return diameter;
}

double Circle::get_radius() const
{
    return radius;
}

void Circle::set_diameter(double diameter)
{
    if (diameter < 10)this->diameter = 10;
    this->diameter = diameter;
    radius = diameter / 2;
}

void Circle::set_radius(double radius)
{
    if (radius < 5)radius = 5;
    this->radius = radius;
    diameter = radius * 2;
}

Circle::Circle(double diameter)
{
    set_diameter(diameter);
}

Circle::~Circle()
{
}

double Circle::get_area() const
{
    return M_PI * (radius * radius);
}

double Circle::get_perimeter() const
{
    return 2 * M_PI * radius;
}

void Circle::draw() const
{
    for (int y = diameter - radius; y <= diameter + radius; y++)
    {
        for (int x = diameter - radius; x <= diameter + radius; x++)
        {
            if (std::sqrt((x - diameter) * (x - diameter) + (y - diameter) * (y - diameter)) <= radius)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

ostream& Circle::print(ostream& ost) const
{
    ost << typeid(*this).name() << endl;
    ost << "Диаметр круга " << diameter << endl;
    ost << "Радиус круга " << radius << endl;
    Shape::print(ost);
    return ost;
}
