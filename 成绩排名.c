#include<stdio.h>
int main ()
{struct student
    {
        int num;
        char name[20];
        float score;
    }student1,student2;
    scanf("%d %s %f",&student1.num,student1.name,&student1.score);
    scanf("%d %s %f",&student2.num,student2.name,&student2.score);
    printf("%d %s %.3f\n",student1.num,student1.name,student1.score);
    printf("%d %s %.3f",student2.num,student2.name,student2.score);
    return 0;
}
