#include"fraction.hpp"

/*----------------------------------start-class-------------------------------------------------------*/

                        /*Модификаторы доступа*/

int Fraction::get_numerator() const {

    return numerator;
}

int Fraction::get_denominator() const {

    return denominator;
}

int Fraction::get_wholePart() const {

    return wholePart;
}

void Fraction::set_numerator(int numerator) {

    this->numerator = numerator;
}

void Fraction::set_denominator(int denominator){

    if (denominator == 0){
        denominator = 1; 
    }
    this->denominator = denominator;
}

void Fraction::set_wholePart(int wholePart){

    this->wholePart = wholePart;
}

                        /*Конструкторы и Деструктор*/

//Конструктор по умолчанию
Fraction::Fraction() {

    wholePart = int();
    numerator = int();
    denominator = 1;
}
//Конструктор №1
Fraction::Fraction(int wholePart){

    this->wholePart = wholePart;
    numerator = int();
    denominator = 1;
}
//Конструктор №2
Fraction::Fraction(int numerator, int denominator){

    wholePart = int();
    this->numerator = numerator;
    set_denominator(denominator);
}
//Конструктор №3
Fraction::Fraction(int wholePart, int numerator, int denominator){

    this->wholePart = wholePart;
    this->numerator = numerator;
    set_denominator(denominator);
}
//Конструктор копирования
Fraction::Fraction(const Fraction& other) {

    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->wholePart = other.wholePart;
}
//Деструктор
Fraction::~Fraction() {}


                        /*Методы*/

//Вывод дроби на экран
void Fraction::PrintFraction() const{

    if (wholePart) {
        cout << wholePart;
    }
    if (numerator) {
        if (wholePart) {
            cout << "(";
        }

        cout << numerator << "/" << denominator;

        if (wholePart) {
            cout << ")";
        }
    }else if (wholePart == 0) {
        cout << wholePart;
    }
    cout << "\t";
}
//Переобразование в неправильную дробь
Fraction& Fraction::to_improper(){

    numerator += wholePart * denominator;
    wholePart = int();
    return *this;
}
//Переобразование в правильную дробь
Fraction& Fraction::to_proper(){

    wholePart += numerator / denominator;
    numerator %= denominator;
    return *this;
}
//Меняем числитель и знаменатель местами
Fraction& Fraction::inverted() const{

    Fraction inverted = *this;	//копируем объект!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    inverted.to_improper();
    swap(inverted.numerator, inverted.denominator);
    return inverted;
}
//Получение общего знаменателя
Fraction& Fraction::getCommonDenominator( const int additionalMultiplier) {
    
    numerator *= additionalMultiplier;
    denominator *= additionalMultiplier;
    return *this;
}
//Сокращение дроби
Fraction& Fraction::reduce(){
    if (numerator == 0) {
        return *this;
    }
    int tmp = GCD(numerator, denominator);
    numerator /= tmp;
    denominator /= tmp;
    return *this;
}


                        /*Операторы*/

//Оператор присваивания
Fraction& Fraction::operator=(const Fraction& other) {

    numerator = other.numerator;
    denominator = other.denominator;
    wholePart = other.wholePart;
    return *this;
}
//Оператор Сложение, совмещённое с присваиванием
Fraction& Fraction::operator+=(const Fraction& other){
    
    return *this = *this + other;
}
//Оператор Вычитание, совмещённое с присваиванием
Fraction& Fraction::operator-=(const Fraction& other){

    return *this = *this - other;
}
//Оператор Умножение, совмещённое с присваиванием
Fraction& Fraction::operator*=(const Fraction& other){

    return *this = *this * other;
}
//Оператор Деление, совмещённое с присваиванием
Fraction& Fraction::operator/=(const Fraction& other){

    return *this = *this / other;
}


/*----------------------------------end-class-------------------------------------------------------*/

                        /*Функции*/

//Наибольший общий делитель(алгоритм Евклида)
int GCD(int first, int second){

    if (first < second) {
        swap(first, second);
    }
    while (first % second != 0) {
        first = first % second;
        swap(first, second);
    }
    return second;
}
//Наименьшее общее кратное
int LCM(int first, int second) {
    
    return first * second / GCD(first, second);
}
//Оператор сложения
Fraction operator+(Fraction left, Fraction right){
    
    left.to_improper();
    right.to_improper();

    if (left.get_denominator() != right.get_denominator()) {

        left.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / left.get_denominator());
        right.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / right.get_denominator());
    }
    
    return Fraction(
        left.get_numerator() + right.get_numerator(),
        left.get_denominator()
    ).to_proper().reduce();
}
//Оператор вычитания
Fraction operator-(Fraction left, Fraction right) {

    left.to_improper();
    right.to_improper();

    if (left.get_denominator() != right.get_denominator()) {

        left.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / left.get_denominator());
        right.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / right.get_denominator());
    }
    
    return Fraction(
            left.get_numerator() - right.get_numerator(),
            left.get_denominator()
    ).to_proper().reduce();
}
//Оператор умножения
Fraction operator*(Fraction left, Fraction right) {

    left.to_improper();
    right.to_improper();
    
    return Fraction(
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()
    ).to_proper().reduce();
}
//Оператор деления
Fraction operator/(const Fraction& left, const Fraction& right) {
    return left * right.inverted();
}
//Оператор равенство
bool operator==(Fraction left, Fraction right){
    left.to_improper();
    right.to_improper();
    left.reduce();
    right.reduce();

    return (left.get_denominator() == right.get_denominator() &&
            left.get_numerator() == right.get_numerator());
}
//Оператор неравенство
bool operator!=(Fraction left,Fraction right){

    left.to_improper();
    right.to_improper();
    left.reduce();
    right.reduce();

    return (left.get_denominator() != right.get_denominator() &&
            left.get_numerator() != right.get_numerator());
}
//Оператор больше
bool operator>(Fraction left, Fraction right){

    left.to_improper();
    right.to_improper();
    left.reduce();
    right.reduce();

    if (left.get_numerator() == right.get_numerator()) {

        return (left.get_denominator() < right.get_denominator());
    }
    else if (left.get_denominator() == right.get_denominator()) {

        return (left.get_numerator() > right.get_numerator());
    }
    else{
        left.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / left.get_denominator());
        right.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / right.get_denominator());

        return (left.get_numerator() > right.get_numerator());
    }
}
//Оператор меньше
bool operator<(Fraction left, Fraction right){

    left.to_improper();
    right.to_improper();
    left.reduce();
    right.reduce();

    if (left.get_numerator() == right.get_numerator()) {

        return (left.get_denominator() > right.get_denominator());
    }
    else if (left.get_denominator() == right.get_denominator()) {

        return (left.get_numerator() < right.get_numerator());
    }
    else {
        left.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / left.get_denominator());
        right.getCommonDenominator(LCM(left.get_denominator(), right.get_denominator()) / right.get_denominator());

        return (left.get_numerator() < right.get_numerator());
    }
}
//Оператор больше или равно
bool operator>=(const Fraction& left, const Fraction& right){
    if (left == right) {
        return true;
    }
    else if (left > right) {
        return true;
    }
    else {
        return false;
    }
}
//Оператор меньше или равно
bool operator<=(const Fraction& left, const  Fraction& right){

    if (left == right) {
        return true;
    }
    else if (left < right) {
        return true;
    }
    else {
        return false;
    }
}


bool CorrectFraction(const Fraction& A) {
    return (A.get_numerator() && A.get_denominator() != 0);
}

bool CorrectWholePart(const Fraction& A) {
    return (A.get_numerator() && A.get_denominator() != 0);
}
