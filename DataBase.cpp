#include "DataBase.h"

using namespace std;

DataBase::DataBase()
{
  masterStudent = new BST<Student>;
  masterFaculty = new BST<Faculty>;
}

DataBase::~DataBase()
{
  delete masterStudent;
  delete masterFaculty;
}

// organizes data for serialiation
void DataBase::getOrder()
{
  ifstream studentFile;
  ifstream facultyFile;
  studentFile.open("studentFile.txt");
  facultyFile.open("facultyFile.txt");

  string line = "";
  if (studentFile.is_open())
  {
    while (!studentFile.eof())
    {

      string n = ""; // name
      string y = ""; // year
      string m = ""; // major
      double g = 0; // gpa
      int sID = 0; // student id
      int fID = 0; // faculty id

      getline(studentFile, line); //read name
      if (line.empty())
        continue;
      line.erase(0, 6);
      n = line;

      getline(studentFile, line); //year
      line.erase(0, 6);
      y = line;

      getline(studentFile, line); //major
      line.erase(0, 7);
      m = line;

      getline(studentFile, line); //gpa
      line.erase(0, 5);
      g = stod(line);

      line = "";
      getline(studentFile, line); //studentID
      line.erase(0, 12);
      sID = stoi(line);

      getline(studentFile, line); //facultyID
      line.erase(0, 12);
      fID = stoi(line);

      Student s(n, y, m, g, sID, fID);
      masterStudent->insert(s);
    }
  }

  if (facultyFile.is_open())
  {
    while (!facultyFile.eof())
    {
      string n = "";
      string l = "";
      string d = "";
      int fID = 0;

      getline(facultyFile, line); //name
      if (line.empty())
        continue;
      line.erase(0, 6);
      n = line;

      getline(facultyFile, line); //level
      line.erase(0, 7);
      l = line;

      getline(facultyFile, line); //department
      line.erase(0, 12);
      d = line;

      getline(facultyFile, line); //facultyID
      line.erase(0, 12);
      fID = stod(line);

      Faculty f(n, l, d, fID);

      getline(facultyFile, line); //student IDs
      line.erase(0, 15);
      if (line.empty())
      {
        masterFaculty->insert(f);
        continue;
      }
      stringstream iss(line);
      while (iss >> line)
      masterFaculty->insert(f);
    }
  }

  studentFile.close();
  facultyFile.close();
}



void DataBase::userOptions()
{
  while (true)
  {
    string userInput = "";
    string inputValue = "";
    string inputValue2 = "";
    cout <<
      "\nEnter the number for what you would like to do:"
      "\n1. Print all students and their information (sorted by ascending ID #)" <<
      "\n2. Print all faculty and their information (sorted by ascending ID #)" <<
      "\n3. Find and display student information given the students ID" <<
      "\n4. Find and display faculty information given the faculty ID" <<
      "\n5. Given a student’s ID, print the name and info of their faculty advisor" <<
      "\n6. Given a faculty ID, print all the names and info of his/her advisees" <<
      "\n7. Add a new student" <<
      "\n8. Delete a student given the ID" <<
      "\n9. Add a new faculty member" <<
      "\n10. Delete a faculty member given the ID" <<
      "\n11. Change a student’s advisor given the student id and the new faculty ID" <<
      "\n12. Remove an advisee from a faculty member given the IDs" <<
      "\n13. Rollback" <<
      "\n14. Exit" <<
      "\n";

    cin >> userInput;

    switch (stoi(userInput))
    {
      // in the order of the above list:

      case 1: // print all students and their info
      {
        masterStudent->printTree();
        break;
      }

      case 2: // print all faculty and their info
      {
        masterFaculty->printTree();
        break;
      }

      case 3: // find and display student info
      {
        cout << "Enter the student ID: " << endl;
        cin >> inputValue;
        if (masterStudent->search(stoi(inputValue)))
        {
          cout << masterStudent->search(stoi(inputValue))->key << endl; // prints the student & their info
        }

        else
        {
          cout << "Student not found" << endl;
        }

        break;
      }

      case 4: // find and display faculty member info
      {
        cout << "Enter the faculty ID:" << endl;
        cin >> inputValue;
        if (masterFaculty->search(stoi(inputValue)))
        {
          cout << masterFaculty->search(stoi(inputValue))->key << endl; // prints the faculty member & their info
        }

        else
        {
          cout << "Faculty member not found" << endl;
        }

        break;
      }

      case 5: // print a student's faculty advisor
      {
        cout << "Enter the student ID:" << endl;
        cin >> inputValue;
        int tempVar = stoi(inputValue);
        if (masterStudent->search(tempVar))
        {
          if (masterFaculty->search(masterStudent->search(tempVar)->key.facultyID)) // found both student and faculty member
          {
            cout << (masterFaculty->search(masterStudent->search(tempVar)->key.facultyID)->key) << endl; //prints corresponding faculty member & their info
          }
          else
          {
            cout << "Faculty member not found" << endl;
          }
        }
        else
        {
          cout << "Student not found" << endl;
        }

        break;
      }

      case 6: // print advisees
      {
        cout << "Enter the faculty ID:" << endl;
        cin >> inputValue;
        if (masterFaculty->search(stoi(inputValue))) //if faculty member found
        {
          vector<int>* vect; // advisee list

          for (int i = 0; i < vect->size(); i++)
          {
            cout << masterStudent->search((*vect)[i])->key << endl; // prints their students
          }
        }

        else
        {
          cout << "Faculty member not found" << endl;
        }

        break;
      }

      case 7:  // add student
      {
        string name = "";
        string year = "";
        string major = "";
        double gpa = 0;
        int studentID = 0;
        int facultyID = 0;
        cin.ignore();

        cout << "Enter student name:" << endl;
        getline(cin, name);

        cout << "Enter student year:" << endl;
        getline(cin, year);

        cout << "Enter student major:" << endl;
        getline(cin, major);

        cout << "Enter student GPA:" << endl;
        getline(cin, inputValue);
        gpa = stod(inputValue);

        cout << "Enter student ID:" << endl;
        getline(cin, inputValue);
        studentID = stoi(inputValue);

        if (!masterStudent->search(studentID)) //make sure the student doesn't already exist
        {
          masterStudent->insert(Student(name, year, major, gpa, studentID, -1)); // empty faculty member to start
        }
        else
        {
          cout << "Student already exists" << endl;
        }
        break;
      }

      case 8: // delete student
      {
        cout << "Enter the student ID:" << endl;
        cin >> inputValue;
        int temp = stoi(inputValue);
        if (masterStudent->search(temp))
        {
          if (masterStudent->search(temp)->key.facultyID == -1) // make sure student doesn't have an advisor
          {
            masterStudent->deleteNode(temp);
          }
          else
            cout << "Remove the student's advisor before deleting the student" << endl;
        }
        else
        {
          cout << "Student not found" << endl;
        }
        break;
      }

      case 9: // add faculty member
      {
        string name = "";
        string level = "";
        string department = "";
        int facultyID = 0;
        cin.ignore();

        cout << "Enter faculty member name:" << endl;
        getline(cin, name);

        cout << "Enter faculty member level:" << endl;
        getline(cin, level);

        cout << "Enter faculty member department:" << endl;
        getline(cin, department);

        cout << "Enter faculty member ID:" << endl;
        getline(cin, inputValue);
        facultyID = stoi(inputValue);

        Faculty fac(name, level, department, facultyID);

        if (!masterFaculty->search(facultyID)) // make sure faculty member doesn't already exist
        {
          masterFaculty->insert(fac);
        }
        else
        {
          cout << "Faculty member already exists" << endl;
        }

        break;
      }

      case 10: // delete faculty member
      {
        cout << "Enter the faculty member ID:" << endl;
        cin >> inputValue;
        int tempVal = stoi(inputValue);
        if (masterFaculty->search(tempVal)) //if faculty member found
        {
            masterFaculty->deleteNode(tempVal);
        }
        else
        {
          cout << "Faculty member not found" << endl;
        }
        break;
      }

      case 11: // swap student advisor
      {
        cout << "Enter the student ID:" << endl;
        cin >> inputValue;

        cout << "Enter the faculty member ID:" << endl;
        cin >> inputValue2;

        int tempVal1 = stoi(inputValue);
        int tempVal2 = stoi(inputValue2);

        if (masterStudent->search(tempVal1))
        {
          if (masterFaculty->search(tempVal2)) // both student and corresponding faculty member found
          {
            if (masterStudent->search(stoi(inputValue))->key.facultyID == -1) // no advisor
            {
              masterStudent->search(tempVal1)->key.facultyID = tempVal2;
            }
            else
            {
              cout << "Error: Remove current faculty advisor before switching" << endl;
            }
          }
          else
          {
            cout << "Faculty member not found" << endl;
          }
        }
        else
        {
          cout << "Student not found" << endl;
        }
        break;
      }

      case 12: // remove student from advisee list
      {
        cout << "Enter the faculty member ID:" << endl;
        cin >> inputValue;

        cout << "Enter the student ID:" << endl;
        cin >> inputValue2;

        int tempVal1 = stoi(inputValue2);
        int tempVal2 = stoi(inputValue);
        if (masterFaculty->search(tempVal2))
        {
          if (masterStudent->search(tempVal1))
          {
            if (masterStudent->search(tempVal1)->key.facultyID == stoi(inputValue))
            {
              masterStudent->search(tempVal1)->key.facultyID = -1;
            }

            else
            {
              cout << "Advisee not found" << endl;
            }
          }

          else
            cout << "Student not found" << endl;
        }
          else
          {
            cout << "Faculty member not found" << endl;
          }

        break;
      }

      case 13: //rollback
      {
        // would need a stack of operations
        break;
      }

      case 14: // exit
      {
        // save data onto file before exiting
        ofstream myStu;
        ofstream myFac;
        myStu.open("student.txt");
        myFac.open("faculty.txt");
        if (myStu.is_open())
          masterStudent->serialize(myStu);
        if (myFac.is_open())
          masterFaculty->serialize(myFac);
        myStu.close();
        myFac.close();
        return;
      }

      default:
      {
        cout << "Please enter a number from the above list." << endl;
      }

    }
  }
}
