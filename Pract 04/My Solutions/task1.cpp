#include <iostream>
#include <fstream>

long getFileSize(const char* filename)
{
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  if (!file.is_open())
  {
    std::cout << "Could not open file " << filename << std::endl;
    return -1;
  }

  long size = file.tellg();
  file.close();
  return size;
}

int main() {
  char filename[256];

  std::cout << "Enter the name of the binary file: ";
  std::cin >> filename;

  long size = getFileSize(filename);
  if (size != -1)
  {
    std::cout << "The size of the file is: " << size << " bytes!" << std::endl;
  }

  return 0;
}