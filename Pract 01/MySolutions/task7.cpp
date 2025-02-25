#include <iostream>

void fillArray(int* arr, int size) {
  std::cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
}

void printArray(int* arr, int size) {
  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    if (i < size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

bool pred(int a) {
  return a % 2 == 0;
}

void partition(int* arr, int size, bool(*pred)(int))
{
  int index = 0;

  for (int i = 0; i < size; i++)
  {
    if (pred(arr[i]))
    {
      std::swap(arr[i], arr[index]);
      index++;
    }
  }
}

int main() {
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  int* arr = new int[size];
  fillArray(arr, size);

  partition(arr, size, pred);
  printArray(arr, size);

  delete[] arr;

  return 0;
}
