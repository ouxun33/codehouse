#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "s_m1.h"
#include "s_m2.h"

int choi()
{
    char user[32], pass[32];
    printf("用户名：");
    scanf("%31s", user);

    if (strcmp(user, "退出系统")== 0) 
    {
        return -1; 
    }

    printf("密码：");
    scanf("%31s", pass);

    if (strcmp(user, "吴沛泽") == 0 && strcmp(pass, "070301") == 0) 
    {
        m1_run();
        return 0;   // 登录成功
    }
    else if (strcmp(user, "王明浩") == 0 && strcmp(pass, "070612") == 0) 
    {
        m2_run();
        return 0;   // 登录成功
    }
    else {
        printf("用户名或密码错误, 请重新输入\n");
        return 1;   // 登录失败
    }
}

int main()
{
    for (;;) {
        int k;
        do {
            k = choi();
            if (k == -1) {   
                return 0;     
            }
        } while (k != 0);    

        
    }
    return 0;
}
