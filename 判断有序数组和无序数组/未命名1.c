#include <stdio.h>
int main()
{
	int n;
	int flag1 = 0;
	int flag2 = 0;
	int arr[50] = {0};
	int i;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&arr[i]);
		if(i > 0)
		{
			if(arr[i] > arr[i - 1])
			{
				flag1 = 1;
			}
			else if(arr[i] < arr[i - 1])
			{
				flag2 = 1;
			}
			else ;
		}
	}
	if(flag1 + flag2 <= 1)
	{
		printf("ÓĞĞò");
	}
	else printf("ÎŞĞò");
	return 0;
}
