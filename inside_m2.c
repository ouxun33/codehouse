#define _CRT_SECURE_NO_WARNINGS
#include "s_m2.h"

void table()
{
    printf("=====================================\n");
    printf("|        后端仓储 系统菜单          |\n");
    printf("|===================================|\n");
    printf("| 1. 添加商品                       |\n");
    printf("| 2. 修改商品信息                   |\n");
    printf("| 3. 删除商品                       |\n");
    printf("| 4. 查看商品列表                   |\n");
    printf("| 5. 查询商品库存                   |\n");
    printf("| 0. 退出系统                       |\n");
    printf("=====================================\n");
}

void into() // 添加商品
{
    printf("请输入商品编号(输入0退出)\n");
    int n;
start:
    scanf("%d", &n);
    if (n == 0) 
        return;
    for (int i = 0; i < a2; i++) //商品查重
    {
        if (n == a1[i].id) 
        {
            printf("商品编号重复，请重新输入\n");
            goto start;
        }
    }
    a1[a2].id = n;
    printf("请输入商品名称、库存、价格\n");
    scanf("%49s %d %f", a1[a2].name, &a1[a2].stock, &a1[a2].price);
    a2++;
}

void alter() // 修改商品信息
{
next:
    printf("请输入要修改的商品编号(输入0退出)\n");
    int n;
    scanf("%d", &n);
    if (n == 0) return;
    int k = -1;
    for (int i = 0; i < a2; i++) //遍历数组查找该编号的商品
    {
        if (a1[i].id == n)
        {
            k = i;
            break;
        }
    }
    if (k == -1) 
    {
        printf("未找到该编号商品，请重试\n");
        goto next;
    }
    printf("请输入新的 名称 库存 价格\n");
    scanf("%49s %d %f", a1[k].name, &a1[k].stock, &a1[k].price);
}

void delete_goods() // 删除商品
{
next:
    printf("请输入要删除的商品编号(输入0退出)\n");
    int n;
    scanf("%d", &n);
    if (n == 0) 
        return;
    int k = -1;
    for (int i = 0; i < a2; i++) 
    {
        if (a1[i].id == n)
        { 
            k = i;
            break;
        }
    }
    if (k == -1) 
    {
        printf("未找到该编号商品，请重试\n");
        goto next;
    }
    a1[k] = a1[a2 - 1];
    a2--;
}

void chack() // 查看商品
{
    for (int i = 0; i < a2; i++) 
    {
        printf("编号:%d\t名称:%s\t库存:%d\t价格:%g\n",
            a1[i].id, a1[i].name, a1[i].stock, a1[i].price);
    }
}

void chack_num() // 查询商品库存
{
    int n;
    while (1) {
        printf("请输入要查询的商品编号\n");
        scanf("%d", &n);
        int k = -1;
        for (int i = 0; i < a2; ++i) 
        {
            if (a1[i].id == n) 
            {
                k = i;
                break;
            }
        }
        if (k == -1) 
        {
            printf("未找到该编号商品，请重试\n");
            continue;
        }
        printf("该商品库存为 %d\n", a1[k].stock);
        break;
    }
}