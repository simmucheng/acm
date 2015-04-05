#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    int a,b,i,j,c,max,min,s;
    while(scanf("%d%d%d",&a,&b,&c)&&a&&b&&c)
    {
        max=min=0;
        priority_queue<int ,vector<int>,greater<int> >Q1;
        priority_queue<int>Q2;
        double num=0.0;
        for(i=0;i<c;i++)
        {
         scanf("%d",&s);
         num+=s;
         Q1.push(s);
         Q2.push(s);
        if(Q1.size()>a)
             Q1.pop();
         if(Q2.size()>b)
             Q2.pop();
        }
        while(!Q1.empty())
        {
            max+=Q1.top();
            Q1.pop();
        }
        while(!Q2.empty())
        {
            min+=Q2.top();
            Q2.pop();
        }
        num=(num-min-max)*1.0/(c-a-b);
        printf("%.6f\n",num);
    }
    return 0;
}
