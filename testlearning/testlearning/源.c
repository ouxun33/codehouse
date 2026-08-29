#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//九九乘法表的打印
//int main()
//{
//	int mul1;
//	int mul2;
//	int result;
//	for (mul1 = 1; mul1 <=9 ; mul1++)
//	{
//		for (mul2 = 1; mul2 <= mul1; mul2++)
//		{
//			result = mul1 * mul2;
//			printf("%d*%d=%d ", mul1, mul2, result);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int a = 1;
//
//
//int main()
//{
//	static int a = 5;
//	char str[] = "string";
//	printf("%s\n", &str);
//	int* p = &a;
//	printf("%p\n%d\n", (void*) & a,a);
//	printf("%p\n%d\n", (void*)p,a);
//	return 0;
//}


//int main()
//{
//	FILE* fp = fopen("C:/Users/17704/OneDrive/Desktop/新建 文本文档.txt", "r");
//	if (fp == NULL) {
//		perror("打开文件失败");
//		return 1;
//	}
//	int fgetc(FILE * fp);
//	fclose(fp);
//	return 0;
//
//}

#include <stdio.h>

int main() {
    // 先创建一个只含 "Hello" 的文件
    FILE* fp = fopen("test.txt", "w");
    fputs("Hello", fp);   // 写入5个字符，没有EOF
    fclose(fp);

    // 再读取，统计字节数
    fp = fopen("test.txt", "r");
    int ch;
    int count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        count++;
        printf("第%d次: 读取 '%c' (ASCII %d)\n", count, ch, ch);
    }
    printf("第%d次: 返回 EOF (%d)\n", count + 1, ch);
    printf("文件实际字节数: %d\n", count);  // 输出 5，不是 6
    fclose(fp);
    return 0;
}
