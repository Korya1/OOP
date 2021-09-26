#pragma once
#include "Common.h"
//
// --------- class Person
//
class Person
{
public:
	Person() {};
	Person(const std::string& name, const std::string& sex, short int age, float weight)
		:
		name(name),
		sex(sex),
		age(age),
		weight(weight)
	{}
	void setName(const std::string& name);
	void setSex(const std::string& sex);
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
void Person::setName(const std::string& name) { this->name = name; }
void Person::setSex(const std::string& sex) { this->sex = sex; }
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
	Student(){ };

	Student(const std::string& name, const std::string& sex, short int age, float weight, std::size_t startYear, std::size_t endYear)
		:
		Person(name, sex, age, weight),
		startYear(startYear),
		endYear(endYear)		
	{}
	void setStartYear(std::size_t startYear);
	void setEndYear(std::size_t endYear);
	void getInfo();
	

private:
	std::size_t startYear{ 0 }, endYear{ 0 };	
};
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
	std::cout << "End year - " << endYear << "\n";	
}
//
// --------- class CollectStudents
//
class CollectStudents
{
public:
	CollectStudents(){};
	void addStudent(const Student& student);
	void getStudent(const std::string& name);

private:
	std::vector<Student> stack;	
};

void CollectStudents::addStudent(const Student& student)
{	
	stack.emplace_back(student);
}


void CollectStudents::getStudent(const std::string& name)
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
			std::cout << "\nYou have " << stack.size() << " student(s)\n\n";
			break;
		}
	}
	if (!isStudent)	{ std::cout << "Student not found\n"; }

	
}

void run()
{

	CollectStudents collect;
	std::string name;	
	
	collect.addStudent(Student("Ivan", "Male", 23, 107.4, 2015, 2020));
	collect.addStudent(Student("Vasya", "Male", 21, 65.4, 2015, 2020));
	collect.addStudent(Student("Petya", "Male", 17, 89.2, 2015, 2020));
	collect.addStudent(Student("Tanya", "Female", 23, 45.2, 2015, 2020));

	std::cout << "Write student name: ";
	std::cin >> name;

	collect.getStudent(name);

}