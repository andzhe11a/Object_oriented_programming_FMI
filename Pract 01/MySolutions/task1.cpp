#include <iostream>

int strLength(const char* str) {
  int length = 0;
  while(str[length] != '\0') {
    length++;
  }
  return length;
}

char* getDigits(const char* str) {
  int len = strLength(str);

  char* result = new char[len + 1];
  int index = 0;

  for(int i = 0; i < len; i++) {
    if(str[i] >= '0' && str[i] <= '9') {
      result[index++] = str[i];
    }
  }

  result[index] = '\0';
  return result;
}

int main() {
  char input[100];
  std::cout << "Enter a string: " << std::endl;
  std::cin.getline(input, 100);

  char* output = getDigits(input);

  std::cout << "Digits extracted from the string: " << output << std::endl;

  delete[] output;

  return 0;
}