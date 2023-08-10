#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
/*void Initcontact(people* pc)��̬
{
	pc->count = 0;
	memset(pc->data, 0, People_max);
}*/
//��̬
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
	/*if (pc->count == People_max)��̬
	{
		printf("��������");
		return;
	}*/
	if (pc->count == pc->capity)
	{
		contact* ptr = (contact*)realloc(pc->data, (pc->capity + 2) * sizeof(contact));
		if (ptr == NULL)
		{
			printf("Addcontact: %s\n", strerror(errno));
			printf("����ʧ��");
		}
		else
		{
			printf("���ݳɹ�");
			pc->capity += 2;
			pc->data = ptr;
		}
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pc->count].name);
		printf("����������:>");
		scanf("%d", &pc->data[pc->count].age);
		printf("�������Ա�:>");
		scanf("%s", pc->data[pc->count].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pc->count].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[pc->count].addr);
		pc->count++;
		printf("��ӳɹ�\n");
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
		printf("����ɾ��");
		return;
	}
	printf("����Ҫɾ��������");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("��ɾ������");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�");
}
void Searchcontact(people* pc)
{
	char name[Name_max] = { 0 };
	if (pc->count == 0)
	{
		printf("û������");
		return;
	}
	printf("����Ҫ���ҵ�����");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("�޲��ҵ���");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
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
		printf("�����޸�");
		return;
	}
	printf("����Ҫ�޸ĵ�����");
	scanf("%s", name);
	int pos = Findnum(pc, name);
	if (pos == -1)
	{
		printf("���޸�����");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &pc->data[pos].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ�\n");
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
	printf("����ʲô����> \n");
	scanf("%s", name);
	if (strcmp(name, "����") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact),cmp_by_name);
	}
	if (strcmp(name, "����") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_age);
	}
	if (strcmp(name, "�Ա�") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_sex);
	}
	if (strcmp(name, "�绰") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_tele);
	}
	if (strcmp(name, "��ַ") == 0)
	{
		qsort(pc->data, pc->count, sizeof(contact), cmp_by_addr);
	}
	printf("�������");
}
void Printcontact(people* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
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
