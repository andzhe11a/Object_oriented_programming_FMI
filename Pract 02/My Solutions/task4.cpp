#include <iostream>
#include <cmath>

struct Triangle
{
  double a, b, c;
};

Triangle inputTriangle()
{
  Triangle triangle;
  std::cout << "Enter the three sides of the triangle: ";
  std::cin >> triangle.a >> triangle.b >> triangle.c;

  return triangle;
}

void printTriangle(const Triangle& triangle)
{
  std::cout << "Side A: " << triangle.a << ", " << "Side b: " << triangle.b << ", " << "Side C: " << triangle.c << std::endl;
}

double perimeter(const Triangle& triangle)
{
  return triangle.a + triangle.b + triangle.c;
}

double area(const Triangle& triangle)
{
  double semiPer = perimeter(triangle) / 2;
  return sqrt(semiPer * (semiPer - triangle.a) * (semiPer - triangle.b) * (semiPer - triangle.c));
}

std::string typeBySides(const Triangle& triangle)
{
  if (triangle.a == triangle.b && triangle.b == triangle.c)
  {
    return "Equilateral";
  }

  if (triangle.a == triangle.b || triangle.b == triangle.c || triangle.a == triangle.c)
  {
    return "Isosceles";
  }

  return "Scalene";
}

int main() {
  Triangle triangle = inputTriangle();

  printTriangle(triangle);
  std::cout << std::endl;

  std::cout << "Perimeter = " << perimeter(triangle) << std::endl;
  std::cout << "Area = " << area(triangle) << std::endl;
  std::cout << "The triangle is: " << typeBySides(triangle);

  return 0;
}