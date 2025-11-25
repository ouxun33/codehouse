#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int tri(int x, int y, int z)//判断三角形
{
	if ((x + y > z) && (x + z > y) && (y + z > x))
		return 1;//是个三角形
	else
		return 0;//不是三角形
}

int right(int a, int b, int c)//判断直角
{
	if ((a + b == c) || (a + c == b) || (b + c == a))
		return 1;
	else
		return 0;
}

int acu(int x, int y, int z)//判断锐角
{
	if ((x + y > z) && (x + z > y) && (z + y > x))
		return 1;
	else
		return 0;
}

int iso(int x, int y, int z)//判断等腰
{
	if (x == y || x == z || y == z)
		return 1;
	else
		return 0;
}

int equ(int x, int y, int z)//判断等边
{
	if (x == y && x == z)
		return 1;
	else
		return 0;
}

int obt(int x, int y, int z)//判断钝角
{
	if ((x + y < z) || (x + z < y) || (y + z < x))
		return 1;
	else
		return 0;
}

int main()
{
	int a, b, c;//三边长度
	scanf("%d %d %d", &a, &b, &c);
	int x = a * a;//三条边的平方
	int y = b * b;
	int z = c * c;
	if (tri(a, b, c) == 1)
	{
		if (right(x, y, z) == 1)
		{
			printf("Right triangle\n");
			if (iso(x, y, z) == 1)
				printf("Isosceles triangle");
			return 0;
		}
		else if (acu(x, y, z) == 1)
		{
			printf("Acute triangle\n");
			if (iso(x, y, z) == 1)
			{
				printf("Isosceles triangle\n");
				if (equ(x, y, z) == 1)
					printf("Equilateral triangle");
			}
			return 0;
		}
		else if (obt(x, y, z) == 1)
		{
			printf("Obtuse triangle\n");
			if (iso(x, y, z) == 1)
				printf("Isosceles triangle");
			return 0;
		}
	}
	else
	{
		printf("Not triangle");
		return 0;
	}
	return 0;
}

//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	int A = a * a; int B = b * b; int C = c * c;
//	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
//		printf("Not triangle");
//	else if (((A + B) == C )||( (A + C )== B) ||( (B + C) == A))//直角三角形的情况
//	{
//		printf("Right triangle\n");
//		if (a == b || b == c || a == c)//判断是否为等腰三角形
//			printf("Isosceles triangle");
//	}
//	else if ((A + B) > C || (A + C) > B || (B + C) > A)//锐角三角形的情况
//	{
//		printf("Acute triangle\n");
//		if (a == b || b == c || a == c)//判断是否为等腰三角形
//		{
//			printf("Isosceles triangle\n");
//			if (a == b && a == c)//判断是否为等边三角形
//				printf("Equilateral triangle");
//		}
//	}
//	else if ((A + B) < C || (A + C) < B|| (B + C) < A)
//	{
//		printf("Obtuse triangle\n");
//		if (a == b || b == c || a == c)
//		{
//			printf("Isosceles triangle");
//		}
//	}
//	return 0;
//}