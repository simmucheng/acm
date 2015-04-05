#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[1011];
	int y[3],x[4];
	int i,j,m,n;
	scanf("%d",&n);
	while(n--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",&s);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		int t=strlen(s);
		for(i=0;i<t;i++)
		{
			if(s[i]=='A')y[0]++;
			else if(s[i]=='B')y[1]++;
			else if(s[i]=='C')y[2]++;
		}
		//cout<<y[0]<<endl;
		for(i=0;i<y[0];i++)
		{
            if(s[i]=='B')x[0]++;
            else if(s[i]=='C')x[1]++;
		}
		for(i=y[0];i<y[0]+y[1];i++)
		{
            if(s[i]=='C')x[2]++;
		}
		for(i=y[0]+y[1];i<y[0]+y[1]+y[2];i++)
		{
            if(s[i]=='B')x[3]++;
		}
		int num=0;
		num=x[0]+x[1]+max(x[2],x[3]);
        printf("%d\n",num);
	}
	return 0;
}