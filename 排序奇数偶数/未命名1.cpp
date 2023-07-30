#include<stdio.h>
void print(const int * arr,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%d ",arr[i]);
	}
}
void move(int *arr,int sz)
{
	int i=0;
	int j=0;
	int temp;
	int left;
	int right;
	left=0;
	right=sz-1;
	while(left<right)
	{
		while((left<right)&&(arr[left]%2==1))
		{
			left++;//TODO
		}
		while((left<right)&&(arr[right]%2==0))
		{
			right--;//TODO
		}
		if(left<right)
		{
			temp = arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
	}
/*	for(i=0;i<sz;i++)
	{
		j=0;
		for(j=0;j<sz-i;j++)
		{
			if(arr[j]%2==0)
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= temp;
			}
		}对算法的操作练习太少，导致出错
	}*/
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	move(arr,sz);
	print(arr,sz);
	return 0;
}
