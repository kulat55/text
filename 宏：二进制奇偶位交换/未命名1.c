#include <stdio.h> // 宏 ： 二进制奇偶位交换
#define SWAP(n) (((n&0xaaaaaaaa)>>1)+((n&0x55555555)<<1))
int main()
{
	int n = 0;
	while(scanf("%d",&n) == 1)
	{
		printf("%d\n",SWAP(n));
	}
	return 0;
}
