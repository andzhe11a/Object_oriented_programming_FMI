#include <iostream>

int* fillArray(const int size) {
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  return arr;
}

void printArray(const int* arr, const int size) {
  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    if (i < size - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

int countDivisible(const int* arr, const int size, int K) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % K == 0) {
      count++;
    }
  }
  return count;
}

int* filterDivisible(const int* arr1, const int size1, const int* arr2, int size2, int K, int& resultSize) {
  resultSize = countDivisible(arr1, size1, K) + countDivisible(arr2, size2, K);
  int* result = new int[resultSize];

  int index = 0;
  for (int i = 0; i < size1; i++) {
    if (arr1[i] % K == 0) {
      result[index++] = arr1[i];
    }
  }
  for (int i = 0; i < size2; i++) {
    if (arr2[i] % K == 0) {
      result[index++] = arr2[i];
    }
  }

  return result;
}

int main() {
  int k = 0;

  std::cout << "Enter the divisor: ";
  std::cin >> k;

  int size1;
  std::cout << "Enter the size of the first array: ";
  std::cin >> size1;
  std::cout << "Enter " << size1 << " elements for the first array: ";
  const int* arr1 = fillArray(size1);

  int size2;
  std::cout << "Enter the size of the second array: ";
  std::cin >> size2;
  std::cout << "Enter " << size2 << " elements for the second array: ";
  const int* arr2 = fillArray(size2);

  int resultSize;
  const int* result = filterDivisible(arr1, size1, arr2, size2, k, resultSize);

  std::cout << "Filtered array: ";
  printArray(result, resultSize);

  delete[] arr1;
  delete[] arr2;
  delete[] result;

  return 0;
}
