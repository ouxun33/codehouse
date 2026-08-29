#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return 1;
    }
    
    fprintf(fp, "Hello, C语言!\n");
    fprintf(fp, "这是一个文件操作示例\n");
    fprintf(fp, "数字: %d, %f\n", 100, 3.14);
    fclose(fp);
    
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return 1;
    }
    
    printf("读取文件内容:\n");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
    
    printf("\n二进制文件操作:\n");
    fp = fopen("data.bin", "wb");
    int numbers[] = {1, 2, 3, 4, 5};
    fwrite(numbers, sizeof(int), 5, fp);
    fclose(fp);
    
    fp = fopen("data.bin", "rb");
    int read_numbers[5];
    fread(read_numbers, sizeof(int), 5, fp);
    printf("从二进制文件读取: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\n");
    fclose(fp);
    
    return 0;
}