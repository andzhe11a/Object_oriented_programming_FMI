#include <iostream>

enum Subject
{
  Math,
  English,
  Science,
  Physics,
  Art,
  Music,
  Geography
};

class Teacher
{
private:
  char name[26];
  int age;
  Subject subject;
  double salary;

public:
  Teacher() : age(18), salary(500.0), subject(Subject::Math)
  {
    name[0] = '\0';
  }

  Teacher(const char* name, int age, Subject subject, double salary)
  {
    setName(name);
    setAge(age);
    setSubject(subject);
    setSalary(salary);
  }

  const char* getName() const
  {
    return name;
  }

  void setName(const char* name)
  {
    int i = 0;
    while (name[i] != '\0' && i < 26)
    {
      this->name[i] = name[i];
      i++;
    }
    this->name[i] = '\0';
  }

  int getAge() const
  {
    return age;
  }

  void setAge(int age)
  {
    if (age >= 18 && age <= 70)
    {
      this->age = age;
    } else
    {
      std::cerr << "Age must be between 18 and 70!" << std::endl;
    }
  }

  Subject getSubject() const
  {
    return subject;
  }

  void setSubject(Subject subject)
  {
    this->subject = subject;
  }

  double getSalary() const
  {
    return salary;
  }

  void setSalary(double salary)
  {
    if (salary >= 500.0)
    {
      this->salary = salary;
    } else
    {
      std::cerr << "Salary must be greater ot equal to 500!" << std::endl;
    }
  }

  void printInfo() const
  {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Subject: " << subjectToString() << std::endl;
    std::cout << "Salary: " << salary << " BGN" << std::endl;
  }

private:
  const char* subjectToString() const
  {
    switch (subject)
    {
    case Subject::Math: return "Math";
    case Subject::English: return "English";
    case Subject::Science: return "Science";
    case Subject::Physics: return "Physics";
    case Subject::Art: return "Art";
    case Subject::Music: return "Music";
    case Subject::Geography: return "Geography";
    default: return "Unknown";
    }
  }
};

int main() {
  Teacher teacher1 ("Maria Petrova", 56, Subject::Math, 1600.0);
  teacher1.printInfo();
  std::cout << std::endl;

  Teacher teacher2;
  teacher2.setName("Simeon Georgiev");
  teacher2.setAge(44);
  teacher2.setSubject(Subject::Physics);
  teacher2.setSalary(2900.0);
  teacher2.printInfo();
  return 0;
}