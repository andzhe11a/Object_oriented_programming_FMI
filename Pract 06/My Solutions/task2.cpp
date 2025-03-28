#include <iostream>

struct Interval
{
  int a, b;

  Interval() : a(0), b(0) {}

  Interval(int x, int y)
  {
    if (x <= y)
    {
      a = x;
      b = y;
    } else
    {
      a = 0;
      b = 0;
    }
  }

  int length() const
  {
    return b - a + 1;
  }

  bool IsInInterval(int num) const
  {
    return num >= a && num <= b;
  }

  bool isPrime(int num) const
  {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
    {
      if (num % i == 0) return false;
    }
    return true;
  }

  int countPrimes() const
  {
    int count = 0;
    for (int i = a; i <= b; i++)
    {
      if (isPrime(i)) count++;
    }
    return count;
  }

  bool isPalindrome(int num) const
  {
    int reversed = 0;
    int original = num;
    while (num > 0)
    {
      reversed = reversed * 10 + num % 10;
      num /= 10;
    }
    return original == reversed;
  }

  int countPalindromes() const
  {
    int count = 0;
    for (int i = a; i <= b; i++)
    {
      if (isPalindrome(i)) count++;
    }
    return count;
  }

  bool hasUniqueDigits(int num) const {
    bool digits[10] = {false};
    while (num > 0) {
      int digit = num % 10;
      if (digits[digit]) return false;
      digits[digit] = true;
      num /= 10;
    }
    return true;
  }

  int countUniqueDigitNumbers() const {
    int count = 0;
    for (int i = a; i <= b; i++) {
      if (hasUniqueDigits(i)) count++;
    }
    return count;
  }

  bool isPowerOfTwo(int num) const {
    return num > 0 && (num & (num - 1)) == 0;
  }

  bool isStartAndEndPowerOfTwo() const {
    return isPowerOfTwo(a) && isPowerOfTwo(b);
  }

  Interval intersect(const Interval& other) const {
    int newA = (a > other.a) ? a : other.a;
    int newB = (b < other.b) ? b : other.b;
    if (newA <= newB) {
      return Interval(newA, newB);
    }
    return Interval(0, 0);
  }

  bool isSubInterval(const Interval& other) const {
    return a <= other.a && b >= other.b;
  }
};

int main() {
  Interval t1(3, 10);
  Interval t2(4, 14);
  Interval t3;

  Interval result = t1.intersect(t2);

  std::cout << "Prime numbers in result: " << result.countPrimes() << std::endl;
  std::cout << "Palindromes in result: " << result.countPalindromes() << std::endl;
  std::cout << "Numbers with unique digits in result: " << result.countUniqueDigitNumbers() << std::endl;
  std::cout << "Start and end are power of two? " << (t1.isStartAndEndPowerOfTwo() ? "Yes" : "No") << std::endl;
  std::cout << "Is result sub-interval of t2? " << (t2.isSubInterval(result) ? "Yes" : "No") << std::endl;

  return 0;
}