#pragma once
#include "Common.h"
//
// --------- class Person
//
class Person
{
public:
	Person() {};
	Person(std::string name, std::string sex, short int age, float weight)
		:
		name(name),
		sex(sex),
		age(age),
		weight(weight)
	{}
	void setName(std::string name);
	void setAge(short int age);
	void setWeight(float weight);

	void getName();
	void getAge();
	void getWeight();

protected:
	std::string name{ "Undefined" };
	std::string sex{ "Undefined" };
	short int age{0};
	float weight{0.0};
};

//
// --------- SETs
//
void Person::setName(std::string name) { this->name = name; }
void Person::setAge(short int age) { this->age = age; }
void Person::setWeight(float weight) { this->weight = weight; }
//
// --------- GETs
//
void Person::getName() { std::cout << name << "\n"; }
void Person::getAge() { std::cout << age << "\n"; }
void Person::getWeight() { std::cout << weight << "\n"; }
//
// --------- class Student
//
class Student : public Person
{
public:
	Student() : thisCounter(++counter) { };

	Student(std::string name, std::string sex, short int age, float weight, std::size_t startYear, std::size_t endYear)
		:
		Person(name, sex, age, weight),
		startYear(startYear),
		endYear(endYear),
		thisCounter(++counter)
	{}
	void setStartYear(std::size_t startYear);
	void setEndYear(std::size_t endYear);
	void getInfo();
	friend void getNumStudents(Student& student);

private:
	std::size_t startYear{ 0 }, endYear{0};
	static int counter;
	int thisCounter;
};

int Student::counter = 0; // Я так и не понял как это работает(нашёл решение в инете), надеюсь на уроке пойму :) 

//
// --------- SETs
//
void Student::setStartYear(std::size_t startYear) { this->startYear = startYear; }
void Student::setEndYear(std::size_t endYear) { this->endYear = endYear; }
//
// --------- GETs
//
void Student::getInfo()
{
	std::cout << "Name - " << name << "\n";
	std::cout << "Sex - " << sex << "\n";
	std::cout << "Age - " << age << "\n";
	std::cout << "Weight - " << weight << "\n";
	std::cout << "Start year - " << startYear << "\n";
	std::cout << "End year - " << endYear << "\n";
}
void getNumStudents(Student& student) { std::cout << "\nYou have " << student.counter << " student(s)\n\n"; }