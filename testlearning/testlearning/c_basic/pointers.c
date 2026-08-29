#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void increment(int *p) {
    (*p)++;
}

int *getPointer() {
    static int num = 20;
    return &num;
}

int main() {
    int a = 10;
    int *p = &a;
    
    printf("指针基础:\n");
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    
    printf("\n指针运算:\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("ptr = %p, *ptr = %d\n", ptr, *ptr);
    ptr++;
    printf("ptr++ = %p, *ptr = %d\n", ptr, *ptr);
    ptr += 2;
    printf("ptr += 2 = %p, *ptr = %d\n", ptr, *ptr);
    
    printf("\n指针与函数（传址调用）:\n");
    int x = 5, y = 10;
    printf("交换前: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("交换后: x=%d, y=%d\n", x, y);
    
    printf("\n指针作为返回值:\n");
    int *result = getPointer();
    printf("*result = %d\n", *result);
    
    printf("\n多级指针:\n");
    int **pp = &p;
    printf("**pp = %d\n", **pp);
    
    return 0;
}