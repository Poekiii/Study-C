//三子棋测试

#include "C:\Users\poeki\Desktop\C-Test\test\tic-tac-toe-C\game.h"

void menu()
{
	printf("*************************\n");
	printf("**** 1.Play   0.Exit ****\n");
	printf("*************************\n");
}

//游戏实现逻辑
void game()
{
	//存放棋盘信息
	char board[ROW][COL] = {0}; 
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while(1)
	{
		//玩家先手
		PlayerDo(board, ROW, COL);
	    DisplayBoard(board, ROW, COL);

		//电脑后手
		ComputerDo(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));   //使用了rand需要先调用srand,srand只需要调用一次,所以用时间戳作为生成起点。
	do{
		menu();
		printf("请选择：\n");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 2:
				printf("退出游戏.\n");
				break;
			default:
				printf("选择错误，请重新输入！\n");
				break;
		}

	}while(input);
}


int main()
{
	test();
	return 0;
}