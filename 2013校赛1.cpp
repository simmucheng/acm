#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int s[1011];
	int y[3];
	int i,j,m,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		memset(s,0,sizeof(s));
		int t=strlen(s);
		for(i=0;i<t;i++)
		{
			if(s[i]=='A')y[0]++;
			else if(s[i]=='B')y[1]++;
			else if(s[i]=='C')y[2]++;
		}
		for(i=0;i<y[0];i++)
		{
            if(s[i]=='B')x[0]++;
            else if(s[i]=='C')x[1]++;
		}
		for(i=y[0];i<y[0]+y[1];i++)
		{
            if(s[i]=='C')x[2]++;
		}
		int num=0;
		num=x[0]+x[1]+x[2];
        printf("%d\n",num);
	}
	return 0;
}