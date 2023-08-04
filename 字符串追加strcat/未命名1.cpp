#include <stdio.h>
char* my_strcat(char* arr1,const char* arr2)
{
	char* ret = arr1;
	while(*++arr1 != '\0')//这里有个问题，就是为什么++不能放上去，具体看笔记
	{
		;
	}
	while(*arr1++ = *arr2++);
	return ret;
}
int main()
{
	char arr[20] = "hello ";
	my_strcat(arr,"bit");
	printf("%s\n",arr);
	return 0;
}
