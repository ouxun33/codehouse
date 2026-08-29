# C++入门指南

## 一、C++与C的关系

### 1.1 基本关系

- C++是C语言的超集，大部分C代码可以直接在C++中运行
- C++在C的基础上添加了面向对象编程、泛型编程等特性
- C++保留了C的所有功能：指针、数组、结构体、文件操作等

### 1.2 主要区别

| 特性 | C语言 | C++ |
|------|-------|-----|
| 编程范式 | 面向过程 | 面向对象+面向过程 |
| 函数重载 | 不支持 | 支持 |
| 引用 | 无 | 有 |
| 类 | 无 | 有 |
| 继承 | 无 | 有 |
| 多态 | 无 | 有 |
| 模板 | 无 | 有 |
| 异常 | 无 | 有 |
| 命名空间 | 无 | 有 |
| STL | 无 | 有 |

## 二、C++基础语法

### 2.1 头文件

```cpp
#include <iostream>    // 输入输出流
#include <string>      // 字符串
#include <vector>      // 动态数组
#include <algorithm>   // 算法
using namespace std;   // 使用标准命名空间
```

### 2.2 引用

引用是变量的别名，必须初始化：

```cpp
int a = 10;
int &b = a;   // b是a的引用
b = 20;       // 修改b，a也会被修改
```

### 2.3 函数重载

函数名相同，但参数列表不同：

```cpp
int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
```

### 2.4 命名空间

```cpp
namespace MySpace {
    int x = 10;
    void func() { cout << "Hello" << endl; }
}

// 使用
using namespace MySpace;
cout << x << endl;
func();
```

## 三、面向对象编程

### 3.1 类的定义

```cpp
class Person {
private:
    string name;
    int age;
    
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
    void introduce();
};

void Person::introduce() {
    cout << "My name is " << name << ", I'm " << age << " years old." << endl;
}
```

### 3.2 对象的创建和使用

```cpp
int main() {
    Person p1;
    p1.setName("张三");
    p1.setAge(20);
    p1.introduce();
    
    Person *p2 = new Person();
    p2->setName("李四");
    p2->setAge(25);
    p2->introduce();
    delete p2;
    
    return 0;
}
```

### 3.3 构造函数

构造函数在对象创建时自动调用：

```cpp
class Person {
private:
    string name;
    int age;
    
public:
    Person() {           // 默认构造函数
        name = "Unknown";
        age = 0;
    }
    
    Person(string n, int a) {  // 带参数的构造函数
        name = n;
        age = a;
    }
    
    Person(const Person &other) {  // 拷贝构造函数
        name = other.name;
        age = other.age;
    }
};
```

### 3.4 析构函数

析构函数在对象销毁时自动调用：

```cpp
class Person {
public:
    ~Person() {
        cout << "Person destroyed" << endl;
    }
};
```

### 3.5 封装

封装是将数据和操作数据的方法捆绑在一起，隐藏内部实现：

- `private`: 只能在类内部访问
- `protected`: 可以在类内部和派生类中访问
- `public`: 可以在任何地方访问

## 四、继承

### 4.1 继承的概念

继承是从现有类派生出新类，新类继承父类的属性和方法：

```cpp
class Student : public Person {
private:
    string school;
    float score;
    
public:
    Student(string n, int a, string s, float sc) 
        : Person(n, a) {
        school = s;
        score = sc;
    }
    
    void study() {
        cout << name << " is studying at " << school << endl;
    }
};
```

### 4.2 继承方式

| 继承方式 | 父类public | 父类protected | 父类private |
|----------|-----------|--------------|-------------|
| public | public | protected | 不可访问 |
| protected | protected | protected | 不可访问 |
| private | private | private | 不可访问 |

### 4.3 多重继承

```cpp
class A { ... };
class B { ... };
class C : public A, public B { ... };
```

## 五、多态

### 5.1 虚函数

虚函数允许在派生类中重写父类的方法：

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};
```

### 5.2 多态的使用

```cpp
int main() {
    Animal *animal1 = new Dog();
    Animal *animal2 = new Cat();
    
    animal1->speak();  // 输出 "Woof!"
    animal2->speak();  // 输出 "Meow!"
    
    delete animal1;
    delete animal2;
    
    return 0;
}
```

### 5.3 纯虚函数和抽象类

纯虚函数没有实现，包含纯虚函数的类是抽象类，不能实例化：

```cpp
class Shape {
public:
    virtual double area() = 0;  // 纯虚函数
    virtual double perimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    double area() override { return 3.14159 * radius * radius; }
    double perimeter() override { return 2 * 3.14159 * radius; }
};
```

## 六、模板

### 6.1 函数模板

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 5) << endl;      // int
    cout << add(3.14, 2.71) << endl; // double
    return 0;
}
```

### 6.2 类模板

```cpp
template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(T item) { elements.push_back(item); }
    T pop() {
        T item = elements.back();
        elements.pop_back();
        return item;
    }
    bool isEmpty() { return elements.empty(); }
};
```

## 七、STL标准库

### 7.1 容器

| 容器 | 说明 |
|------|------|
| vector | 动态数组 |
| list | 双向链表 |
| deque | 双端队列 |
| set | 有序集合 |
| map | 有序键值对 |
| unordered_set | 无序集合 |
| unordered_map | 无序键值对 |

### 7.2 vector示例

```cpp
#include <vector>
#include <algorithm>

int main() {
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    cout << v.size() << endl;      // 3
    cout << v[1] << endl;          // 20
    
    sort(v.begin(), v.end());      // 排序
    
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    for (int num : v) {            // 范围for循环
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

### 7.3 map示例

```cpp
#include <map>

int main() {
    map<string, int> m;
    
    m["apple"] = 10;
    m["banana"] = 20;
    m["orange"] = 15;
    
    cout << m["apple"] << endl;    // 10
    
    for (auto pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    return 0;
}
```

## 八、智能指针

### 8.1 为什么需要智能指针

普通指针需要手动释放内存，容易造成内存泄漏：

```cpp
int *p = new int(10);
// ...忘记delete p;
```

### 8.2 unique_ptr

独占所有权的智能指针：

```cpp
#include <memory>

int main() {
    unique_ptr<int> p1(new int(10));
    cout << *p1 << endl;
    
    // unique_ptr<int> p2 = p1;  // 错误，不能拷贝
    
    return 0;  // 自动释放内存
}
```

### 8.3 shared_ptr

共享所有权的智能指针，使用引用计数：

```cpp
int main() {
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2 = p1;  // 可以共享
    
    cout << p1.use_count() << endl;  // 2
    
    return 0;
}
```

## 九、异常处理

### 9.1 try-catch

```cpp
int main() {
    try {
        int a = 10;
        int b = 0;
        
        if (b == 0) {
            throw "Division by zero";
        }
        
        cout << a / b << endl;
    }
    catch (const char *msg) {
        cout << "Error: " << msg << endl;
    }
    catch (...) {
        cout << "Unknown error" << endl;
    }
    
    return 0;
}
```

### 9.2 自定义异常

```cpp
class MyException : public exception {
public:
    const char* what() const throw() {
        return "My custom exception";
    }
};

void func() {
    throw MyException();
}
```

## 十、C++学习建议

1. **先巩固C语言基础**: C++是C的扩展，C语言基础扎实才能更好地学习C++
2. **理解面向对象**: 重点掌握封装、继承、多态三个核心概念
3. **多写代码**: 通过实践理解概念
4. **学习STL**: STL是C++的精华，掌握常用容器和算法
5. **阅读优秀代码**: 学习别人的编程风格和设计模式
6. **练习项目**: 从简单的控制台程序开始，逐步做复杂项目

## 十一、C++与C的关键区别总结

1. **面向对象**: C++支持类、继承、多态
2. **类型安全**: C++有更强的类型检查
3. **引用**: C++引入了引用的概念
4. **异常处理**: C++有try-catch机制
5. **模板**: C++支持泛型编程
6. **内存管理**: C++有智能指针
7. **标准库**: C++有丰富的STL
8. **函数重载**: C++支持函数重载

## 十二、推荐学习路径

1. C语言基础复习 → 2. C++基础语法 → 3. 类和对象 → 4. 继承 → 5. 多态 → 6. 模板 → 7. STL → 8. 智能指针 → 9. 异常处理 → 10. 设计模式