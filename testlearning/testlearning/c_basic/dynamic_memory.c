#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("输入数组大小: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    printf("输入%d个整数:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("数组内容:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\n重新分配内存（扩大到%d）:\n", n * 2);
    arr = (int*)realloc(arr, n * 2 * sizeof(int));
    if (arr == NULL) {
        printf("内存重新分配失败\n");
        return 1;
    }
    
    for (int i = n; i < n * 2; i++) {
        arr[i] = i + 1;
    }
    
    printf("扩展后数组:\n");
    for (int i = 0; i < n * 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    printf("\ncalloc示例:\n");
    int *arr2 = (int*)calloc(5, sizeof(int));
    printf("calloc初始化为0的数组: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    free(arr2);
    
    return 0;
}