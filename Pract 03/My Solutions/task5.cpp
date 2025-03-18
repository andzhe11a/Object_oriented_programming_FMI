#include <iostream>
#include <fstream>

void mergeSortedFiles(const char* file1, const char* file2, const char* resultFile)
{
  std::ifstream firstFile(file1), secondFile(file2);
  std::ofstream outputFile(resultFile);

  if (!firstFile.is_open() || !secondFile.is_open() || !outputFile.is_open())
  {
    std::cout << "Could not open the files!" << std::endl;
    return;
  }

  int currNum1, currNum2;
  bool hasNum1 = (firstFile >> currNum1);
  bool hasNum2 = (secondFile >> currNum2);

  while (hasNum1 && hasNum2)
  {
    if (currNum1 < currNum2)
    {
      outputFile << currNum1 << " ";
      hasNum1 = (firstFile >> currNum1);
    }
    else
    {
      outputFile << currNum2 << " ";
      hasNum2 = (secondFile >> currNum2);
    }
  }

  while (hasNum1)
  {
    outputFile << currNum1 << " ";
    hasNum1 = (firstFile >> currNum1);
  }

  while (hasNum2)
  {
    outputFile << currNum2 << " ";
    hasNum2 = (secondFile >> currNum2);

    firstFile.close();
    secondFile.close();
    outputFile.close();
  }
}

int main() {
  char file1[100], file2[100], resultFile[100];

  std::cout << "Enter the name of the first sorted file: ";
  std::cin >> file1;

  std::cout << "Enter the name of the second sorted file: ";
  std::cin >> file2;

  std::cout << "Enter the name of the result file: ";
  std::cin >> resultFile;

  mergeSortedFiles(file1, file2, resultFile);

  return 0;
}