#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_GOODS_M1 1000

typedef struct 
{
    int id;
    char name[50];
    float price;
    int stock;
} Goods;

//商品数组
extern Goods a1[MAX_GOODS_M1];
extern int a2;//已存放的商品数

//购物车数组
typedef struct 
{
    int goods_id;
    int quantity;
} CartItem;

extern CartItem cart[MAX_GOODS_M1];
extern int car_buy;//购物车商品数

//前端函数声明
void menu_m1();
void add_goods();
void show_goods();
void addto();
void checkout();

void m1_run();

//后端函数声明
void table();
void into();
void alter();
void delete_goods();
void chack();
void chack_num();

void m2_run();
