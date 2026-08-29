#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, typename U>
T max(T a, U b) {
    return (a > b) ? a : b;
}

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T item) {
        elements.push_back(item);
    }

    T pop() {
        T item = elements.back();
        elements.pop_back();
        return item;
    }

    bool isEmpty() {
        return elements.empty();
    }

    int size() {
        return elements.size();
    }
};

template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() { return first; }
    T getSecond() { return second; }

    void swap() {
        T temp = first;
        first = second;
        second = temp;
    }
};

int main() {
    cout << "Function Templates:" << endl;
    cout << "add(3, 5) = " << add(3, 5) << endl;
    cout << "add(3.14, 2.71) = " << add(3.14, 2.71) << endl;
    cout << "max(10, 20) = " << max(10, 20) << endl;
    cout << "max(10, 25.5) = " << max(10, 25.5) << endl;

    cout << "\nClass Templates - Stack:" << endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    cout << "Stack size: " << intStack.size() << endl;
    cout << "Pop: " << intStack.pop() << endl;
    cout << "Pop: " << intStack.pop() << endl;
    cout << "Stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Pop: " << stringStack.pop() << endl;

    cout << "\nClass Templates - Pair:" << endl;
    Pair<int> p1(10, 20);
    cout << "Pair: (" << p1.getFirst() << ", " << p1.getSecond() << ")" << endl;
    p1.swap();
    cout << "After swap: (" << p1.getFirst() << ", " << p1.getSecond() << ")" << endl;

    return 0;
}