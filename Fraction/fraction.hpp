#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
using namespace std;


class Fraction {
public:
            /*������������ �������*/

    int get_numerator() const;
    int get_denominator() const;
    int get_wholePart() const;
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    void set_wholePart(int wholePart);

    //�����������
    Fraction(int wholePart = int(), int numerator = int(), int denominator = int());
    //����������� �����������
    Fraction(const Fraction& other);
    //����������
    ~Fraction();

            /*������*/
    //����� ����� �� ����� 
    void PrintFraction() const;

    

            /*���������� ����������*/
    //�������� ������������
    Fraction& operator=(const Fraction& other);
    
    

private:
    int numerator;
    int denominator;
    int wholePart;
};
//���������� ����� ��������(�������� �������)
int GCD(int first, int second);
//���������� ����� �������
int LCM(int first, int second);

//�������� ��������
Fraction operator+(const Fraction& left, const Fraction& right);
//�������� ���������
Fraction operator-(const Fraction& left, const Fraction& right);
//�������� ���������
Fraction operator*(const Fraction& left, const Fraction& right);
//�������� �������
Fraction operator/(const Fraction& left, const Fraction& right);

bool CorrectFraction(const Fraction& A);

bool CorrectWholePart(const Fraction& A);



#endif // !FRACTION_HPP
