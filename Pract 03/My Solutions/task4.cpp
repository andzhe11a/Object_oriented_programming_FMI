#include <iostream>
#include <fstream>

void includeSumAndProdInFile (unsigned a, unsigned b, unsigned c, const char* fileName)
{
  std::ofstream file(fileName);
  if (!file.is_open())
  {
    std::cout << "Could not open file " << fileName << std::endl;
    return;
  }

  unsigned sum = a + b + c;
  unsigned product = a * b * c;

  file << sum << std::endl;
  file << product << std::endl;

  file.close();
}

int main() {
  unsigned a, b, c;
  std::cout << "Enter 3 numbers: ";
  std::cin >> a >> b >> c;

  char fileName[100];
  std::cout << "Enter the name of the file: ";
  std::cin >> fileName;

  includeSumAndProdInFile(a, b, c, fileName);

  return 0;
}