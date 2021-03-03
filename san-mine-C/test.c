#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0,j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0,j = 0;
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ",i);
	}
		printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}	

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while(count)
	{
		int x = rand()%row +1; //1-9 
		int y = rand()%col +1; //1-9 
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count --;
		}
	}

}

//'1' - '0' =1  字符相减等于ASCII表中的十进制(数字)相减

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	
	return mine[x - 1][y + 1] +
	mine[x - 1][y] +
	mine[x - 1][y - 1] +
	mine[x][y + 1] +
	mine[x][y - 1] +
	mine[x + 1][y + 1] +
	mine[x + 1 ][y] +
	mine[x + 1 ][y - 1] - 8 * '0';
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0,y = 0;
	int count = 0; //存放周围雷的个数
	int win = 0;
	//9*9 - 10 = 71
	while(win < row*col - EASY_COUNT)
	{
		printf("请输入排除雷的坐标:>");
		scanf("%d%d", &x, &y);
		//判断合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断是否为雷
			if (mine[x][y] == '1')
			{
				//踩雷了
				printf("你被炸死了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//没踩雷,计算周围雷的个数
				count = get_mine_count(mine, x ,y);
				show[x][y] = count + '0'; //+'0' 是关键
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法！\n");
		}
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你排雷成功！\n");
		DisplayBoard(mine, row, col);
	}
}


void menu()
{
	printf("******************\n");
	printf("**1. play 0.exit**\n");
	printf("******************\n");

}

void game()
{
	//雷的信息储存
	//1.布置雷的信息
	char mine[ROWS][COLS] = {0};
	//2.排除雷的信息，给用户展示的信息
	char show[ROWS][COLS] = {0};
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误！\n");
				break;
		}
	}while(input);
}



int main()
{
	test();
	return 0;
}