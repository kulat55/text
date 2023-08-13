#include <stdio.h>//箭形图案
int main()//第一种思维  我们还可以用“ ”两个空格 不需要一个空格一个空格打印
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		for( i = 0 ;i < n + 1 ;i++)
		{
			for(j = 2 * n ; j > 2 * i ; j--)
			{
				printf(" ");
			}
			for(k = 0 ;k <= i; k++)
			{
				printf("*");
			}
			printf("\n");
		}
		for(i = 0;i< n;i++)
		{
			for(j = 0 ;j < 2*(i + 1);j++)printf(" ");
			for(k = n  - i;k > 0; k--)printf("*");
			printf("\n");
		}
	}
	return 0;
}
