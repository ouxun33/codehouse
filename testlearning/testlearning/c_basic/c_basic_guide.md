# C语言基础复习指南

## 一、数据类型与变量

### 1.1 基本数据类型

| 类型 | 大小（字节） | 范围 | 说明 |
|------|-------------|------|------|
| char | 1 | -128 ~ 127 | 字符类型 |
| short | 2 | -32768 ~ 32767 | 短整型 |
| int | 4 | -2147483648 ~ 2147483647 | 整型 |
| long | 4或8 | 更大范围 | 长整型 |
| float | 4 | ±3.4×10^38 | 单精度浮点 |
| double | 8 | ±1.7×10^308 | 双精度浮点 |

### 1.2 类型修饰符

- `signed`: 有符号（默认）
- `unsigned`: 无符号，范围翻倍
- `const`: 常量，不可修改

### 1.3 变量声明与初始化

```c
int a;              // 声明
int b = 10;         // 声明并初始化
int c = 3, d = 5;   // 多个变量
const int PI = 3;   // 常量
```

## 二、运算符与表达式

### 2.1 算术运算符

```c
+   加    -   减    *   乘    /   除    %   取余
++  自增  --  自减
```

### 2.2 关系运算符

```c
>   大于    <   小于    >=  大于等于
<=  小于等于 ==  等于    !=  不等于
```

### 2.3 逻辑运算符

```c
&&  逻辑与    ||  逻辑或    !   逻辑非
```

### 2.4 位运算符

```c
&   按位与    |   按位或    ^   按位异或
~   按位取反  <<  左移      >>  右移
```

### 2.5 优先级

从高到低：`()` → `++ -- ~ !` → `* / %` → `+ -` → `<< >>` → `> < >= <=` → `== !=` → `&` → `^` → `|` → `&&` → `||` → `=`

## 三、控制流程

### 3.1 条件语句

```c
// if-else
if (条件) {
    语句1;
} else if (条件2) {
    语句2;
} else {
    语句3;
}

// switch
switch (表达式) {
    case 常量1:
        语句1;
        break;
    case 常量2:
        语句2;
        break;
    default:
        语句3;
}
```

### 3.2 循环语句

```c
// for循环
for (初始化; 条件; 更新) {
    循环体;
}

// while循环
while (条件) {
    循环体;
}

// do-while循环（至少执行一次）
do {
    循环体;
} while (条件);
```

### 3.3 跳转语句

```c
break;      // 跳出循环
continue;   // 跳过本次循环
return;     // 返回函数值
```

## 四、数组

### 4.1 一维数组

```c
int arr[5];                  // 声明
int arr[5] = {1, 2, 3, 4, 5}; // 初始化
int arr[] = {1, 2, 3};       // 自动推断大小

// 访问数组元素
printf("%d", arr[0]);  // 第一个元素
```

### 4.2 二维数组

```c
int matrix[3][4];                    // 3行4列
int matrix[3][4] = {{1,2},{3,4},{5,6}}; // 部分初始化
```

### 4.3 数组与指针

```c
int arr[5] = {1,2,3,4,5};
int *p = arr;        // p指向数组首元素
printf("%d", *p);    // 输出1
printf("%d", *(p+1));// 输出2
```

## 五、指针（重点）

### 5.1 指针的概念

指针是存储内存地址的变量。

```c
int a = 10;
int *p;       // 声明指针
p = &a;       // p指向a的地址
printf("%d", *p); // 输出10（解引用）
```

### 5.2 指针运算

```c
p++;          // 指针移动一个类型大小（int为4字节）
p += 2;       // 指针移动2个类型大小
```

### 5.3 指针与函数

```c
// 传值调用
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 传址调用（真正交换）
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
```

### 5.4 指针数组与数组指针

```c
int *arr[5];    // 指针数组：数组的每个元素是指针
int (*p)[5];    // 数组指针：指向数组的指针
```

## 六、结构体

### 6.1 结构体定义

```c
struct Student {
    char name[20];
    int age;
    float score;
};
```

### 6.2 结构体变量

```c
struct Student s1;
s1.age = 20;
strcpy(s1.name, "张三");

// 初始化
struct Student s2 = {"李四", 18, 95.5};
```

### 6.3 结构体指针

```c
struct Student *p = &s1;
p->age = 21;        // 等价于 (*p).age
```

### 6.4 结构体数组

```c
struct Student class[50];
class[0].age = 19;
```

## 七、函数

### 7.1 函数定义

```c
返回类型 函数名(参数列表) {
    函数体;
    return 返回值;
}
```

### 7.2 函数声明

```c
int add(int a, int b);  // 声明
```

### 7.3 函数调用

```c
int result = add(3, 5);
```

### 7.4 递归函数

```c
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}
```

## 八、字符串

### 8.1 字符串表示

```c
char str[20] = "Hello";  // 末尾自动添加'\0'
char str[] = "World";    // 自动推断大小
```

### 8.2 常用字符串函数

```c
#include <string.h>

strlen(str);      // 获取长度
strcpy(dst, src); // 复制字符串
strcat(dst, src); // 拼接字符串
strcmp(s1, s2);   // 比较字符串
strstr(s1, s2);   // 查找子串
```

## 九、动态内存分配

### 9.1 常用函数

```c
#include <stdlib.h>

malloc(size);     // 分配内存
calloc(n, size);  // 分配并初始化为0
realloc(ptr, size); // 重新分配
free(ptr);        // 释放内存
```

### 9.2 示例

```c
int *arr = (int*)malloc(5 * sizeof(int));
if (arr == NULL) {
    printf("内存分配失败\n");
    return 1;
}

arr[0] = 1;
arr[1] = 2;

free(arr);  // 必须释放
```

## 十、文件操作

### 10.1 文件打开与关闭

```c
#include <stdio.h>

FILE *fp = fopen("test.txt", "r");  // 只读
FILE *fp = fopen("test.txt", "w");  // 只写（覆盖）
FILE *fp = fopen("test.txt", "a");  // 追加
FILE *fp = fopen("test.txt", "rb"); // 二进制只读

fclose(fp);  // 关闭文件
```

### 10.2 文件读写

```c
// 字符读写
fputc('A', fp);
char c = fgetc(fp);

// 字符串读写
fputs("Hello", fp);
char str[100];
fgets(str, 100, fp);

// 格式化读写
fprintf(fp, "%d %s", 10, "hello");
fscanf(fp, "%d %s", &num, str);

// 二进制读写
fwrite(&data, sizeof(data), 1, fp);
fread(&data, sizeof(data), 1, fp);
```

## 十一、预处理指令

```c
#define PI 3.14159   // 宏定义
#include <stdio.h>    // 包含头文件

#ifdef DEBUG
    printf("调试模式\n");
#endif
```

## 十二、常见错误与注意事项

1. **数组越界**: 访问超出数组范围的元素
2. **未初始化变量**: 使用未赋值的变量
3. **内存泄漏**: 动态分配的内存未释放
4. **指针为空**: 对NULL指针进行解引用
5. **字符串操作**: 忘记字符串末尾的'\0'
6. **函数声明**: 使用未声明的函数
7. **类型不匹配**: 赋值或参数类型不一致

## 十三、复习建议

1. 每天至少写一个完整的C程序
2. 重点复习指针和结构体
3. 多做练习题，尤其是数组和指针相关
4. 尝试实现简单的数据结构（链表、栈、队列）
5. 编写文件操作程序，加深理解