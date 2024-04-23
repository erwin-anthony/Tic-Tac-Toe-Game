/* 
这是一个开始界面
 */

#include "menu.h"

void Menu(void){

    printf("*****************************\n");
    printf("*****   1.Play 0.Exit   *****\n");
    printf("*****************************\n");

}

void Start(int choice){


        printf("请选择：-->\n");
        scanf("%d",&choice);
        //判断是否进行游戏
        switch(choice){
            case 1:
                printf("三子棋游戏开始\n");
                game(); 
                break;
            case 0:
                printf("游戏结束，谢谢游玩\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }    

}