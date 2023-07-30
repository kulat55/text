#include<stdio.h>/*喝汽水，一瓶一元，两瓶可以换一个汽水，给20元，可以换多少个汽水*/
/*一元一瓶，20元20瓶，20瓶循环除以2，直到得到小于2的数*/
int main()
{
	int i=0,n=0,sun=0;//n是多少元，sun喝的汽水,i空瓶
	scanf("%d",&n);
	sun=n;
	i=n;
	while(i>=2)
	{
		sun+=i/2;
		i=i/2+i%2;
	}
	printf("%d\n",sun);
	return 0;
}
