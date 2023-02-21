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
            /*Конструкторы*/
    //Конструктор по умолчанию
    Fraction();
    //Конструктор №1
    Fraction(int wholePart);
    //Конструктор №2
    Fraction(int numerator, int denominator);
    //Конструктор №3
    Fraction(int wholePart, int numerator, int denominator);
    //Конструктор копирования
    Fraction(const Fraction& other);
    //Деструктор
    ~Fraction();

            /*Методы*/
    //Вывод дроби на экран 
    void PrintFraction() const;

    //Переобразование в неправильную дробь
    Fraction& to_improper();
    //Переобразование в правильную дробь
    Fraction& to_proper();
    //Меняем числитель и знаменатель местами
    Fraction& inverted()const;
    //Получение общего знаменателя
    Fraction& getCommonDenominator(const int additionalMultiplier);
    //Сокращение дроби
    Fraction& reduce();



            /*Перегрузка операторов*/
    //Оператор присваивания
    Fraction& operator=(const Fraction& other);
    //Оператор Сложение, совмещённое с присваиванием
    Fraction& operator+=(const Fraction& other);
    //Оператор Вычитание, совмещённое с присваиванием
    Fraction& operator-=(const Fraction& other);
    //Оператор Умножение, совмещённое с присваиванием
    Fraction& operator*=(const Fraction& other);
    //Оператор Деление, совмещённое с присваиванием
    Fraction& operator/=(const Fraction& other);
    

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
Fraction operator+(Fraction left, Fraction right);
//Оператор вычитания
Fraction operator-(Fraction left, Fraction right);
//Оператор умножения
Fraction operator*(Fraction left, Fraction right);
//Оператор деления
Fraction operator/(const Fraction& left, const Fraction& right);
//Оператор равенство
bool operator==(Fraction left, Fraction right);
//Оператор неравенство
bool operator!=(Fraction left, Fraction right);
//Оператор больше
bool operator>(Fraction left, Fraction right);
//Оператор меньше
bool operator<(Fraction left, Fraction right);
//Оператор больше или равно
bool operator>=(const Fraction& left, const Fraction& right);
//Оператор меньше или равно
bool operator<=(const Fraction& left, const  Fraction& right);

bool CorrectFraction(const Fraction& A);

bool CorrectWholePart(const Fraction& A);



#endif // !FRACTION_HPP
