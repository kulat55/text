#include <stdio.h>//�ҳ�����   һ��������ֻ�����������ǳ���һ�Σ������������ֶ�����������
#define way 0 //��дһ�������ҳ�������ֻ����һ�ε�����
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
	//1. ���
	for(i = 0; i < sz ; i++ )
	{
		ret ^= arr[i]; // 5 6 �������ȫΪ000 101 110 = 011
	}// 6 8 0110 1000  1110
	// 2 .����ret�Ķ����������ұߵĵڼ�λ��1
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
    //����
    // 1 . �����������(��� ��ͬΪ0 ����Ϊ1 )  ϵͳ�ռ�洢�Ƕ����ƴ洢 ������0 1 
    // 2 . �ҳ����Ľ����������һλΪ1 - n   �������ԵĿ���B����������A����ż��
    // 3 . �Ե� n Ϊ1 ,��һ�飬��nλΪ0��һ��
    //���԰��ղ�ͬ�ķ������� �������һλ ���ߵ����ڶ�λ  ������0  1
	#endif
	return 0;
}
