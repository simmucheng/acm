#include<iostream>
#include<cstdio>
using namespace std;
int y=0;
int sum[51001<<2];
void uplish(int e1)
{
    sum[e1]=sum[e1<<1]+sum[(e1<<1)+1];
}
void build(int star,int end,int tar)
{
    if(star==end)
    {
      scanf("%d",&sum[tar]);
      //cout<<"tar="<<tar<<endl;
      return ;
    }
    build(star,(star+end)>>1,(tar<<1));
    build((star+end>>1)+1,end,(tar<<1)+1);
    uplish(tar);
}
void ADD(int a1,int a2,int a3,int a4,int a5)
{
  //  cout<<"greg"<<endl;
    if(a4==a3)
    {
    sum[a5]+=a2;
    return ;
    }
    else if(a1<=(a3+a4)/2){ADD(a1,a2,a3,(a3+a4)>>1,a5<<1);}
    else ADD(a1,a2,((a3+a4)>>1)+1,a4,a5<<1|1);
    uplish(a5);
   // cout<<"verbhnirewhg"<<endl;
   // cout<<sum[a5]<<' '<<a5<<endl;
}
int quary(int q1,int q2,int st,int en,int re)
{
    //cout<<"greyh"<<endl;
    if(q1<=st&&q2>=en)
    return sum[re];
    int su=0;
    if(q1<=(st+en)>>1)su+=quary(q1,q2,st,(st+en)>>1,re<<1);
    if(q2>(st+en)>>1)su+=quary(q1,q2,((st+en)>>1)+1,en,(re<<1)+1);
    return su;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    {
        scanf("%d",&m);
        build(1,m,1);
        printf("Case %d:\n",k);
        //cout<<y<<endl;
       // for(i=1;i<=16;i++)
      // cout<<sum[i]<<' '<<"i="<<i<<endl;
        getchar();
        char t[10];
        while(scanf("%s",t)!=EOF){
        if(t[0]=='E')
        break;
        else if(t[0]=='Q')
        {
            //cout<<"gerh"<<endl;
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",quary(a,b,1,m,1));
        }
        else if(t[0]=='A')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ADD(a,b,1,m,1);
         //   for(i=1;i<=16;i++)
      // cout<<sum[i]<<' '<<"i="<<i<<endl;
        }

        else if(t[0]=='S')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ADD(a,-1*b,1,m,1);
        }

    }
    }
    return 0;
}
