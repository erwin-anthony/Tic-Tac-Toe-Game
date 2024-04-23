#ifndef _GAME_H
#define _GAME_H

#include "main.h"
#include "math.h"
#define ROW         3
#define COL         3
#define WinEvent    3
#define EMPTY              ' '
#define Player_Symbols     '*'
#define Computer_Symbols   '#'

//game函数
void game(void);


//棋盘初始化
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col,int *x,int *y);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col, int *x, int *y);

//检测是否获胜函数
int checkWin(char board[ROW][COL], int player_x, int player_y);






#endif /*_GAME_H*/