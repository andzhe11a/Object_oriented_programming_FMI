#include <iostream>
#include <fstream>

enum Faculty {FMI, History, Geography};

struct Student
{
  char name[26];
  char facultyNumber[11];
  int faculty;

  void input()
  {
    std::cout << "Enter name of the student (max 25 symbols): ";
    std::cin.getline(name, 26);
    std::cout << "Enter faculty number (10 symbols): ";
    std::cin.getline(facultyNumber, 10);

    int fac;
    do
    {
      std::cout << "Enter faculty (1 - FMI, 2 - History, 3 - Geography): ";
      std::cin >> fac;
    } while (fac < 1 || fac > 3);

    std::cin.ignore();
  }

  void saveToBinary(const char* filename) const
  {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);
    if (!outFile.is_open())
    {
      std::cerr << "Error opening file " << filename << std::endl;
      return;
    }
    outFile.write(reinterpret_cast<const char*>(this), sizeof(Student));
  }

  bool readFromBinary(const char* filename)
  {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open())
    {
      std::cerr << "Error opening file " << filename << std::endl;
      return false;
    }
    inFile.read(reinterpret_cast<char*>(this), sizeof(Student));
  }
};

struct Course
{
  char name[51];
  Student students[100];
  int studentCount;

  void input()
  {
    std::cout << "Enter course name (max 50 symbols): ";
    std::cin.getline(name, 51);

    std::cout << "Enter number of students: ";
    std::cin >> studentCount;
    std::cin.ignore();

    for (int i = 0; i < studentCount; i++) {
      std::cout << "Enter details for student " << i + 1 << ":\n";
      students[i].input();
    }
  }

  void saveToBinray(const char* filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
      std::cerr << "Error opening file " << filename << std::endl;
      return;
    }
    outFile.write(name, sizeof(name));
    outFile.write(reinterpret_cast<const char*>(&studentCount), sizeof(studentCount));
    for (int i = 0; i < studentCount; i++) {
      students[i].saveToBinary(filename);
    }
  }

  void readFromBinary(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
      std::cerr << "Error opening file " << filename << std::endl;
      return;
    }
    inFile.read(name, sizeof(name));
    inFile.read(reinterpret_cast<char*>(&studentCount), sizeof(studentCount));
    for (int i = 0; i < studentCount; i++) {
      students[i].readFromBinary(filename);
    }
  }
};

int main() {
  Course course;
  course.input();

  course.saveToBinray("course.dat");

  Course loadedCourse;
  loadedCourse.readFromBinary("course.dat");

  return 0;
}