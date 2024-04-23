/*
三子棋游戏的实现 
*/

#include "game.h"

void game(void){
    //声明变量
    char board[ROW][COL] = {0};
    int player_x = 0;
    int player_y = 0;
    int move_count = 0;
    int retWinner = 0;
    //初始化棋盘
    InitBoard(board,ROW,COL);
    //打印棋盘
    DisplayBoard(board,ROW,COL);

    //下棋过程
    while(1){
        //玩家下棋
        PlayerMove(board,ROW,COL,&player_x,&player_y);
        move_count++;
        //打印棋盘
        DisplayBoard(board,ROW,COL);
        //检测棋盘是否充满
        retWinner = checkWin(board,player_x,player_y);
        if(move_count == (ROW*COL) && retWinner == 0){
            printf("平局\n");
            break;
        }
        if(1 == retWinner){
            //检测胜利
            printf("恭喜玩家获胜\n");
            break;
        }
        


        //电脑下棋
        ComputerMove(board,ROW,COL,&player_x,&player_y);
        move_count++;
        //打印棋盘
        DisplayBoard(board,ROW,COL);
        //检测胜利
        retWinner = checkWin(board,player_x,player_y);
        if(move_count == (ROW*COL) && retWinner == 0){
            printf("平局\n");
            break;
        }
        if(1 == retWinner){
            printf("恭喜电脑获胜\n");
            break;
        }        

    }
}


//棋盘初始化函数
void InitBoard(char board[ROW][COL], int row, int col){

    int i = 0;
    int j = 0;

    for(i = 0; i < row; i++){

        for(j = 0; j < col; j++){
            board[i][j] = EMPTY;
        }
    }

}


//打印棋盘函数
void DisplayBoard(char board[ROW][COL], int row, int col){
    int i = 0;
    for(i = 0; i < row; i++){
        int j = 0;
        for(j = 0; j < col; j++){
            printf(" %c ",board[i][j]);
            if(j < col - 1){
                printf("|");
            }
        }
        printf("\n");

        //打印分割信息
        if(i < row - 1){

            int j = 0;
            for(j = 0; j < col; j++){
                printf("---");
                if(j < col - 1){
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

//玩家下棋的函数
void PlayerMove(char board[ROW][COL], int row, int col,int *x,int *y){



    printf("玩家下棋：\n");

    while(1){
        printf("请输入坐标：>");
        scanf("%d %d",x,y);
        //判断坐标是否合法
        if(*x >= 1 && *x <= row && *y >= 1 && *y <= col){
            //判断位置是否被占用
            if(board[*x-1][*y-1] == EMPTY){
                board[*x-1][*y-1] = Player_Symbols;
                break;
            }
            else{
                printf("位置被占用，请重新输入\n");
            }
        }
        else{
            printf("坐标非法，请重新输入\n");
        }
    }
}


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col, int *x, int *y){

    printf("电脑下棋：\n");
     while(1){
        //在%row和%col后，产生的正好的是小于等于行和列的个数的
        *x = rand()%row+1;
        *y = rand()%col+1;
        //判断位置是否被占用
        if(board[*x-1][*y-1] == EMPTY){
            board[*x-1][*y-1] = Computer_Symbols;
            break;
        }
    } 
}

//检测是否获胜函数
int checkWin(char board[ROW][COL], int player_x, int player_y){
    char player = board[player_x-1][player_y-1];
    int directions[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};
    //向四个方向配对寻找
    for (int d = 0; d < 4; d++) {
        int count = 1;
        int dirx = directions[d][0];
        int diry = directions[d][1];
        int r, c;

        r = player_x-1 + dirx; c = player_y-1 + diry;
        while (r >= 0 && r < ROW && c >= 0 && c < COL && board[r][c] == player) {
            count++;
            r += dirx;
            c += diry;
        }

        r = player_x-1 - dirx; c = player_y-1 - diry;
        while (r >= 0 && r < ROW && c >= 0 && c < COL && board[r][c] == player) {
            count++;
            r -= dirx;
            c -= diry;
        }

        if (count >= WinEvent) return 1;
    }
    return 0;
}


