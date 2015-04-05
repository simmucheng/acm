#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,s,d;
    int w[12];
    while(scanf("%d%d",&s,&d)!=EOF)
    {
        int ju=0;
        if(s>=4*d)ju=1;
        else
        {
            int mark=0;
           for(i=0;i<5;i++)
           {
               if((i+1)*s-(4-i)*d<0&&((i+2)*s-(3-i)*d>=0)){mark=1;break;}
           }
           //cout<<i<<endl;
            if(mark==0)
           {
            for(i=0;i<4;i++)
            w[i]=s;
            w[i]=-d;
           }
           else
           for(j=0;j<5;j++)
           {
               if(j<=i)w[j]=s;
               else w[j]=-d;
           }
            //for(int l=0;l<5;l++)
           // cout<<w[l]<<' ';
           for(i=1;i<8;i++)
           {
               int num=0;
               for(j=i;j<i+4;j++)
                   num+=w[j];
                if(num+s<0)w[j]=s;
                else w[j]=-d;
           }
        }
        int co=0;
        for(i=0;i<12;i++)
        co+=w[i];
        if(ju==1||co<0)printf("Deficit\n");
        else
        printf("%d\n",co);
    }
    return 0;
}
