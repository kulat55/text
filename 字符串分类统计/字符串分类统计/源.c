//#include<stdio.h> ��������Լ��ķ������Ǵ����
//int main()
//{
//	char num[50];
//	int i=0,eng=0,mas=0,kong=0,or=0;
//	for(i=0;i<50;i++)
//	{
//		scanf("%s",num);
//	}
//	for(i=0;i<50;i++)
//	{
//		if(num[i]>='a'&&num[i]<='z'||num[i]>='A'&&num[i]<='Z')
//		{
//			eng++;
//		}
//		if(num[i]>='0'&&num[i]<='9')
//		{
//			mas++;
//		}
//		if(num[i]==' ')
//		{
//			kong++;
//		}
//		else
//		{
//			or++;
//		}
//	}
//	printf("%d %d %d %d",eng,mas,kong,or);
//	return 0;
//}
//#include <stdio.h>���ǵ�һ����ȷ�ķ���
//#include<stdlib.h>
//int main(void)
//{
//    int letter = 0, number = 0, space = 0, other = 0;
//    char ch;
//    while( (ch = getchar()) != '\n'){     /*����ġ�\n�����ܻ���EOF��Ҫ���Ͱ�����Ļ��з�����������������ַ�������������ַ�������������Ŀ������������һ*/
//        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//            letter += 1;   //letter��ʾ��ĸ����
//        else
//        if (ch == ' ')
//                space += 1;  //�ո�����
//            else
//            if (ch >= '0' && ch <= '9')
//                number += 1; //��������
//                else
//                other += 1;  //�����ַ�����
//    }
//    printf("%d %d %d %d", letter, number, space, other);
//     system("pause");
//    return 0;
//}
#include <stdio.h>
#include <string.h> 
int main(void)
{
    char str[200];//����һ���������ڴ洢������ַ�
    int letter = 0, number = 0, space = 0, other, n;
     
    gets(str); //��ȡ���벢�洢�������gets�������Ļ��з�\n����
    n = strlen (str); //��ȡ������ַ�����
     
     
     
    for(int i = 0; i < n; i++)//forѭ��������������ͬʱ��ʼ������������� , ���Ÿ���
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            letter += 1;
        if (str[i] == ' ')
            space += 1;
        if (str[i] >= '0' && str[i] <= '9')
            number += 1;       
    }
    other = n - space - number - letter; //�������ַ����ȼ�ȥ��ĸ�����ո����ֵó������ַ�������
     
    printf("%d %d %d %d", letter, number, space, other);
     
    return 0;
}