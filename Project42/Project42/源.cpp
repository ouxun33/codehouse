//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//template <typename T>
//void printArray(const T arr[], int n) {
//    for (int i = 0; i < n; ++i) {
//        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
//    }
//}
//
//
//template <typename T>
//void bubbleSort(T arr[], int n) {
//    for (int i = 0; i < n - 1; ++i) {
//        bool swapped = false; 
//        for (int j = 0; j < n - 1 - i; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                T tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//                swapped = true;
//            }
//        }
//        if (!swapped) break;
//    }
//}
//
//int main() {
//    int intArray[] = { 5, 2, 9, 1, 3 };
//    int n1 = sizeof(intArray) / sizeof(intArray[0]);
//
//    double doubleArray[] = { 3.14, 2.71, 1.41, 0.577 };
//    int n2 = sizeof(doubleArray) / sizeof(doubleArray[0]);
//
//    bubbleSort(intArray, n1);
//    printArray(intArray, n1);
//
//    bubbleSort(doubleArray, n2);
//    printArray(doubleArray, n2);
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//template <class T>
//class Node {
//private:
//    T data;            
//    Node<T>* next;      
//
//public:
//
//    Node(const T& data, Node<T>* next = 0) : data(data), next(next) {}
//
//
//    void insertAfter(Node<T>* p) {
//        if (!p) return;
//        p->next = next;
//        next = p;
//    }
//
//
//    Node<T>* deleteAfter() {
//        Node<T>* deleted = next;
//        if (next) {
//            next = next->next;
//        }
//        return deleted;
//    }
//
//
//    Node<T>* nextNode() {
//        return next;
//    }
//
//
//    const Node<T>* nextNode() const {
//        return next;
//    }
//
// 
//    T getData() const { return data; }
//};
//
//int main() {
//
//    cout << "请输入5个整数：" << endl;
//
//    int x;
//
//    Node<int>* head = new Node<int>(0, 0);
//    Node<int>* tail = head;
//
//    for (int i = 0; i < 5; ++i) {
//        cin >> x;
//        Node<int>* p = new Node<int>(x, 0);
//        tail->insertAfter(p);
//        tail = p;
//    }
//
//
//    cout << "链表内容为：" << endl;
//    for (Node<int>* p = head->nextNode(); p != 0; p = p->nextNode()) {
//        cout << p->getData() << (p->nextNode() ? " " : "\n");
//    }
//
//
//    int target;
//    cout << "请输入待查找并删除的整数：" << endl;
//    cin >> target;
//
//    Node<int>* prev = head;
//    while (prev->nextNode() != 0) {
//        if (prev->nextNode()->getData() == target) {
//            Node<int>* del = prev->deleteAfter();
//            delete del; 
//        }
//        else {
//            prev = prev->nextNode();
//        }
//    }
//
//
//    cout << "删除后的链表为：" << endl;
//    if (head->nextNode() == 0) {
//        cout << "(空链表)" << endl;
//    }
//    else {
//        for (Node<int>* p = head->nextNode(); p != 0; p = p->nextNode()) {
//            cout << p->getData() << (p->nextNode() ? " " : "\n");
//        }
//    }
//
//
//    while (head != 0) {
//        Node<int>* next = head->nextNode();
//        delete head;
//        head = next;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Pet {
//private:
//    string name;
//    string kind;
//    int age;
//
//public:
//    Pet(string name, int age, string kind) : name(name), kind(kind), age(age) {}
//
//    virtual void bark() {  // 作为基类接口，允许派生类重写
//        cout << name << " is barking." << endl;
//    }
//
//    void eat(string food) {
//        cout << name << " eats " << food << "." << endl;
//    }
//
//    void sleep() {
//        cout << name << " is sleeping." << endl;
//    }
//
//
//    virtual ~Pet() = default;
//};
//
//class Dog : public Pet {
//public:
//    Dog(string name, int age, string kind) : Pet(name, age, kind) {}
//
//    void bark() override {
//        cout << "Woof! Woof!" << endl;
//    }
//};
//
//class Cat : public Pet {
//public:
//    Cat(string name, int age, string kind) : Pet(name, age, kind) {}
//
//    void bark() override {
//        cout << "Meow~ Meow~" << endl;
//    }
//};
//
//int main() {
//    Dog dog("Buddy", 3, "Golden Retriever");
//    Cat cat("Mimi", 2, "British Shorthair");
//
//    dog.eat("bone");
//    dog.bark();
//    dog.sleep();
//
//    cat.eat("fish");
//    cat.bark();
//    cat.sleep();
//
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string kind;
    int age;

public:
    Pet(const string& name, int age, const string& kind)
        : name(name), kind(kind), age(age) {
    }

    virtual void bark() {  
        cout << name << " is barking." << endl;
    }

    void eat(const string& food) {
        cout << name << " eats " << food << "." << endl;
    }

    void sleep() {
        cout << name << " is sleeping." << endl;
    }

    const string& getName() const { return name; }

    virtual ~Pet() = default; 
};

class Dog : public Pet {
public:
    Dog(const string& name, int age, const string& kind)
        : Pet(name, age, kind) {
    }

    void bark() override {
        cout << getName() << ": Woof! Woof!" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name, int age, const string& kind)
        : Pet(name, age, kind) {
    }

    void bark() override {
        cout << getName() << ": Meow~ Meow~" << endl;
    }
};


void feedWhenBark(Pet* p) {
    if (!p) return;


    p->bark();


    if (dynamic_cast<Dog*>(p)) {
        p->eat("bone");
    }
    else if (dynamic_cast<Cat*>(p)) {
        p->eat("fish");
    }
    else {
        p->eat("food");
    }
}

int main() {

    Pet* pets[4];
    pets[0] = new Dog("Buddy", 3, "Golden Retriever");
    pets[1] = new Cat("Mimi", 2, "British Shorthair");
    pets[2] = new Dog("Lucky", 1, "Husky");
    pets[3] = new Cat("Coco", 4, "Ragdoll");


    for (int i = 0; i < 4; ++i) {
        feedWhenBark(pets[i]);
        cout << "----" << endl;
    }

    //释放内存
    for (int i = 0; i < 4; ++i) {
        delete pets[i];
        pets[i] = nullptr;
    }

    return 0;
}