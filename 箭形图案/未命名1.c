#include <stdio.h>//����ͼ��
int main()//��һ��˼ά  ���ǻ������á� �������ո� ����Ҫһ���ո�һ���ո��ӡ
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
