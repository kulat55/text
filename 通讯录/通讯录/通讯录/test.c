#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("************************************\n");
	printf("*****1.����*********2.ɾ��**********\n");
	printf("************************************\n");
	printf("*****3.����*********4.�޸�**********\n");
	printf("************************************\n");
	printf("*****5.����*********6.��ʾ**********\n");
	printf("*************0.�˳�*****************\n");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("������>");
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
			printf("��������"); break;
		}
	} while(input);
	return 0;
}