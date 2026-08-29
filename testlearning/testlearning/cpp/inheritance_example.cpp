#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "My name is " << name << ", I'm " << age << " years old." << endl;
    }
};

class Student : public Person {
private:
    string school;
    float score;

public:
    Student(string n, int a, string s, float sc) 
        : Person(n, a), school(s), score(sc) {}

    void study() {
        cout << name << " is studying at " << school << ", score: " << score << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
    int salary;

public:
    Teacher(string n, int a, string sub, int sal) 
        : Person(n, a), subject(sub), salary(sal) {}

    void teach() {
        cout << name << " teaches " << subject << ", salary: " << salary << endl;
    }
};

int main() {
    Student s("张三", 20, "北京大学", 95.5);
    s.introduce();
    s.study();

    Teacher t("李四", 40, "Computer Science", 15000);
    t.introduce();
    t.teach();

    return 0;
}