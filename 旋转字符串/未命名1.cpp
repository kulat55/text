#include <stdio.h>
#include <string.h>
/*void left_move(char* arr,int x)//������ⷨ
{
	int len = strlen(arr);
	for(int i=0;i<x;i++){
		int temp =arr [0];//char* temp = arr;
		for(int j=0;j<len - 1;j++){
			arr[j] = arr [j+1];// *(arr + j) = *(arr + j + 1);
		}//TODO
		arr [len - 1] = temp;// *(arr + len - 1 ) = temp ;
	}
}*/
void reverse(char* left,char* right)
{
	while(left < right){
		char temp = *left;
		*left=*right;
		*right = temp;
		left++;
		right--;
	}
}
void left_move(char* arr,int x)//����ת����
{
	int len = strlen ( arr );
	reverse(arr,arr + x - 1);
	reverse(arr + x,arr + len -1);
	reverse(arr,arr + len - 1);
}
/*int main()�ͼ���ת
{
	char arr[] = "abdswd";
	left_move(arr,2);
	printf("%s",arr);
	return 0;
}*/
int is_left_move(char* x,char* y)
{
	int len = strlen (x);
	for(int i=0;i<len;i++){
		left_move(x,1);
		int ret = strcmp(x,y);
		if(ret == 0){
			return 1;//TODO
		}//TODO
	}return 0;
}
int is_is_left_move(char* str1,char* str2)//��һ�ַ��������1.��str1׷��һ���ַ�����str2�ж�
{
	int len = strlen(str1);
	int len1 = strlen(str2);
	if(len != len1)return 0;
	else {
			strncat(str1,str1,5);//��str1����
			char* ret = strstr(str1,str2);//���str2���Ƿ���str1
			if(ret == NULL){return 0;
				//TODO
			}
			else return 1;
	}
	
	
}
int main()
{
	char s1[30] = "AABCD";
	char s2[] = "BCDAA";
	int ret = is_is_left_move(s1,s2);
	if(ret == 1)printf("yes\n");
	else printf("NO\n");
	return 0;
}
