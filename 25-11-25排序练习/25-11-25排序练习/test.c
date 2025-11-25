#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int k = i; k < 10; k++)
		{
			int m = 0;
			if (arr[k] < arr[i])
			{
				m = arr[i];
				arr[i] = arr[k];
				arr[k] = m;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d", arr[i]);
	return 0;
}