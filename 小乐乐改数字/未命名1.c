#include <stdio.h>
#include <math.h>
/*int main()
{
	int n = 0;
	int i = 0;
	int num = 0;
	scanf("%d",&n);
	i = n;
	while(i / 10 != 0)
	{
		num = i % 10;
		i/=10;
	}
}*/
int main()
{
	int input = 0;
	int sum = 0;
	int i = 0;
	scanf("%d",&input);
	while(input)
	{
		int bit = input % 10;
		if(bit % 2 == 1)
		{
			sum += 1 * pow(10,i);
			i++;
		}
		else
			{
				sum += 0 * pow(10,i);
					i++;
				}
				input /= 10;
	}
	printf("%d\n",sum);
	return 0;
}
