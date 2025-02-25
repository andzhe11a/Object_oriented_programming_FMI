#include <iostream>

void fillArray(int* arr, int size)
{
  std::cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++)
  {
    std::cin >> arr[i];
  }
}

void printArray (int* arr, int size)
{
  std::cout << "[";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i];
    if (i < size - 1)
    {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int multiplyByTwo(int a)
{
  return a * 2;
}

void map(int* arr, int size, int(*func)(int))
{
  for (int i = 0; i < size; i++)
  {
    arr[i] = func(arr[i]);
  }
}

int main() {
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  int* arr = new int[size];

  fillArray(arr, size);

  map(arr, size, multiplyByTwo);

  printArray(arr, size);

  delete[] arr;

  return 0;
}