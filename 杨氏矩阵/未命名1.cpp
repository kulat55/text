#include<stdio.h>//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
int FindNum(int arr[3][3],int k,int* row,int* col)
{
	int x = 0;
	int y = *col - 1;
	while((x < 3) && (y >= 0)){
	if(arr[x][y] > k)
		{
			y--;
		}
		else if(arr[x][y] < k){
			x++;
		}
		else 
		{
			*row = x + 1;
			* col = y + 1;
			return 1;
		}
	}
	return 0;
}
int main()//��д���������Ƿ���ڣ�Ҫ��ʱ�临�Ӷ�С��o(N);
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9}};
	int k=7;//k�ǲ��ҵ�����
	int row=3;
	int col = 3;
	int ret = FindNum(arr,k,&row,&col);
	if(ret == 1)
	{
		printf("yes,%d,%d",row,col);
	}
	else printf("No");
	return 0;
}
