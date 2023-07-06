#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#define High 20
#define Width 30
#define EnemyNum 5		// �л�����
//����ȫ������6
int position_x, position_y; //��x,y�����ʾ�ɻ�λ��
int score;//�÷�
int flag = 0;
int number;	// ���ٵл���
int BulletWidth;// �ӵ����
int EnemyMoveSpeed;// �л��ƶ��ٶ�

struct enemy {
	int x;
	int y;
	int life;
} enemy[EnemyNum]; // �л�λ��

int canvas[High][Width] = {0};	// ��ά����洢��Ϸ�����ж�Ӧ��Ԫ��,�Խ�����䵯ҩ����

void FileRead();
void FileWrite();

void menu() {
	int n;
	printf("******************************\n");
	printf("*   	   �ɻ���ս          *\n");
	printf("*          1.��ʼ��Ϸ        *\n");
	printf("*          2.�˳���Ϸ        *\n");
	printf("******************************\n");
	printf("����������1-2:");
	while(1)
	{
	scanf("%d", &n);
	switch(n) {
		case 1:
			flag = 1;//ʹ��flag���жϼ��ص�ʱ�򵽵��Ƕ�ȡ�浵���Ǵ�ͷ��ʼ��Ϸ
			system("cls");
			break;
		case 2:
			exit(0);       // �˳���Ϸ
		default:
			printf("������1-2֮�����");
			system("cls");break;
	}
	if(flag==1)break;
	}
}

void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//GetStdHandle(STD_OUTPUT_HANDLE); ��ȡ����̨������
	COORD pos;
	//COORD��Windows API�ж����һ�ֽṹ�����ͣ���ʾ����̨��Ļ�ϵ�����
	//��������Ƕ�����COORD���͵ı���pos�������β�x��y���г�ʼ����
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);//��λ�������
	//Ȼ����SetConsoleCursorPosition���ÿ���̨(cmd)���λ��
	//COORD�Ľṹ�����ͣ�typedef struct _COORD {
	//SHORT X; ������
	//SHORT Y; ������
	//}
}
//Ϊʲô������������������ӡ������ݵ�ʱ���ǰ�˳������ġ��ӵ�һ��һֱ��ӡ�����һ����
//���������������ʮ���Ӵ��ʱ�򣬵�һ�������һ����������ʱ��Ҳ����ǰ��������ˣ��������㻹û���������Ի�������������
//Ϊʲô�ܽ���������ֲ����Ǹ��¼��ٸ���������
//���á�SetConsoleCursorPosition���������̨APIȥ��̬���ù�꣬����ӡ�͸��ǵ�һЩ���ݣ���ʵ�־ֲ���ˢ��

void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; //�����Ϣ�Ľṹ������ ǰһ�����ֱ�ʾ��ȣ���һ����ʾ�Ƿ�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���޸ĺ����Ϣд��
	//�ṹ��typedef struct _CONSOLE_CURSOR_INFO {
	//DWORD  dwSize;
	//BOOL   bVisible;
	//}

}


void startup()//��Ƶ��ҷɻ���ʼλ�ó�ʼλ�� 
{ //��λ����ߴ���г�ʼ��
	//��������0Ϊ�ո�1Ϊ�ɻ���2Ϊ�ӵ���3Ϊ�л�
	position_x = High / 2;
	position_y  = Width / 2;//�ɻ���ʼλ�������м�
	canvas[position_x][position_y] = 1;
	canvas[position_x + 1][position_y - 1] = 1;
	canvas[position_x + 1][position_y] = 1;
	canvas[position_x + 1][position_y + 1] = 1;//�ɻ�ģ��
	int k;
	for (k = 0; k < EnemyNum; k++) { //����л�����,��ӡEnemyNum�Σ��ﵽ����������Ŀ��
		enemy[k].x = rand() % 2;//������л�����
		enemy[k].y = rand() % Width;//������л�����
		canvas[enemy[k].x][enemy[k].y] = 3;//���л�����д������
	}
	int score = 0;			// �ɼ�
	int number = 0;			// ���ٵл���
	BulletWidth = 0;        //�ӵ����
	EnemyMoveSpeed = 30;//�����ƶ��ٶ�
	HideCursor();			// ���
}

void show() { //��ʾ���� ��ӡ���ɻ�
	gotoxy(0,0); //����system("cls")��Ļ��˸���أ�Ӱ���Ӿ�,�ʲ����ϵó�
	int i, j;
	for (i = 0; i < High; i++) { //��ӡ��Ϸ����
		for (j = 0; j < Width; j++) {
			if ((j == Width - 1) || (i == High - 1) || (j == 0) || (i == 0))
				printf("#");             // ��ӡ�߽�#
			else if (canvas[i][j] == 1)
				printf("*");             // ����ɻ�8
			else if (canvas[i][j] == 2)
				printf("o");             // ����ӵ�o
			else if (canvas[i][j] == 3)
				printf("@");             // ����л�O
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("[�÷�]: %d\n", score);
	printf("[��ɱ]: %d\n\n", number);
	Sleep(20);//��������20���룬������������
}

void updatewithoutinput() {
	int i, j, k;
	for (i = 0; i < High; i++) {
		for (j = 0; j < Width; j++) {
			if (canvas[i][j] == 2) { //�ӵ�������ж�
				for (k = 0; k < EnemyNum; k++) { //ֻ��enemynum̨�л������Ҳֻ��Ҫ�Ը���Ŀ�ĵл����ݽ��и���
					if ((i == enemy[k].x) && (j == enemy[k].y)) 
					{		// ������ӵ�������ڵл����꣬���ж��ӵ����ел�
						score++;										// ������1
						number++;// ���ٵл�����1
						canvas[enemy[k].x][enemy[k].y] = 0;				// ��Ӱ����,��������ел��������Ӧ�������ݸ�Ϊ0
						enemy[k].x = rand() % 2;						// �����µĵл�
						enemy[k].y = rand() % Width;
						canvas[enemy[k].x][enemy[k].y] = 3;
						canvas[i][j] = 0;								// �ӵ���ʧ
					}
				}
				// �ӵ������ƶ�
				canvas[i][j] = 0;//���ӵ���ǰ����������Ϊ�հף��������������һ�����ʵ���ӵ����ϵ�Ч��
				if (i > 0)//
					canvas[i - 1][j] = 2;
			}
		}
	}
	static int speed = 0;//��̬�ֲ�����speed
	//ʹ�øñ������˳������󣬲��ᱻ���٣�����ٴε��øú���ʱ���ñ�����ֵ���ϴ��˳�����ʱֵ��ͬ
	if (speed < EnemyMoveSpeed)//ʹupdatewithoutinput����EnemyMoveSpeed�Σ��л����ƶ�һ��
		speed++;
	for (k = 0; k < EnemyNum; k++) {
		// �л�ײ���һ�
		if ((position_x == enemy[k].x) && (position_y == enemy[k].y) 
			|| (position_x + 1 == enemy[k].x)&& (position_y - 1 == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y + 1 == enemy[k].y)
		        || (position_x + 2 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x)
		        && (position_y - 1 == enemy[k].y))
			//�ɻ�ռ�ĸ��������ݣ���һ������������л�������ͬ����Ϊײ��
		{
			printf("\n��Ϸ����!\n");
			Sleep(3000);//ֹͣ������
			system("pause");
			exit(0);
		}

		// �л��ܳ���ʾ��Ļ
		if (enemy[k].x > High) { //�л������������Ϸ�����������
			canvas[enemy[k].x][enemy[k].y] = 0;
			enemy[k].x = rand() % 2; // �����µĵл�
			enemy[k].y = rand() % Width;
			canvas[enemy[k].x][enemy[k].y] = 3;
			score--; // ����
		}

		if (speed == EnemyMoveSpeed) { //����EnemyMoveSpeed��ѭ������ʼ�ƶ��л����꣬��۱�ʾΪ�л��ƶ��ٶ�
			// �л�����
			for (k = 0; k < EnemyNum; k++) {
				canvas[enemy[k].x][enemy[k].y] = 0;//���л�Ŀǰλ�ø�Ϊ0������Ϊ�հ�����
				enemy[k].x++;//���ӷɻ���������
				speed = 0;//�����ٶ�
				canvas[enemy[k].x][enemy[k].y] = 3;//�Ӷ��ﵽ�л��ƶ���Ч��
			}

		}
	}

}

void updatewithinput() {
	char input;
	if (kbhit()) // �ж��Ƿ�������,����kbhit���ܼ�����ֵ�� ��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
		//��getch()������kbhitΪ��������������Ӱ����һ������
	{
		input = getch(); // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a' && position_y > 1 || input == 'A') {
			canvas[position_x][position_y] = 0;//��ԭ���ɻ�������������Ϊ�հ�
			canvas[position_x + 1][position_y - 1] = 0;//��ԭ���ɻ�������������Ϊ�հ�
			canvas[position_x + 1][position_y] = 0;//��ԭ���ɻ�������������Ϊ�հ�
			canvas[position_x + 1][position_y + 1] = 0;//��ԭ���ɻ�������������Ϊ�հ�
			position_y--; // λ������
			canvas[position_x][position_y] = 1;//���ɻ���������д��
			canvas[position_x + 1][position_y - 1] = 1;//���ɻ���������д��
			canvas[position_x + 1][position_y] = 1;//���ɻ���������д��
			canvas[position_x + 1][position_y + 1] = 1;//���ɻ���������д��
		}
		//���в���ͬ��
		else if (input == 'd' && position_y < Width - 2 || input == 'D') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_y++; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == 'w' && position_x > 1 || input == 'W') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x--; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == 's' && position_x < High - 3 || input == 'S') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x++; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == ' ') { // �����ӵ�
			int left = position_y - BulletWidth;//yʵ��Ϊ�����꣬������ݴ���ɻ����������������ƶ�BulletWidth���������
			int right = position_y + BulletWidth;//�����ݴ���ɻ��������������ұ߶�BulletWidth���������
			if (left < 0)//left��С����С��0
				left = 0;
			if (right > Width - 1)//right��󲻵ó���width-1
				right = Width - 1;
			int k;
			for (k = left; k <= right; k++)		// �����ӵ� �ӵ�������Ҳ������ɱ���������ţ��൱�ڴ�������ӵ�
				canvas[position_x - 1][k] = 2;	// �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
		}
		else if (input == 'Z' || input == 'z') {	// ��Z�浵
			FileWrite();//����Ϸ����д��浵�ļ�
			system("pause");
			exit(0);
		}
	}
}
// �浵����
void FileWrite() {
	int i, j;
	FILE *fp;							// �����ļ�ָ��
	fp = fopen("D:\\game.data", "w");	// ���ļ� "w": writeд���ļ�
	if (fp == NULL) { //����Ƿ�������
		printf("Open file5.txt error");
	}
	for (i = 0; i < EnemyNum; i++) { //���ַ���ʽ���¼������,�˴�Ϊ¼���������
		fwrite(&enemy[i], sizeof(struct enemy), 1,
		       fp);//���У����� &enemy[i]��һ��ָ��������ݵĴ�ŵ�ַ��sizeof(struct enemy)ָ�����ĵ������ݴ�С��1
		//ָ��һ����Ҫ����� size ���ֽڵ����ݣ�fp ��ָ����������ƶ���ʽ�򿪵��ļ�ָ��
	}
	fwrite(&position_x, sizeof(int), 1, fp);
	fwrite(&position_y, sizeof(int), 1, fp);
	fwrite(&score, sizeof(int), 1, fp);
	fwrite(&number, sizeof(int), 1, fp);
	fwrite(&BulletWidth, sizeof(int), 1, fp);
	fwrite(&EnemyMoveSpeed, sizeof(int), 1, fp);
	fclose(fp);  // �ر��ļ�
	printf("\n����ɹ�\n");
}
int main() {
	menu();
	HideCursor();
	if (flag == 1)
		startup();
	while (1) {
		show();
		updatewithoutinput();
		updatewithinput();
	}
	return 0;
}
