//#include<stdio.h> 这个是我自己的方法，是错误的
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
//#include <stdio.h>这是第一种正确的方法
//#include<stdlib.h>
//int main(void)
//{
//    int letter = 0, number = 0, space = 0, other = 0;
//    char ch;
//    while( (ch = getchar()) != '\n'){     /*这里的‘\n’不能换成EOF，要不就把输入的换行符输入进来当成其他字符处理，因此其他字符的数量将比题目所给的数量多一*/
//        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//            letter += 1;   //letter表示字母数量
//        else
//        if (ch == ' ')
//                space += 1;  //空格数量
//            else
//            if (ch >= '0' && ch <= '9')
//                number += 1; //数字数量
//                else
//                other += 1;  //其他字符数量
//    }
//    printf("%d %d %d %d", letter, number, space, other);
//     system("pause");
//    return 0;
//}
#include <stdio.h>
#include <string.h> 
int main(void)
{
    char str[200];//声明一个数组用于存储输入的字符
    int letter = 0, number = 0, space = 0, other, n;
     
    gets(str); //获取输入并存储到数组里，gets会把输入的换行符\n丢弃
    n = strlen (str); //获取输入的字符长度
     
     
     
    for(int i = 0; i < n; i++)//for循环可以声明变量同时初始化，多个声明用 , 逗号隔开
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            letter += 1;
        if (str[i] == ' ')
            space += 1;
        if (str[i] >= '0' && str[i] <= '9')
            number += 1;       
    }
    other = n - space - number - letter; //把整个字符长度减去字母数、空格、数字得出其他字符的数量
     
    printf("%d %d %d %d", letter, number, space, other);
     
    return 0;
}