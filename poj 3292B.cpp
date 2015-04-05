#include<iostream>
#include<cstdio>
using namespace std;
int prim[1000000];
void prime()
{
	int top=1;
	prim[0]=5;
    for(int i=9;i<=1000001;i+=4)
    {
    	int flag=0;
        for(int j=0;prim[j]*prim[j]<=i;j++)
        {
        	if(i%prim[j]==0){flag=1;break;}
        }
        if(!flag)prim[top++]=i;
    }
    cout<<top<<endl;
    return ;
}
/*int table()
{
	int num=0;
    for(int i=0;i<=1000001;i++)
    {

    }
}*/
int main()
{
	int i,j,m,n;
	prime();
	//table();
    while(scanf("%d",&n),n)
    {
        //printf("%d\n",s[i]);
    }
}