#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

void testVector() {
    cout << "=== Vector ===" << endl;
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    sort(v.begin(), v.end());

    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    v.insert(v.begin() + 2, 25);
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    v.erase(v.begin() + 1);
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

void testList() {
    cout << "\n=== List ===" << endl;
    list<int> l;

    l.push_back(10);
    l.push_front(5);
    l.push_back(20);
    l.push_front(1);

    for (int num : l) {
        cout << num << " ";
    }
    cout << endl;

    l.sort();
    for (int num : l) {
        cout << num << " ";
    }
    cout << endl;
}

void testMap() {
    cout << "\n=== Map ===" << endl;
    map<string, int> m;

    m["apple"] = 10;
    m["banana"] = 20;
    m["orange"] = 15;
    m["grape"] = 25;

    for (auto pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "apple: " << m["apple"] << endl;
    cout << "Contains orange? " << (m.find("orange") != m.end() ? "Yes" : "No") << endl;
}

void testSet() {
    cout << "\n=== Set ===" << endl;
    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(20);

    cout << "Size: " << s.size() << endl;
    for (int num : s) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Contains 20? " << (s.count(20) > 0 ? "Yes" : "No") << endl;
    s.erase(20);
    cout << "Contains 20? " << (s.count(20) > 0 ? "Yes" : "No") << endl;
}

void testAlgorithms() {
    cout << "\n=== Algorithms ===" << endl;
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    cout << "Original: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    int count5 = count(v.begin(), v.end(), 5);
    cout << "Count of 5: " << count5 << endl;

    auto it = find(v.begin(), v.end(), 9);
    if (it != v.end()) {
        cout << "Found 9 at index: " << distance(v.begin(), it) << endl;
    }

    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int num : v) cout << num << " ";
    cout << endl;
}

int main() {
    testVector();
    testList();
    testMap();
    testSet();
    testAlgorithms();

    return 0;
}