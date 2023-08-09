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
	printf("*****1.增添         2.删除**********\n");
	printf("************************************\n");
	printf("*****3.查找         4.修改**********\n");
	printf("************************************\n");
	printf("*****5.排序         6.显示**********\n");
	printf("*************0.退出*****************\n");
}
int main()
{
	int input = 0;
	people num;//定义结构体num
	Initcontact(&num);//结构体初始化
	do
	{
		menu();
		printf("请输入>");
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
			printf("重新输入"); break;
		}
	} while(input);
	return 0;
}
