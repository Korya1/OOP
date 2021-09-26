#pragma once
#include "Common.h"
const int SIZE = 10;
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
	void setSex(std::string sex);
	void setAge(short int age);
	void setWeight(float weight);

	std::string getName();
	std::string getSex();
	int getAge();
	int getWeight();

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
void Person::setSex(std::string sex) { this->sex = sex; }
void Person::setAge(short int age) { this->age = age; }
void Person::setWeight(float weight) { this->weight = weight; }
//
// --------- GETs
//
std::string Person::getName() { return name; };
std::string Person::getSex() { return sex; };
int Person::getAge() { return age; };
int Person::getWeight() { return weight; };
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
	std::cout << "\nName - " << name << "\n";
	std::cout << "Sex - " << sex << "\n";
	std::cout << "Age - " << age << "\n";
	std::cout << "Weight - " << weight << "\n";
	std::cout << "Start year - " << startYear << "\n";
	std::cout << "End year - " << endYear << "\n\n";
}
void getNumStudents(Student& student) { std::cout << "\nYou have " << student.counter << " student(s)\n\n"; }
//
// --------- class CollectStudents
//
class CollectStudents
{
public:
	CollectStudents(){};
	void addStudent(Student& student);
	void getStudent(std::string name);

private:
	std::vector<Student> stack;	
};

void CollectStudents::addStudent(Student& student)
{
	stack.push_back(student);
}

void CollectStudents::getStudent(std::string name)
{
	std::string findName;
	bool isStudent = false;

	for (size_t i = 0; i < stack.size(); i++)
	{
		findName = stack[i].getName();
		if (findName == name)
		{
			isStudent = true;
			stack[i].getInfo();
			break;
		}
	}

	if (!isStudent)	{ std::cout << "Student not found\n"; }
}

void run()
{
	CollectStudents collect;
	std::string name;

	Student student1("Vasya", "Male", 21, 65.4, 2015, 2020);
	Student student2("Petya", "Male", 17, 89.2, 2015, 2020);
	Student student3("Tanya", "Female", 23, 45.2, 2015, 2020);
	Student student4("Ivan", "Male", 23, 107.4, 2015, 2020);
	collect.addStudent(student1);
	collect.addStudent(student2);
	collect.addStudent(student3);
	collect.addStudent(student4);

	std::cout << "Write student name: ";
	std::cin >> name;

	collect.getStudent(name);

}