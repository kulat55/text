#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define Name_max 20 // ���� ���� �Ա� �绰 ��ַ
#define Sex_max 20
#define Tele_max 20
#define Addr_max 20
#define People_max 100
#define Move_people 3
typedef struct contact
{
	char name[Name_max];
	char sex[Sex_max];
	char addr[Addr_max];
	int tele[Tele_max];
	int age;
}contact;
//��̬
/*typedef struct people
{
	contact data[People_max];
	int count;
}people;*/
typedef struct people
{
	contact* data;
	int count;
	int capity;
}people;
//void Initcontact(people* pc);//��ʼ������
int Initcontact(people* pc);//��̬��ʼ������
void Addcontact(people* pc);//��Ӻ���
void Delectcontact(people* pc);//ɾ������
void Searchcontact(people* pc);//���Һ���
void Modifycontact(people* pc);//�޸ĺ���
void Qsortcontact(people* pc);//������
void Printcontact(people* pc);//��ӡ����
void Quitcoontact(people* pc);//�ڴ淵�غ���
