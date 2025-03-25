#include <iostream>
#include <fstream>

void writeArrayToBinary(const char* filename, int* arr, int size) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    outFile.write(reinterpret_cast<char*>(arr), size * sizeof(int));
    outFile.close();
}

int* readArrayFromBinary(const char* filename, int& size) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return nullptr;
    }

    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    int* arr = new int[size];
    inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));
    inFile.close();

    return arr;
}

bool getNthNumFromBinary(const char* filename, int n, int& number) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return false;
    }

    int size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (n < 0 || n >= size)
    {
        std::cerr << "Invalid index!" << std::endl;
        return false;
    }

    inFile.seekg(sizeof(size) + n * sizeof(int), std::ios::beg);
    inFile.read(reinterpret_cast<char*>(&number), sizeof(int));
    inFile.close();

    return true;
}

int main() {
    char filename[100];

    std::cout << "Enter the name of the binary file: ";
    std::cin >> filename;

    //example array
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    writeArrayToBinary(filename, arr, size);

    int newSize;
    int* newArr = readArrayFromBinary(filename, newSize);

    if (newArr)
    {
        std::cout << "Numbers read from file: ";
        for (int i = 0; i < newSize; i++)
        {
            std::cout << newArr[i] << " ";
        }
        std::cout << std::endl;
        delete[] newArr;
    }

    int n, number;
    std::cout << "Enter the index of the number that is going to be extracted: ";
    std::cin >> n;

    if (getNthNumFromBinary(filename, n, number))
    {
        std::cout << "Number at index " << n << " is: " << number << std::endl;
    }

    return 0;
}
