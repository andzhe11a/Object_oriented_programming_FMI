#include <iostream>

enum class StatusCode {
  OK,
  Error
};

struct ParseResult {
  int num;
  StatusCode status;
};

ParseResult parse (const char* str){
  int result = 0;
  int i = 0;

  while (str[i] != '\0')
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return {0, StatusCode::Error};
    }
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return {result, StatusCode::OK};
}

int main () {
  char input[100];
  std::cout << "Enter a string: ";
  std::cin.getline(input, 100);

  ParseResult output = parse(input);

  if (output.status == StatusCode::OK)
  {
    std::cout << "{number: " << output.num << ", statusCode: OK}" << std::endl;
  } else
  {
    std::cout << "{number: _, statusCode: Error}" << std::endl;
  }

  return 0;
}