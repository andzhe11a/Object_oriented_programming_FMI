#include <iostream>

struct ComplexNumber {
    double real;
    double imag;
};

ComplexNumber inputComplexNumber() {
    ComplexNumber num;
    std::cout << "Enter real part: ";
    std::cin >> num.real;
    std::cout << "Enter imaginary part: ";
    std::cin >> num.imag;
    return num;
}

void printComplexNumber(const ComplexNumber& num) {
    std::cout << num.real;
    if (num.imag >= 0) {
        std::cout << " + " << num.imag << "i";
    } else {
        std::cout << " - " << -num.imag << "i";
    }
    std::cout << std::endl;
}

ComplexNumber conjugate(const ComplexNumber& num) {
    return { num.real, -num.imag };
}

ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b) {
    return { a.real + b.real, a.imag + b.imag };
}

ComplexNumber subtract(const ComplexNumber& a, const ComplexNumber& b) {
    return { a.real - b.real, a.imag - b.imag };
}

ComplexNumber multiply(const ComplexNumber& a, const ComplexNumber& b) {
    return {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

ComplexNumber divide(const ComplexNumber& a, const ComplexNumber& b) {
    double denominator = b.real * b.real + b.imag * b.imag;

    return {
        (a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator
    };
}

bool areEqual(const ComplexNumber& a, const ComplexNumber& b) {
    return (a.real == b.real) && (a.imag == b.imag);
}

int main() {
    std::cout << "Enter the first complex number:" << std::endl;;
    ComplexNumber a = inputComplexNumber();
    std::cout << std::endl;

    std::cout << "Enter the second complex number:" << std::endl;;
    ComplexNumber b = inputComplexNumber();
    std::cout << std::endl;

    std::cout << "Complex numbers:" << std::endl;;
    printComplexNumber(a);
    printComplexNumber(b);
    std::cout << std::endl;

    std::cout << "Conjugate of the first number: ";
    printComplexNumber(conjugate(a));

    std::cout << "Conjugate of the second number: ";
    printComplexNumber(conjugate(b));
    std::cout << std::endl;

    std::cout << "Operations:" << std::endl;

    std::cout << "a + b = ";
    printComplexNumber(add(a, b));

    std::cout << "a - b = ";
    printComplexNumber(subtract(a, b));

    std::cout << "a * b = ";
    printComplexNumber(multiply(a, b));

    std::cout << "a / b = ";
    printComplexNumber(divide(a, b));
    std::cout << std::endl;

    std::cout << "Are the complex number equal: ";
    std::cout << (areEqual(a, b) ? "Equal" : "Not Equal") << std::endl;

    return 0;
}