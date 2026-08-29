#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//#include <iomanip>

//class Vector {
//private:
//    std::vector<double> data;
//
//public:
//    // (1) n 的值自行定义：通过构造函数传入 n
//    explicit Vector(std::size_t n, double init = 0.0) : data(n, init) {}
//
//    std::size_t size() const { return data.size(); }
//
//    // 方便输入/访问
//    double& operator[](std::size_t i) { return data.at(i); }
//    const double& operator[](std::size_t i) const { return data.at(i); }
//
//#ifdef USE_MEMBER_OP
//    // (2) 成员函数重载实现内积
//    double operator*(const Vector& rhs) const {
//        if (size() != rhs.size()) {
//            throw std::invalid_argument("Dot product requires vectors of the same dimension.");
//        }
//        double sum = 0.0;
//        for (std::size_t i = 0; i < size(); ++i) {
//            sum += data[i] * rhs.data[i];
//        }
//        return sum;
//    }
//#else
//    // (2) 友元函数重载实现内积
//    friend double operator*(const Vector& lhs, const Vector& rhs) {
//        if (lhs.size() != rhs.size()) {
//            throw std::invalid_argument("Dot product requires vectors of the same dimension.");
//        }
//        double sum = 0.0;
//        for (std::size_t i = 0; i < lhs.size(); ++i) {
//            sum += lhs.data[i] * rhs.data[i];
//        }
//        return sum;
//    }
//#endif
//
//    // 辅助：输出向量
//    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
//        os << "(";
//        for (std::size_t i = 0; i < v.size(); ++i) {
//            os << v[i];
//            if (i + 1 != v.size()) os << ", ";
//        }
//        os << ")";
//        return os;
//    }
//};
//
//int main() {
//    // 自行定义 n
//    std::size_t n = 4;
//
//    Vector a(n), b(n);
//
//    // 示例赋值：a=(1,2,3,4), b=(10,20,30,40)
//    for (std::size_t i = 0; i < n; ++i) {
//        a[i] = static_cast<double>(i + 1);
//        b[i] = static_cast<double>(10 * (i + 1));
//    }
//
//    std::cout << "a = " << a << "\n";
//    std::cout << "b = " << b << "\n";
//
//    double dot = a * b;
//    std::cout << "a*b = " << std::fixed << std::setprecision(2) << dot << "\n";
//
//    return 0;
//}

//#include <iostream>
//#include <iomanip>
//
//class Circle {
//private:
//    double banjing; // 半径
//    static constexpr double PI = 3.14159265358979323846;
//
//public:
//    Circle(double r = 0.0) : banjing(r) {}
//
//    void setRadius(double r) { banjing = r; }
//    double getRadius() const { return banjing; }
//
//    // 面积
//    double area() const {
//        return PI * banjing * banjing;
//    }
//
//    // 周长
//    double zhouChang() const {
//        return 2.0 * PI * banjing;
//    }
//};
//
//class YuanZhu { // 圆柱类
//private:
//    Circle cir; // 圆（底面）
//    double gao; // 高
//
//public:
//    YuanZhu(double r = 0.0, double h = 0.0) : cir(r), gao(h) {}
//
//    void set(double r, double h) {
//        cir.setRadius(r);
//        gao = h;
//    }
//
//    // 体积
//    double tiJi() const {
//        return cir.area() * gao;
//    }
//
//    // 表面积 = 2*底面积 + 侧面积(周长*高)
//    double biaoMianJi() const {
//        return 2.0 * cir.area() + cir.zhouChang() * gao;
//    }
//};
//
//int main() {
//    double r, h;
//    std::cout << "请输入半径r和高h：";
//    std::cin >> r >> h;
//
//    YuanZhu yz(r, h);
//
//    std::cout << std::fixed << std::setprecision(2);
//    std::cout << "体积 = " << yz.tiJi() << std::endl;
//    std::cout << "表面积 = " << yz.biaoMianJi() << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <stdexcept>
//
//class Fraction {
//private:
//    long long num; // 分子
//    long long den; // 分母
//
//    static long long gcd(long long a, long long b) {
//        if (a < 0) a = -a;
//        if (b < 0) b = -b;
//        while (b != 0) {
//            long long t = a % b;
//            a = b;
//            b = t;
//        }
//        return a == 0 ? 1 : a;
//    }
//
//    void normalize() {
//        if (den == 0) throw std::invalid_argument("分母不能为0");
//        if (den < 0) { den = -den; num = -num; } // 分母保持为正
//
//        long long g = gcd(num, den);
//        num /= g;
//        den /= g;
//    }
//
//public:
//    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
//        normalize();
//    }
//
//    // 加法：成员函数运算符重载
//    Fraction operator+(const Fraction& rhs) const {
//        // a/b + c/d = (ad + bc) / bd
//        long long n = num * rhs.den + rhs.num * den;
//        long long d = den * rhs.den;
//        return Fraction(n, d); // 构造时会约分
//    }
//
//    // 比较大小：成员函数运算符重载
//    bool operator>(const Fraction& rhs) const {
//        // a/b > c/d  <=>  ad > cb （这里假设分母已规范为正）
//        return num * rhs.den > rhs.num * den;
//    }
//
//    void print() const {
//        std::cout << num << "/" << den;
//    }
//};
//
//int main() {
//    long long a, b, c, d;
//    std::cout << "请输入第一个分数的分子 分母(a b)：";
//    std::cin >> a >> b;
//    std::cout << "请输入第二个分数的分子 分母(c d)：";
//    std::cin >> c >> d;
//
//    try {
//        Fraction f1(a, b), f2(c, d);
//
//        Fraction sum = f1 + f2;
//
//        std::cout << "f1 = "; f1.print(); std::cout << "\n";
//        std::cout << "f2 = "; f2.print(); std::cout << "\n";
//        std::cout << "f1 + f2 = "; sum.print(); std::cout << "\n";
//
//        std::cout << "f1 > f2 ? " << (f1 > f2 ? "true" : "false") << "\n";
//    }
//    catch (const std::exception& e) {
//        std::cout << "错误: " << e.what() << "\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//// 函数模板：求数组最大值（传入数组首元素指针 + 元素个数）
//template <typename T>
//T arrayMax(const T* a, int n) {
//    T mx = a[0];
//    for (int i = 1; i < n; ++i) {
//        if (a[i] > mx) mx = a[i];
//    }
//    return mx;
//}
//
//int main() {
//    int ia[5] = { 10, 7, 14, 3, 25 };
//    double da[4] = { 10.2, 7.1, 14.5, 3.2 };
//    string sa[3] = { "上海", "北京", "沈阳" };
//
//    cout << "int数组最大值: " << arrayMax(ia, 5) << endl;
//    cout << "double数组最大值: " << arrayMax(da, 4) << endl;
//    cout << "string数组最大值: " << arrayMax(sa, 3) << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <iomanip>
//
//using namespace std;
//
//class Employee {
//protected:
//    string name;
//    int ID;
//
//public:
//    Employee(const string& n = "", int id = 0) : name(n), ID(id) {}
//    virtual ~Employee() = default;
//
//    // 为了统一输出，提供虚函数获取工资（基类默认0）
//    virtual double getSal() const { return 0.0; }
//
//    virtual void print() const {
//        cout << "name=" << name << ", ID=" << ID << ", sal=" << fixed << setprecision(2) << getSal() << endl;
//    }
//};
//
//class Manager : public Employee {
//private:
//    double sal; // 经理月工资
//
//public:
//    Manager(const string& n = "", int id = 0, double s = 0.0)
//        : Employee(n, id), sal(s) {
//    }
//
//    double getSal() const override { return sal; }
//
//    void print() const override {
//        cout << "Manager -> ";
//        Employee::print();
//    }
//};
//
//class HourlyWorker : public Employee {
//private:
//    double wage;   // 每小时工资
//    double hours;  // 月工作时数
//    double sal;    // 月工资总数
//
//public:
//    HourlyWorker(const string& n = "", int id = 0, double w = 0.0, double h = 0.0)
//        : Employee(n, id), wage(w), hours(h), sal(0.0) {
//        salary(); // 构造时计算一次
//    }
//
//    // (3) 求钟点工月工资总数 = 每小时工资 * 月工作时数
//    void salary() {
//        sal = wage * hours;
//    }
//
//    double getSal() const override { return sal; }
//
//    void print() const override {
//        cout << "HourlyWorker -> ";
//        Employee::print();
//    }
//};
//
//int main() {
//    // 示例：也可以改成从键盘输入
//    Manager m("Alice", 1001, 12000.0);
//    HourlyWorker h("Bob", 2002, 55.0, 160.0);
//
//    m.print();
//    h.print();
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//// 1. 基类：Person
//class Person {
//protected:
//    string name; // 姓名
//    int age;     // 年龄
//
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//};
//
//// 2. 派生类：Student
//class Student : public Person {
//protected:
//    string banji; // 班级
//    string xuehao; // 学号
//
//public:
//    Student(const string& n = "", int a = 0,
//        const string& bj = "", const string& xh = "")
//        : Person(n, a), banji(bj), xuehao(xh) {
//    }
//};
//
//// 3. 再派生：YStu（研究生）
//class YStu : public Student {
//private:
//    string tutorName; // 导师姓名
//
//public:
//    YStu(const string& n = "", int a = 0,
//        const string& bj = "", const string& xh = "",
//        const string& tn = "")
//        : Student(n, a, bj, xh), tutorName(tn) {
//    }
//
//    // 4. 输出研究生所有信息
//    void print() const {
//        cout << "姓名: " << name << "\n";
//        cout << "年龄: " << age << "\n";
//        cout << "班级: " << banji << "\n";
//        cout << "学号: " << xuehao << "\n";
//        cout << "导师姓名: " << tutorName << "\n";
//    }
//};
//
//int main() {
//    // 可改为从键盘输入，这里给一个示例
//    YStu ys("张三", 24, "研一1班", "20260001", "李老师");
//    ys.print();
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <memory>
//using namespace std;
//
//// 1. 抽象基类：Shape（图形）
//class Shape {
//public:
//    virtual ~Shape() = default;
//
//    // 纯虚函数：计算面积
//    virtual double area() const = 0;
//};
//
//// 2. Circle 继承 Shape
//class Circle : public Shape {
//private:
//    double r;
//    static constexpr double PI = 3.14159265358979323846;
//
//public:
//    explicit Circle(double radius = 0.0) : r(radius) {}
//
//    double area() const override {
//        return PI * r * r;
//    }
//};
//
//// 3. Rect 继承 Shape
//class Rect : public Shape {
//private:
//    double w; // 宽
//    double h; // 高
//
//public:
//    Rect(double width = 0.0, double height = 0.0) : w(width), h(height) {}
//
//    double area() const override {
//        return w * h;
//    }
//};
//
//int main() {
//    // 4. 多态：用基类指针/智能指针统一管理不同图形
//    vector<unique_ptr<Shape>> shapes;
//
//    // 示例：也可以改为从键盘输入
//    shapes.push_back(make_unique<Circle>(3.0)); // 半径3
//    shapes.push_back(make_unique<Rect>(4.0, 5.0)); // 4x5矩形
//
//    for (size_t i = 0; i < shapes.size(); ++i) {
//        cout << "第" << (i + 1) << "个图形面积 = " << shapes[i]->area() << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <memory>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//// 4. 定义教师抽象类
//class Teacher {
//protected:
//    string name;
//    int hours; // 月课时数
//
//public:
//    Teacher(const string& n, int h) : name(n), hours(h) {}
//    virtual ~Teacher() = default;
//
//    // 月工资 = 固定工资 + hours * 补贴单价
//    virtual double salary() const = 0;
//    virtual string title() const = 0;
//
//    void print() const {
//        cout << title() << "  姓名:" << name
//            << "  课时:" << hours
//            << "  月工资:" << fixed << setprecision(2) << salary()
//            << endl;
//    }
//};
//
//// 1. 教授
//class Professor : public Teacher {
//public:
//    Professor(const string& n, int h) : Teacher(n, h) {}
//    double salary() const override { return 5000.0 + hours * 50.0; }
//    string title() const override { return "教授"; }
//};
//
//// 2. 副教授
//class AssociateProfessor : public Teacher {
//public:
//    AssociateProfessor(const string& n, int h) : Teacher(n, h) {}
//    double salary() const override { return 3000.0 + hours * 30.0; }
//    string title() const override { return "副教授"; }
//};
//
//// 3. 讲师
//class Lecturer : public Teacher {
//public:
//    Lecturer(const string& n, int h) : Teacher(n, h) {}
//    double salary() const override { return 2000.0 + hours * 20.0; }
//    string title() const override { return "讲师"; }
//};
//
//int main() {
//    int n;
//    cout << "请输入教师人数n：";
//    cin >> n;
//
//    vector<unique_ptr<Teacher>> teachers;
//    teachers.reserve(n);
//
//    cout << "输入格式：职称编号 姓名 课时数\n";
//    cout << "职称编号：1=教授 2=副教授 3=讲师\n";
//
//    for (int i = 0; i < n; ++i) {
//        int type, h;
//        string nm;
//        cout << "第" << (i + 1) << "位：";
//        cin >> type >> nm >> h;
//
//        if (type == 1) teachers.push_back(make_unique<Professor>(nm, h));
//        else if (type == 2) teachers.push_back(make_unique<AssociateProfessor>(nm, h));
//        else if (type == 3) teachers.push_back(make_unique<Lecturer>(nm, h));
//        else {
//            cout << "职称编号输入错误，默认按讲师计算。\n";
//            teachers.push_back(make_unique<Lecturer>(nm, h));
//        }
//    }
//
//    cout << "\n--- 工资表 ---\n";
//    double total = 0.0;
//    for (const auto& t : teachers) {
//        t->print();
//        total += t->salary();
//    }
//    cout << "总工资 = " << fixed << setprecision(2) << total << endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

// (2) 共同特征：名字、住址
class Employee {
protected:
    string name;
    string address;

public:
    Employee(const string& n, const string& addr) : name(n), address(addr) {}
    virtual ~Employee() = default;

    // (3) 工资计算不同：用纯虚函数体现多态
    virtual double salary() const = 0;
    virtual string type() const = 0;

    // (4) 输出名字、住址、工资等信息
    virtual void print() const {
        cout << type()
            << "  姓名:" << name
            << "  住址:" << address
            << "  工资:" << fixed << setprecision(2) << salary()
            << endl;
    }
};

// (1)(3) 固定工资工人：每月工资不变
class FixedWorker : public Employee {
private:
    double monthlyPay;

public:
    FixedWorker(const string& n, const string& addr, double pay)
        : Employee(n, addr), monthlyPay(pay) {
    }

    double salary() const override { return monthlyPay; }
    string type() const override { return "固定工资工人"; }
};

// (1)(3) 计件工人：按产品数量计算
class PieceWorker : public Employee {
private:
    int pieces;        // 产品数量
    double payPerPiece; // 每件单价

public:
    PieceWorker(const string& n, const string& addr, int p, double price)
        : Employee(n, addr), pieces(p), payPerPiece(price) {
    }

    double salary() const override { return pieces * payPerPiece; }
    string type() const override { return "计件工人"; }
};

// (1)(3) 计时工人：按工作时长计算
class HourWorker : public Employee {
private:
    double hours;     // 工作时长(小时)
    double payPerHour; // 每小时工资

public:
    HourWorker(const string& n, const string& addr, double h, double rate)
        : Employee(n, addr), hours(h), payPerHour(rate) {
    }

    double salary() const override { return hours * payPerHour; }
    string type() const override { return "计时工人"; }
};

int main() {
    // (4)(5) 在 main 中创建不同员工，用基类指针容器体现多态
    vector<unique_ptr<Employee>> emps;

    emps.push_back(make_unique<FixedWorker>("张三", "上海市浦东新区", 4500.0));
    emps.push_back(make_unique<PieceWorker>("李四", "北京市海淀区", 320, 12.5));
    emps.push_back(make_unique<HourWorker>("王五", "沈阳市和平区", 160.0, 35.0));

    cout << "--- 员工信息 ---\n";
    for (const auto& e : emps) {
        e->print(); // 多态调用
    }

    return 0;
}