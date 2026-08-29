#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    
    printf("数组遍历:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
        sum += arr[i];
    }
    printf("数组元素和: %d\n", sum);
    
    printf("\n二维数组:\n");
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n数组与指针:\n");
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        printf("*(p+%d) = %d\n", i, *(p+i));
    }
    
    printf("\n数组排序（冒泡排序）:\n");
    int unsorted[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (unsorted[j] > unsorted[j+1]) {
                int temp = unsorted[j];
                unsorted[j] = unsorted[j+1];
                unsorted[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", unsorted[i]);
    }
    printf("\n");
    
    return 0;
}