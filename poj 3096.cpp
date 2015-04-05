#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mm[30][30];
char s[100];
int main()
{
	int i,j,m,n;
	while(scanf("%s",s),s[0]!='*')
	{
		int mark=0;
		int t=strlen(s);
		for(i=1;i<t;i++)
		{
			memset(mm,0,sizeof(mm));
			for(j=0;j+i<t;j++)
			{
				if(!mm[s[j]-'A'][s[j+i]-'A'])mm[s[j]-'A'][s[j+i]-'A']=1;
				else {mark=1;break;}
			}
			if(mark==1)break;
		}
		if(mark==1)printf("%s is NOT surprising.\n",s);
		else printf("%s is surprising.\n",s);
	}
	return 0;
}