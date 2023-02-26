#ifndef FRACTION_HPP
#define FRACTION_HPP
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
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
    //Конструктор № 1.1
    Fraction(int wholePart);
    //Конструктор № 1.2
    Fraction(double number);
    //Конструктор № 2
    Fraction(int numerator, int denominator);
    //Конструктор № 3
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

            /*Операторы преобразовании типов:*/
    //Преобразование в целое число
    operator int();
    //Преобразование в смешаное число
    operator double();

    
    

private:
    int numerator;
    int denominator;
    int wholePart;
};
        /*Функции*/

//Наибольший общий делитель(алгоритм Евклида)
int GCD(int first, int second);
//Наименьшее общее кратное
int LCM(int first, int second);

        /*Арифметические операторы*/
//Оператор сложения
Fraction operator+(const Fraction& left,  const Fraction& right);
//Оператор вычитания
Fraction operator-(Fraction left, Fraction right);
//Оператор умножения
Fraction operator*(Fraction left, Fraction right);
//Оператор деления
Fraction operator/(const Fraction& left, const Fraction& right);

        /*Операторы сравнения*/
//Оператор равенство
bool operator==(Fraction left, Fraction right);
//Оператор неравенство
bool operator!=(const Fraction& left, const Fraction& right);
//Оператор больше
bool operator>(Fraction left, Fraction right);
//Оператор меньше
bool operator<(Fraction left, Fraction right);
//Оператор больше или равно
bool operator>=(const Fraction& left, const Fraction& right);
//Оператор меньше или равно
bool operator<=(const Fraction& left, const  Fraction& right);

        /*Прочие операторы*/
//Оператор вставки в поток
ostream& operator<<(ostream& ost, const  Fraction& obj);
//Оператор извлечения из потока
istream& operator>>(istream& ist, Fraction& obj);





#endif // !FRACTION_HPP
