#include <stdio.h>
#include <string.h>
/*int main()
{
	char arr1[20] = {0};
	char arr2[] = {' '};
	scanf("%s",arr1);
	while(1)
	{
		char* ret = strstr(arr1,arr2);
		if(ret != NULL)
		{
			*ret = '%20';
		}
		else break;
	}
	printf("%s",arr1);
}*/
int main()
{
	char arr[] = "hello bit world";
	int length = sizeof(arr)/sizeof(arr[0]);
	char* cur = arr;
	int space_count = 0;
	while(*cur)
	{
		if(*cur == ' ')space_count++;
		cur++;
	}
	int end1 = length - 1;
	int end2 = length + space_count*2 -1;
	while(end1 != end2)
	{
		if(arr[end1] != ' ')
		{
			arr[end2--] = arr[end1--];
		}
		else 
		{
			end1--;
			arr[end2--] = '0';
			arr[end2--] = '2';
			arr[end2--] = '%';
		}
	}
	printf("%s",arr);
	return 0;
}
