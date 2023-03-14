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

Human::Human()
{
    firstName = string();
    lastName = string();
    age = int();
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
ofstream& Human::print(ofstream& ofs) const
{
    ofs << lastName << " " << firstName << " " << age;
    return ofs;
}

istream& Human::scan(istream& is)
{
    return is >> lastName >> firstName >> age;
}

ifstream& Human::scan(ifstream& ifs)
{
    ifs >> lastName >> firstName >> age;
    return ifs;
}


/*------------------------------end-class-Human------------------------------*/

ostream& operator<<(ostream& os, const Human& obj)
{
    return obj.print(os);
}

ofstream& operator<<(ofstream& ofs, const Human& obj)
{
    return obj.print(ofs);
}

istream& operator>>(istream& is, Human& obj)
{
    return obj.scan(is);
}

ifstream& operator>>(ifstream& ifs, Human& obj)
{
    obj.scan(ifs);
    return ifs;
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

ofstream& Student::print(ofstream& ofs) const
{
    Human::print(ofs) << " ";
    ofs.width(MAX_WIDTH_SPECIALITY);
    ofs << left;
    ofs << speciality;
    ofs << " " << group << " " << rating << " " << attendance;
    return ofs;
}

istream& Student::scan(istream& is)
{
    return Human::scan(is) >> speciality >> group >> rating >> attendance;
}

ifstream& Student::scan(ifstream& ifs)
{
    Human::scan(ifs);
    char tmp[MAX_WIDTH_SPECIALITY]{};
    ifs.read(tmp, MAX_WIDTH_SPECIALITY - 1);
    for (int i = MAX_WIDTH_SPECIALITY - 2; tmp[i] == ' '; i--)
        tmp[i] = 0;
    while (tmp[0] == ' ')
        for (int i = 0; tmp[i]; i++)tmp[i] = tmp[i + 1];
    speciality = tmp;
    ifs >> group;
    ifs >> rating;
    ifs >> attendance;
    return ifs;
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

ofstream& Teacher::print(ofstream& ofs) const
{
    Human::print(ofs) << " ";
    ofs.width(MAX_WIDTH_SPECIALITY);
    ofs << left;
    ofs << speciality;
    ofs << " " << experience;
    return ofs;
}

istream& Teacher::scan(istream& is)
{
    return Human::scan(is) >> speciality >> experience;
}

ifstream& Teacher::scan(ifstream& ifs)
{
    Human::scan(ifs);
    char tmp[MAX_WIDTH_SPECIALITY]{};
    ifs.read(tmp, MAX_WIDTH_SPECIALITY - 1);
    for (int i = MAX_WIDTH_SPECIALITY - 2; tmp[i] == ' '; i--)
        tmp[i] = 0;
    while (tmp[0] == ' ')
        for (int i = 0; tmp[i]; i++)tmp[i] = tmp[i + 1];
    speciality = tmp;
    ifs >> experience;
    return ifs;
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

ofstream& Graduate::print(ofstream& ofs) const
{
    Student::print(ofs) << " " << subject;
    return ofs;
}

istream& Graduate::scan(istream& is)
{
    return Student::scan(is) >> subject;
}

ifstream& Graduate::scan(ifstream& ifs)
{
    Student::scan(ifs);
    getline(ifs, subject);
    return ifs;
}
/*------------------------------end-class-Graduate----------------------------*/



/*--------------------------start-class-SeniorLecturer-------------------------*/

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

ofstream& SeniorLecturer::print(ofstream& ofs) const
{
    Teacher::print(ofs) << " " << degree;
    return ofs;
}

istream& SeniorLecturer::scan(istream& is)
{
    return Teacher::scan(is) >> degree;
}

ifstream& SeniorLecturer::scan(ifstream& ifs)
{
    Teacher::scan(ifs);
    getline(ifs, degree);
    return ifs;
}
/*----------------------------end-class-SeniorLecturer-------------------------*/


Human* HumanFactory(const std::string& type)
{
    if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
    if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
    if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
    if (type.find("SeniorLecturer") != std::string::npos)return new SeniorLecturer("", "", 0, "", 0, "");
}

void save(Human** group, const int n, const char* filename)
{
    ofstream fout(filename);
    for (int i = 0; i < n; i++)
    {
        fout << typeid(*group[i]).name() << ":\t";
        fout << *group[i] << endl;
    }
    fout.close();
    string s_command = "start notepad ";
    s_command += filename;
    system(s_command.c_str());
}
Human** load(const char* filename, int& n)
{
    Human** group = nullptr;	
    n = 0;

    ifstream fin(filename);
    if (fin.is_open())
    {
        
        while (!fin.eof())
        {
            string buffer;
            getline(fin, buffer);
            if (buffer.empty())continue;
            n++;
        }

        group = new Human * [n] {};
        fin.clear();
        fin.seekg(0);

        string obj_type;
        for (int i = 0; i < n; i++)
        {
            getline(fin, obj_type, ':');
            fin.ignore();
            if (obj_type.empty())continue;
            group[i] = HumanFactory(obj_type);
            fin >> *group[i];
        }

        fin.close();
    }
    else
    {
        cerr << "Error: file not found" << endl;
    }

    return group;
}