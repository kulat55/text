#include<stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j==0)
			{
				arr[i][j]=1;
			}//TODO
			if(i == j){
				arr[i][j] = 1;//TODO
			}
			if(i >= 2 && j >= 1){
				arr[i][j] = arr[i - 1][j] + arr [i - 1][j - 1];//TODO
			}
		}
	}
	//��ӡ
	for(int i=0;i<10;i++){
			for(int j=0;j<=i;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		return 0;
}
