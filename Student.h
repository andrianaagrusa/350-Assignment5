#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int studentID);
  Student(string name, string year, string major, double gpa, int studentID, int facultyID);
  ~Student();

  string name;
  string year;
  string major;

  double gpa;

  int studentID;
  int facultyID;

};

bool operator<(const Student &s1, const Student &s2);
bool operator>(const Student &s1, const Student &s2);
bool operator==(const Student &s1, const Student &s2);
bool operator!=(const Student &s1, const Student &s2);
ostream& operator<<(ostream& os, const Student &s1);
