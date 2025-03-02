#include <iostream>
#include <cmath>

struct Point
{
  double x;
  double y;
};

Point readInput()
{
  Point point;
  std::cout << "Enter x coordinate: ";
  std::cin >> point.x;

  std::cout << "Enter y coordinate: ";
  std::cin >> point.y;

  return point;
}

void printPoint(const Point &point)
{
  std::cout << "(" << point.x << ", " << point.y << ")";
}

double findDistance(const Point &point1, const Point &point2)
{
  return sqrt(((point2.x - point1.x) * (point2.x - point1.x)) + ((point2.y - point1.y) * (point2.y - point1.y)));
}

int main() {
  std::cout << "Enter the first point: " << std::endl;
  Point point1 = readInput();
  std::cout << std::endl;

  std::cout << "Enter the second point: " << std::endl;
  Point point2 = readInput();
  std::cout << std::endl;

  std::cout << "Point 1: ";
  printPoint(point1);
  std::cout << std::endl;
  std::cout << "Point 2: ";
  printPoint(point2);
  std::cout << std::endl;

  double distance = findDistance(point1, point2);
  std::cout << "\nDistance between the two points: " << distance << std::endl;

  return 0;
}