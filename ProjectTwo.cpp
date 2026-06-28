#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// Course structure
struct Course
{
  string courseNumber;
  string courseTitle;
  vector<string> prerequisites;
};

// Global variables
unordered_map<string, Course> courseTable;
bool dataLoaded = false;

// Function declarations
void displayMenu();
void loadCourses(string fileName);
void printCourseList();
void printCourse(string courseNumber);
string toUpperCase(string text);

// Display menu
void displayMenu()
{
  cout << endl;
  cout << "1. Load Data Structure." << endl;
  cout << "2. Print Course List." << endl;
  cout << "3. Print Course." << endl;
  cout << "9. Exit" << endl;
}
string toUpperCase(string text)
{
  for (char &ch : text)
  {
    ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
  }
  return text;
}

void loadCourses(string fileName)
{
  courseTable.clear();
  dataLoaded = false;
  // Open the file
  ifstream file(fileName);

  // Verify file opened successfully
  if (!file.is_open())
  {
    cout << "Unable to open file." << fileName << endl;
    return;
  }

  string line;

  // Read each line from the CSV file
  while (getline(file, line))
  {
    stringstream ss(line);

    string token;
    vector<string> tokens;

    // Split the line using commas
    while (getline(ss, token, ','))
    {
      // Remove carriage return characters from Windows CSV files
      token.erase(remove(token.begin(), token.end(), '\r'), token.end());

      tokens.push_back(token);
    }

    // Display an error and skip invalid records
    if (tokens.size() < 2)
    {
      cout << "Format Error: Course record is invalid" << endl;
      continue;
    }

    // Create a course object
    Course course;

    course.courseNumber = toUpperCase(tokens[0]);
    course.courseTitle = tokens[1];

    // Store prerequisites (if any)
    for (size_t i = 2; i < tokens.size(); i++)
    {
      if (!tokens[i].empty())
      {
        course.prerequisites.push_back(toUpperCase(tokens[i]));
      }
    }
    // Insert into hash table
    courseTable[course.courseNumber] = course;
  }

  file.close();

  // Optional prerequisite validation
  for (const auto &pair : courseTable)
  {
    const Course &course = pair.second;

    for (const string &prereq : course.prerequisites)
    {
      if (prereq.empty())
      {
        continue;
      }

      if (courseTable.find(prereq) == courseTable.end())
      {
        cout << "Prerequisite course number "
             << prereq
             << ". No matching course number exists."
             << endl;
      }
    }
  }

  dataLoaded = true;
  cout << "Courses loaded successfully." << endl;
}

void printCourseList()
{
  vector<Course> courses;

  // Copy courses into a vector so they can be sorted
  for (const auto &pair : courseTable)
  {
    courses.push_back(pair.second);
  }

  // Sort courses from lowest to highest course number
  sort(courses.begin(), courses.end(),
       [](const Course &a, const Course &b)
       {
         return a.courseNumber < b.courseNumber;
       });

  cout << "Computer Science Courses:" << endl;

  // Display the sorted course list
  for (const Course &course : courses)
  {
    cout << course.courseNumber << ", "
         << course.courseTitle << endl;
  }
}

void printCourse(string courseNumber)
{
  // Convert user input to uppercase before searching
  courseNumber = toUpperCase(courseNumber);
  // Search for the course in the hash table
  auto it = courseTable.find(courseNumber);
  // Display a message if the course is not found
  if (it == courseTable.end())
  {
    cout << "Course not found." << endl;
    return;
  }

  const Course &course = it->second;
  // Display the course number and title
  cout << course.courseNumber << ", "
       << course.courseTitle << endl;

  // Display the course prerequisites
  cout << "Prerequisites:" << endl;

  if (course.prerequisites.empty())
  {
    cout << "None" << endl;
  }
  else
  {
    // Display each prerequisite course
    for (const string &prereq : course.prerequisites)
    {
      // Find the prerequisite in the hash table
      auto prereqIt = courseTable.find(prereq);

      if (prereqIt != courseTable.end())
      {
        cout << prereqIt->second.courseNumber
             << ", "
             << prereqIt->second.courseTitle
             << endl;
      }
      else
      {
        cout << prereq << endl;
      }
    }
  }
}

// Main program loop
int main()
{

  cout << "Welcome to the course planner." << endl;

  int choice = 0;

  do
  {
    // Show the menu options
    displayMenu();

    cout << "What would you like to do? ";
    // Handle invalid menu input
    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input." << endl;
      continue;
    }
    // Load course data from a file
    if (choice == 1)
    {

      string fileName;

      cout << "Enter file name: ";
      cin >> fileName;

      loadCourses(fileName);
    }
    // Print the complete course list
    else if (choice == 2)
    {

      if (!dataLoaded)
      {
        cout << "Please load data first." << endl;
      }
      else
      {
        printCourseList();
      }
    }
    // Display information for one course
    else if (choice == 3)
    {

      if (!dataLoaded)
      {
        cout << "Please load data first." << endl;
      }
      else
      {

        string courseNumber;

        cout << "What course do you want to know about? ";
        cin >> courseNumber;

        printCourse(courseNumber);
      }
    }
    // Exit the program
    else if (choice == 9)
    {

      cout << "Thank you for using the course planner!" << endl;
    }
    // Handle invalid menu choices
    else
    {

      cout << choice << " is not a valid option." << endl;
    }

  } while (choice != 9);

  return 0;
}
