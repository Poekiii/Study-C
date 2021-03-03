#include "C:\Users\poeki\Desktop\C-Test\test\tic-tac-toe-C\game.h"

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}


//-0-|   |      子和分割列
//---|---|---   分割行
//   |   |   
//---|---|---
//   |   |   


void DisplayBoard(char board [ROW][COL],int row,int col)
{
	int i = 0,j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			   printf(" %c |", board[i][j]);
			else
			   printf(" %c \n", board[i][j]);
		}
		if (i < row - 1)
			printf("---|");
		else
			printf("---\n", board[i][j]);
	}
}

void PlayerDo(char board [ROW][COL],int row,int col)
{
	int x = 0, y = 0;
	printf("玩家走:>\n");
    while (1)
    {
    	printf("请输入坐标:>\n");
		scanf("%d%d", &x , &y);
	    //判断合法性
		if( x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if(board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用！\n");
			}
		}
		else
		{
			printf("坐标非法！\n");
		}
    }
}

void ComputerDo(char board [ROW][COL],int row,int col)
{
	int x = 0, y = 0;
	printf("电脑走:>\n");
    
    while(1)
    {
		x = rand() % row;  //生成 0 - row 的随机数
		y = rand() % col;

		if(board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
    }
}

