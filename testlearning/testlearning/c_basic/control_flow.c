#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int score;
    
    printf("输入分数: ");
    scanf("%d", &score);
    
    if (score >= 90) {
        printf("优秀\n");
    } else if (score >= 80) {
        printf("良好\n");
    } else if (score >= 60) {
        printf("及格\n");
    } else {
        printf("不及格\n");
    }
    
    printf("\nswitch示例:\n");
    printf("输入1-7表示星期: ");
    int day;
    scanf("%d", &day);
    switch (day) {
        case 1: printf("星期一\n"); break;
        case 2: printf("星期二\n"); break;
        case 3: printf("星期三\n"); break;
        case 4: printf("星期四\n"); break;
        case 5: printf("星期五\n"); break;
        case 6: printf("星期六\n"); break;
        case 7: printf("星期日\n"); break;
        default: printf("无效输入\n");
    }
    
    printf("\nfor循环打印1-10:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\nwhile循环求1-100和:\n");
    int sum = 0, j = 1;
    while (j <= 100) {
        sum += j;
        j++;
    }
    printf("sum = %d\n", sum);
    
    printf("\ndo-while循环:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");
    
    return 0;
}