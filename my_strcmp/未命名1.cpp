#include <stdio.h>
#include <string.h>
int my_strcmp(char* arr1,char* arr2)
{
	while(*arr1 == *arr2)
	{
		if(*arr1 == '\0')return 0;
		arr1++;
		arr2++;
	}
	if(*arr1 > *arr2) return 1;
	else return -1;
	//»òÕßreturn (*arr1 - *arr2);
}
int main()
{
	char arr1[] = "abc";
	char arr2[] = "acb";
	int ret = my_strcmp(arr1,arr2);
	if(ret < 0){
		printf("<");
	}
	else if(ret == 0)printf("==");
	else printf(">");
}
