#pragma warning (disable: 6011)
#pragma warning(disable : 4996)
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

/*******宏定义*******/
#define snake 64 //标题的snake的横坐标 
#define inity 11 //初始时蛇头的X坐标
#define initx 24 //初始时蛇头的y坐标

/*贪吃蛇的各种参数*/
typedef struct Snake
{
	int x; //列坐标 
	int y; //行坐标 
	struct Snake* Next; //指向下一个身体节点的指针 
}SNAKE, * PSNAKE;
int sta = 0; //用于检测按键状态
int score = 0; //得分（每吃一个食物得5分） 
PSNAKE pHead; //蛇链表的头指针
PSNAKE food; //食物的指针 
int flag = 0; //用于指示是否撞墙或撞到自己
int HighScore = 0; //存储最高分

/******函数声明******/
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
