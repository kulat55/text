#include <stdio.h>//����Ա����  ÿ���߸���  ȥ��������С ��ƽ��ֵ
#define _SWITCH_ 1
int main()
{
	#if _SWITCH_
	int min = 100 ;
	int max = 0 ;
	int n = 0;
	int sum = 0;
	int score = 0;
	while(scanf("%d",&score) == 1)
	{
		n++;
		if(score > max)max = score;
		if(score < min)min = score;
		sum += score;
		if(n == 7)
		{
			printf("%.2lf\n",(sum-max-min)/5.0);
			n = 0;
			max = 0;
			min = 100;
			sum = 0;
		}
	}
	#endif
	#if !_SWITCH_
	//����������д�أ�
	#endif
	return 0;
}
