#include <stdio.h>
//������ʵ��void my_strcpy( char* arr2, const char* arr1 )//strcpy�Ǹ��ǲ��ǽ���
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
//ģ��ʵ��
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
//ʹ��ģ�⺯����������ģ����忴�ʼ�
