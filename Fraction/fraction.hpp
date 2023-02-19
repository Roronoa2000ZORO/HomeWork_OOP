#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
using namespace std;


class Fraction {
public:
            /*Модификаторы доступа*/

    int get_numerator() const;
    int get_denominator() const;
    int get_wholePart() const;
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    void set_wholePart(int wholePart);

    //Конструктор
    Fraction(int wholePart = int(), int numerator = int(), int denominator = int());
    //Конструктор копирования
    Fraction(const Fraction& other);
    //Деструктор
    ~Fraction();

            /*Методы*/
    //Вывод дроби на экран 
    void PrintFraction() const;

    

            /*Перегрузка операторов*/
    //Оператор присваивания
    Fraction& operator=(const Fraction& other);
    
    

private:
    int numerator;
    int denominator;
    int wholePart;
};
//Наибольший общий делитель(алгоритм Евклида)
int GCD(int first, int second);
//Наименьшее общее кратное
int LCM(int first, int second);

//Оператор сложения
Fraction operator+(const Fraction& left, const Fraction& right);
//Оператор вычитания
Fraction operator-(const Fraction& left, const Fraction& right);
//Оператор умножения
Fraction operator*(const Fraction& left, const Fraction& right);
//Оператор деления
Fraction operator/(const Fraction& left, const Fraction& right);

bool CorrectFraction(const Fraction& A);

bool CorrectWholePart(const Fraction& A);



#endif // !FRACTION_HPP
