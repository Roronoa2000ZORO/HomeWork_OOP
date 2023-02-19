#include"fraction.hpp"

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
    this->denominator = denominator;
}

void Fraction::set_wholePart(int wholePart){
    this->wholePart = wholePart;
}

Fraction::Fraction(int wholePart, int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
    this->wholePart = wholePart;
}

Fraction::Fraction(const Fraction& other) {
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->wholePart = other.wholePart;
}

Fraction::~Fraction() {}

void Fraction::PrintFraction() const{
    if (this->wholePart > 0) {
        cout << this->wholePart << " ";
    }

    if (this->numerator && this->denominator > 0) {
        cout << this->numerator << "/" << this->denominator;
    }
}

Fraction& Fraction::operator=(const Fraction& other) {

    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->wholePart = other.wholePart;
    return *this;
}


                        /*�������*/


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

int LCM(int first, int second) {
    int result;
    result = first * second / GCD(first, second);
    return result;
}

Fraction operator+(const Fraction& left, const Fraction& right){
    Fraction result;
    int tmp = int();
    //�������� ������ ����� � ����� ������ ��� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*if ((left.get_numerator() == 0 || left.get_denominator() == 0) || (right.get_numerator() == 0 || right.get_denominator() == 0)) {
        result.set_numerator(left.get_numerator() + right.get_numerator());
        result.set_denominator(left.get_denominator() + right.get_denominator());
        result.set_wholePart(left.get_wholePart() + right.get_wholePart());

    //�������� ������ � ����������� �������������
    } else*/ if(left.get_denominator() == right.get_denominator()) {

        result.set_numerator(left.get_numerator() + right.get_numerator());
        result.set_denominator(left.get_denominator());
        result.set_wholePart(left.get_wholePart() + right.get_wholePart());// �������� ����� �����

    }else { //�������� ������ � ������� �������������
        Fraction left_tmp, right_tmp;

        //����������� � ����� ������
        tmp = LCM(right.get_denominator(), left.get_denominator()) / left.get_denominator();// ����� ��� � ��������� ��������������� ���������
        left_tmp.set_numerator(tmp * left.get_numerator());
        left_tmp.set_denominator(tmp * left.get_denominator());
        
        //����������� � ������ ������
        tmp = LCM(right.get_denominator(), left.get_denominator()) / right.get_denominator();// ����� ��� � ��������� ��������������� ���������
        right_tmp.set_numerator(tmp * right.get_numerator());
        right_tmp.set_denominator(tmp * right.get_denominator());

        //�������� ������
        result.set_numerator(left_tmp.get_numerator() + right_tmp.get_numerator());
        result.set_denominator(left_tmp.get_denominator());
        result.set_wholePart(left.get_wholePart() + right.get_wholePart());// �������� ����� �����
    }
    
    //��������������� ������������ ����� � ����������
    if (result.get_numerator() >= result.get_denominator()) {
        result.set_wholePart(result.get_wholePart() + result.get_numerator() / result.get_denominator());
        result.set_numerator(result.get_numerator() % result.get_denominator());
    }

    //���������� ����� ���� ��� ��������
    tmp = GCD(result.get_numerator(), result.get_denominator());
    result.set_numerator(result.get_numerator() / tmp);
    result.set_denominator(result.get_denominator() / tmp);
    result.set_numerator(result.get_numerator() % result.get_denominator());
    

    return result;
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    Fraction result;
    int tmp = int();
    //��������� ������ � ����������� �������������
    if (left.get_denominator() == right.get_denominator()) {
        result.set_numerator(left.get_numerator() - right.get_numerator());
        result.set_denominator(left.get_denominator());
        result.set_wholePart(left.get_wholePart() - right.get_wholePart());// ��������� ����� �����
    }
    else { //��������� ������ � ������� �������������
        Fraction left_tmp, right_tmp;

        //����������� � ����� ������
        tmp = LCM(right.get_denominator(), left.get_denominator()) / left.get_denominator();// ����� ��� � ��������� ��������������� ���������
        left_tmp.set_numerator(tmp * left.get_numerator());
        left_tmp.set_denominator(tmp * left.get_denominator());

        //����������� � ������ ������
        tmp = LCM(right.get_denominator(), left.get_denominator()) / right.get_denominator();// ����� ��� � ��������� ��������������� ���������
        right_tmp.set_numerator(tmp * right.get_numerator());
        right_tmp.set_denominator(tmp * right.get_denominator());

        //��������� ������
        result.set_numerator(left_tmp.get_numerator() - right_tmp.get_numerator());
        result.set_denominator(left_tmp.get_denominator());
        result.set_wholePart(left.get_wholePart() - right.get_wholePart());// �������� ����� �����
    }

    //��������������� ������������ ����� � ����������
    if (result.get_numerator() >= result.get_denominator()) {
        result.set_wholePart(result.get_wholePart() + result.get_numerator() / result.get_denominator());
        result.set_numerator(result.get_numerator() % result.get_denominator());
    }

    //���������� ����� ���� ��� ��������
    tmp = GCD(result.get_numerator(), result.get_denominator());
    result.set_numerator(result.get_numerator() / tmp);
    result.set_denominator(result.get_denominator() / tmp);
    result.set_numerator(result.get_numerator() % result.get_denominator());

    return result;
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    Fraction result, left_tmp, right_tmp;
    int tmp = int();
    if (!CorrectFraction(left) && !CorrectFraction(right) && !CorrectWholePart(left) && !CorrectWholePart(right)) {
        return result;
    }
    
    

    // ��������������� ����� ����� � ������� � ������ ����� ���� �� ��������� �������� ������ ����� ������
    if ((!CorrectFraction(left) || !CorrectFraction(right)) && !CorrectWholePart(left)) {
        left_tmp.set_numerator(left.get_wholePart());
        left_tmp.set_denominator(1);
    }else if ((!CorrectFraction(left) || !CorrectFraction(right)) && !CorrectWholePart(right)) {
        right_tmp.set_numerator(right.get_wholePart());
        right_tmp.set_denominator(1);
    }

    if (CorrectFraction(left) && CorrectFraction(right)) {
        left_tmp.set_numerator(left.get_wholePart() * left.get_denominator() + left.get_numerator());
        right_tmp.set_numerator(right.get_wholePart() * right.get_denominator() + right.get_numerator());
    }else {

        left_tmp.set_numerator(left.get_wholePart() * left.get_denominator() + left.get_numerator());
        right_tmp.set_numerator(right.get_wholePart() * right.get_denominator() + right.get_numerator());
    }

    result.set_numerator(left_tmp.get_numerator() * right_tmp.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    
    //��������������� ������������ ����� � ����������
    if (result.get_numerator() >= result.get_denominator()) {
        result.set_wholePart(result.get_wholePart() + result.get_numerator() / result.get_denominator());
        result.set_numerator(result.get_numerator() % result.get_denominator());
    }

    //���������� ����� ���� ��� ��������
    tmp = GCD(result.get_numerator(), result.get_denominator());
    result.set_numerator(result.get_numerator() / tmp);
    result.set_denominator(result.get_denominator() / tmp);
    result.set_numerator(result.get_numerator() % result.get_denominator());
    

    return result;
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    Fraction result;
    int tmp = int();
    //������� ������
    result.set_numerator(left.get_numerator() * right.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_numerator());
    //result.set_wholePart(left.get_wholePart() / right.get_wholePart());// ������� ����� �����!!!!!!!!!

    //��������������� ������������ ����� � ����������
    if (result.get_numerator() >= result.get_denominator()) {
        result.set_wholePart(result.get_wholePart() + result.get_numerator() / result.get_denominator());
        result.set_numerator(result.get_numerator() % result.get_denominator());
    }

    if (CorrectFraction(result)) {
    //���������� ����� ���� ��� ��������
        tmp = GCD(result.get_numerator(), result.get_denominator());
        result.set_numerator(result.get_numerator() / tmp);
        result.set_denominator(result.get_denominator() / tmp);
        result.set_numerator(result.get_numerator() % result.get_denominator());
    }

    return result;
}

bool CorrectFraction(const Fraction& A) {
    return (A.get_numerator() && A.get_denominator() != 0);
}

bool CorrectWholePart(const Fraction& A) {
    return (A.get_numerator() && A.get_denominator() != 0);
}
