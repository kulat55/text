#include <stdio.h>//不使用strlen求字符串长度
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
char arr[] = "abcdef";//在空间中是abcdef\0
size_t len = my_strlen(arr);
printf("%d\n",len);
return 0;
}
