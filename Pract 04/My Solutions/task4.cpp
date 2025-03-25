#include <iostream>
#include <fstream>

struct Person
{
  char name[24];
  unsigned salary;
};

void addPersonToFile(const char* filename)
{
  Person person;

  std::cout << "Enter name: ";
  std::cin.getline(person.name, 24);

  std::cout << "Enter salary: ";
  std::cin >> person.salary;

  std::ofstream outFile(filename, std::ios::binary | std::ios::app);
  if (!outFile.is_open())
  {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }

  outFile.write(reinterpret_cast<char*>(&person), sizeof(Person));
  outFile.close();
}

void printAboveAverageSalary(const char* filename)
{
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile.is_open())
  {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }

  int count = 0;
  unsigned allSalaries = 0;
  Person person;

  while (inFile.read(reinterpret_cast<char*>(&person), sizeof(Person)))
  {
    allSalaries += person.salary;
    count++;
  }

  unsigned averageSalary = allSalaries / count;

  inFile.clear();
  inFile.seekg(0, std::ios::beg);

  std::cout << "People with salary above average: " << std::endl;
  while (inFile.read(reinterpret_cast<char*>(&person), sizeof(Person)))
  {
    if (person.salary > averageSalary)
    {
      std::cout << "Name: " << person.name << ", Salary: " << person.salary << std::endl;
    }
  }

  inFile.close();
}

int main() {
  const char* filename = "people.dat";

  int choice;
  std::cout << "1. Add Person" << std::endl;
  std::cout << "2. Print people with salary above the average" << std::endl;
  std::cin >> choice;

  switch (choice)
  {
  case 1:
    addPersonToFile(filename);
    break;
  case 2:
    printAboveAverageSalary(filename);
    break;
  default:
    std::cout << "Invalid choice!" << std::endl;
  }

  return 0;
}