#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <cstddef>

using namespace std;

int main (int argc, char** argv)
{
  DataBase dataBase;
  
  dataBase.getOrder();
  dataBase.userOptions();

  return 0;
}
