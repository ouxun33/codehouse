#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual void speak() {
        cout << "Animal speaks" << endl;
    }

    virtual void eat() {
        cout << name << " is eating" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void speak() override {
        cout << name << " says Woof!" << endl;
    }

    void eat() override {
        cout << name << " eats bones" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void speak() override {
        cout << name << " says Meow!" << endl;
    }

    void eat() override {
        cout << name << " eats fish" << endl;
    }
};

class Bird : public Animal {
public:
    Bird(string n) : Animal(n) {}

    void speak() override {
        cout << name << " says Chirp!" << endl;
    }

    void eat() override {
        cout << name << " eats seeds" << endl;
    }
};

void makeSound(Animal *animal) {
    animal->speak();
    animal->eat();
}

int main() {
    Animal *animals[3];
    animals[0] = new Dog("旺财");
    animals[1] = new Cat("咪咪");
    animals[2] = new Bird("小鸟");

    for (int i = 0; i < 3; i++) {
        makeSound(animals[i]);
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}