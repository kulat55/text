#include<stdio.h>//求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。
#include<stdlib.h>
int main()
{
	int n,s=0,num=2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//num*=2;出现错误，误以为22是2*2
		s+=num;
		num=num*10+2;
	}
	printf("%d",s);
	system("pasue");
	return 0;
}