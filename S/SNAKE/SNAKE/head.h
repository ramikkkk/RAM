#pragma warning (disable: 6011)
#pragma warning(disable : 4996)
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

/*******�궨��*******/
#define snake 64 //�����snake�ĺ����� 
#define inity 11 //��ʼʱ��ͷ��X����
#define initx 24 //��ʼʱ��ͷ��y����

/*̰���ߵĸ��ֲ���*/
typedef struct Snake
{
	int x; //������ 
	int y; //������ 
	struct Snake* Next; //ָ����һ������ڵ��ָ�� 
}SNAKE, * PSNAKE;
int sta = 0; //���ڼ�ⰴ��״̬
int score = 0; //�÷֣�ÿ��һ��ʳ���5�֣� 
PSNAKE pHead; //�������ͷָ��
PSNAKE food; //ʳ���ָ�� 
int flag = 0; //����ָʾ�Ƿ�ײǽ��ײ���Լ�
int HighScore = 0; //�洢��߷�

/******��������******/
void HideCursor();
void ShowCursor();
void gotoxy(int x, int y);
int changecolor(int a);
void startmenu_gametitle();
void startmenu_picture();
void startmenu_options();
void startmenu_choices(int a);
void instruction();
void startmenu();
void createmap();
void initsnake();
void createfood();
void keystatus();
bool movesnake();
void startourgame();
int cannotcrossthewall();
int cannotbiteyourself();
void gameover();
void write_file();
void read_file();
void highestscore();
