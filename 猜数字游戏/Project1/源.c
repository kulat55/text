#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int secretNum, guess;
int attempts = 0;
char name[20];
FILE *file;// 读取之前保存的游戏数据
void Fileread()
{
    file = fopen("game_data.doc", "r");
    if (file != NULL)
    {
        fscanf(file, "%s %d", name, &attempts);
        fclose(file);
        printf("欢迎回来，%s！\n\n", name);
        printf("你已经玩了 %d 次游戏。\n\n", attempts);
    } 
}
void update()
	{
   while (1) {
      // 生成随机数作为答案
      printf("\n猜一个1到100之间的整数：");
      scanf("%d", &guess);
      attempts++;
      if (guess > secretNum) {
         printf("太大了！再试一次。\n");
      } 
	  if (guess < secretNum) 
	  {
         printf("太小了！再试一次。\n");
      }
	  if(guess==secretNum){
         printf("\n恭喜你，猜对了！\n");
         // 保存当前游戏数据
         file = fopen("game_data.doc", "a+");
         fprintf(file, "%s %d\n", name, attempts);
         fclose(file);
         break;
      }
   }
	}
int main()
{
	Fileread();
    printf("请输入你的姓名："); // 输入玩家姓名
    scanf("%s", name);
	srand((unsigned int)time(NULL));
    secretNum = rand() % 100 + 1;
	update();
   printf("你一共猜了 %d 次。\n", attempts);
   system("pause");
   return 0;
}