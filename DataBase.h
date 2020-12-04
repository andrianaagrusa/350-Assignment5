#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <sstream>
#include <algorithm>


using namespace std;

class DataBase
{
public:
  DataBase();
  ~DataBase();

  BST<Student>* masterStudent;
  BST<Faculty>* masterFaculty;

  void getOrder();
  void userOptions();
};
