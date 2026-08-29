#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchFirst(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("输入要查找的数字: ");
    scanf("%d", &target);
    
    int linearResult = linearSearch(arr, n, target);
    printf("顺序查找: %d\n", linearResult);
    
    int binaryResult = binarySearch(arr, n, target);
    printf("二分查找: %d\n", binaryResult);
    
    int firstResult = binarySearchFirst(arr, n, target);
    printf("二分查找第一个: %d\n", firstResult);
    
    return 0;
}