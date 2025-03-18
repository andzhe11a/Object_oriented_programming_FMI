#include <iostream>
#include <fstream>

struct City
{
  char name[64];
  unsigned population;
};

struct District
{
  City cities[20];
  int size;
};

void inputDistrict(District &district)
{
  std::cout << "Enter the number of cities (max 20): ";
  std::cin >> district.size;

  if (district.size > 20)
  {
    std::cout << "Too many cities!" << std::endl;
    district.size = 20;
  }

  std::cin.ignore();

  for (int i = 0; i < district.size; i++)
  {
    std::cout << "Enter the name of the city: ";
    std::cin.getline(district.cities[i].name, 64);

    std::cout << "Enter the population: ";
    std::cin >> district.cities[i].population;
    std::cin.ignore();
  }
}

void addDistrictToFile(const District& district, const char* filename)
{
  std::ofstream outputFile(filename);
  if (!outputFile.is_open())
  {
    std::cout << "Could not open file " << filename << std::endl;
    return;
  }

  outputFile << district.size << std::endl;
  for (int i = 0; i < district.size; i++)
  {
    outputFile << district.cities[i].name << " " << district.cities[i].population << std::endl;
  }

  outputFile.close();
}

void readDistrictFromFile (District& district, const char* filename)
{
  std::ifstream inFile(filename);
  if (!inFile.is_open())
  {
    std::cout << "Could not open file " << filename << std::endl;
    return;
  }

  inFile >> district.size;
  inFile.ignore();

  for (int i = 0; i < district.size; i++)
  {
    inFile.getline(district.cities[i].name, 64, ' ');
    inFile >> district.cities[i].population;
    inFile.ignore();
  }

  inFile.close();
}

void sortDistrictByPopulation(District &district)
{
  for (int i = 0; i < district.size - 1; i++)
  {
    for (int j = 0; j < district.size - i - 1; j++)
    {
      if (district.cities[j].population > district.cities[j + 1].population)
      {
        City temp = district.cities[j];
        district.cities[j] = district.cities[j + 1];
        district.cities[j + 1] = temp;
      }
    }
  }
}

void saveToOutputFile (const char* inputFile, const char* outputFile)
{
  District district;
  readDistrictFromFile(district, inputFile);
  sortDistrictByPopulation(district);
  addDistrictToFile(district, outputFile);
}

int main() {
  District district;
  char inputFile[100], outputFile[100];

  inputDistrict(district);

  std::cout << "Enter the name of the file to save district: ";
  std::cin.getline(inputFile, 100);

  addDistrictToFile(district, inputFile);

  std::cout << "Enter the name of the file to save sorted district: ";
  std::cin.getline(outputFile, 100);

  saveToOutputFile(inputFile, outputFile);

  return 0;
}
