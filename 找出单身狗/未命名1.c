#include <stdio.h>//找出单身狗   一个数组中只有两个数字是出现一次，其他所有数字都出现了两个
#define way 0 //编写一个函数找出这两个只出现一次的数字
#include <stdlib.h>
typedef struct str 
{
	int cout;
	int arr[];
}str;
void find_single_dog(int arr[],int sz,int* pd1,int* pd2)
{
	int i = 0;
	int ret = 0;
	//1. 异或
	for(i = 0; i < sz ; i++ )
	{
		ret ^= arr[i]; // 5 6 其他异或全为000 101 110 = 011
	}// 6 8 0110 1000  1110
	// 2 .计算ret的二进制中左右边的第几位是1
	int pos = 0;
	for(pos = 0;pos < 32; pos++)
	{
		if(((ret >> pos)&1) == 1)
		{
			break;
		}
	}
	for( i = 0; i < sz; i++ )
	{
		if(((arr[i] >> pos) & 1) == 1)
		{
			* pd1 ^= arr[i];
		}
		else 
		{
			* pd2 ^= arr[i];
		}
	}
}
int main()
{
	#if way
	int i = 0;
	int j = 0;
	int cout;
	str* ps = (str*)malloc(sizeof(str)+40);
	if(ps == NULL)
	{
		perror("ps error : ");
		return 1;
	}
	if(ps->arr == NULL)
	{
		perror("ps->arr error : ");
		return 1;
	}
	for(i = 0 ;i < 10;i++)
	{
		scanf("%d",&(ps->arr[i]));
	}
	for(i = 0 ;i < 10 ;i++)
	{
		j = 0;
		cout = 0;
		for(j = 0; j < 10;j++)
		{
			if(ps->arr[i] != ps->arr[j])//
			{
				cout++;
			}
		}
		if(cout == 9)printf("%d\n",ps->arr[i]);
	}
	free(ps);
	ps = NULL;
	#elif !way
	int arr[] = { 1,2,3,4,5,1,2,3,4,6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int dog1 = 0;
	int dog2 = 0;
	find_single_dog(arr,sz,&dog1,&dog2);
	printf("%d %d\n",dog1,dog2);
	//5^6
	//101 - 5 B 1 1 3 3
	//101 - 6 A 2 2 4 4
	//011 
	//    - 5 B 1 1 4 4
    //    - 6 A 2 2 3 3
    //分组
    // 1 . 所有数字异或(异或 相同为0 相异为1 )  系统空间存储是二进制存储 二进制0 1 
    // 2 . 找出异或的结果数字中哪一位为1 - n   可以明显的看到B组是是奇数A组是偶数
    // 3 . 以第 n 为1 ,分一组，第n位为0分一组
    //可以按照不同的方法分组 比如最后一位 或者倒数第二位  二进制0  1
	#endif
	return 0;
}
