#include"academy.hpp"

/*----------------------------start-class-Human----------------------------*/
const string& Human::get_lastName() const
{
    return lastName;
}

const string& Human::get_firstName() const
{
    return firstName;
}

int Human::get_age() const
{
    return age;
}

void Human::set_lastName(const string& lastName)
{
    this->lastName = lastName;
}

void Human::set_firstName(const string& firstNmae) 
{
    this->firstName = firstNmae;
}

void Human::set_age(int age) 
{
    this->age = age;
}

Human::Human(HUMAN_TAKE_PARAMETERS)
{
    set_lastName(lastName);
    set_firstName(firstName);
    set_age(age);
}

Human::~Human()
{
}

void Human::info()const
{
    cout << lastName << " " << firstName << " " << age << " лет" << endl;
}

ostream& Human::print(ostream& os) const
{
    return os << lastName << " " << firstName << " " << age;
}


/*------------------------------end-class-Human------------------------------*/

ostream& operator<<(ostream& os, const Human& obj)
{
    return obj.print(os);
}



/*----------------------------start-class-Student----------------------------*/

const string& Student::get_speciality()const
{
    return speciality;
}

const string& Student::get_group()const
{
    return group;
}

double Student::get_rating()const
{
    return rating;
}

double Student::get_attendance()const
{
    return attendance;
}


void Student::set_speciality(const string& speciality)
{
    this->speciality = speciality;
}

void Student::set_group(const string& group)
{
    this->group = group;
}

void Student::set_rating(double rating)
{
    this->rating = rating;
}

void Student::set_attendance(double attendance)
{
    this->attendance = attendance;
}



Student::Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS)
    : Human(HUMAN_GIVE_PARAMETERS)
{
    set_speciality(speciality);
    set_group(group);
    set_rating(rating);
    set_attendance(attendance);
}

Student::~Student() 
{
}


void Student::info()const
{
    Human::info();
    cout << "Студент по " << speciality << " " << group << " успеваемость - " << rating <<
        " посещаемость - " << attendance << "%" << endl;
}
ostream& Student::print(ostream& os) const
{
    return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
}
/*------------------------------end-class-Student----------------------------*/



/*----------------------------start-class-Teacher----------------------------*/

const string& Teacher::get_speciality()const
{
    return speciality;
}

int Teacher::get_experience()const
{
    return experience;
}

void Teacher::set_speciality(const string& speciality)
{
    this->speciality = speciality;
}

void Teacher::set_experience(int experience)
{
    this->experience = experience;
}

Teacher::Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS)
    : Human(HUMAN_GIVE_PARAMETERS)
{
    set_speciality(speciality);
    set_experience(experience);
}

Teacher::~Teacher() 
{
}

void Teacher::info()const
{
    Human::info();
    cout << "Преподаватель по " << speciality << " " << experience << " лет стажа" << endl;
}
ostream& Teacher::print(ostream& os) const
{
    return Human::print(os) << " " << speciality << " " << experience;
}
/*------------------------------end-class-Teacher----------------------------*/


/*----------------------------start-class-Graduate----------------------------*/

const string& Graduate::get_subject()const
{
    return subject;
}

void Graduate::set_subject(const string& subject)
{
    this->subject = subject;
}


Graduate::Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
    :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
{
    set_subject(subject);
}

Graduate::~Graduate() 
{
}


void Graduate::info()const
{
    Student::info();
    cout << subject << endl;
}
ostream& Graduate::print(ostream& os) const
{
    return Student::print(os) << " " << subject;
}
/*------------------------------end-class-Graduate----------------------------*/



/*--------------------------start-class-Qualification-------------------------*/

const string& SeniorLecturer::get_degree()const
{
    return degree;
}

void SeniorLecturer::set_degree(const string& degree)
{
    this->degree = degree;
}


SeniorLecturer::SeniorLecturer(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS, QUALIFICATION_TAKE_PARAMETERS)
    : Teacher(HUMAN_GIVE_PARAMETERS, TEACHER_GIVE_PARAMETERS)
{
    set_degree(degree);
}

SeniorLecturer::~SeniorLecturer()
{
}


void SeniorLecturer::info()const
{
    Teacher::info();
    cout << degree << endl;
}
ostream& SeniorLecturer::print(ostream& os) const
{
    return Teacher::print(os) << " " << degree;
}
/*----------------------------end-class-Qualification-------------------------*/


