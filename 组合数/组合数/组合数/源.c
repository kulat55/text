#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int combination(int n, int r)//组合数函数
//{
//	int i;
//	int num1 = 1;//上面计数
//	int num2 = 1;//下面计数
//	double sum = 0;//总数
//	for (i = n; i > n - r; i--)
//	{
//		num1 *= i;
//	}
//	for (i = r; i > 0; i--)
//	{
//		num2 *= i;
//	}
//	sum = (double)num1 / num2;
//	return (int)sum;
//}
int combination(int n, int r)
{
	if (r == n || r == 0)return 1;
	if (r == 1) return n;
	return combination(n - 1, r - 1) + combination(n - 1, r);
}
int main()
{
	int n, r; //n是底 r是上
	printf("输入n >>    输入r >>\n");
	scanf("%d %d", &n, &r);
	printf("%d", combination(n, r));
	system("pause");
	return 0;
}

