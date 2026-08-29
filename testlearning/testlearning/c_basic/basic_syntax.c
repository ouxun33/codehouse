#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 10, b = 5;
    float c = 3.14;
    char ch = 'A';
    
    printf("基本数据类型:\n");
    printf("int: %d\n", a);
    printf("float: %.2f\n", c);
    printf("char: %c\n", ch);
    
    printf("\n算术运算:\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d * %d = %d\n", a, b, a * b);
    
    printf("\n关系运算:\n");
    printf("%d > %d: %d\n", a, b, a > b);
    printf("%d == %d: %d\n", a, b, a == b);
    
    printf("\n逻辑运算:\n");
    printf("%d && %d: %d\n", 1, 0, 1 && 0);
    printf("%d || %d: %d\n", 1, 0, 1 || 0);
    
    printf("\n位运算:\n");
    printf("%d & %d = %d\n", a, b, a & b);
    printf("%d | %d = %d\n", a, b, a | b);
    
    printf("\n自增自减:\n");
    printf("a++ = %d, a = %d\n", a++, a);
    printf("++a = %d, a = %d\n", ++a, a);
    
    return 0;
}