#ifndef DISTANCE_HW_HPP
#define DISTANCE_HW_HPP

#include <iostream>

using namespace std;

class Point {
public:
	/*Модификаторы доступа*/

	double get_y() const;
	double get_x() const;
	void set_y(double y);
	void set_x(double x);
	/*____________________*/

	//Конструктор Широты и Долготы объекта
	Point(double y, double x);
	//Деструктор
	~Point();

	//Метод вычисление дистанции между двух точек
	double distance(const Point& specified) const;
	//Печать значений координат
	void Print() const;
	
private:
	double y;
	double x;
};


//Функция вычисления дистанции между двух точек
double Distance(const Point A, const Point B);

void PrintDistance(const Point A, const Point B);



#endif // !DISTANCE_HW_HPP
