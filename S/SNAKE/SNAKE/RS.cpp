#include"head.h"

int main()
{
	startmenu();

	return 0;
}

/*隐藏光标函数*/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

/*显示光标函数*/
void ShowCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = TRUE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

/*控制光标位置（方便指定打印位置）*/
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*改变字体颜色（具体颜色请参照十进制颜色对照表）*/
int changecolor(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	return 0;
}

/*主界面上检测按键状态以进入不同的选项中*/
void startmenu_choices(int a) //a为行坐标(15,17,19,21),注意开始时光标本来就是在startgame前面的 
{

	int ch = getch();
	//控制光标的移动
	while (ch != 0x0d || ch == 0xE0) //如果按下回车，则跳出循环 
	//0x0d表示回车，0XE0表示上下左右等键的键码 
	{
		//再判断是哪个键
		ch = getch(); //这句千万不要掉了！！ 
		if (ch == 0x48 && a > 15)
		{
			a -= 2;
			gotoxy(5, a);
		}
		if (ch == 0x50 && a < 21)
		{
			a += 2;
			gotoxy(5, a);
		}
	}
	switch (a)
	{
	case 15: startourgame(); break;
	case 17: instruction(); break;
	case 19: highestscore(); break;
	case 21: gotoxy(2, 25);  exit(0); break;
	}
}

/*游戏标题（开始界面）*/
void startmenu_gametitle()
{
	changecolor(11);
	printf("                                                                 \n");
	printf("   @ @@@@@@@                                                     \n");
	printf(" @@@@@@@@@@@@                                                    \n");
	printf("  @@@    @@@@@                                                   \n");
	printf("  @@@     @@@@                                                   \n");
	printf("  @@@    @@@@      @@@@@@@ @     @ @@@@@   @@@@@@                \n");
	printf("  @@@@@@@@@@     @ @@@@@@@@@@     @@@@@@@ @ @@@@@@@     @@@      \n");
	printf("  @@@@ @@@@     @@@      @@@     @@@    @@@@    @@@@   @   @     \n");
	printf("  @@@   @@@@   @@@       @@@@    @@@     @@@     @@@    @@@  @   \n");
	printf("  @@@    @@@@  @@@       @@@@    @@@     @@@     @@@   @   @@    \n");
	printf("  @@@     @@@@  @@@@     @@ @@   @@@     @@@     @@@  @@   @ @@  \n");
	printf(" @@@@@     @@@@@  @@@@@@@   @@@@ @@@    @@@@@    @@@@  @@@@   @@@\n");

	gotoxy(snake, 2);
	changecolor(14);
	printf("               @ @@@@@@                           \n");
	gotoxy(snake, 3);
	printf("             @          @                         \n");
	gotoxy(snake, 4);
	printf("            @            @                        \n");
	gotoxy(snake, 5);
	printf("           @     @@@@  ## @                       \n");
	gotoxy(snake, 6);
	printf("           @    @@   @    @                       \n");
	gotoxy(snake, 7);
	printf("           @     @@   @@@@                        \n");
	gotoxy(snake, 8);
	printf("            @      @@                             \n");
	gotoxy(snake, 9);
	printf("              @      @@                           \n");
	gotoxy(snake, 10);
	printf("               @      @@                          \n");
	gotoxy(snake, 11);
	printf("  @@@@@@       @     @@                           \n");
	gotoxy(snake, 12);
	printf(" @      @@@     @     @@                          \n");
	gotoxy(snake, 13);
	printf("@     @@       @      @ @@@@@@    @    @   @ @@@@@\n");
	gotoxy(snake, 14);
	printf("@      @@@@@ @       @  @    @   @ @   @  @  @    \n");
	gotoxy(snake, 15);
	printf(" @                 @@   @    @  @@@@@  @@    @@@@ \n");
	gotoxy(snake, 16);
	printf("  @              @@     @    @ @     @ @  @  @    \n");
	gotoxy(snake, 17);
	printf("     @ @@@@@@@@@        @    @@       @@   @ @@@@@\n");
}

/*开始界面图画和其他文字的部分*/
void startmenu_picture()
{
	gotoxy(3, 13);
	changecolor(11);
	printf("Ram和他的贪吃蛇的故事......");
	//	gotoxy(5,14);

		//补充在另一个程序里 
}

/*菜单选择项*/
void startmenu_options()
{
	changecolor(9);
	gotoxy(5, 15);
	printf("◆Start Game\n");
	gotoxy(5, 17);
	printf("◆Instruction\n");
	gotoxy(5, 19);
	printf("◆Highest Score\n");
	gotoxy(5, 21);
	printf("◆Exit Game\n");
	gotoxy(5, 15); //光标起始位置 
	startmenu_choices(15);
}

/*主菜单函数的合体*/
void startmenu()
{
	ShowCursor();
	flag = 0;
	char chCmd[32];   //这三行用于控制 主菜单 窗口大小 
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 117, 31);
	system(chCmd);
	read_file(); //读取最高分
	startmenu_gametitle();
	startmenu_picture();
	startmenu_options();
}

/*游戏说明及规则*/
void instruction()
{
	system("cls");
	changecolor(3);
	printf("----------------------Hi,Snake!~o(*= ▽=*)ブ----------------------\n"); //上边框
	gotoxy(0, 17);
	changecolor(3);
	printf("------------------------------------------------------------------\n"); //下边框 
	gotoxy(2, 2);
	changecolor(14);
	printf("◇ 操作说明 ◇\n");
	gotoxy(2, 4);
	changecolor(3);
	printf("※按↑↓←→键分别控制贪吃蛇向上、下、左、右移动\n");
	gotoxy(2, 6);
	printf("※按空格键暂停游戏\n");
	gotoxy(2, 8);
	printf("※按ESC键于游戏中途退出游戏\n");
	changecolor(14);
	gotoxy(2, 10);
	printf("◇ 游戏规则 ◇\n");
	gotoxy(2, 12);
	changecolor(3);
	printf("※肥肠简单，只要不撞到自己或撞到墙就行了（笑）\n");
	//增加一个按回车键返回主菜单
	gotoxy(1, 16);
	printf("Press space back to the menu......");
	gotoxy(35, 16);
	int cha = getch();
	while (cha == 0x0d)
	{
		system("cls");
		startmenu();
	}
}

/*游戏主体部分整合*/
void startourgame()
{
	createmap();
	initsnake();
	Sleep(100);
	createfood();
	keystatus();
	write_file();
	score = 0;
}

/*加载地图*/
void createmap()
{
	HideCursor();
	system("cls");
	char chCmd[32];   //这三行用于控制 主菜单 窗口大小 
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 51, 26);
	system(chCmd);
	int i, j;
	changecolor(5);
	for (i = 0; i < 49; i += 2)  //上下两个边框 
	{
		gotoxy(i, 0);
		printf("〓");
		gotoxy(i, 24);
		printf("〓");
	}
	for (i = 1; i < 25; i++) //左右边框 
	{
		gotoxy(0, i);
		printf("〓");
		gotoxy(48, i);
		printf("〓");
	}
	changecolor(11);
	for (i = 1; i < 24; i++) //控制行数 
	{
		for (j = 2; j < 48; j += 2)
		{
			gotoxy(j, i);
			printf("■");
		}
		printf("\n");
	}
	printf("\n");
}

/*初始化蛇身*/
void initsnake()
{
	pHead = (PSNAKE)malloc(sizeof(SNAKE)); //头节点
	PSNAKE pTail = (PSNAKE)malloc(sizeof(SNAKE)); //尾节点 

	pTail = pHead;
	if (pTail != NULL && pHead != NULL)
	{
		pHead->Next = NULL;
		int i, val = initx;
		for (i = 0; i < 4; i++)
		{
			PSNAKE isnake = (PSNAKE)malloc(sizeof(SNAKE));
			if (isnake != NULL)
			{
				isnake->x = val;  //横向摆放初始状态的蛇 
				isnake->y = inity;
				val -= 2;
				pTail->Next = isnake;
				isnake->Next = NULL;
				pTail = isnake;
			}
		}
		PSNAKE p = pHead->Next;
		gotoxy(p->x, p->y);
		changecolor(5);
		printf("●");
		p = p->Next;

		while (p != NULL) //在地图的初始位置输出初始化的蛇 
		{
			changecolor(5);
			gotoxy(p->x, p->y);
			printf("◆");
			p = p->Next;
		}
	}
}

/*在地图上随机产生食物，在蛇头吃到食物后再次执行该函数*/
void createfood()
{
	srand((unsigned)time(NULL));
	PSNAKE ffood = (PSNAKE)malloc(sizeof(SNAKE));
	food = (PSNAKE)malloc(sizeof(SNAKE));
	if (ffood != NULL && food != NULL)
	{
		int we = rand() % 46 + 2;
		while (we % 2 == 1) //2<= x <=46，且列坐标必须为偶数（食物和格子都占两个字符）
			we = rand() % 46 + 2;
		ffood->x = we;
		ffood->y = rand() % 23 + 1; //1<= y <=23
		PSNAKE p = (PSNAKE)malloc(sizeof(SNAKE));
		p = pHead->Next;
		//在随机出现食物的时候，食物不能与蛇的身体重合 
		while (p != NULL)
		{
			if (p->x == ffood->x && p->y == ffood->y) //若重合，则释放该食物空间并重新生成一个食物 
			{
				free(ffood);
				ffood = NULL;
				createfood();
			}
			p = p->Next;
		}
		// 如果未重合，则说明该食物生成成功，并将食物打印在地图上
		food = ffood;
		changecolor(4);
		gotoxy(food->x, food->y);
		printf("●");
		changecolor(5);
	}
}

/*检测游戏过程中各个键的状态*/
void keystatus()
{
	sta = 4; //初始蛇向右走
	while (1) //死循环，能保证按键按下的时候进行判断并进入movesnake函数
	{
		if (GetAsyncKeyState(VK_UP) && sta != 2)
			sta = 1;
		else
		{
			if (GetAsyncKeyState(VK_DOWN) && sta != 1)
				sta = 2;
			else
			{
				if (GetAsyncKeyState(VK_LEFT) && sta != 4)
					sta = 3;
				else
				{
					if ((GetAsyncKeyState(VK_RIGHT) && sta != 3))
						sta = 4;
				}
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) //按空格键暂停
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE)) //再次检测到空格键的时候就恢复原游戏状态
					break;
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE)) //按esc键直接从游戏时的状态退回到主菜单界面
		{
			system("cls");
			startmenu();
			break; //检测到退出->退出该死循环 
		}
		if (movesnake() == false)
		{
			gameover();
			break;
		}
	}
}

/*上下左右键控制蛇的运动（注意蛇的身体是由两个字符长度的字符组成的，坐标都是以左为基准）*/
bool movesnake()
{
	HideCursor();
	PSNAKE qq = (PSNAKE)malloc(sizeof(SNAKE));        //移动过程等效于产生一个新节点（坐标在原来蛇头坐标基础上变化） 
	PSNAKE pp = (PSNAKE)malloc(sizeof(SNAKE));         //并同时去掉尾节点（新节点使用头插法）
	pp = pHead->Next; //pp暂存蛇头的地址 
	if (sta == 1) //向上走                       
	{
		qq->x = pp->x;
		qq->y = pp->y - 1; //行坐标减一 
		qq->Next = pp; //原来的蛇头成为第二个节点 
		pHead->Next = qq; //头节点存这个新开节点的地址，新节点成为蛇头 
		PSNAKE a = (PSNAKE)malloc(sizeof(SNAKE));
		a = pHead->Next; //a为蛇头
		if (cannotbiteyourself() == 1 || cannotcrossthewall() == 1) //如果撞了墙或撞到自己
			return false;
		else
		{
			if (a->x == food->x && a->y == food->y)//如果蛇向上走了一步，且这一步遇到了食物
			{
				//尾节点仍然是 ◆
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				Sleep(200);   //减慢打印时间用的（同时也是减慢蛇的速度用的）
				createfood();
				score += 5;
			}
			else //如果没有碰到食物，打印尾节点时变成 ■
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a->Next->Next != NULL)
				{ //最后那a是倒数第二个节点的地址
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("◆");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;         //b存最后一个节点的地址
				a->Next = NULL;      //a的指针域为空，倒数第二个节点成为尾节点
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("■");
				free(b);
				b = NULL;
				changecolor(5);
				Sleep(200);
			}
			return true;
		}
	}
	if (sta == 2) //向下走
	{
		qq->x = pp->x;
		qq->y = pp->y + 1;
		qq->Next = pp;
		pHead->Next = qq;
		PSNAKE a = (PSNAKE)malloc(sizeof(SNAKE));
		a = pHead->Next;
		if (cannotbiteyourself() == 1 || cannotcrossthewall() == 1)
			return false;
		else
		{
			if (a->x == food->x && a->y == food->y)
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("◆");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("■");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
	if (sta == 3) //向左走
	{
		qq->x = pp->x - 2;
		qq->y = pp->y;
		qq->Next = pp;
		pHead->Next = qq;
		PSNAKE a = (PSNAKE)malloc(sizeof(SNAKE));
		a = pHead->Next;
		if (cannotbiteyourself() == 1 || cannotcrossthewall() == 1)
			return false;
		else
		{
			if (a->x == food->x && a->y == food->y)
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("◆");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("■");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
	if (sta == 4) //向右 
	{
		qq->x = pp->x + 2;
		qq->y = pp->y;
		qq->Next = pp;
		pHead->Next = qq;
		PSNAKE a = (PSNAKE)malloc(sizeof(SNAKE));
		a = pHead->Next;
		if (cannotbiteyourself() == 1 || cannotcrossthewall() == 1)
			return false;
		else
		{
			if (a->x == food->x && a->y == food->y)
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("●");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("◆");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("◆");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("■");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
}

/*不能撞墙*/
int cannotcrossthewall()
{
	if (pHead->Next->x == 0 || pHead->Next->x == 50 || pHead->Next->y == 0 || pHead->Next->y == 26)
		flag = 1;
	return flag;
}

/*不能撞到自己*/
int cannotbiteyourself()
{
	PSNAKE bite = (PSNAKE)malloc(sizeof(SNAKE));
	bite = pHead->Next->Next;    //bite从第二个节点开始判断
	while (bite != NULL)
	{
		if (bite->x == pHead->Next->x && bite->y == pHead->Next->y)
			flag = 1;
		bite = bite->Next;
	}
	return flag;
}

/*游戏结束画面*/
void gameover()
{
	if (score > HighScore)
		write_file();
	system("cls");
	changecolor(11);
	char chCmd[32];
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 60, 25);
	system(chCmd);
	gotoxy(5, 5);
	printf("  /\\________/\\\n");
	gotoxy(5, 6);
	printf(" |   Q    Q   |\n");
	gotoxy(5, 7);
	printf(" |     ⌒     |   ---你死的好惨啊呜呜呜(；′⌒`)    \n");
	gotoxy(5, 8);
	printf(" |            |\n");
	gotoxy(5, 9);
	printf(" \\____________/              \n");
	gotoxy(5, 10);
	printf("                                        \n");
	gotoxy(5, 11);
	changecolor(9);
	printf("  Your score is %d      \n", score);
	gotoxy(5, 12);
	printf("Highest score : %d    \n", HighScore);
	gotoxy(1, 15);
	printf("Press space back to the menu......");
	gotoxy(35, 15);
	getchar();
	system("cls");
	startmenu();
}

/*读取最高分*/
void read_file()
{
	FILE* fp;
	fp = fopen("saveeeee.txt", "a+");       //打开文件save.txt
	fscanf(fp, "%d", &HighScore);       //把文件中的最高分读出来
	fclose(fp);                         //关闭文件
}

/*记录最高分*/
void write_file()
{
	FILE* fp;
	fp = fopen("saveeeee.txt", "w+");       //以读写的方式建立一个名为save.txt的文件
	fprintf(fp, "%d", score);           //把分数写进文件中
	fclose(fp);
}

/*查看最高分*/
void highestscore()
{
	system("cls");
	char chCmd[32];
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 50, 25);
	system(chCmd);
	changecolor(14);
	gotoxy(5, 5);
	printf("Your highest score is %d.\n\n", HighScore);
	gotoxy(1, 9);
	printf("Press space back to the menu......");
	gotoxy(35, 9);
	int cha = getch();
	while (cha == 0x0d)
	{
		system("cls");
		startmenu();
	}
}