
#include "main.h"

int main(){

    //声明变量
    int choice = 0;
    //设置随机数的生成起点
    srand((unsigned int)time(NULL));
    
    //打印开始菜单（至少执行一次）
    do{
        //开始界面
        Menu();
        //开始游戏选择
        Start(choice);
        
    }while(choice);



    return 0;
}