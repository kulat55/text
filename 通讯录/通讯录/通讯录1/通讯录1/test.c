#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
enum num
{
	go,
	add,
	delect,
	search,
	modify,
	sort,
	show
};
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
		case add:Addcontact(&num); break;
		case delect:Delectcontact(&num); break;
		case search:Searchcontact(&num); break;
		case modify:Modifycontact(&num); break;
		case sort:Qsortcontact(&num); break;
		case show:Printcontact(&num); break;
		case go: Quitcoontact(&num); break;
		default:
			printf("��������"); break;
		}
	} while(input);
	return 0;
}
