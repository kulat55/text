#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
/*void Initcontact(people* pc)静态
{
	pc->count = 0;
	memset(pc->data, 0, People_max);
}*/
//动态
int Initcontact(people* pc)
{
	pc->capity = Move_people;
	pc->count = 0;
	pc->data = calloc(pc->capity, sizeof(contact));
	if (pc->data == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	return 0;
}
void Addcontact(people* pc)
{
	/*if (pc->count == People_max)静态
	{
		printf("数据已满");
		return;
	}*/
	if (pc->count == pc->capity)
	{
		contact* ptr = (contact*)realloc(pc->data, (pc->capity + 2) * sizeof(contact));
		if (ptr == NULL)
		{
			printf("Addcontact: %s\n", strerror(errno));
			printf("增容失败");
		}
		else
		{
			printf("增容成功");
			pc->capity += 2;
			pc->data = ptr;
		}
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->count].name);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[pc->count].age);
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->count].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->count].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->count].addr);
		pc->count++;
		printf("添加成功\n");
	}
}
static int Findnum(people* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Delectcontact(people* pc)
{
	char name[Name_max] = { 0 };
	if (pc->count == 0)
	{
		printf("无需删除");
		return;
	}
	printf("输入要删除的姓名");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("无删除数据");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功");
}
void Searchcontact(people* pc)
{
	char name[Name_max] = { 0 };
	if (pc->count == 0)
	{
		printf("没有数据");
		return;
	}
	printf("输入要查找的姓名");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("无查找的人");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}
void Modifycontact(people* pc)
{
	char name[Name_max] = { 0 };
	if (pc->count == 0)
	{
		printf("无需修改");
		return;
	}
	printf("输入要修改的姓名");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("无修改数据");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pos].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功\n");
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((contact*)e1)->name, ((contact*)e2)->name);
}
int cmp_by_sex(const void* e1, const void* e2)
{
	return strcmp(((contact*)e1)->sex, ((contact*)e2)->sex);
}
int cmp_by_tele(const void* e1, const void* e2)
{
	return strcmp(((contact*)e1)->tele, ((contact*)e2)->tele);
}
int cmp_by_addr(const void* e1, const void* e2)
{
	return strcmp(((contact*)e1)->addr, ((contact*)e2)->addr);
}
int cmp_by_age(const void* e1, const void* e2)
{
	return _stricmp(((contact*)e1)->age, ((contact*)e2)->age);
}
void Qsortcontact(people* pc)
{
	char name[Name_max] = { 0 };
	printf("按照什么排序> \n");
	scanf("%s", name);
	if (strcmp(name, "姓名") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact),cmp_by_name);
	}
	if (strcmp(name, "年龄") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_age);
	}
	if (strcmp(name, "性别") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_sex);
	}
	if (strcmp(name, "电话") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_tele);
	}
	if (strcmp(name, "地址") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_addr);
	}
	printf("排序完成");
}
void Printcontact(people* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}
void Quitcoontact(people* pc)
{
	free(pc->data);
	pc->data = NULL;
}
