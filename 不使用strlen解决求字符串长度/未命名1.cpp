#include <stdio.h>//��ʹ��strlen���ַ�������
#include <string.h>
size_t my_strlen(const char* str)
{
	const char* p = str;
	while(*str != '\0'){
		str++;
	}
	return str - p;
}
int main()
{
char arr[] = "abcdef";//�ڿռ�����abcdef\0
size_t len = my_strlen(arr);
printf("%d\n",len);
return 0;
}
