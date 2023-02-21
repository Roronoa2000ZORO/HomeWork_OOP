#include "distance_hw.hpp"

//class Point:

double Point::get_y() const {
    return y;
}
double Point::get_x() const {
    return x;
}
void Point::set_y(double y) {
    this->y = y;
}
void Point::set_x(double x) {
    this->x = x;
}

Point::Point(double y, double x) {
    this->x = x;
    this->y = y;
}

Point::~Point() {}

double Point::distance(const Point& specified) const{
    double y_distance = this->y - specified.y;
    double x_distance = this->x - specified.x;
    double distance = sqrt(y_distance * y_distance + x_distance * x_distance);
    return distance;
}

void Point::Print() const{
    cout << "y = " << y << "\tx = " << x << endl;
}


// functions:

double Distance(const Point A, const Point B){
    double y_distance = A.get_y() - B.get_y();
    double x_distance = A.get_x() - B.get_x();
    double distance = sqrt(y_distance * y_distance + x_distance * x_distance);
    return distance;
}

void PrintDistance(const Point A, const Point B){
    cout << "Метод distance" << endl;
    cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
    cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
    cout << "\nФункция Distance" << endl;
    cout << "Расстояние между точками A и B: " << Distance(A, B) << endl;
    cout << "Расстояние между точками B и A: " << Distance(B, A) << endl;
}
