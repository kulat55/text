#include<stdio.h>/*����ˮ��һƿһԪ����ƿ���Ի�һ����ˮ����20Ԫ�����Ի����ٸ���ˮ*/
/*һԪһƿ��20Ԫ20ƿ��20ƿѭ������2��ֱ���õ�С��2����*/
int main()
{
	int i=0,n=0,sun=0;//n�Ƕ���Ԫ��sun�ȵ���ˮ,i��ƿ
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
