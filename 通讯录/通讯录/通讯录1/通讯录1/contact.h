#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define Name_max 20 // 姓名 年龄 性别 电话 地址
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
//静态
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
//void Initcontact(people* pc);//初始化函数
int Initcontact(people* pc);//动态初始化函数
void Addcontact(people* pc);//添加函数
void Delectcontact(people* pc);//删除函数
void Searchcontact(people* pc);//查找函数
void Modifycontact(people* pc);//修改函数
void Qsortcontact(people* pc);//排序函数
void Printcontact(people* pc);//打印函数
void Quitcoontact(people* pc);//内存返回函数
