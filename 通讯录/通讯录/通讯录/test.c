#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("************************************\n");
	printf("*****1.增添*********2.删除**********\n");
	printf("************************************\n");
	printf("*****3.查找*********4.修改**********\n");
	printf("************************************\n");
	printf("*****5.排序*********6.显示**********\n");
	printf("*************0.退出*****************\n");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:break;
		case 6:break;
		case 0: exit(0); break;
		default:
			printf("重新输入"); break;
		}
	} while(input);
	return 0;
}