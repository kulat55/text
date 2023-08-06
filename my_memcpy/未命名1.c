#include <stdio.h>
#include <string.h>
void* my_memcpy(void* arr1,const void* arr2,size_t num)
{
	void* ret = arr1;
	while(num--)
	{
		*(char*)arr1 = *(char*)arr2;
		(char*)arr1++;
		(char*)arr2++;
	}
	return ret;
}
int main()
{
	int arr1[] = {1,2,3,4,5,6,7};
	int arr2[7] = {0};
	int i = 7;
	my_memcpy(arr2,arr1,28);
	while(i--)
	{
		printf("%d ",arr2[i]);
	}
	return 0;
}
