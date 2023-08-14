#include <stdio.h> //Finoacci 数列 兔子数列  0 1 1 2 3 5 8 13 ... 
#include <string.h>
#include <math.h>
#define way 0
int main()
{
	#if way
	int arr[15] = {0};
	int i = 0;
	int left = 0;
	int right = 0;
	int n = 0;
	arr[0] = 0;
	arr[1] = 1;
	for(i = 1; i< 15; i++)
	{
		arr[i + 1] = arr[i] + arr[i - 1];
	}
	while(scanf("%d",&n) == 1)
	{
		for(i = 0; i < 15; i++)
		{
			if(arr[i] <= n)left = i;
			if(arr[i] >= n)
			{
				right = i;break;
			}
		}
		if((n - arr[left])-(arr[right] - n)> 0)
		{
			printf("%d\n",arr[right] - n);
		}
		else printf("%d\n",n - arr[left]);
	}
	#elif !way
	int n;
	scanf("%d",&n);
	int a = 0;
	int b = 1;
	int c = a + b;
	while(1)
	{
		if(n == b)
		{
			printf("0\n");break;
		}
		else if(n < b)
		{
			if(abs(a - n) > abs(b - n))
			{
				printf("%d",abs(b - n));
			}
			else 
			{
				printf("%d",abs(a - n));break;
			}
		}
		c = a + b;
		a = b;
		b = c;
	}
	#endif
	return 0;
}
