#include<stdio.h>
#include<stdlib.h>
int panduan()//����
{
	//int a=1;
	//char* p=(char*)&a;
	//return *p;
	int a=1;
	return *(char*)&a;
}
int main()
{
	int a=1;
	char* p=(char*)&a;
	if(*p==1)
	{
		printf("С��");
	}
	else
	{
		printf("���");
	}
	system("pause");
	return 0;
}