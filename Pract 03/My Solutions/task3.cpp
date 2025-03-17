#include <iostream>
#include <fstream>

void copyFileContent(const char* sourceFile, const char* destinationFile)
{
  std::ifstream source(sourceFile);
  if (!source.is_open())
  {
    std::cout << "Could not open source file " << source << std::endl;
    return;
  }

  std::ofstream destination(destinationFile);
  if (!destination.is_open())
  {
    std::cout << "Could not open destination file " << destination << std::endl;
    source.close();
    return;
  }

  char line[256];
  while (source.getline(line, sizeof(line)))
  {
    destination << line << std::endl;
  }

  source.close();
  destination.close();
}

int main() {
  char sourceFile[100], destinationFile[100];

  std::cout << "Enter the name of the source file: ";
  std::cin >> sourceFile;

  std::cout << "Enter the name of the destination file: ";
  std::cin >> destinationFile;

  copyFileContent(sourceFile, destinationFile);

  return 0;
}
