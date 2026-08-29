#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called" << endl;
    }

    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called" << endl;
    }

    Person(const Person &other) {
        name = other.name;
        age = other.age;
        cout << "Copy constructor called" << endl;
    }

    ~Person() {
        cout << "Destructor called for " << name << endl;
    }

    void setName(string n) { name = n; }
    string getName() { return name; }

    void setAge(int a) { age = a; }
    int getAge() { return age; }

    void introduce() {
        cout << "My name is " << name << ", I'm " << age << " years old." << endl;
    }
};

int main() {
    Person p1;
    p1.setName("张三");
    p1.setAge(20);
    p1.introduce();

    Person p2("李四", 25);
    p2.introduce();

    Person p3 = p2;
    p3.introduce();

    Person *p4 = new Person("王五", 30);
    p4->introduce();
    delete p4;

    return 0;
}