
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Faculty
{
public:
  Faculty();
  Faculty(int facultyID);
  Faculty(string name, string level, string department, int facultyID);
  ~Faculty();

  string name;
  string level;
  string department;

  int facultyID;
};

bool operator<(const Faculty &f1, const Faculty &f2);
bool operator>(const Faculty &f1, const Faculty &f2);
bool operator==(const Faculty &f1, const Faculty &f2);
bool operator!=(const Faculty &f1, const Faculty &f2);
ostream& operator<<(ostream& os, const Faculty &f1);
