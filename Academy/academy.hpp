#ifndef ACADEMY_HPP
#define ACADEMY_HPP

#include<iostream>
#include<string>
#include<fstream>

using namespace std;


/*----------------------------start-class-Human----------------------------*/
#define HUMAN_TAKE_PARAMETERS const string& lastName, const string& firstName, int age
#define HUMAN_GIVE_PARAMETERS lastName, firstName, age

class Human
{
private:
	string firstName;
	string lastName;
	int age;
public:
	const string& get_lastName()const;
	const string& get_firstName()const;
	int get_age()const;

	void set_lastName(const string& lastName);
	void set_firstName(const string& firstName);
	void set_age(int age);

	Human(HUMAN_TAKE_PARAMETERS);
	virtual ~Human();

	virtual void info()const;
	virtual ostream& print(ostream& os)const;
};
/*------------------------------end-class-Human------------------------------*/
ostream& operator<<(ostream& os, const Human& obj);



/*----------------------------start-class-Student----------------------------*/
#define STUDENT_TAKE_PARAMETERS const string& speciality, const string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student: public Human 
{
private:
	string speciality;
	string group;
	double rating;
	double attendance;
public:
	const string& get_speciality()const;
	const string& get_group()const;
	double get_rating()const;
	double get_attendance()const;

	void set_speciality(const string& speciality);
	void set_group(const string& group);
	void set_rating(double rating);
	void set_attendance(double attendance);

	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS);
	~Student();

	void info()const;
	ostream& print(ostream& os)const override;
};
/*------------------------------end-class-Student----------------------------*/


/*----------------------------start-class-Teacher----------------------------*/
#define TEACHER_TAKE_PARAMETERS const string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher: public Human
{
private:
	string speciality;
	int experience;
public:
	const string& get_speciality()const;
	int get_experience()const;

	void set_speciality(const string& speciality);
	void set_experience(int experience);

	Teacher(HUMAN_TAKE_PARAMETERS,TEACHER_TAKE_PARAMETERS);
	~Teacher();

	void info()const;
	ostream& print(ostream& os)const override;
};
/*------------------------------end-class-Teacher----------------------------*/



/*----------------------------start-class-Graduate----------------------------*/
#define GRADUATE_TAKE_PARAMETERS const string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate: public Student
{
private:
	string subject;
public:
	const string& get_subject()const;

	void set_subject(const string& subject);

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS);
	~Graduate();

	void info()const;
	ostream& print(ostream& os)const override;
};
/*------------------------------end-class-Graduate----------------------------*/



/*--------------------------start-class-Qualification-------------------------*/
#define QUALIFICATION_TAKE_PARAMETERS const string& degree
#define QUALIFICATION_GIVE_PARAMETERS degree

class SeniorLecturer : public Teacher
{
private:
	string degree;
public:
	const string& get_degree()const;

	void set_degree(const string& degree);

	SeniorLecturer(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS, QUALIFICATION_TAKE_PARAMETERS);
	~SeniorLecturer();


	void info()const;
	ostream& print(ostream& os)const override;
};
/*----------------------------end-class-Qualification-------------------------*/

#endif // !ACADEMY_HPP

