#include "Faculty.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Faculty::Faculty(){}

Faculty::Faculty(int facultyID)
{
  this->facultyID = facultyID;
}

Faculty::Faculty(string name, string level, string department, int facultyID)
{
  this->name = name;
  this->level = level;
  this->department = department;
  this->facultyID = facultyID;
}

Faculty::~Faculty(){}

bool operator<(const Faculty &f1, const Faculty &f2)
{
  return f1.facultyID < f2.facultyID;
}

bool operator>(const Faculty &f1, const Faculty &f2)
{
  return f1.facultyID > f2.facultyID;
}

bool operator==(const Faculty &f1, const Faculty &f2)
{
  return f1.facultyID == f2.facultyID;
}

bool operator!=(const Faculty &f1, const Faculty &f2)
{
  return f1.facultyID != f2.facultyID;
}

ostream &operator<<(ostream &os, const Faculty &f1)
{
  stringstream result;

  os <<
    "Name: " << f1.name <<
    "\nLevel: " << f1.level <<
    "\nDepartment: " << f1.department <<
    "\nFaculty ID: " << f1.facultyID <<
    "\n";

  return os;
}
