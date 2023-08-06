#include <stdio.h>
#include <string.h>
void* my_memmove(void* arr1,const void* arr2,size_t num)
{
	void* ret = arr1;
	if(arr1 < arr2)
	{
		while(num--)
		{
			*(char*)arr1 = *(char*)arr2;
			arr1 = (char*)arr1 + 1;
			arr2 = (char*)arr2 +1 ;
		}
	}
	else 
	{
		while(num--)
		{
			*((char*)arr1+num) = *((char*)arr2 + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	my_memmove(arr1+4,arr1+3,20);
	for(i = 0 ; i <10 ;i++)
	{
		printf("%d ",arr1[i]);
	}
	return 0;
}
