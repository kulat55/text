#include<stdio.h>//��Sn=a+aa+aaa+��+aa��aaa����n��a��ֵ֮������a��һ�����֣�Ϊ2�� ���磬n=5ʱ=2+22+222+2222+22222��n�ɼ������롣
#include<stdlib.h>
int main()
{
	int n,s=0,num=2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//num*=2;���ִ�������Ϊ22��2*2
		s+=num;
		num=num*10+2;
	}
	printf("%d",s);
	system("pasue");
	return 0;
}