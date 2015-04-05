#include<iostream>
#include<cstdio>
using namespace  std;
int main()
{
    void hanoi(int n,char one ,char two,char three);
    int m;
    printf("input the number of diskes:");
    scanf("%d",&m);
    printf("The step to move %d disks:\n",m);
    hanoi(m,'A','B','C');//分为三个塔，分别为A，B，C
}
void hanoi(int n,char one,char two,char three)//汉诺塔函数
{
    void move(char x,char y);
    if(n==1)move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}
void move(char x,char y)//输出
{
    printf("%c->%c\n",x,y);
}
