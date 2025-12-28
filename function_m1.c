#define _CRT_SECURE_NO_WARNINGS
#include "s_m1.h"

//表示商品的结构体数组
Goods a1[MAX_GOODS_M1] =
{
    { 1, "面包",     3.5f, 155 },
    { 2, "牛奶",     7.0f, 48  },
    { 3, "方便面",   5.5f, 45  },
    { 4, "可乐330",  3.5f, 100 }
};
int a2 = 4;

CartItem cart[MAX_GOODS_M1] = { 0 };
int car_buy = 0;

void add_goods() //增添商品
{
    if (a2 >= MAX_GOODS_M1) 
    {
        printf("商品数量已达到上限\n");
        return;
    }
    Goods g;
    printf("请输入商品编号: ");
    scanf("%d", &g.id);
    printf("请输入商品名称: ");
    scanf("%49s", g.name);
    printf("请输入商品价格: ");
    scanf("%f", &g.price);
    printf("请输入库存数量: ");
    scanf("%d", &g.stock);
    a1[a2++] = g;
    printf("商品添加成功\n");
}

void show_goods() //展示商品
{
    printf("编号\t名称\t价格\t库存\n");
    for (int i = 0; i < a2; i++) 
    {
        printf("%d\t%s\t%.2f\t%d\n", a1[i].id, a1[i].name, a1[i].price, a1[i].stock);
    }
}

void addto() //购物
{
    int id, number, found = 0;
    printf("请输入要加入的商品编号: ");
    scanf("%d", &id);
    for (int i = 0; i < a2; i++) 
    {
        if (a1[i].id == id) //查找是否有该商品
        {
            found = 1;
            printf("请输入购买数量: ");
            scanf("%d", &number);
            if (a1[i].stock < number) //检查商品数目是否足够
            {
                printf("库存不足！\n");
                return;
            }
            a1[i].stock -= number;
            cart[car_buy].goods_id = id;
            cart[car_buy].quantity = number;
            car_buy++;
            printf("已加入购物车\n");
            return;
        }
    }
    if (!found) 
    {
        printf("未找到该编号商品\n");
    }
}

void checkout() //结算
{
    float total = 0;//总金额
    printf("购物车明细:\n");
    printf("编号\t名称\t单价\t数量\t小计\n");
    for (int i = 0; i < car_buy; i++) 
    {
        for (int j = 0; j < a2; j++) 
        {
            if (a1[j].id == cart[i].goods_id) 
            {
                float subtotal = a1[j].price * cart[i].quantity;//该商品应付数目
                printf("%d\t%s\t%.2f\t%d\t%.2f\n", a1[j].id, a1[j].name, a1[j].price, cart[i].quantity, subtotal);
                total += subtotal;
                break;
            }
        }
    }
    printf("应付总额: %.2f 元\n", total);
    car_buy = 0;
}

void menu_m1() //桌面
{
    printf("\n----- 收银前端 -----\n");
    printf("1. 商品录入\n");
    printf("2. 商品展示\n");
    printf("3. 加入购物车\n");
    printf("4. 结算\n");
    printf("0. 退出\n");
    printf("请选择: ");
}
