#include <stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	int r = 0;
	while(scanf("%d %d",&n,&m) == 2)
	{//暴力求解法
	int min = n<m?n:m;
	int max = n>m?n:m;
	int i = min;
	int j = max;
		/*while(1)
		{
			if(min % i == 0&& max %i == 0)
			{
				break;
			}
			i--;
		}
		while(1)
		{
			if(j%max==0&&j%min==0)break;
			j++;
		}
		printf("%d",i+j);
	}*/
	//辗转相除法
	while(r=j%i)
	{
		j = i;
		i = r;
	}
	printf("%d\n",m*n/i+i);
	}
	return 0;
}
