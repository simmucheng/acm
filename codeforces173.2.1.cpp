#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,m,n;
	char s[10];
	scanf("%d",&n);
	int num=0;
	while(n--)
	{
	   //getchar();
	   cin>>s;
       if(s[1]=='-')num--;
       else if(s[1]=='+')num++;
       //cout<<num<<endl;
	}
	printf("%d\n",num);
	return 0;
}