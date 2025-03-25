#include <iostream>
#include <fstream>
#include <cmath>

struct Point
{
  double x, y;
};

double distance(const Point& p1, const Point& p2)
{
  return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                   (p1.y - p2.y) * (p1.y - p2.y));
}

Point calculateCG(const Point* points, int count)
{
  Point cg = {0, 0};
  if (count == 0) return cg;

  for (int i = 0; i < count; i++)
  {
    cg.x += points[i].x;
    cg.y += points[i].y;
  }

  cg.x /= count;
  cg.y /= count;

  return cg;
}

Point* readPointsFromFile(const char* filename, int& count)
{
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile.is_open())
  {
    std::cerr << "Could not open file " << filename << std::endl;
    return nullptr;
  }

  inFile.seekg(0, std::ios::end);
  int fileSize = inFile.tellg();
  count = fileSize / sizeof(Point);
  inFile.seekg(0, std::ios::beg);

  Point* points = new Point[count];
  inFile.read(reinterpret_cast<char*>(points), fileSize);
  inFile.close();

  return points;
}

int main () {
  char inputFile[100];
  std::cout << "Enter the name of the binary file: ";
  std::cin >> inputFile;

  int count;
  Point* points = readPointsFromFile(inputFile, count);

  Point cg = calculateCG(points, count);
  std::cout << "The center of gravity of the points is: (" << cg.x << ", " << cg.y << ")" << std::endl;

  delete[] points;

  return 0;
}