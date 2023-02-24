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

    Fraction inverted = *this;
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



            /*Арифметические операторы*/

//Оператор сложения
Fraction operator+(const Fraction& left, const Fraction& right){
    
    return Fraction
    (
        left.get_wholePart() + right.get_wholePart(),
        left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()
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


            /*Операторы сравнения*/

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
bool operator!=(const Fraction& left, const Fraction& right){

    return !(left == right);
}
//Оператор больше
bool operator>(Fraction left, Fraction right){

    left.to_improper();
    right.to_improper();

    return left.get_numerator() * right.get_denominator() >
            right.get_numerator() * left.get_denominator();
}
//Оператор меньше
bool operator<(Fraction left, Fraction right){

    left.to_improper();
    right.to_improper();

    return left.get_numerator() * right.get_denominator() <
        right.get_numerator() * left.get_denominator();
}
//Оператор больше или равно
bool operator>=(const Fraction& left, const Fraction& right){

    return !(left < right);
}
//Оператор меньше или равно
bool operator<=(const Fraction& left, const  Fraction& right){

    return !(left > right);
}


            /*Прочие операторы*/

//Оператор вставки в поток
ostream& operator<<(ostream& ost, const Fraction& obj){

    if (obj.get_wholePart()) {

        ost << obj.get_wholePart();
    }
    if (obj.get_numerator()){

        if (obj.get_wholePart()) {

            ost << "(";
        }
        ost << obj.get_numerator() << "/" << obj.get_denominator();

        if (obj.get_wholePart()) {

            ost << ")";
        }
    }
    else if (obj.get_wholePart() == 0) {

        ost << 0;
    }

    return ost;
}

//#define KOLHOZ

//Оператор извлечения из потока
istream& operator>>(istream& ist, Fraction& obj){ 
    // Улучшеный вариант
    int first, middle, second;
    ist >> first;
        
    if (ist.peek() == '\n') {
        obj.set_wholePart(first);

        ist.ignore(32000, '\n');
    } 
    else if(ist.peek() == ' ' || ist.peek() == '(') {

        ist >> middle;
        ist.ignore();
        ist >> second;

        obj.set_wholePart(first);
        obj.set_numerator(middle);
        obj.set_denominator(second);

        ist.ignore(32000, '\n');
    }
    else if (ist.peek() == '/') {
        ist.ignore();
        ist >> second;
        obj.set_numerator(first);
        obj.set_denominator(second);

        
    }

    ist.clear();
    ist.ignore(32000, '\n');

    return ist;

    // Колхозный вариант
    #ifdef KOLHOZ
    
        string str;
        getline(ist, str);
        int* p = new int[static_cast<int>(size(str))]{};
        int space = 0, division = 0, end = 0;
    
        for (int i = 0; i < str.length(); i++){
    
            switch (str[i]){
            case '/':
                division = i;
                break;
            case ' ':
                space = i;
                break;
            case '(':
                space = i;
                break;
            case ')':
                end = i;
                break;
            default:
                break;
            }
        }
    
        if (division == 0) { // только целое число
            obj.set_wholePart(stoi(str));
            return ist;
        }
        else if (space == 0) { // только дробные числа
            int i = division + 1, denom = 0;
                obj.set_numerator(stoi(str));
            do{
                denom *= 10;
                denom += str[i] - '0';
                i++;
            } while (i < str.length());
            obj.set_denominator(denom);
            return ist;
        }
    
        //      далее смешанные
        int i = space + 1, numer = 0, denom = 0;
        obj.set_wholePart(stoi(str));
        do {
            numer *= 10;
            numer += str[i] - '0';
            i++;
        } while (i < division );
    
        obj.set_numerator(numer);
        i++;
        if (end == 0)end = str.length();
        do {
            denom *= 10;
            denom += str[i] - '0';
            i++;
        } while (i < end);
    
        obj.set_denominator(denom);
    
        return ist;
    #endif // KOLHOZ

}





