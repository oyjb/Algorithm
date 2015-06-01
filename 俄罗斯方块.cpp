/*游戏规则如下：
每次消除后得到的分数为消除的行数的平方，比如：一次消除1行得到1分，两行得4分
等级随着消除的行数的增加而增加，比如：原来等级为X，一次性消除Y行，则等级变为X+Y；
下落时间随等级(开始等级为1)的升高而变短，具体为1000.0除以等级(时间为double型），比如：等级为2，则停留时间为500ms;*/
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
//#include <conio.h>
#include <cstdio>
#include <iomanip>
#include <time.h>
//#include <windows.h>
using namespace std;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
void gotoxy(HANDLE hout, const int X, const int Y)
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(hout,coord);
}
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
    SetConsoleTextAttribute(hout, bg_color*16+fg_color);
}
void basic_structure()
{
    setcolor(hout,0,13);
    cout<<"简单游戏规则:上为翻转，左右移动，下为加速"<<endl;
    cout<<"每次消去X行，则等级加X，分数加X的平方,下降速度提高";
    setcolor(hout,0,11);
    gotoxy(hout,2,10);
    cout<<"SCORE";
    gotoxy(hout,2,20);
    cout<<"LEVEL";
    gotoxy(hout,50,10);
    cout<<"NEXT";
    gotoxy(hout,20,3);
    cout<<"制作者：李文";
    setcolor(hout,0,9);
    gotoxy(hout,3,11);
    cout<<"0";
    gotoxy(hout,3,21);
    cout<<"1";
    setcolor(hout,0,10);
    gotoxy(hout,13,5);
    cout<<"┏━━━━━━━━━━━━━┓";
    int i;
    for(i=0;i<23;i++){
        gotoxy(hout,13,6+i);
        cout<<"┃                          ┃";
    }
    gotoxy(hout,13,29);
    cout<<"┗━━━━━━━━━━━━━┛"<<endl;
}
const int coord[28][4][4]=
{{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
 {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},{1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
 {0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0},{1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
 {0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0},{1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
 {0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0},{0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0},{1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0},{1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
 {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},//这一行的三个和第一个形状一样
 {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},{1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
 {0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0},{1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0}};
int xy[23][13]={0},color[23][13]={0},level=1,score=0,shape_num1,shape_num2,color1,color2,square_x,square_y,i,k;
char key1,key2;
void print_next(int n,int c)
{
    for(i=0;i<4;i++){
        gotoxy(hout,50,12+i);
        for(k=0;k<4;k++){
            if(coord[n][i][k]){
                setcolor(hout,0,c);
                cout<<"◎";
            }
            else{
                setcolor(hout,0,0);
                cout<<"  ";
            }
        }
    }
}
void left(int s,int c)
{
    for(i=0;i<4;i++){
        for(k=0;k<4;k++){
            if(coord[s][i][k]){
                if(square_y+k==0||xy[square_x+i][square_y+k-1])
                    goto L;
                break;
            }
        }
    }
   //可以左移
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=0;
                color[square_x+i][square_y+k]=0;
            }
    square_y-=1;
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=1;
                color[square_x+i][square_y+k]=c;
            }
   L://不能移动
       ;
}
void right(int s,int c)
{
    for(i=0;i<4;i++){
        for(k=3;k>=0;k--){
            if(coord[s][i][k]){
                if(square_y+k==12||xy[square_x+i][square_y+k+1])
                    goto L;
                break;
            }
        }
    }
   //可以右移
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=0;
                color[square_x+i][square_y+k]=0;
            }
    square_y+=1;
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                 xy[square_x+i][square_y+k]=1;
                 color[square_x+i][square_y+k]=c;
            }
   L://不能移动
       ;
}
int up(int &s,int c)
{
    if(s==1||s==3||s==5||s==7||s==8||s==9||s==11||s==12||s==13||s==15||s==16||s==17||s==22||s==24||s==26){
        for(i=0;i<4;i++)
            for(k=0;k<4;k++)
                if(coord[s][i][k]==0&&coord[s+1][i][k]==1){
                    if(xy[square_x+i][square_y+k])
                        return 0;
                }
        //可以翻转
        for(i=0;i<4;i++)
            for(k=0;k<4;k++){
                if(coord[s][i][k]==0&&coord[s+1][i][k]==1){
                    xy[square_x+i][square_y+k]=1;
                    color[square_x+i][square_y+k]=c;
                }
                else if(coord[s][i][k]==1&&coord[s+1][i][k]==0){
                    xy[square_x+i][square_y+k]=0;
                    color[square_x+i][square_y+k]=0;
                }
            }
        s+=1;
    }
    else if(s==2||s==4||s==6||s==23||s==25||s==27){
        for(i=0;i<4;i++)
            for(k=0;k<4;k++)
                if(coord[s][i][k]==0&&coord[s-1][i][k]==1)
                    if(xy[square_x+i][square_y+k])
                        return 0;
        //可以移动
        for(i=0;i<4;i++)
            for(k=0;k<4;k++){
                if(coord[s][i][k]==0&&coord[s-1][i][k]==1){
                    xy[square_x+i][square_y+k]=1;
                    color[square_x+i][square_y+k]=c;
                }
                else if(coord[s][i][k]==1&&coord[s-1][i][k]==0){
                    xy[square_x+i][square_y+k]=0;
                    color[square_x+i][square_y+k]=0;
                }
            }
        s-=1;
    }
    else if(s==10||s==14||s==18){
        for(i=0;i<4;i++)
            for(k=0;k<4;k++)
                if(coord[s][i][k]==0&&coord[s-3][i][k]==1)
                    if(xy[square_x+i][square_y+k])
                        return 0;
        //可以移动
        for(i=0;i<4;i++)
            for(k=0;k<4;k++){
                if(coord[s][i][k]==0&&coord[s-3][i][k]==1){
                    xy[square_x+i][square_y+k]=1;
                    color[square_x+i][square_y+k]=c;
                }
                else if(coord[s][i][k]==1&&coord[s-3][i][k]==0){
                    xy[square_x+i][square_y+k]=0;
                    color[square_x+i][square_y+k]=0;
                }
            }
        s-=3;
    }
    return 1;
}
int down(int s,int c)
{
    for(k=0;k<4;k++)
        for(i=3;i>=0;i--)
            if(coord[s][i][k]){
                if(square_x+i==22||xy[square_x+i+1][square_y+k])//不可移动
                    return 0;
                break;
            }
    //下移
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=0;
                color[square_x+i][square_y+k]=0;
            }
    square_x+=1;
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
            if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=1;
                color[square_x+i][square_y+k]=c;
            }
    return 1;
}
void Add_score()
{
    int h=0,bh;
    for(i=22;i>=0;i--){
        for(k=0;k<13;k++){
            if(xy[i][k]==0)
                break;
        }
        if(k==13){
            bh=i;
            h++;
        }
    }
    if(h){
        score+=h*h;
        level+=h;
        //把分数,级别的输出更新一下
        setcolor(hout,0,2);
        gotoxy(hout,3,11);
        cout<<score;
        gotoxy(hout,3,21);
        cout<<level;
        //将可消去的整行的上面的部分全部下移s行
        for(i=bh-1;i>=0;i--)
            for(k=0;k<13;k++){
                xy[i+h][k]=xy[i][k];
                color[i+h][k]=color[i][k];
            }
        for(i=0;i<h;i++)
            for(k=0;k<13;k++){
                xy[i][k]=0;
                color[i][k]=0;
            }
    }
}
int top()
{
    int i;
    for(i=0;i<13;i++)
        if(xy[0][i]==1)
            return 1;
    return 0;
}
void initial(int s,int c)
{
    for(i=0;i<4;i++)
        for(k=0;k<4;k++)
           if(coord[s][i][k]){
                xy[square_x+i][square_y+k]=1;
                color[square_x+i][square_y+k]=c;
           }
}
void all_print()
{
    for(i=0;i<23;i++){
        gotoxy(hout,15,6+i);
        for(k=0;k<13;k++){
            if(xy[i][k]){
                setcolor(hout,0,color[i][k]);
                cout<<"◎";
            }
            else{
                setcolor(hout,0,0);
                cout<<"  ";
            }
        }
    }
}
int main()
{
    //确定窗口大小
    char cmd[200];
    sprintf(cmd,"mode con cols=%d lines=%d",65,33);
    system(cmd);
    basic_structure();
    gotoxy(hout,0,33);setcolor(hout,0,7);
    shape_num1=rand()%28;
    color1=rand()%6+9;//颜色设置为 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 6种
    shape_num2=rand()%28;
    color2=rand()%6+9;
    int bottom;
    double start;
    while(top()==0){
        square_x=0;square_y=6;
        initial(shape_num1,color1);
        all_print();
        print_next(shape_num2,color2);
        bottom=1;
        while(bottom){//bottom为0则表示不能再继续下移
            start=clock();
            while(clock()-start<=1000.0/level&&!kbhit())
                ;
            if(kbhit()){//有键盘输入
                key1=getch();
                if(key1==-32){
                    key2=getch();
                    if(key2=='H'){//向上为翻转
                        i=up(shape_num1,color1);
                    }
                    else if(key2=='P'){//向下为加速
                        bottom=down(shape_num1,color1);
                        bottom=down(shape_num1,color1);
                    }
                    else if(key2=='K')//左移
                        left(shape_num1,color1);
                    else if(key2=='M')//右移
                        right(shape_num1,color1);
                }
            }
            else{
                bottom=down(shape_num1,color1);
            }
            all_print();
        }
        //看看是否有可以得分的,并且完成消去后整个图形界面的变化
        Add_score();
        all_print();
        //把下一个变为当前的，并重新生成下一个
        shape_num1=shape_num2;
        color1=color2;
        shape_num2=rand()%28;
        color2=rand()%6+9;
    }
    //循环完毕，游戏结束！
    gotoxy(hout,0,30);setcolor(hout,0,14);
    cout<<"               -_-游戏结束-_-！"<<endl;
    setcolor(hout,0,7);
    return 0;
}
