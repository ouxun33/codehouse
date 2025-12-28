#define _CRT_SECURE_NO_WARNINGS
#include "s_m1.h"

void m1_run() 
{
    int choice;
    show_goods();  // 启动时展示已有商品
    do {
        menu_m1();
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            add_goods();//增添商品
            break;
        case 2: 
            show_goods();//展示商品
            break;
        case 3:
            addto(); //购物
            break;
        case 4: 
            checkout(); //结算
            break;
        case 0: 
            printf("退出前端系统\n"); 
            break;
        default: printf("无效选择，请重试\n");
        }
    } while (choice != 0);
}