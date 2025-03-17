#include <iostream>
#include <fstream>

void printFile(const char* fileName)
{
  std::ifstream file(fileName);
  if (!file.is_open())
  {
    std::cout << "Could not open file " << fileName << std::endl;
    return;
  }

  char line[256];
  while (file.getline(line, sizeof(line)))
  {
    std::cout << line << std::endl;
  }

  file.close();
}

int main() {
  char fileName[100];

  std::cout << "Enter the name of the file: ";
  std::cin >> fileName;

  printFile(fileName);

  return 0;
}
