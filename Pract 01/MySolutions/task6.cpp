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

void filter(const int* arr, int size, int*& result, int& resultSize, bool (*pred)(int)) {
  resultSize = 0;

  for (int i = 0; i < size; i++) {
    if (pred(arr[i])) {
      resultSize++;
    }
  }

  result = new int[resultSize];

  int index = 0;
  for (int i = 0; i < size; i++) {
    if (pred(arr[i])) {
      result[index++] = arr[i];
    }
  }
}

int main() {
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  int* arr = new int[size];
  fillArray(arr, size);

  int* result = nullptr;
  int resultSize = 0;

  filter(arr, size, result, resultSize, pred);
  printArray(result, resultSize);

  delete[] arr;
  delete[] result;

  return 0;
}