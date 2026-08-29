#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int age;
    float score;
};

void printStudent(struct Student s) {
    printf("姓名: %s, 年龄: %d, 分数: %.2f\n", s.name, s.age, s.score);
}

void updateStudent(struct Student *s) {
    s->score += 5;
}

int main() {
    struct Student s1;
    strcpy(s1.name, "张三");
    s1.age = 20;
    s1.score = 90.5;
    
    struct Student s2 = {"李四", 19, 85.0};
    
    printf("结构体变量:\n");
    printStudent(s1);
    printStudent(s2);
    
    printf("\n结构体指针:\n");
    struct Student *p = &s1;
    printf("姓名: %s, 年龄: %d\n", p->name, p->age);
    
    printf("\n修改结构体:\n");
    printf("修改前分数: %.2f\n", s1.score);
    updateStudent(&s1);
    printf("修改后分数: %.2f\n", s1.score);
    
    printf("\n结构体数组:\n");
    struct Student class[3] = {
        {"王五", 21, 92.5},
        {"赵六", 18, 88.0},
        {"钱七", 20, 95.0}
    };
    for (int i = 0; i < 3; i++) {
        printStudent(class[i]);
    }
    
    return 0;
}