#ifndef DISTANCE_HW_HPP
#define DISTANCE_HW_HPP

#include <iostream>

using namespace std;

class Point {
public:
	/*������������ �������*/

	double get_y() const;
	double get_x() const;
	void set_y(double y);
	void set_x(double x);
	/*____________________*/

	//����������� ������ � ������� �������
	Point(double y, double x);
	//����������
	~Point();

	//����� ���������� ��������� ����� ���� �����
	double distance(const Point& specified) const;
	//������ �������� ���������
	void Print() const;
	
private:
	double y;
	double x;
};


//������� ���������� ��������� ����� ���� �����
double Distance(const Point A, const Point B);

void PrintDistance(const Point A, const Point B);



#endif // !DISTANCE_HW_HPP
