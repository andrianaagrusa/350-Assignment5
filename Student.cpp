#include "Student.h"

Student::Student(){}

Student::Student(int studentID)
{
  this->studentID = studentID;
}

Student::Student(string name, string year, string major, double gpa, int studentID, int facultyID)
{
  this->name = name;
  this->year = year;
  this->major = major;
  this->gpa = gpa;
  this->studentID = studentID;
  this->facultyID = facultyID;
}

Student::~Student(){}

bool operator<(const Student &s1, const Student &s2)
{
  return s1.studentID < s2.studentID;
}

bool operator>(const Student &s1, const Student &s2)
{
  return s1.studentID > s2.studentID;
}

bool operator==(const Student &s1, const Student &s2)
{
  return s1.studentID == s2.studentID;
}

bool operator!=(const Student &s1, const Student &s2)
{
  return s1.studentID != s2.studentID;
}

ostream& operator<<(ostream& os, const Student &s1)
{
    os << "Name: " << s1.name <<
      "\nYear: " << s1.year <<
      "\nMajor: " << s1.major <<
      "\nGPA: " << s1.gpa <<
      "\nStudent ID: " << s1.studentID <<
      "\nAdvisor ID: " << s1.facultyID <<
      "\n";

  return os;
}
