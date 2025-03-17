#include <iostream>
#include <fstream>

void countFileLines(const char* fileName)
{
  std::ifstream file(fileName);
  if (!file.is_open())
  {
    std::cout << "Could not open file" << fileName << std::endl;
    return;
  }

  int lineCount = 0;
  char line[256];

  while (file.getline(line, sizeof(line)))
  {
    lineCount++;
  }

  file.close();

  std::cout << "File " << fileName << " contains " << lineCount << " lines!" << std::endl;
}

int main() {
  char fileName[100];

  std::cout << "Enter the name of the file: ";
  std::cin >> fileName;

  countFileLines(fileName);

  return 0;
}