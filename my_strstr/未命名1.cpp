#include <stdio.h>
#include <string.h>
char* my_strstr(const char* str1,const char* str2)
{
	const char* p = str1;
	const char* s1 = str1;
	const char* s2 = str2;
	while(*p)
	{
		s1 = p;
		s2 = str2;
		while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2){
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "abdsjad";
	char arr2[] = "abd";
	char* ret = my_strstr(arr1,arr2);
	if(ret == NULL)
	{
		printf("no");
	}
	else {
		printf("yes");
	}
	return 0;
}
