#include <iostream>

bool isLetterOrDigit(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z') ||
           (symbol >= 'a' && symbol <= 'z') ||
           (symbol >= '0' && symbol <= '9');
}

int countWords(const char* str)
{
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isLetterOrDigit(str[i]))
        {
            if (!inWord)
            {
                count++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }
    return count;
}

int main() {
  char input[100];
  std::cout << "Enter a string: " << std::endl;
  std::cin.getline(input, 100);

  std::cout << "Number of words in the string: " << countWords(input) << std::endl;

  return 0;
}