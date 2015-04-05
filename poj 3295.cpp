#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int l1,l2,l3,l4,l5;
stack <int> w1;
queue <char> w2;
int trans(char y)
{
    if(y=='p')return l1;
    else if(y=='q')return l2;
    else if(y=='r')return l3;
    else if(y=='s')return l4;
    else if(y=='t')return l5;
}
int main()
{
   int i,j,m,n;
   char s[1000];
   while(scanf("%s",s)!=EOF)
   {

       if(s[0]=='0')break;
       int e;
       int mark=0;
       for(l1=0;l1<2;l1++)
       {
           for(l2=0;l2<2;l2++)
           {
               for(l3=0;l3<2;l3++)
               {
                   for(l4=0;l4<2;l4++)
                   {
                       for(l5=0;l5<2;l5++)
                       {
                           while(!w1.empty())w1.pop();
                           while(!w2.empty())w2.pop();
                           for(i=strlen(s)-1;i>=0;i--)
                            {
                              if(s[i]=='p'||s[i]=='q'||s[i]=='r'||s[i]=='s'||s[i]=='t')
                              {w1.push(trans(s[i]));}
                              else
                              {
                                  int x1,x2;
                                  x1=w1.top();
                                  w1.pop();
                                  if(s[i]!='N')
                                  {
                                    x2=w1.top();
                                    w1.pop();
                                  }
                                 if(s[i]=='K')w1.push(x1&x2);
                                 else if(s[i]=='A')w1.push(x1|x2);
                                 else if(s[i]=='N')w1.push(x1^1);
                                 else if(s[i]=='C')w1.push((1^x1)|x2);
                                 else if(s[i]=='E')w1.push(1^(x1^x2));
                              }
                            }
                          e=w1.top();
                          w1.pop();
                          if(e==0){mark=1;break;}
                       }
                       if(mark==1)break;
                   }
                   if(mark==1)break;
               }
               if(mark==1)break;
           }
           if(mark==1)break;
       }
       if(mark==0)printf("tautology\n");
       else printf("not\n");
       memset(s,0,sizeof(s));
   }
   return 0;
}
