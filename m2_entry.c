#define _CRT_SECURE_NO_WARNINGS
#include "s_m2.h"

void m2_run() 
{
    int choice;
    do {
        table();
        scanf("%d", &choice);
        switch (choice) {
        case 1: into(); break;
        case 2: alter(); break;
        case 3: delete_goods(); break;
        case 4: chack(); break;
        case 5: chack_num(); break;
        case 0: printf("退出后端系统\n"); break;
        default: printf("输入错误，请重试\n");
        }
    } while (choice != 0);
}