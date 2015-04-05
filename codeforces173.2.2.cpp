#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,m,n;
	scanf("%d",&n);
	int num1;
	num1=0;
	int a,b;
	char s[1000010];
	int mark=0;
	for(i=0;i<n;i++)
	{
       scanf("%d%d",&a,&b);
       if(num1+a<=500){num1+=a;s[i]='A';}
       else if(num1-b>=-500){num1-=b;s[i]='G';}
	}
	for(i=0;i<n;i++)
	printf("%c",s[i]);
    printf("\n");
	return 0;
}