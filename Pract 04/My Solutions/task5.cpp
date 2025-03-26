#include <iostream>
#include <fstream>

void decypherMessage(const char* rawMessageFileName, const char* keyFileName)
{
  std::ifstream keyFile(keyFileName, std::ios::binary);
  if (!keyFile.is_open())
  {
    std::cerr << "Could not open key file!" << std::endl;
    return;
  }

  char key;
  keyFile.read(reinterpret_cast<char*>(&key), sizeof(key));
  keyFile.close();

  std::ifstream messageFile(rawMessageFileName, std::ios::binary);
  if (!messageFile.is_open())
  {
    std::cerr << "Could not open message file!" << std::endl;
    return;
  }

  std::cout << "Decoded message: ";

  unsigned number;
  while (messageFile.read(reinterpret_cast<char*>(&number), sizeof(number)))
  {
    std::cout << (number + key) << " ";
  }

  std::cout << std::endl;
  messageFile.close();
}

int main() {
  char messageFile[50], keyFile[50];

  std::cout << "Enter the message file: ";
  std::cin >> messageFile;

  std::cout << "Enter key file name: ";
  std::cin >> keyFile;

  decypherMessage(messageFile, keyFile);

  return 0;
}