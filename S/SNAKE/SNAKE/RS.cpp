#include"head.h"

int main()
{
	startmenu();

	return 0;
}

/*���ع�꺯��*/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

/*��ʾ��꺯��*/
void ShowCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = TRUE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

/*���ƹ��λ�ã�����ָ����ӡλ�ã�*/
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*�ı�������ɫ��������ɫ�����ʮ������ɫ���ձ�*/
int changecolor(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	return 0;
}

/*�������ϼ�ⰴ��״̬�Խ��벻ͬ��ѡ����*/
void startmenu_choices(int a) //aΪ������(15,17,19,21),ע�⿪ʼʱ��걾��������startgameǰ��� 
{

	int ch = getch();
	//���ƹ����ƶ�
	while (ch != 0x0d || ch == 0xE0) //������»س���������ѭ�� 
	//0x0d��ʾ�س���0XE0��ʾ�������ҵȼ��ļ��� 
	{
		//���ж����ĸ���
		ch = getch(); //���ǧ��Ҫ���ˣ��� 
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

/*��Ϸ���⣨��ʼ���棩*/
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

/*��ʼ����ͼ�����������ֵĲ���*/
void startmenu_picture()
{
	gotoxy(3, 13);
	changecolor(11);
	printf("Ram������̰���ߵĹ���......");
	//	gotoxy(5,14);

		//��������һ�������� 
}

/*�˵�ѡ����*/
void startmenu_options()
{
	changecolor(9);
	gotoxy(5, 15);
	printf("��Start Game\n");
	gotoxy(5, 17);
	printf("��Instruction\n");
	gotoxy(5, 19);
	printf("��Highest Score\n");
	gotoxy(5, 21);
	printf("��Exit Game\n");
	gotoxy(5, 15); //�����ʼλ�� 
	startmenu_choices(15);
}

/*���˵������ĺ���*/
void startmenu()
{
	ShowCursor();
	flag = 0;
	char chCmd[32];   //���������ڿ��� ���˵� ���ڴ�С 
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 117, 31);
	system(chCmd);
	read_file(); //��ȡ��߷�
	startmenu_gametitle();
	startmenu_picture();
	startmenu_options();
}

/*��Ϸ˵��������*/
void instruction()
{
	system("cls");
	changecolor(3);
	printf("----------------------Hi,Snake!~o(*= ��=*)��----------------------\n"); //�ϱ߿�
	gotoxy(0, 17);
	changecolor(3);
	printf("------------------------------------------------------------------\n"); //�±߿� 
	gotoxy(2, 2);
	changecolor(14);
	printf("�� ����˵�� ��\n");
	gotoxy(2, 4);
	changecolor(3);
	printf("���������������ֱ����̰�������ϡ��¡������ƶ�\n");
	gotoxy(2, 6);
	printf("�����ո����ͣ��Ϸ\n");
	gotoxy(2, 8);
	printf("����ESC������Ϸ��;�˳���Ϸ\n");
	changecolor(14);
	gotoxy(2, 10);
	printf("�� ��Ϸ���� ��\n");
	gotoxy(2, 12);
	changecolor(3);
	printf("���ʳ��򵥣�ֻҪ��ײ���Լ���ײ��ǽ�����ˣ�Ц��\n");
	//����һ�����س����������˵�
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

/*��Ϸ���岿������*/
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

/*���ص�ͼ*/
void createmap()
{
	HideCursor();
	system("cls");
	char chCmd[32];   //���������ڿ��� ���˵� ���ڴ�С 
	sprintf_s(chCmd, "mode con cols=%d lines=%d", 51, 26);
	system(chCmd);
	int i, j;
	changecolor(5);
	for (i = 0; i < 49; i += 2)  //���������߿� 
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, 24);
		printf("��");
	}
	for (i = 1; i < 25; i++) //���ұ߿� 
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(48, i);
		printf("��");
	}
	changecolor(11);
	for (i = 1; i < 24; i++) //�������� 
	{
		for (j = 2; j < 48; j += 2)
		{
			gotoxy(j, i);
			printf("��");
		}
		printf("\n");
	}
	printf("\n");
}

/*��ʼ������*/
void initsnake()
{
	pHead = (PSNAKE)malloc(sizeof(SNAKE)); //ͷ�ڵ�
	PSNAKE pTail = (PSNAKE)malloc(sizeof(SNAKE)); //β�ڵ� 

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
				isnake->x = val;  //����ڷų�ʼ״̬���� 
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
		printf("��");
		p = p->Next;

		while (p != NULL) //�ڵ�ͼ�ĳ�ʼλ�������ʼ������ 
		{
			changecolor(5);
			gotoxy(p->x, p->y);
			printf("��");
			p = p->Next;
		}
	}
}

/*�ڵ�ͼ���������ʳ�����ͷ�Ե�ʳ����ٴ�ִ�иú���*/
void createfood()
{
	srand((unsigned)time(NULL));
	PSNAKE ffood = (PSNAKE)malloc(sizeof(SNAKE));
	food = (PSNAKE)malloc(sizeof(SNAKE));
	if (ffood != NULL && food != NULL)
	{
		int we = rand() % 46 + 2;
		while (we % 2 == 1) //2<= x <=46�������������Ϊż����ʳ��͸��Ӷ�ռ�����ַ���
			we = rand() % 46 + 2;
		ffood->x = we;
		ffood->y = rand() % 23 + 1; //1<= y <=23
		PSNAKE p = (PSNAKE)malloc(sizeof(SNAKE));
		p = pHead->Next;
		//���������ʳ���ʱ��ʳ�ﲻ�����ߵ������غ� 
		while (p != NULL)
		{
			if (p->x == ffood->x && p->y == ffood->y) //���غϣ����ͷŸ�ʳ��ռ䲢��������һ��ʳ�� 
			{
				free(ffood);
				ffood = NULL;
				createfood();
			}
			p = p->Next;
		}
		// ���δ�غϣ���˵����ʳ�����ɳɹ�������ʳ���ӡ�ڵ�ͼ��
		food = ffood;
		changecolor(4);
		gotoxy(food->x, food->y);
		printf("��");
		changecolor(5);
	}
}

/*�����Ϸ�����и�������״̬*/
void keystatus()
{
	sta = 4; //��ʼ��������
	while (1) //��ѭ�����ܱ�֤�������µ�ʱ������жϲ�����movesnake����
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
		if (GetAsyncKeyState(VK_SPACE)) //���ո����ͣ
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE)) //�ٴμ�⵽�ո����ʱ��ͻָ�ԭ��Ϸ״̬
					break;
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE)) //��esc��ֱ�Ӵ���Ϸʱ��״̬�˻ص����˵�����
		{
			system("cls");
			startmenu();
			break; //��⵽�˳�->�˳�����ѭ�� 
		}
		if (movesnake() == false)
		{
			gameover();
			break;
		}
	}
}

/*�������Ҽ������ߵ��˶���ע���ߵ��������������ַ����ȵ��ַ���ɵģ����궼������Ϊ��׼��*/
bool movesnake()
{
	HideCursor();
	PSNAKE qq = (PSNAKE)malloc(sizeof(SNAKE));        //�ƶ����̵�Ч�ڲ���һ���½ڵ㣨������ԭ����ͷ��������ϱ仯�� 
	PSNAKE pp = (PSNAKE)malloc(sizeof(SNAKE));         //��ͬʱȥ��β�ڵ㣨�½ڵ�ʹ��ͷ�巨��
	pp = pHead->Next; //pp�ݴ���ͷ�ĵ�ַ 
	if (sta == 1) //������                       
	{
		qq->x = pp->x;
		qq->y = pp->y - 1; //�������һ 
		qq->Next = pp; //ԭ������ͷ��Ϊ�ڶ����ڵ� 
		pHead->Next = qq; //ͷ�ڵ������¿��ڵ�ĵ�ַ���½ڵ��Ϊ��ͷ 
		PSNAKE a = (PSNAKE)malloc(sizeof(SNAKE));
		a = pHead->Next; //aΪ��ͷ
		if (cannotbiteyourself() == 1 || cannotcrossthewall() == 1) //���ײ��ǽ��ײ���Լ�
			return false;
		else
		{
			if (a->x == food->x && a->y == food->y)//�������������һ��������һ��������ʳ��
			{
				//β�ڵ���Ȼ�� ��
				gotoxy(a->x, a->y);
				printf("��");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				Sleep(200);   //������ӡʱ���õģ�ͬʱҲ�Ǽ����ߵ��ٶ��õģ�
				createfood();
				score += 5;
			}
			else //���û������ʳ���ӡβ�ڵ�ʱ��� ��
			{
				gotoxy(a->x, a->y);
				printf("��");
				a = a->Next;
				while (a->Next->Next != NULL)
				{ //�����a�ǵ����ڶ����ڵ�ĵ�ַ
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("��");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;         //b�����һ���ڵ�ĵ�ַ
				a->Next = NULL;      //a��ָ����Ϊ�գ������ڶ����ڵ��Ϊβ�ڵ�
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("��");
				free(b);
				b = NULL;
				changecolor(5);
				Sleep(200);
			}
			return true;
		}
	}
	if (sta == 2) //������
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
				printf("��");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("��");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("��");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("��");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
	if (sta == 3) //������
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
				printf("��");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("��");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("��");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("��");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
	if (sta == 4) //���� 
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
				printf("��");
				a = a->Next;
				while (a != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				Sleep(200);
				createfood();
				score += 5;
			}
			else
			{
				gotoxy(a->x, a->y);
				printf("��");
				a = a->Next;
				while (a->Next->Next != NULL)
				{
					gotoxy(a->x, a->y);
					printf("��");
					a = a->Next;
				}
				gotoxy(a->x, a->y);
				printf("��");
				PSNAKE b = (PSNAKE)malloc(sizeof(SNAKE));
				b = a->Next;
				a->Next = NULL;
				changecolor(11);
				gotoxy(b->x, b->y);
				printf("��");
				free(b);
				b = NULL;
				Sleep(200);
				changecolor(5);
			}
			return true;
		}
	}
}

/*����ײǽ*/
int cannotcrossthewall()
{
	if (pHead->Next->x == 0 || pHead->Next->x == 50 || pHead->Next->y == 0 || pHead->Next->y == 26)
		flag = 1;
	return flag;
}

/*����ײ���Լ�*/
int cannotbiteyourself()
{
	PSNAKE bite = (PSNAKE)malloc(sizeof(SNAKE));
	bite = pHead->Next->Next;    //bite�ӵڶ����ڵ㿪ʼ�ж�
	while (bite != NULL)
	{
		if (bite->x == pHead->Next->x && bite->y == pHead->Next->y)
			flag = 1;
		bite = bite->Next;
	}
	return flag;
}

/*��Ϸ��������*/
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
	printf(" |     ��     |   ---�����ĺòҰ�������(�����`)    \n");
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

/*��ȡ��߷�*/
void read_file()
{
	FILE* fp;
	fp = fopen("saveeeee.txt", "a+");       //���ļ�save.txt
	fscanf(fp, "%d", &HighScore);       //���ļ��е���߷ֶ�����
	fclose(fp);                         //�ر��ļ�
}

/*��¼��߷�*/
void write_file()
{
	FILE* fp;
	fp = fopen("saveeeee.txt", "w+");       //�Զ�д�ķ�ʽ����һ����Ϊsave.txt���ļ�
	fprintf(fp, "%d", score);           //�ѷ���д���ļ���
	fclose(fp);
}

/*�鿴��߷�*/
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