#include <stdio.h> // �� �� ��������żλ����
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
