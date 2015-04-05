#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node
{
	int mark;
	char h[30];
}s[1010];
void prin(int kk,int yy)
{
	for(int ii=0;ii<kk;ii++)
	{
		printf("%c",s[yy].h[ii]);
	}
	printf("\n");
	return ;
}
int main()
{
	int i,j,m,n;
	i=0;
	cin>>n;
	for(j=0;j<n;j++)
		scanf("%s",s[j].h);
	i=n;
		for(j=0;j<n;j++)
		{
           for(int k=s[j].mark;k<strlen(s[i].h);k++)
           {
           	 int mark1=0;
           	 for(int l=j+1;l<n;l++)
           	 {
           	 	if(k>=strlen(s[l].h)){mark1++;continue;}
           	 	if(s[j].h[k]==s[l].h[k]){mark1++;s[l].mark=k;}
           	 }
           	 if(mark1==i-j)prin(k,j);
           }
		}
	return 0;
}