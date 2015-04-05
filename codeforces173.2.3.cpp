#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000010],w[1000010];
bool judge1(int x)
{
	if(x==0)return false;
	int p,q;
	p=(s[x]-'0')|(s[x-1]-'0');
	q=(s[x]-'0')^(s[x-1]-'0');
	if((w[x-1]-'0'==p)&&(w[x]-'0'==q)){s[x]=w[x];s[x-1]=w[x-1];return true;}
	else if((w[x-1]-'0'==q)&&(w[x]-'0'==p)){s[x]=w[x];s[x-1]=w[x-1];return true;}
	return false;
}
bool judge2(int x)
{
   if(x+1==strlen(s))return false;
	int p,q;
	p=(s[x]-'0')|(s[x+1]-'0');
	q=(s[x]-'0')^(s[x+1]-'0');
	if((w[x]-'0'==q)){s[x]=w[x];s[x+1]=p;return true;}
	else if((w[x]-'0'==p)){s[x]=w[x];s[x+1]=q;return true;}
	return false;	
}
int main()
{
	int i,j,m,n;
	while(scanf("%s%s",s,w)!=EOF)
	{
		//cin>>s;
		//cin>>w;
		int t=strlen(s);
		int e=strlen(w);
		//int mark=0;
		int num1=0;
		int num2=0;
		if(t!=e)printf("NO\n");
		else 
		{
			for(i=0;i<t;i++)
			{
				if(s[i]=='1')num1++;
				if(w[i]=='1')num2++;
			}
		if(num2>0&&num1>0)printf("YES\n");
		else if(num2==0&&num1==0)printf("YES\n");
		else printf("NO\n");
		}
	}
	return 0;
}