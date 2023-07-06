#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#define High 20
#define Width 30
#define EnemyNum 5		// 敌机个数
//设置全局坐标6
int position_x, position_y; //用x,y坐标表示飞机位置
int score;//得分
int flag = 0;
int number;	// 销毁敌机数
int BulletWidth;// 子弹宽度
int EnemyMoveSpeed;// 敌机移动速度

struct enemy {
	int x;
	int y;
	int life;
} enemy[EnemyNum]; // 敌机位置

int canvas[High][Width] = {0};	// 二维数组存储游戏画布中对应的元素,以解决发射弹药问题

void FileRead();
void FileWrite();

void menu() {
	int n;
	printf("******************************\n");
	printf("*   	   飞机大战          *\n");
	printf("*          1.开始游戏        *\n");
	printf("*          2.退出游戏        *\n");
	printf("******************************\n");
	printf("请输入数字1-2:");
	while(1)
	{
	scanf("%d", &n);
	switch(n) {
		case 1:
			flag = 1;//使用flag来判断加载的时候到底是读取存档还是从头开始游戏
			system("cls");
			break;
		case 2:
			exit(0);       // 退出游戏
		default:
			printf("请输入1-2之间的数");
			system("cls");break;
	}
	if(flag==1)break;
	}
}

void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
	COORD pos;
	//COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标
	//上面语句是定义了COORD类型的变量pos，并以形参x和y进行初始化。
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);//定位光标坐标
	//然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
	//COORD的结构体类型：typedef struct _COORD {
	//SHORT X; 横坐标
	//SHORT Y; 纵坐标
	//}
}
//为什么会闪屏：我们正常打印输出内容的时候，是按顺序输出的。从第一个一直打印的最后一个。
//当我们输出的内容十分庞大的时候，第一个和最后一个会存在输出时间差，也就是前面先输出了，而后面你还没看到。所以会有闪屏的现象。
//为什么能解决闪屏：局部覆盖更新减少更新数据量
//调用“SetConsoleCursorPosition”这个控制台API去动态设置光标，来打印和覆盖掉一些数据，以实现局部的刷新

void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; //光标信息的结构体类型 前一个数字表示厚度，后一个表示是否可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//把修改后的信息写入
	//结构体typedef struct _CONSOLE_CURSOR_INFO {
	//DWORD  dwSize;
	//BOOL   bVisible;
	//}

}


void startup()//设计敌我飞机初始位置初始位置 
{ //对位置与尺寸进行初始化
	//数据数据0为空格，1为飞机，2为子弹，3为敌机
	position_x = High / 2;
	position_y  = Width / 2;//飞机初始位置设在中间
	canvas[position_x][position_y] = 1;
	canvas[position_x + 1][position_y - 1] = 1;
	canvas[position_x + 1][position_y] = 1;
	canvas[position_x + 1][position_y + 1] = 1;//飞机模型
	int k;
	for (k = 0; k < EnemyNum; k++) { //存入敌机数据,打印EnemyNum次，达到控制数量的目的
		enemy[k].x = rand() % 2;//随机化敌机坐标
		enemy[k].y = rand() % Width;//随机化敌机坐标
		canvas[enemy[k].x][enemy[k].y] = 3;//将敌机数据写入数据
	}
	int score = 0;			// 成绩
	int number = 0;			// 销毁敌机数
	BulletWidth = 0;        //子弹宽度
	EnemyMoveSpeed = 30;//敌人移动速度
	HideCursor();			// 光标
}

void show() { //显示画面 打印出飞机
	gotoxy(0,0); //清屏system("cls")屏幕闪烁严重，影响视觉,故查资料得出
	int i, j;
	for (i = 0; i < High; i++) { //打印游戏画面
		for (j = 0; j < Width; j++) {
			if ((j == Width - 1) || (i == High - 1) || (j == 0) || (i == 0))
				printf("#");             // 打印边界#
			else if (canvas[i][j] == 1)
				printf("*");             // 输出飞机8
			else if (canvas[i][j] == 2)
				printf("o");             // 输出子弹o
			else if (canvas[i][j] == 3)
				printf("@");             // 输出敌机O
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("[得分]: %d\n", score);
	printf("[击杀]: %d\n\n", number);
	Sleep(20);//函数滞留20毫秒，降低闪屏风险
}

void updatewithoutinput() {
	int i, j, k;
	for (i = 0; i < High; i++) {
		for (j = 0; j < Width; j++) {
			if (canvas[i][j] == 2) { //子弹的相关判定
				for (k = 0; k < EnemyNum; k++) { //只有enemynum台敌机，因此也只需要对该数目的敌机数据进行更新
					if ((i == enemy[k].x) && (j == enemy[k].y)) 
					{		// 如果，子弹坐标等于敌机坐标，则判断子弹击中敌机
						score++;										// 分数加1
						number++;// 销毁敌机数加1
						canvas[enemy[k].x][enemy[k].y] = 0;				// 残影问题,即如果击中敌机，则将其对应数组数据改为0
						enemy[k].x = rand() % 2;						// 产生新的敌机
						enemy[k].y = rand() % Width;
						canvas[enemy[k].x][enemy[k].y] = 3;
						canvas[i][j] = 0;								// 子弹消失
					}
				}
				// 子弹向上移动
				canvas[i][j] = 0;//将子弹当前所处区域设为空白，并将其纵坐标减一，则可实现子弹向上的效果
				if (i > 0)//
					canvas[i - 1][j] = 2;
			}
		}
	}
	static int speed = 0;//静态局部变量speed
	//使得该变量在退出函数后，不会被销毁，因此再次调用该函数时，该变量的值与上次退出函数时值相同
	if (speed < EnemyMoveSpeed)//使updatewithoutinput运行EnemyMoveSpeed次，敌机才移动一次
		speed++;
	for (k = 0; k < EnemyNum; k++) {
		// 敌机撞到我机
		if ((position_x == enemy[k].x) && (position_y == enemy[k].y) 
			|| (position_x + 1 == enemy[k].x)&& (position_y - 1 == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y + 1 == enemy[k].y)
		        || (position_x + 2 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x)
		        && (position_y - 1 == enemy[k].y))
			//飞机占四个方格数据，任一方格坐标若与敌机坐标相同则视为撞机
		{
			printf("\n游戏结束!\n");
			Sleep(3000);//停止三秒钟
			system("pause");
			exit(0);
		}

		// 敌机跑出显示屏幕
		if (enemy[k].x > High) { //敌机纵坐标大于游戏画面的纵坐标
			canvas[enemy[k].x][enemy[k].y] = 0;
			enemy[k].x = rand() % 2; // 产生新的敌机
			enemy[k].y = rand() % Width;
			canvas[enemy[k].x][enemy[k].y] = 3;
			score--; // 减分
		}

		if (speed == EnemyMoveSpeed) { //经过EnemyMoveSpeed次循环，开始移动敌机坐标，宏观表示为敌机移动速度
			// 敌机下落
			for (k = 0; k < EnemyNum; k++) {
				canvas[enemy[k].x][enemy[k].y] = 0;//将敌机目前位置改为0，即改为空白区域
				enemy[k].x++;//增加飞机的纵坐标
				speed = 0;//归零速度
				canvas[enemy[k].x][enemy[k].y] = 3;//从而达到敌机移动的效果
			}

		}
	}

}

void updatewithinput() {
	char input;
	if (kbhit()) // 判断是否有输入,函数kbhit功能及返回值： 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
		//与getch()的区别：kbhit为非阻塞函数，不影响下一步进行
	{
		input = getch(); // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a' && position_y > 1 || input == 'A') {
			canvas[position_x][position_y] = 0;//将原来飞机所在区域设置为空白
			canvas[position_x + 1][position_y - 1] = 0;//将原来飞机所在区域设置为空白
			canvas[position_x + 1][position_y] = 0;//将原来飞机所在区域设置为空白
			canvas[position_x + 1][position_y + 1] = 0;//将原来飞机所在区域设置为空白
			position_y--; // 位置左移
			canvas[position_x][position_y] = 1;//将飞机数据重新写入
			canvas[position_x + 1][position_y - 1] = 1;//将飞机数据重新写入
			canvas[position_x + 1][position_y] = 1;//将飞机数据重新写入
			canvas[position_x + 1][position_y + 1] = 1;//将飞机数据重新写入
		}
		//下列操作同理
		else if (input == 'd' && position_y < Width - 2 || input == 'D') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_y++; // 位置右移
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == 'w' && position_x > 1 || input == 'W') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x--; // 位置上移
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == 's' && position_x < High - 3 || input == 'S') {
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x++; // 位置下移
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		} else if (input == ' ') { // 发射子弹
			int left = position_y - BulletWidth;//y实则为纵坐标，则此数据代表飞机所在纵坐标向左移动BulletWidth步后的坐标
			int right = position_y + BulletWidth;//此数据代表飞机所在纵坐标向右边动BulletWidth步后的坐标
			if (left < 0)//left最小不得小于0
				left = 0;
			if (right > Width - 1)//right最大不得超过width-1
				right = Width - 1;
			int k;
			for (k = left; k <= right; k++)		// 发射子弹 子弹的左侧右侧随机击杀数不断扩张，相当于打出更多子弹
				canvas[position_x - 1][k] = 2;	// 发射子弹的初始位置在飞机的正上方
		}
		else if (input == 'Z' || input == 'z') {	// 按Z存档
			FileWrite();//将游戏数据写入存档文件
			system("pause");
			exit(0);
		}
	}
}
// 存档代码
void FileWrite() {
	int i, j;
	FILE *fp;							// 创建文件指针
	fp = fopen("D:\\game.data", "w");	// 打开文件 "w": write写入文件
	if (fp == NULL) { //检测是否正常打开
		printf("Open file5.txt error");
	}
	for (i = 0; i < EnemyNum; i++) { //以字符形式逐个录入数据,此处为录入敌人数据
		fwrite(&enemy[i], sizeof(struct enemy), 1,
		       fp);//其中，参数 &enemy[i]是一个指向读入数据的存放地址，sizeof(struct enemy)指定读的单个数据大小，1
		//指定一共需要读多个 size 个字节的数据，fp 是指向包含二进制读方式打开的文件指针
	}
	fwrite(&position_x, sizeof(int), 1, fp);
	fwrite(&position_y, sizeof(int), 1, fp);
	fwrite(&score, sizeof(int), 1, fp);
	fwrite(&number, sizeof(int), 1, fp);
	fwrite(&BulletWidth, sizeof(int), 1, fp);
	fwrite(&EnemyMoveSpeed, sizeof(int), 1, fp);
	fclose(fp);  // 关闭文件
	printf("\n保存成功\n");
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
