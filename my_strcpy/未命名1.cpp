#include <stdio.h>
//创造性实践void my_strcpy( char* arr2, const char* arr1 )//strcpy是覆盖不是交换
//{
//	while(/**arr1 != '\0'*/*arr2++ = *arr1++)
//	{
		//*arr2++ = *arr1++ ;
//		}
	/*while(*arr1 != '\0')
	{char temp = *arr2;
	*arr2 = *arr1;
	*arr1 = *arr2;
	arr1++;
	arr2++;
	*/
	/**/
//}
//模拟实践
char* my_strcpy(char* arr2,char* arr1)
{
	char* ret = arr2;
	while(*arr1)
	{
		*arr2++ = *arr1++;
	}
	*arr2 = *arr1;
	return ret;
}
/*char* my_strcpy(char* arr2,const char* arr1)
{
	char* ret = arr2;
	while(*arr2++ = *arr1++)
		;
	return ret;
}*/
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = { 0 };
	printf("%s\n",my_strcpy(arr2,arr1));
	return 0;
}
//使用模拟函数是有问题的，具体看笔记
