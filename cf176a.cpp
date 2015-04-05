#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,m,n;
	int s[4][4];
	char e;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%c",&e);
			if(e=='#')s[i][j]=1;
			else s[i][j]=0;
        }
        getchar();
	}
	int mark=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			int num=s[i][j]+s[i][j+1]+s[i+1][j]+s[i+1][j+1];
		    if(num>=3||num<=1){mark=1;break;}	
		}
	}
	if(mark==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}