#include <stdio.h>//公务员面试  每组七个数  去掉最大和最小 求平均值
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
	//假如用数组写呢？
	#endif
	return 0;
}
