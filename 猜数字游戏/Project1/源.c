#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int secretNum, guess;
int attempts = 0;
char name[20];
FILE *file;// ��ȡ֮ǰ�������Ϸ����
void Fileread()
{
    file = fopen("game_data.doc", "r");
    if (file != NULL)
    {
        fscanf(file, "%s %d", name, &attempts);
        fclose(file);
        printf("��ӭ������%s��\n\n", name);
        printf("���Ѿ����� %d ����Ϸ��\n\n", attempts);
    } 
}
void update()
	{
   while (1) {
      // �����������Ϊ��
      printf("\n��һ��1��100֮���������");
      scanf("%d", &guess);
      attempts++;
      if (guess > secretNum) {
         printf("̫���ˣ�����һ�Ρ�\n");
      } 
	  if (guess < secretNum) 
	  {
         printf("̫С�ˣ�����һ�Ρ�\n");
      }
	  if(guess==secretNum){
         printf("\n��ϲ�㣬�¶��ˣ�\n");
         // ���浱ǰ��Ϸ����
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
    printf("���������������"); // �����������
    scanf("%s", name);
	srand((unsigned int)time(NULL));
    secretNum = rand() % 100 + 1;
	update();
   printf("��һ������ %d �Ρ�\n", attempts);
   system("pause");
   return 0;
}