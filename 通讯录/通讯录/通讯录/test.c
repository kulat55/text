#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("************************************\n");
	printf("*****1.����         2.ɾ��**********\n");
	printf("************************************\n");
	printf("*****3.����         4.�޸�**********\n");
	printf("************************************\n");
	printf("*****5.����         6.��ʾ**********\n");
	printf("*************0.�˳�*****************\n");
}
int main()
{
	int input = 0;
	people num;//����ṹ��num
	Initcontact(&num);//�ṹ���ʼ��
	do
	{
		menu();
		printf("������>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:Addcontact(&num); break;
		case 2:Delectcontact(&num); break;
		case 3:Searchcontact(&num); break;
		case 4:Modifycontact(&num); break;
		case 5:Qsortcontact(&num); break;
		case 6:Printcontact(&num); break;
		case 0: exit(0); break;
		default:
			printf("��������"); break;
		}
	} while(input);
	return 0;
}